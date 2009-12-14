#ifndef __COLA__
#define __COLA__

/* Interfaz de Cola*/

template <class T>
class Cola {
	public:
		
		// Constructor por defecto
		Cola();
		
		// Destructor
		~Cola();
		
		// Agrega un elemento al final de la cola
		void encolar(const T& elem);
		
		// Elimina el primer elemento de la cola
		void desencolar();
		
		// Devuelve el primer elemento de la cola
		T observar() const;
		
		// Indica si la cola es vacia
		bool vacia() const;
	
		// Indica la longitud de la cola
		Nat tam() const;
	
	
	private:

		template <typename T2> 
		struct Nodo{
			T2 elem;
			Nodo<T2>* siguiente;
			Nodo<T2>(T2 e) : elem(e), siguiente(NULL) {}
		};

		Nodo<T>* prim;
		Nodo<T>* ult;
		Nat cant;
};



/* Implementacion de los metodos de Cola*/

template <class T>
Cola<T>::Cola(){
	prim = NULL;
	ult = NULL;
	cant = 0;
}


template <class T>
Cola<T>::~Cola(){

	while(cant != 0){
		desencolar();
	}
}


template <class T>
void Cola<T>::encolar(const T& elem){
	
	Nodo<T>* e = new Nodo<T>(elem);
	
	if (cant == 0){
		prim = e;
		ult = e;
	}
	else{
		ult->siguiente = e;
		ult = e;
	}
	cant++;
}
	

template <class T>
void Cola<T>::desencolar(){
	
	if(cant!= 0){
		Nodo<T>* aux = prim;
		prim = prim->siguiente;
		delete aux; 
		cant--;
	}
}


template <class T>
T Cola<T>::observar() const{
	return (prim->elem);
}


template <class T>
bool Cola<T>::vacia() const{
	return (cant == 0);
}


template <class T>
Nat Cola<T>::tam() const{
	return cant;
}
#endif
