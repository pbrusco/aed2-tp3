#ifndef __TP3__ROUTER__
#define __TP3__ROUTER__

#include "tipos_basicos.h"
#include "tipos_impl.h"

struct VersionYArbol{

	Nat version;
	ArbolDeReglas abr;
};

struct NatYSecuEvento{

	Nat tiempoCaida;
	Secu<Evento> eventos;
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



Enrutador::Enrutador(const int cantInter){

	cantInterfaces = cantInter;
	ArregloDimensionable<NatYSecuEvento> nuevo(cantInter);
	status_inter = nuevo;


}

#endif
