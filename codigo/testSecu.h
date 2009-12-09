#ifndef __TEST__SECU__
#define __TEST__SECU__

void testSecu();
void testLongitudSecu();
void testEsta();
void testAgregar();
void testCopiaSecu();
void testIesimo();
void testEscribirSecu();
void randSecu(Secu<Nat> &s, Nat tam);
bool sonIguales(Secu<Nat>& s,Secu<Nat>& t);
bool estaOrdenada(Secu<Nat>& s);


void testSecu(){

	cout << "testEsta..."; testEsta(); cout << "OK" << endl;
	cout << "testAgregar..."; testAgregar(); cout << "OK" << endl;
	cout << "testLongitudSecu..."; testLongitudSecu(); cout << "OK" << endl;
	cout << "testCopiaSecu..."; testCopiaSecu(); cout << "OK" << endl;
	cout << "testIesimo..."; testIesimo(); cout << "OK" << endl;
	cout << "test EscribirSecu...  "; testEscribirSecu(); cout << endl;

	cout << "MODULO SECU FUNCIONA CORRECTAMENTE" << endl << endl;

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

	// Asignacion de secu vacia
	Secu<Nat> nueva;
	Secu<Nat> asignada = nueva;
	assert(sonIguales(nueva,asignada));
	
	// Copia de secu vacia
	Secu<Nat> copiada(nueva);
	assert(sonIguales(nueva,copiada));	

	// Creo una secu de longitud 300 con numeros aleatorios
	randSecu(nueva,300);
	
	// Copia de la lista no vacia
	Secu<Nat> copiada2(nueva);
	assert(sonIguales(nueva,copiada2));
	
	// Asignacion de lista no vacia
	asignada = nueva;
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
	assert(actualAdelante(it) == nueva.iesimo(1));

	avanzar(it);
	avanzar(it);
	avanzar(it);
	assert(actualAdelante(it)==nueva.iesimo(4));
	assert(actualAtras(it)==nueva.iesimo(100));

}


void testEscribirSecu() {
	Secu<Nat> s;
	cout << endl << '\t';
	cout << "vacia: " << s;
	randSecu(s,5);
	cout << endl << '\t';
	cout << "no vacia: " << s << endl;
}

#endif
