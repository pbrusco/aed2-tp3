#ifndef __TP3__TIPOS_IMPL__
#define __TP3__TIPOS_IMPL__

/*
 * - Interfaces (externas) implementadas para la solucion
 */

typedef unsigned int Nat;

#include <ostream>

using namespace std;

/////////////////////// CONJUNTO ///////////////////////

template <typename T>
class Conjunto
{
public:

    Conjunto();

    void agregar(const T & elem);

    bool pertenece(const T & elem) const;

    void escribir(ostream & os) const;

private:
    // A completar...

};

/////////////////////// FIN CONJUNTO ///////////////////////


/////////////////////// SECU ///////////////////////

template <typename T>
class Secu
{
public:

    Secu();
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

/////////////////////// FIN SECU ///////////////////////


/////////////////////// ARREGLO DIMENSIONABLE ///////////////////////

template <typename T>
class ArregloDimensionable
{
public:
    // Constructor que toma tamaño inicial
    ArregloDimensionable(Nat tamInicial);

	// Destructor de arreglo dimensionable
    ~ArregloDimensionable();

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
	T* arreglo;
	Nat tamanio;
};


template <typename T>
ArregloDimensionable<T>::ArregloDimensionable(Nat tamInicial){

	arreglo = new T[tamInicial];
	tamanio = tamInicial;

}

template <typename T>
ArregloDimensionable<T>::~ArregloDimensionable(){

	delete []arreglo;

}

template <typename T>
ArregloDimensionable<T>::ArregloDimensionable(const ArregloDimensionable& otro){

	tamanio = otro.tam();
	arreglo = new T[tamanio];
	for(int i=0;i<tamanio;i++)
		arreglo[i] = (otro.arreglo)[i];

}

template <typename T>
Nat ArregloDimensionable<T>::tam() const{
	return tamanio;
}

template <typename T>
T & ArregloDimensionable<T>::operator[](Nat pos){

	return arreglo[pos];

}

template <typename T>
const T & ArregloDimensionable<T>::operator[](Nat pos) const{

	return arreglo[pos];

}

template <typename T>
void ArregloDimensionable<T>::escribir(ostream & os) const{

	os << "(";
	for(int i=0;i<tamanio-1;i++)
		os << arreglo[i] << " ";
	os << arreglo[tamanio-1] << ")";

}
/////////////////////// FIN ARREGLO DIMENSIONABLE ///////////////////////





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
