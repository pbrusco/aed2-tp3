#ifndef __ARBOLDEREGLAS__
#define __ARBOLDEREGLAS__

////////////////////////////////////// ARBOL DE REGLAS /////////////////////////////////////

typedef ArregloDimensionable<Nat> DirIp;
typedef Nat	Interfaz;



// Regla de direccionamiento
struct ReglaDir
{
    DirIp dirIp;
    Nat cantBits;
    Interfaz interfazSalida;
    
    ReglaDir(DirIp d) : dirIp(d) {}
};


class ArbolDeReglas{

	public:

			//constructor de la clase
			ArbolDeReglas();

			//destructor de la clase
			~ArbolDeReglas();

			//agrega una regla al arbol
			void agRegla(const ReglaDir & r);

			//dada una dirIp indica si existe alguna regla que la contemple
			bool tieneRegla(const DirIp & d);

			//dada una dirIp indica por que interfaz debe salir
			Interfaz& interfazDeSalida(const DirIp & d) const;			//PRECONDICION: tieneRegla(d)

	private:
		
			struct Nodo{
	
				Interfaz* inter;
				Nodo* izq;	
				Nodo* der;
				bool sucio;
				Nodo(): inter(NULL), izq(NULL), der(NULL), sucio(false){}
			
			};

			Nodo* abr;
			void vaciar(Nodo*);
			ArregloDimensionable<bool>& pasarABits(const DirIp d);


};

ArbolDeReglas::ArbolDeReglas(){

	abr = NULL;
}

ArbolDeReglas::~ArbolDeReglas(){

	vaciar(abr);
}

void ArbolDeReglas::vaciar(Nodo* abr){

	if(abr != NULL){
		Nodo* aux = abr;
		vaciar(abr->izq);
		vaciar(abr->der);
		delete aux->inter;
		delete aux;
	}
}

void ArbolDeReglas::agRegla(const ReglaDir & r){

	Nodo* aux;
	ArregloDimensionable<bool> a(r.dirIp.tam()*8);
	bool estabaSucio = false;

	if(abr == NULL)
		abr = new Nodo;

	a = pasarABits(r.dirIp);
	aux = abr;

	for(Nat n = 0; n<r.cantBits;n++){

		if (a[n]){
		
			if(aux->der == NULL)
				aux->der = new Nodo;

			if(aux->sucio){
				estabaSucio = true;
				aux->sucio = false;
			}

			delete aux->inter;

			if(aux->izq != NULL)
				aux->izq->sucio = estabaSucio;

			aux = aux->der;
		}
		else{

			if(aux->izq == NULL)
				aux->izq = new Nodo;

			if(aux->sucio){
				estabaSucio = true;
				aux->sucio = false;
			}

			aux->inter = NULL;
			if(aux->der != NULL)
				aux->der->sucio = estabaSucio;

			aux = aux->izq;
		}
	}

	if(aux->inter == NULL){
		Interfaz* i = new Interfaz;
		*i = r.interfazSalida;
		aux->inter = i;
	}
	else
		*(aux->inter) = r.interfazSalida;


}

ArregloDimensionable<bool>& ArbolDeReglas::pasarABits(const DirIp d){

	ArregloDimensionable<bool> res(d.tam()*8);
	Nat i = 7;
	Nat j = 0;
	Nat aux;
	
	for(j;j<d.tam();j++){

		aux = d[j];
		for(i;i>=j*8;i--){



		}

	}





}

bool ArbolDeReglas::tieneRegla(const DirIp & d){


	




}


Interfaz& ArbolDeReglas::interfazDeSalida(const DirIp & d) const{



}



////////////////////////////////////// FIN ARBOL DE REGLAS /////////////////////////////////////

#endif
