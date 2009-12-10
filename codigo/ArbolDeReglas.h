#ifndef __ARBOLDEREGLAS__
#define __ARBOLDEREGLAS__

////////////////////////////////////// ARBOL DE REGLAS /////////////////////////////////////

typedef ArregloDimensionable<Nat> DirIp;
typedef Nat	Interfaz;

class ArbolDeReglas{

	public:

			//constructor de la clase
			ArbolDeReglas();

			//destructor de la clase
			~ArbolDeReglas();

			//dada una dirIp indica si existe alguna regla que la contemple
			bool tieneRegla(DirIp & d);

			//dada una dirIp indica por que interfaz debe salir
			Interfaz& interfazDeSalida(DirIp & d) const;			//PRECONDICION: tieneRegla(d)

	private:
		
			struct Nodo{
	
				Interfaz* inter;
				ArbolDeReglas* izq;	
				ArbolDeReglas* der;
				bool sucio;
			
			};

			Nodo* abr;
			void vaciar();


};

ArbolDeReglas::ArbolDeReglas(){

	abr = NULL;
}

ArbolDeReglas::~ArbolDeReglas(){

	vaciar();
}

void ArbolDeReglas::vaciar(){

	if(abr != NULL){
		Nodo* aux = abr;
		abr->izq->vaciar();
		abr->der->vaciar();
		delete aux;	
	}
}

bool ArbolDeReglas::tieneRegla(DirIp & d){


	




}




////////////////////////////////////// FIN ARBOL DE REGLAS /////////////////////////////////////

#endif
