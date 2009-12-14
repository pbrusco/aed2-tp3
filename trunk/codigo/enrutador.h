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
	NatYSecuEvento() {
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
    const Conjunto<Version>& versiones() const;
    Nat interfaces() const;                         // devuelve cuantas interfaces tiene
    const Secu<Evento>& eventos(Interfaz i);       // ordenados de mas viejo a mas reciente
    Nat tiempoCaida(Interfaz i) const;
    bool estaCaida(Interfaz i) const;

    // Operaciones
    void agVersion(const Version& v);
    void agRegla(const ReglaDir& r);
    void agEvento(const Evento& e);
    RespuestaDir enrutar(const DirIp& d) const;

private:

		Conjunto<Version> versioness;
		Nat cantInterfaces;
		Secu<VersionYArbol> reglas;
		ArregloDimensionable<NatYSecuEvento> status_inter;
};



Enrutador::Enrutador(const int cantInter){

	cantInterfaces = cantInter;
	status_inter = ArregloDimensionable<NatYSecuEvento>(cantInter);
}


Enrutador::~Enrutador(){
	

}



const Conjunto<Version>& Enrutador::versiones() const {

	return versioness;
}

Nat Enrutador::interfaces() const{

	return cantInterfaces;
}

const Secu<Evento>& Enrutador::eventos(Interfaz i){

	return status_inter[i].eventos;
}


Nat Enrutador::tiempoCaida(Interfaz i) const{

	return status_inter[i].tiempoCaida;
}


bool Enrutador::estaCaida(Interfaz i) const{

	if ((status_inter[i].eventos).vacia()){
	return false;
	}
	else
	{
	IterSecu<Evento> it = status_inter[i].eventos.crearIt();
	return actualAtras(it).esCaida;
	}
}


void Enrutador::agVersion(const Version &v){

	versioness.agregar(v);
	ArbolDeReglas a;
	VersionYArbol aux(v,a);
	reglas.agAdelante(aux);
}


void Enrutador::agRegla(const ReglaDir &r){

	IterSecu<VersionYArbol> it = reglas.crearIt();
	Version v = r.dirIp.tam();

	while(actualAdelante(it).version != v)
		avanzar(it);

	actualAdelante(it).abr.agRegla(r);
}


void Enrutador::agEvento(const Evento &e){

	Interfaz i;
	Nat tc;
	Nat tact;
	Nat tant;
	Nat tsig;

	tact = e.timestamp;

	tc = status_inter[e.interfaz].tiempoCaida;

	status_inter[e.interfaz].eventos.agAtras(e);

	IterSecu<Evento> it = status_inter[e.interfaz].eventos.crearIt();

	

	if ((actualAtras(it) == e) and tieneAnterior(it)){
		 retroceder(it);
		 if (actualAtras(it).esCaida)
			 tc = tc + (tact - actualAtras(it).timestamp);
	}
	else{
		if (tieneAnterior(it)){
			while (not (actualAtras(it) == e)){
			tsig = actualAtras(it).timestamp ;
			retroceder(it);
			}
		
			if (not (tieneAnterior(it))){
				if (e.esCaida)
					tc = tc + (tsig - tact);
				}
			else{
				retroceder(it);
				tant = actualAtras(it).timestamp;
				if (e.esCaida and (not (actualAtras(it).esCaida)))
					tc = tc + (tsig - tact);

				if (not (e.esCaida) and actualAtras(it).esCaida)
					tc = tc - (tsig - tact);
			}
		}
	}
	(status_inter[e.interfaz]).tiempoCaida = tc;
}



RespuestaDir Enrutador::enrutar(const DirIp &d) const{

  if (!versioness.pertenece(d.tam())){
  
      return RespuestaDir::DireccionNoSoportada();
  }else
      {
	IterSecu<VersionYArbol> it = reglas.crearIt();
	      	
      	while (actualAdelante(it).version != d.tam()){
        	avanzar(it);
      	}
     	if (!actualAdelante(it).abr.tieneRegla(d)){
        	return RespuestaDir::InterfazDeSalidaNoEncontrada();
	}
     	else{
        	Interfaz i = actualAdelante(it).abr.interfazDeSalida(d) ;
         	if (estaCaida(i)){
             		return RespuestaDir::InterfazDeSalidaCaida(i);
         	}
		else{
             		return RespuestaDir::SalidaPorInterfaz(i);
         	}
     	}
 }

}

#endif
