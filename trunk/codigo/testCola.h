#ifndef __TESTCOLA__
#define __TESTCOLA__

void testCola();
void testEncolar();
void testDesencolar();
void testLongitudCola();
void testObservar();
void randCola(Cola<Nat>& c, Nat tam);


void testCola(){

	cout << "testLongitudCola..."; testLongitudCola(); cout << "OK" << endl;
	cout << "testObservar..."; testObservar(); cout << "OK" << endl << endl;
	
	cout << "MODULO COLA FUNCIONA CORRECTAMENTE" << endl << endl;
}


void testLongitudCola(){
	
	Cola<Nat> c;
	assert(c.tam() == 0);
		
	Nat n = rand()%10000;
	
	randCola(c,n);
	assert(c.tam() == n);

	for(int i = 0;i<n/2;i++)
		c.desencolar();

	assert(c.tam() == n-n/2);

	while(!c.vacia())
		c.desencolar();

	assert(c.tam() == 0);
}


void testObservar(){
	
	Cola<Nat> c;
	Nat n = rand()%10000;
	
	for(Nat i = 0; i < n ; i++)
		c.encolar(i);

	for(Nat i = 0; i < n ; i++){
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
