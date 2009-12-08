#ifndef __TEST__SECU__
#define __TEST__SECU__


/*
    Secu();
	~Secu();
    Secu(const Secu<T>& s);
    Secu& operator=(const Secu<T> &s);
    Nat longitud();
	bool esta(const T & elem) const;
    void agAtras(const T & elem);
    void agAdelante(const T & elem);
	bool vacia() const;
    const T & iesimo(Nat i) const;
    void escribir(ostream & os) const;
	

	IterSecu<T>& crearIt();
	void avanzar(IterSecu<T>& it);
	void retroceder(IterSecu<T>& it);
	T& actualAdelante(IterSecu<T>& it);
	T& actualAtras(IterSecu<T>& it);
	bool tieneAnterior(IterSecu<T> &it);
	bool tieneSiguiente(IterSecu<T> &it);
*/

void testSecu();
void testLongitudSecu();
void randSecu(Secu<Nat> &s, Nat tam);
void testEsta();
void testAgregar();
void testCopiaSecu();
bool sonIguales(Secu<Nat>& s,Secu<Nat>& t);
void testIesimo();
bool estaOrdenada(Secu<Nat>& s);


void testSecu(){

	cout << "Realizando testEsta..." << endl;
	testEsta();
	cout << "Finalizando testEsta..." << endl;

	cout << "Realizando testAgregar..." << endl;
	testAgregar();
	cout << "Finalizando testAgregar..." << endl;

	cout << "Realizando testLongitudSecu..." << endl;
	testLongitudSecu();
	cout << "Finalizando testLongitudSecu..." << endl;

	cout << "Realizando testCopiaSecu..." << endl;
	testCopiaSecu();
	cout << "Finalizando testCopiaSecu..." << endl;

	cout << "Realizando testIesimo..." << endl;
	testIesimo();
	cout << "Finalizando testIesimo..." << endl;

}





void testLongitudSecu(){

	Nat tam = rand()%1000;
	Secu<Nat> nueva;
	randSecu(nueva,tam);
	assert(nueva.longitud() == tam);

}

void randSecu(Secu<Nat> &s, Nat tam){
	Nat i = 0;
	Nat n;
	while(i < tam){
		n = rand()%100000;
		if(!s.esta(n)){
			s.agAdelante(n);
			i++;
		}
	}

}



void testEsta(){

	Nat n = 1;
	Secu<Nat> nueva;
	assert(nueva.esta(n) == false);

	nueva.agAdelante(n);
	assert(nueva.esta(n) == true);

	for(Nat i=2;i<1000;i++)
		nueva.agAtras(i);

	bool prueba = true;

	for(Nat i=2;i<1000;i++)
		prueba = prueba && nueva.esta(i);

	assert(prueba == true);
	
}



void testAgregar(){
	
	Secu<Nat> nueva;
	randSecu(nueva,200);
	for(Nat i=0;i<20;i++){
		if(!nueva.esta(i))
			nueva.agAtras(i);
	}
	
	assert(estaOrdenada(nueva));
}

bool estaOrdenada(Secu<Nat>& s){

	bool res = true;
	if(!s.vacia()){
		IterSecu<Nat> it = s.crearIt();
		Nat n;
		while(tieneProximo(it)){
			n = actualAdelante(it);
			avanzar(it);
			res = res && (n < actualAdelante(it));
		}
	}

	return res;
}

void testCopiaSecu(){

	Secu<Nat> nueva;
	randSecu(nueva,300);
	Secu<Nat> copiada(nueva);
	assert(sonIguales(nueva,copiada));
	Secu<Nat> asignada = nueva;
	assert(sonIguales(nueva,asignada));

}

bool sonIguales(Secu<Nat>& s,Secu<Nat>& t){

	ostringstream os1,os2;
	string ss,ts;	
	s.escribir(os1);
	t.escribir(os2);
	ss = os1.str();
	ts = os2.str();

	return (ss == ts);
}


void testIesimo(){

	Secu<Nat> nueva;
	randSecu(nueva,100);
	IterSecu<Nat> it = nueva.crearIt();
	assert(actualAdelante(it)==nueva.iesimo(1));

	avanzar(it);
	avanzar(it);
	avanzar(it);
	assert(actualAdelante(it)==nueva.iesimo(4));
	assert(actualAtras(it)==nueva.iesimo(100));

}

#endif
