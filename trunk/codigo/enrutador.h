#ifndef __TP3__ROUTER__
#define __TP3__ROUTER__

#include "tipos_basicos.h"
#include "tipos_impl.h"

class Enrutador
{
public:
    
    // Debería ser el único constructor
    Enrutador(const int cantInterfaces);    
    // Destructor
    ~Enrutador();

    // Observadores

    const Conjunto<Version> & versiones() const;
    Nat interfaces() const;                               // devuelve cuantas interfaces tiene
    const Secu<Evento> & eventos(Interfaz i);       // ordenados de mas viejo a mas reciente
    Nat tiempoCaida(Interfaz i) const;
    bool estaCaida(Interfaz i) const;

    // Operaciones
    void agVersion(const Version &v);
    void agRegla(const ReglaDir &r);
    void agEvento(const Evento &e);
    RespuestaDir enrutar(const DirIp &d) const;

private:
        
        // Completar...si quiero

};
#endif
