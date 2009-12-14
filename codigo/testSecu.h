#ifndef __TEST__SECU__
#define __TEST__SECU__

void testSecu();
void testLongitudSecu();
void testEsta();
void testAgregar();
void testCopiaSecu();
void testIesimo();
void testIterador();
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
	cout << "test EscribirSecu...  "; testEscribirSecu(); cout << "OK" << endl;
	cout << "test testIterador...  "; testIterador(); cout << "OK" << endl;

	cout << "MODULO SECU FUNCIONA CORRECTAMENTE" << endl << endl;

}
		
void testLongitudSecu(){

	Nat tam = rand()%1000;
	Secu<Nat> nueva;
	assert(nueva.longitud() == 0);
	randSecu(nueva,tam);
	assert(nueva.longitud() == tam);


	Nat n = rand()%100000;
	while(nueva.esta(n)){
		n = rand()%100000;
	}
	nueva.agAtras(n);
	assert(nueva.longitud() == tam+1);

	n = rand()%100000;
	while(nueva.esta(n)){
		n = rand()%100000;
	}
	nueva.agAtras(n);
	assert(nueva.longitud() == tam+2);
	

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
	for(Nat i=20;i<40;i++){
		if(!nueva.esta(i))
			nueva.agAdelante(i);
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
	for(Nat i = 0; i < nueva.longitud();i++){
		assert(nueva.iesimo(i+1) == actualAdelante(it));
		avanzar(it);
	}

}

void testIterador(){

	Secu<Nat> nueva;
	nueva.agAdelante(4);
	IterSecu<Nat> it = nueva.crearIt();
	assert(actualAdelante(it) == 4);
	assert(actualAdelante(it) == actualAtras(it));
	assert(!tieneAnterior(it) && !tieneProximo(it));

}


void testEscribirSecu() {
	Secu<Nat> s;
	ostringstream os1, os2;
	string ss;
	s.escribir(os1);
	ss = os1.str();
	assert("[]" == ss);
	
	for(Nat i = 0;i < 10;i++)
		s.agAtras(i);

	s.escribir(os2);
	ss = os2.str();
	assert("[0,1,2,3,4,5,6,7,8,9]" == ss);


}

#endif
