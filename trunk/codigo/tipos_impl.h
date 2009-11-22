#ifndef __TP3__TIPOS_IMPL__
#define __TP3__TIPOS_IMPL__

/*
 * - Interfaces (externas) implementadas para la solucion
 */

typedef unsigned int Nat;

#include <ostream>
#include <set>
#include <vector>

using namespace std;

template <typename T>
class Conjunto
{
public:

    Conjunto() {}

    void agregar(const T & elem);

    bool pertenece(const T & elem) const;

    void escribir(ostream & os) const;

private:
    // A completar...

};

template <typename T>
class Secu
{
public:

    Secu() {};
    Secu(const Secu<T>& s);
    Secu& operator=(const Secu<T> &s);
    Nat longitud();
    void agAtras(const T & elem);
    void agAdelante(const T & elem);
    const T & iesimo(Nat i) const;
    void escribir(ostream & os) const;

private:
    // A completar...
};

template <typename T>
class ArregloDimensionable
{
public:
    // Constructor que toma tamaño inicial
    ArregloDimensionable(Nat tamInicial);

    // Constructor por copia
    ArregloDimensionable(const ArregloDimensionable& otro);

    // Observador de tamaño
    Nat tam() const;

    // Pide iesimo (modificable)
    T & operator[](Nat pos);

    // Pide iesimo (no modificable)
    const T & operator[](Nat pos) const;

    void escribir(ostream & os) const;

private:
    // A completar...
};

template <typename T>
ostream & operator<<(ostream &os, const Conjunto<T> & c)
{
    c.escribir(os);
    return os;
}

template <typename T>
ostream & operator<<(ostream &os, const Secu<T> & s)
{
    s.escribir(os);
    return os;
}

template <typename T>
ostream & operator<<(ostream &os, const ArregloDimensionable<T> & ad)
{
    ad.escribir(os);
    return os;
}

#endif
