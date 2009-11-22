#ifndef __TP3__ROUTER__
#define __TP3__ROUTER__

#include "tipos_basicos.h"
#include "tipos_impl.h"

#include <string>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

class Enrutador
{
public:

    Enrutador(const int cantInterfaces) : m_cantInterfaces(cantInterfaces) , m_Eventos(cantInterfaces) {}

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


    static bool coincide(const DirIp &d, const ReglaDir & r);

    Nat m_cantInterfaces;
    Conjunto<Version> m_Versiones;
    vector<vector<Evento> > m_Eventos;              // Se indexa por intefaz
    vector<ReglaDir> m_Reglas;         

    Secu<Evento> s_eventos;
};
#endif
