#ifndef __SECUENCIA__
#define __SECUENCIA__

//////////////////////////////////////////////// SECU ////////////////////////////////////////////////

/* --Interfaz de Nodo-- */ 

template <typename T2> 
struct Nodo{
	T2 dato;
	Nodo<T2>* siguiente;
	Nodo<T2>* anterior;
	Nodo(T2 e) : dato(e) {}
};


/* --Interfaz de ItOrd-- */

template <typename T3>
struct IterSecu{
	Nodo<T3>* primero;
	Nodo<T3>* ultimo;
	IterSecu() : primero(NULL), ultimo(NULL) {};
};


/* --Interfaz de Secu-- */

template <typename T>
class Secu{
	public:

		// Constructor por defecto
		Secu();
		
		// Destructor
		~Secu();
		
		// Constructor por copia
		Secu(const Secu<T>& s);
		
		// Operador de asignacion
		Secu& operator=(const Secu<T>& s);
		
		// Indica la longitud de la secuencia
		Nat longitud() const;

		// Indica si el elemento esta dentro de la secuencia
		bool esta(const T& elem) const;

		// Constructor que agrega atras un elemento a la secuencia de manera ordenada 
		void agAtras(const T& elem);

		// Constructor que agrega adelante un elemento a la secuencia de manera ordenada 
		void agAdelante(const T& elem);

		// Indica si la secuencia es vacia
		bool vacia() const;
		
		// Devuelve el iesimo elemento de la secuencia
		const T & iesimo(Nat i) const;

		//Escribe en un ostream una secuencia de caracteres que describen al objeto
		void escribir(ostream& os) const;
	
		// Crea un iterdador de la secuencia
		IterSecu<T> crearIt() const;

		// Avanza el iterador delantero
		void avanzar(IterSecu<T>& it);

		// Retrocede el iterdor trasero
		void retroceder(IterSecu<T>& it);
		
		// Devuelve el valor del iterador delantero
		T& actualAdelante(const IterSecu<T> it);

		// Devuelve el valor del iterador trasero
		T& actualAtras(const IterSecu<T> it);

		// Indica si la secuencia tiene un elemento siguiente desde la posicion iterada delantero
		bool tieneAnterior(const IterSecu<T>& it);

		// Indica si la secuencia tiene un elemento anterior desde la posicion iterada trasero
		bool tieneProximo(const IterSecu<T>& it);

	private:

		Nodo<T> *prim;
		Nodo<T> *ult;
		Nat tamanio;
	
		void vaciar(){

			Nodo<T>* aux;
		
			while (!(vacia())){
				aux = prim;
				prim = prim->siguiente;
				delete aux;
			}
		
			prim = NULL;
			ult = NULL;
			tamanio = 0;	
		};

	
		void copiarDesde(const Secu<T>& s) {

			Nodo<T>* aux = s.prim;
		
			while(aux != NULL){
				agAtras(aux->dato);
				aux = aux->siguiente;
			}
		};

};


/* --Implementacion de los metodos de Secu-- */

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
	tamanio = 0;
	copiarDesde(s);
}


template <typename T>
Secu<T>& Secu<T>::operator=(const Secu<T>& s){
	
	vaciar();
	copiarDesde(s);
	return *this;
}


template <typename T> 
Nat Secu<T>::longitud() const{

	return tamanio;
}


template <typename T>
bool Secu<T>::esta(const T& elem) const{

	bool res = false;
	Nodo<T>* aux = prim;

	while(aux != NULL && aux->dato < elem){
		aux = aux->siguiente;
	}
	
	if(aux != NULL) {
		res = (aux->dato == elem);
	}
	
	return res;
}


template <typename T>
void Secu<T>::agAtras(const T& elem){

	Nodo<T>* nuevo = new Nodo<T>(elem);
	nuevo->anterior = NULL;
	nuevo->siguiente = NULL;

	if (!vacia()){
		if(elem < prim->dato){
			prim->anterior = nuevo;
			nuevo->siguiente = prim;
			prim = nuevo;
		}
		else if(ult->dato < elem){
			ult->siguiente = nuevo;
			nuevo->anterior = ult;
			ult = nuevo;
		}
		else{
			Nodo<T>* aux = ult;

			while(elem < (aux->anterior)->dato) {
				aux = aux->anterior;
			}
			
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
void Secu<T>::agAdelante(const T& elem){

	Nodo<T>* nuevo = new Nodo<T>(elem);
	nuevo->anterior = NULL;
	nuevo->siguiente = NULL;
	
	if (!vacia()){
		if(elem < prim->dato){
			prim->anterior = nuevo;
			nuevo->siguiente = prim;
			prim = nuevo;
		}
		else if(ult->dato < elem){
			ult->siguiente = nuevo;
			nuevo->anterior = ult;
			ult = nuevo;
		}
		else{
			Nodo<T>* aux = prim;

			while((aux->siguiente)->dato < elem){
				aux = aux->siguiente;
			}
			
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
const T& Secu<T>::iesimo(Nat i) const{

	Nodo<T>* aux = prim;	

	for(Nat j = 1; j<i; j++){
		aux = aux->siguiente;
	}

	return aux->dato;
}


template <typename T>
void Secu<T>::escribir(ostream& os) const{

	Nodo<T>* aux = prim;
	os << '[';
		
	if (!vacia()){
		while(aux != ult){
			os << (aux->dato) << ',';
			aux = aux->siguiente;
		}
		os << (ult->dato);
	}

	os << ']';
}


template <typename T> 
ostream& operator<<(ostream& os, const Secu<T>& s) {
    
    s.escribir(os);
    return os;
}



/* --Implementacion de los metodos de ItOrd-- */

template <class T>
IterSecu<T> Secu<T>::crearIt() const {

	IterSecu<T> res;
	res.primero = prim;
	res.ultimo = ult;
	
	return res;
}


template <class T>
void avanzar(IterSecu<T>& it){
	it.primero = it.primero->siguiente;
}


template <class T>
void retroceder(IterSecu<T>& it){ 
	it.ultimo = it.ultimo->anterior;
}


template <class T>
T& actualAdelante(const IterSecu<T> it){
	return it.primero->dato;
}


template <class T>
T& actualAtras(const IterSecu<T> it){
	return it.ultimo->dato;
}


template <class T>
bool tieneAnterior(const IterSecu<T>& it){
	return (it.ultimo->anterior != NULL);
}


template <class T> 
bool tieneProximo(const IterSecu<T>& it){
	return (it.primero->siguiente != NULL);
}

////////////////////////////////////////////// FIN SECU //////////////////////////////////////////////

#endif
