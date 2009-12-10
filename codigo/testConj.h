#ifndef __TEST__CONJ__
#define __TEST__CONJ__

void testConj();
void testAg();
void testPertenece();
void testEscribirConj();
void randConj(Conjunto<Nat> &c, Nat tam);

void testConj(){

	cout << "Realizando testAg..." << endl; testAg(); cout << "OK" << endl;
	cout << "Realizando testPertenece..." << endl; testPertenece(); cout << "OK" << endl;
	cout << "Realizando testEscribir..." << endl; testEscribirConj(); cout << endl;
	cout << "MODULO CONJUNTO FUNCIONA CORRECTAMENTE" << endl << endl;

}

void testAg(){
		
}

void testPertenece(){
	
	Conjunto<Nat> c;

	c.agregar(5);
	c.agregar(2);
	assert(c.pertenece(4) == false);
	assert(c.pertenece(0) == false);
	
	c.agregar(4);
	c.agregar(0);
	assert(c.pertenece(4) == true);
	assert(c.pertenece(0) == true);
}

void testEscribirConj(){

	Conjunto<Nat> c;

	cout << endl << '\t';
	cout << "vacio: " << c;

	randConj(c,5);

	cout << endl << '\t';
	cout << "no vacio: " << c << endl;	
}


void randConj(Conjunto<Nat> &c, Nat tam){
	
	Nat n;
	
	
	for(Nat i = 0; i <= tam; i++){
		n = rand()%100000;
		c.agregar(n);
	}
}

#endif
