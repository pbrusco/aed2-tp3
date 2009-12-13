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

		//constructor por copia
		ArbolDeReglas(const ArbolDeReglas & otro);
		
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

ArbolDeReglas::ArbolDeReglas(const ArbolDeReglas & otro){

	raiz = NULL;
	copiarArbol(otro);
}

/*ArbolDeReglas& ArbolDeReglas::operator=(const ArbolDeReglas& a){

	vaciar();
	copiarArbol(a);
	return *this;
}*/
		

void ArbolDeReglas::agRegla(const ReglaDir& r){

	bool camino_sucio = false;
	ArregloDimensionable<bool> d_ip(pasarABits(r.dirIp));
	
	if (raiz == NULL)
		raiz = new Nodo();

	Nodo* aux = raiz;

 	for(Nat i = 0; i < r.cantBits; i++){
		
		if(aux->dirty){
			camino_sucio = true;
			aux->dirty = false;
		}

		if(camino_sucio)
			delete aux->inter;

		if (d_ip[i]){

			if(aux->izq != NULL)
				(aux->izq)->dirty = camino_sucio;
				
			if (aux->der == NULL)
				aux->der = new Nodo();
			
			aux = aux->der;
		}
			
		else{

			if(aux->der != NULL)
				(aux->der)->dirty = camino_sucio;

			if (aux->izq == NULL){
				aux->izq = new Nodo();
			}
			aux = aux->izq;
		}	
		
		i++;
	}
	
	if(aux->inter == NULL){
		Interfaz* x = new Interfaz;
		*x = r.interfazSalida;
		aux->inter = x;
	}
	else
		*(aux->inter) = r.interfazSalida;		
	
	
	if(aux->der != NULL)
		(aux->der)->dirty = true;
	
	if(aux->izq != NULL)
		(aux->izq)->dirty = true;
	
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

			res = (aux->inter != NULL);

			if(dirEnBits[i]){
				if(aux->der == NULL){
					continuar = false;
				}
				else {
					aux = aux->der;
				}
			}
			else{
				if(aux->izq == NULL){
					continuar = false;
				}
				else {
					aux = aux->izq;
				}
			}

			i++;
		}
	}
	
	return res;
}



/* Implementacion de metodos privados de ArbolDeReglas*/


void ArbolDeReglas::vaciar(){
	Nodo* aux;
	Cola<Nodo*> pendientes;
	
	if(raiz != NULL)
		pendientes.encolar(raiz);
	
	while (!pendientes.vacia()){
		aux = pendientes.observar();
		pendientes.desencolar();

		if((aux->izq) != NULL)
			pendientes.encolar(aux->izq);
		
		if(aux->der != NULL)
			pendientes.encolar(aux->der);
		
		delete aux->inter;
		delete aux;
	}
}


void ArbolDeReglas::copiarArbol(const ArbolDeReglas& a) {
	
		
	
}


ArregloDimensionable<bool>& ArbolDeReglas::pasarABits(const DirIp& dir_ip){

	ArregloDimensionable<bool> *res = new ArregloDimensionable<bool>(dir_ip.tam()*8);
	Nat i = 7;
	Nat j = 0;
	Nat aux;
	
	for(j;j<dir_ip.tam();j++){

		aux = dir_ip[j];
		for(i;i>=j*8;i--){

			if(aux % 2 == 1)
				res[i] = true;
			else
				res[i] = false;
			aux = aux / 2;
		}

		i = i + 15;
	}

	return *res;
}	

///////////////////////////////////////// FIN ARBOL DE REGLAS ////////////////////////////////////////

#endif