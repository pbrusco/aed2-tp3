#ifndef __TESTCOLA__
#define __TESTCOLA__

void testCola();
void testEncolar();
void testDesencolar();
void testLongitudCola();
void testObservar();
void randCola(Cola<Nat>& c, Nat tam);


void testCola(){

	cout << "testEncolar..."; testEncolar(); cout << "OK" << endl;
	cout << "testDesencolar..."; testDesencolar(); cout << "OK" << endl;
	cout << "testLongitudCola..."; testLongitudCola(); cout << "OK" << endl;
	cout << "testObservar..."; testObservar(); cout << "OK" << endl << endl;
	
	cout << "MODULO COLA FUNCIONA CORRECTAMENTE" << endl << endl;
}


void testEncolar(){
	
	Cola<Nat> c;
	Nat n = 0;
	Nat tam = rand()%100;
		
	for(Nat i = 0; i < tam; ++i){
		n = rand()%100000;
		assert(c.tam() == i);
		c.encolar(n);
	}
	
	assert(c.tam() == tam);
}


void testDesencolar(){
	
	Cola<Nat> c;
	
	randCola(c, 20);
	
	for(Nat i = 0; i < 20; i++){
		c.desencolar();
		assert(c.tam() == 19-i);
	}
	
}


void testLongitudCola(){
	
	Cola<Nat> c;
	assert(c.tam() == 0);
		
	Nat n = rand()%100;
	
	randCola(c,n);
	assert(c.tam() == n);
}


void testObservar(){
	
	Cola<Nat> c;
	Nat n = rand()%100;
	
	for(Nat i = 0; i < n ; i++){
		c.encolar(i);
		assert(c.observar() == i);
		c.desencolar();
	}
	
}

void randCola(Cola<Nat>& c, Nat tam){
	
	Nat n = 0;
	
	for(Nat i = 0; i < tam; i++){
		n = rand()%100000;
		c.encolar(n);
	}
}


#endif
