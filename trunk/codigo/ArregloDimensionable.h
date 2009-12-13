#ifndef __ARREGLODIMENSIONABLE__
#define __ARREGLODIMENSIONABLE__

//////////////////////////////////////// ARREGLO DIMENSIONABLE ///////////////////////////////////////


/* --Intefaz de ArregloDimensionable--*/

template <typename T>
class ArregloDimensionable{
	public:
		// Constructor por defecto
		ArregloDimensionable();
		
		// Constructor por defecto que toma tamaño inicial
		ArregloDimensionable(Nat tamInicial);

		// Destructor de arreglo dimensionable
		~ArregloDimensionable();

		// Constructor por copia
		ArregloDimensionable(const ArregloDimensionable& otro);

		// Indica el tamaño del arreglo
		Nat tam() const;

		// Devuelve el iesimo elemento (modificable)
		T & operator[](Nat pos);

		// Devuelve el iesimo elemento (no modificable)
		const T& operator[](Nat pos) const;

		//asignacion
		ArregloDimensionable& operator=(const ArregloDimensionable& otro);

		// Muestra en pantalla los elementos del arreglo encerrados entre "()"
		void escribir(ostream & os) const;

	private:
		T* arreglo;
		Nat tamanio;
		void copiarDesde(const ArregloDimensionable& otro);
};


/* --Implementacion de los metodos de Arreglo Dimensionable --*/

template <typename T>
ArregloDimensionable<T>::ArregloDimensionable(){

	arreglo = NULL;
	tamanio = 0;
}

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

	copiarDesde(otro);
}

template <typename T>
void ArregloDimensionable<T>::copiarDesde(const ArregloDimensionable& otro){

	tamanio = otro.tam();
	arreglo = new T[tamanio];
	for(Nat i = 0; i < tamanio; i++)
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
ArregloDimensionable<T>& ArregloDimensionable<T>::operator=(const ArregloDimensionable& otro){

	delete []arreglo;
	tamanio = 0;
	copiarDesde(otro);
	return *this;

}



template <typename T>
void ArregloDimensionable<T>::escribir(ostream & os) const{

	os << "(";
	for(Nat i=0;i<tamanio-1;i++)
		os << arreglo[i] << ",";
	os << arreglo[tamanio-1] << ")";

}


template <typename T>
ostream & operator<<(ostream &os, const ArregloDimensionable<T> & ad){
    ad.escribir(os);
    return os;
}

////////////////////////////////////// FIN ARREGLO DIMENSIONABLE /////////////////////////////////////

#endif
