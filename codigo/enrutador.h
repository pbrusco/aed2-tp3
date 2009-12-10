#ifndef __TP3__ROUTER__
#define __TP3__ROUTER__

#include "tipos_basicos.h"
#include "tipos_impl.h"

struct VersionYArbol{

	Version version;
	ArbolDeReglas abr;
		
	//CONSTRUCTOR
	VersionYArbol(Version ver,ArbolDeReglas ab){
	version = ver;
	abr = ab;
	}
};

bool operator<(const VersionYArbol& v1,const VersionYArbol& v2)
{
    return v1.version < v2.version;
}

struct NatYSecuEvento{

	Nat tiempoCaida;
	Secu<Evento> eventos;
	
	//CONSTRUCTOR	
	NatYSecuEvento(){
	tiempoCaida = 0;
	}
};


class Enrutador
{
public:
    
    // Debería ser el único constructor
    Enrutador(const int cantInterfaces);    
    // Destructor
    ~Enrutador();

    // Observadores

    const Conjunto<Version> & versiones() const;
    Nat interfaces() const;                         // devuelve cuantas interfaces tiene
    const Secu<Evento> & eventos(Interfaz i);       // ordenados de mas viejo a mas reciente
    Nat tiempoCaida(Interfaz i) const;
    bool estaCaida(Interfaz i) const;

    // Operaciones
    void agVersion(const Version &v);
    void agRegla(const ReglaDir &r);
    void agEvento(const Evento &e);
    RespuestaDir enrutar(const DirIp &d) const;

private:

		Conjunto<Version> versioness;
		Nat cantInterfaces;
		Secu<VersionYArbol> reglas;
		ArregloDimensionable<NatYSecuEvento> status_inter;
};



Enrutador::~Enrutador(){

IterSecu<VersionYArbol> it = reglas.crearIt();

while(tieneProximo(it)){
delete &(actualAdelante(it).abr);
delete &(actualAdelante(it));
}


}


Enrutador::Enrutador(const int cantInter){

	cantInterfaces = cantInter;
	status_inter = ArregloDimensionable<NatYSecuEvento>(cantInter);
}


const Conjunto<Version> & Enrutador::versiones() const {

	return versioness;
}

Nat Enrutador::interfaces() const{

	return cantInterfaces;
}

const Secu<Evento> & Enrutador::eventos(Interfaz i){

	return status_inter[i].eventos;
}



Nat Enrutador::tiempoCaida(Interfaz i) const{
	return status_inter[i].tiempoCaida;

}


bool Enrutador::estaCaida(Interfaz i) const{
IterSecu<Evento> it = status_inter[i].eventos.crearIt();
return actualAtras(it).esCaida;


}


void Enrutador::agVersion(const Version &v){

versioness.agregar(v);
ArbolDeReglas* a = new ArbolDeReglas;
VersionYArbol* aux = new VersionYArbol(v,*a);
reglas.agAdelante(*aux);

}


void Enrutador::agRegla(const ReglaDir &r){
IterSecu<VersionYArbol> it = reglas.crearIt();
Version v = r.dirIp.tam();
while(actualAdelante(it).version != v){
avanzar(it);
}
actualAdelante(it).abr.agRegla(r);


}


void Enrutador::agEvento(const Evento &e){
 
 Interfaz i;
 Nat tc;
 Evento evento_prev;
 Evento evento_post;
 IterSecu<Evento> it = status_inter[i].eventos.crearIt();

 i = e.interfaz ;
 
 tc = (status_inter[i]).tiempoCaida;
 (status_inter[i]).eventos.agAtras(e) ;
 
 if ((actualAtras(it) == e) and tieneAnterior(it)){
     retroceder(it);
     if (actualAtras(it).esCaida)
     {
         tc = tc + (e.timestamp - actualAtras(it).timestamp);
     }
 }
 else{
     if (tieneAnterior(it)){
          while (actualAtras(it) == e){
              evento_post = actualAtras(it) ;
              retroceder(it);
          }
          if (not tieneAnterior(it))
          {
              if (e.esCaida)
              {
                  tc = tc + (evento_post.timestamp - e.timestamp);
              }
          }
          else{
              retroceder(it);
              evento_prev = actualAtras(it);
              if (e.esCaida and (not evento_prev.esCaida))
              {
                  tc = tc + (evento_post.timestamp - e.timestamp);
              }
              if (not e.esCaida and evento_prev.esCaida)
		{
                  tc = tc - (evento_post.timestamp - e.timestamp);
              	}
          }
     }
 }
 (status_inter[i]).tiempoCaida = tc;
}


RespuestaDir Enrutador::enrutar(const DirIp &d) const{

  if (not versioness.pertenece(d.tam())){
  
      return RespuestaDir::DireccionNoSoportada();
  }else
      {
	IterSecu<VersionYArbol> it = reglas.crearIt();
	Interfaz i;
      	
      while (actualAdelante(it).version = d.tam()){
         avanzar(it);
      }
     if (not actualAdelante(it).abr.tieneRegla(d)){
         return RespuestaDir::InterfazDeSalidaNoEncontrada();
	}
     else{
         i = actualAdelante(it).abr.interfazDeSalida(d) ;
         if (estaCaida(i)){
             return RespuestaDir::InterfazDeSalidaCaida(i);
         }else{
             return RespuestaDir::SalidaPorInterfaz(i);
         }
     }
 }













}

#endif
