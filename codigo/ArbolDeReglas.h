#ifndef __ARBOLDEREGLAS__
#define __ARBOLDEREGLAS__


// Renombres básicos
typedef Nat Interfaz;
typedef Nat Version;
typedef ArregloDimensionable<Nat> DirIp;

// Regla de direccionamiento
struct ReglaDir{
    
    DirIp dirIp;
    Nat cantBits;
    Interfaz interfazSalida;
    
    ReglaDir(DirIp d) : dirIp(d) {}
};


/////////////////////////////////////////// ARBOL DE REGLAS //////////////////////////////////////////

/* --Interfaz de ArbolDeReglas */

class ArbolDeReglas{

	public:
		
		// Constructor por defecto
		ArbolDeReglas();
		
		// Destructor
		~ArbolDeReglas();
		
		// Operador de asignacion
		//ArbolDeReglas& ArbolDeReglas::operator=(const ArbolDeReglas& a);
		
		// Constructor que agregra una regla al arbol de reglas
		void agRegla(const ReglaDir& regla);
		
		// Indica dada una DirIp si existe una regla que se corresponda
		bool tieneRegla(const DirIp& dir_ip) const;
		
		// Indica, dada una dirIp, la interfaz de salida
		Interfaz interfazDeSalida(const DirIp& d) const;
			
	
	private:
	
		struct Nodo {
		
			Interfaz* inter;
			Nodo* izq;
			Nodo* der;
			bool dirty;
			Nodo () : inter(NULL), izq(NULL), der(NULL), dirty(false) {}
			
		 };

		Nodo* raiz;
		
		void vaciar();
		void copiarArbol(const ArbolDeReglas& a);
		static ArregloDimensionable<bool>& pasarABits(const DirIp& dir_ip);	
};



/* Implementacion de los metodos publicos de ArbolDeReglas */

ArbolDeReglas::ArbolDeReglas(){
	
	raiz = NULL;	
}


ArbolDeReglas::~ArbolDeReglas(){

	vaciar();
}


/*ArbolDeReglas& ArbolDeReglas::operator=(const ArbolDeReglas& a){

	vaciar();
	copiarArbol(a);
	return *this;
}*/
		

void ArbolDeReglas::agRegla(const ReglaDir& r){

	bool camino_sucio = false;
	Nodo* aux = raiz;
	ArregloDimensionable<bool> d_ip(pasarABits(r.dirIp));
	
	if (raiz == NULL){
		raiz = new Nodo();
	}

 	for(Nat i = 0; i <= r.cantBits; i++){
		
		if(aux->dirty){
			camino_sucio = true;
			aux->dirty = false;
		}

		if (d_ip[i]){

			if(camino_sucio && aux->izq != NULL){
				(aux->izq)->dirty = true;
			}
			if (aux->der == NULL){
				aux->der = new Nodo();
			}
			aux = aux->der;
		}
			
		else{

			if(camino_sucio && aux->der != NULL){
				(aux->der)->dirty = true;
			}
			if (aux->izq == NULL){
				aux->izq = new Nodo();
			}
			aux = aux->izq;
		}	
		
		i++;
	}
	
	if(aux->inter == NULL){
		Interfaz x = r.interfazSalida;
		aux->inter = &x;
	}
	else{
		*(aux->inter) = r.interfazSalida;		
	}
	
	if(aux->der != NULL){
		(aux->der)->dirty = true;
	}
	if(aux->izq != NULL){
		(aux->izq)->dirty = true;
	}
}


Interfaz ArbolDeReglas::interfazDeSalida(const DirIp& dir_ip) const{
   
	Nat i = 0;
	Interfaz* pRes = NULL;
	Interfaz* pTemp = NULL;
 	ArregloDimensionable<bool> dirEnBits(pasarABits(dir_ip));
	
	Nodo* aux = raiz;
	
	while (pRes == NULL) {
	
		if (aux->inter != NULL){
			pTemp = aux->inter;
		}
		
		if (dirEnBits[i] == true){
			if (aux->der == NULL || (aux->der)->dirty){
				pRes = pTemp;
			}
			else{
				aux = aux->der;
			}
		}
       
       else{
			if (aux->izq == NULL || (aux->izq)->dirty){
				pRes = pTemp;
			}
           else{
			   aux = aux->izq;
			}
		}

       i++;
	}

	return *pRes;
}



/* Implementacion de metodos privados de ArbolDeReglas*/


void ArbolDeReglas::vaciar(){
	Nodo* aux;
	Cola<Nodo*> pendientes;
	
	pendientes.encolar(raiz);
	
	while (!pendientes.vacia()){
		aux = pendientes.observar();
	
		if((aux->izq) != NULL){
			pendientes.encolar(aux->izq);
		}
		
		if(aux->der != NULL){
			pendientes.encolar(aux->der);
		}
		pendientes.desencolar();
	}
}


void ArbolDeReglas::copiarArbol(const ArbolDeReglas& a) {
	
	
}


bool ArbolDeReglas::tieneRegla(const DirIp& dir_ip) const{ 

	Nat i = 0;
	bool res = false;
	bool continuar = true;
	ArregloDimensionable<bool> dirEnBits(pasarABits(dir_ip));
	
	if(raiz == NULL){
		return res;
	}
	
	else{
		Nodo* aux = raiz;
		
		while(!aux->dirty && continuar && !res){

			if(dirEnBits[i]){
				aux = aux->der;
			}
			else{
				aux = aux->der;
			}
			
			continuar = (!dirEnBits[i] && aux->izq != NULL) && (dirEnBits[i] && aux->der != NULL);
			res = (aux->inter != NULL);
			i++;
		}
	}
	
	return res;
}


ArregloDimensionable<bool>& ArbolDeReglas::pasarABits(const DirIp& dir_ip){

	ArregloDimensionable<bool>* res = new ArregloDimensionable<bool>(8);
	return *res;
}	

///////////////////////////////////////// FIN ARBOL DE REGLAS ////////////////////////////////////////

#endif
