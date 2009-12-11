#ifndef __TEST__CONJ__
#define __TEST__CONJ__

void testConj();
void testPertenece();
void testEscribirConj();
void randConj(Conjunto<Nat> &c, Nat tam);

void testConj(){


	cout << "Realizando testPertenece..." << endl; testPertenece(); cout << "OK" << endl;
	cout << "Realizando testEscribir..." << endl; testEscribirConj(); cout << "OK" << endl;
	cout << "MODULO CONJUNTO FUNCIONA CORRECTAMENTE" << endl << endl;

}

void testPertenece(){
	
	Conjunto<Nat> c;
	for(Nat i=0;i<10;i++)
		assert(!c.pertenece(rand()%30));

	for(Nat i=0;i<300;i++){
		c.agregar(i);
		assert(c.pertenece(i));
	}

	for(Nat i=300;i<320;i++)
		assert(!c.pertenece(i));
	

}

void testEscribirConj(){

	Conjunto<Nat> c;
	ostringstream os1, os2;
	string sc;
	c.escribir(os1);
	sc = os1.str();
	assert("{}" == sc);
	
	for(Nat i = 0;i < 10;i++)
		c.agregar(i);

	c.escribir(os2);
	sc = os2.str();
	assert("{0,1,2,3,4,5,6,7,8,9}" == sc);
}


void randConj(Conjunto<Nat> &c, Nat tam){
	
	Nat n;
	
	
	for(Nat i = 0; i <= tam; i++){
		n = rand()%100000;
		c.agregar(n);
	}
}

#endif
