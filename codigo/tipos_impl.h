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
	~Secu();
    Secu(const Secu<T>& s);
    Secu& operator=(const Secu<T> &s);
    Nat longitud();
    void agAtras(const T & elem);
    void agAdelante(const T & elem);
	bool vacia() const;
    const T & iesimo(Nat i) const;
    void escribir(ostream & os) const;

private:

	template <typename T2>
	struct Nodo
	{
		Nodo(T2 e) : dato(e) {}

		T2 dato;
		Nodo<T2>* siguiente;
		Nodo<T2>* anterior;
	};

	Nodo<T> *prim;
	Nodo<T> *ult;
	Nat tamanio;
	void vaciar();
	void copiarDesde(const Secu<T>& s);


};

template <typename T>
Secu<T>::Secu(){

	prim = NULL;
    ult = NULL;
	tamanio = 0;
}

template <typename T>
Secu<T>::~Secu(){

	vaciar();
}

template <typename T>
Secu<T>::Secu(const Secu<T>& s){

	prim = NULL;
    ult = NULL;
    copiarDesde(s);
}

template <typename T>
Secu<T>& Secu<T>::operator=(const Secu<T> &s){

	copiarDesde(s);
}

template <typename T>
Nat Secu<T>::longitud(){

	return tamanio;
}

template <typename T>
void Secu<T>::agAtras(const T & elem){

	Nodo<T>* nuevo = new Nodo<T>(elem);
	nuevo->anterior = NULL;
	nuevo->siguiente = NULL;
	if (not (vacia())){
		if (prim->dato > elem || ult->dato < elem){
			if(prim->dato > elem){
			
				prim->anterior = nuevo;
				nuevo->siguiente = prim;
				prim = nuevo;
			}
			else{

				ult->siguiente = nuevo;
				nuevo->anterior = ult;
				ult = nuevo;
			}
		}
		else{

			Nodo<T>* aux = ult;
			while((aux->anterior)->dato > elem)
				aux = aux->anterior;

			(aux->anterior)->siguiente = nuevo;
			nuevo->anterior = aux->anterior;
			nuevo->siguiente = aux;
			aux->anterior = nuevo;
		}
	}
	else{

		prim = nuevo;
		ult = nuevo;		
	}
	tamanio++;

}

template <typename T>
void Secu<T>::agAdelante(const T & elem){

	Nodo<T>* nuevo = new Nodo<T>(elem);
	nuevo->anterior = NULL;
	nuevo->siguiente = NULL;
	if (not (vacia())){
		if (prim->dato > elem || ult->dato < elem){
			if(prim->dato > elem){
			
				prim->anterior = nuevo;
				nuevo->siguiente = prim;
				prim = nuevo;
			}
			else{

				ult->siguiente = nuevo;
				nuevo->anterior = ult;
				ult = nuevo;
			}
		}
		else{

			Nodo<T>* aux = prim;
			while((aux->siguiente)->dato < elem)
				aux = aux->siguiente;

			(aux->siguiente)->anterior = nuevo;
			nuevo->siguiente = aux->siguiente;
			nuevo->anterior = aux;
			aux->siguiente = nuevo;
		}
	}
	else{

		prim = nuevo;
		ult = nuevo;		
	}
	tamanio++;
}



template <typename T>
bool Secu<T>::vacia() const{

	return (prim == NULL);
}

template <typename T>
const T & Secu<T>::iesimo(Nat i) const{

	Nodo<T>* aux = prim;	
	for(int j = 0;j<=i;j++){

		aux = aux->siguiente;
	}

	return &(aux->dato);
}

template <typename T>
void Secu<T>::escribir(ostream & os) const{

	os << '[';
	Nodo<T> *aux = prim;
	while(aux != ult){
		os << (aux->dato) << ',';
		aux = aux->siguiente;
		}
	if (not(vacia())) os << (ult->dato);
	os << ']';
}

template <class T> 
void Secu<T>::vaciar(){

    while (not(vacia())){
        Nodo<T>* aux = prim;
		prim = prim->siguiente;
		if(not(vacia()))
			prim->anterior = NULL;
		delete aux;
    }
}

template <class T>
void Secu<T>::copiarDesde(const Secu<T>& s) {
    
	vaciar();
    Nodo<T> *aux = s.prim;
    while(aux != NULL){
        agAtras(aux->dato);
        aux = aux->siguiente;
    }
}



template <typename T>
ostream & operator<<(ostream &os, const Secu<T> & s)
{
    s.escribir(os);
    return os;
}



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

template <typename T>
ostream & operator<<(ostream &os, const ArregloDimensionable<T> & ad)
{
    ad.escribir(os);
    return os;
}


/////////////////////// FIN ARREGLO DIMENSIONABLE ///////////////////////





template <typename T>
ostream & operator<<(ostream &os, const Conjunto<T> & c)
{
    c.escribir(os);
    return os;
}



#endif
