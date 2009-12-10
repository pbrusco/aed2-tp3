#ifndef __TP3_TIPOS_BASICOS__
#define __TP3_TIPOS_BASICOS__

/*
 * - Tipos basicos usados
 * - Acá no hace falta implementar nada
 */

// SI hay que implementar lo definido en este include
#include "tipos_impl.h"

// Renombres básicos
typedef Nat Interfaz;
typedef Nat Version;
typedef ArregloDimensionable<Nat> DirIp;

// Regla de direccionamiento
struct ReglaDir
{
    DirIp dirIp;
    Nat cantBits;
    Interfaz interfazSalida;
    
    ReglaDir(DirIp d) : dirIp(d) {}
};


// Evento de una interfaz
struct Evento
{
    bool esCaida;
    Nat timestamp;
    Interfaz interfaz;
};

// Representación de las respuestas posibles de un ruteo
class RespuestaDir
{
public:

    // Creación de respuestas sin parámetros
    static RespuestaDir DireccionNoSoportada()
    {
        return RespuestaDir(DIR_NO_SOPORTADA);
    }
    static RespuestaDir InterfazDeSalidaNoEncontrada()
    {
        return RespuestaDir(INT_NO_ENCONTRADA);
    }

    // Creación de respuestas con parámetros
    static RespuestaDir InterfazDeSalidaCaida(Interfaz i)
    {
        return RespuestaDir(INT_CAIDA,i);
    }
    static RespuestaDir SalidaPorInterfaz(Interfaz i)
    {
        return RespuestaDir(SALIDA_POR_INT,i);
    }

    // Observadores
    bool operator==(const RespuestaDir & otra)
    {
        if (m_res != otra.m_res)
            return false;

        switch (m_res)
        {
        case INT_CAIDA:
        case SALIDA_POR_INT:
            return m_inter == otra.m_inter;
            break;  // No hace falta pero evita warning

        default:
            break;
        };

        return true;
    }

    bool esDireccionNoSoportada()           { return m_res == DIR_NO_SOPORTADA;}
    bool esInterfazDeSalidaNoEncontrada()   { return m_res == INT_NO_ENCONTRADA;}
    bool esInterfazDeSalidaCaida()          { return m_res == INT_CAIDA;}
    bool esSalidaPorInterfaz()              { return m_res == SALIDA_POR_INT;}

    // Solo tiene sentido preguntarlo para InterfazDeSalidaCaida/SalidaPorInterfaz
    Interfaz InterfazDeSalida()
    {
        return m_inter;
    }

private:

    enum Respuesta
    {
        DIR_NO_SOPORTADA,
        INT_NO_ENCONTRADA,
        INT_CAIDA,
        SALIDA_POR_INT,
    };

    // No implementada, NO LLAMAR
    RespuestaDir();
    // Auxiliares
    RespuestaDir(Respuesta r) : m_res(r) {}
    RespuestaDir(Respuesta r, Interfaz i) : m_res(r), m_inter(i) {}

    Respuesta m_res;
    // Intefaz de respuesta
    Interfaz m_inter;
};

// Funciones de salida necesitadas por el Parser
bool operator<(const Evento& e1,const Evento& e2)
{
    return e1.timestamp < e2.timestamp;
}

ostream & operator<<(ostream &os, Evento e)
{
    os << "< " << (e.esCaida? "CAIDA" : "NOCAIDA") << " " << e.timestamp << " " << e.interfaz << " >";
    return os;
}

ostream & operator<<(ostream &os, ReglaDir r)
{
    os << "< " << r.dirIp << " " << r.cantBits << " " << r.interfazSalida << " >";
    return os;
}

ostream & operator<<(ostream &os, RespuestaDir r)
{
    if (r.esDireccionNoSoportada())
        os << "DireccionNoSoportada";

    if (r.esInterfazDeSalidaNoEncontrada())
        os << "InterfazDeSalidaNoEncontrada";

    if (r.esInterfazDeSalidaCaida())
        os << "InterfazDeSalidaCaida " << r.InterfazDeSalida();

    if (r.esSalidaPorInterfaz())
        os << "SalidaPorInterfaz " << r.InterfazDeSalida();

    return os;
}

#endif
