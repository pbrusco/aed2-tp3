#ifndef __CONJUNTO__
#define __CONJUNTO__

////////////////////////////////////////////// CONJUNTO //////////////////////////////////////////////


/* --Interfaz de Conjunto-- */

template <typename T>
class Conjunto{
public:

	// Constructor por defecto
    Conjunto();

	// Agrega un elemento al conjunto siempre y cuando el elemento no este previamente
    void agregar(const T& elem);

	// Indica si el elemento esta en dentro del conjunto
    bool pertenece(const T& elem) const;

	// Muestra en pantalla los elementos del conjunto encerrados entre "{}"
    void escribir(ostream& os) const;

private:
    Secu<T> conj;
};



/* --Implementacion de los metodos de Conjunto-- */

template <typename T>
void Conjunto<T>::agregar(const T& elem){
	if(!conj.esta(elem)){
		conj.agAdelante(elem);
	}
}


template <typename T>
bool Conjunto<T>::pertenece(const T& elem) const{
	return conj.esta(elem);
}


template <typename T>
void Conjunto<T>::escribir(ostream& os) const{
	
	IterSecu<T> it = conj.crearIt();
	
	os << '{';
		
	if (!conj.vacia()){
				
		while(tieneProximo(it)){
			os << actualAdelante(it) << ',';
			avanzar(it);
		}
		os << (actualAdelante(it));
	}

	os << '}';
}
 

template <typename T>
ostream & operator<<(ostream &os, const Conjunto<T> & c){
	c.escribir(os);
	return os;
}

//////////////////////////////////////////// FIN CONJUNTO ////////////////////////////////////////////

#endif
