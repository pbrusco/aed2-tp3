#ifndef __TEST_ARBOLDEREGLAS__
#define __TEST_ARBOLDEREGLAS__


void testArbol();
void testTieneRegla();
void testInterfazDeSalida();
void testCopiaArbol();


void testArbol(){

	cout << "testTieneRegla..."; testTieneRegla(); cout << "OK" << endl;
	cout << "testInterfazDeSalida..."; testInterfazDeSalida(); cout << "OK" << endl;
	cout << "testCopiaArbol..."; testCopiaArbol(); cout << "OK" << endl;

	cout << "MODULO ARBOL DE REGLAS FUNCIONA CORRECTAMENTE" << endl << endl;

}


void testTieneRegla(){

	DirIp d1(2);
	d1[0] = 255;
	d1[1] = 0;
	ReglaDir regla1(d1);
	regla1.cantBits = 8;
	regla1.interfazSalida = 5;

	DirIp d2(2);
	d2[0] = 192;
	d2[1] = 168;
	ReglaDir regla2(d2);
	regla1.cantBits = 16;
	regla1.interfazSalida = 7;

	DirIp d3(2);
	d3[0] = 192;
	d3[1] = 140;
	ReglaDir regla3(d3);
	regla1.cantBits = 8;
	regla1.interfazSalida = 3;

	DirIp d4(2);
	d4[0] = 254;
	d4[1] = 0;
	ReglaDir regla4(d4);
	regla1.cantBits = 7;
	regla1.interfazSalida = 10;

	DirIp d5(2);
	d5[0] = 123;
	d5[1] = 47;
	ReglaDir regla5(d5);
	regla5.cantBits = 0;
	regla5.interfazSalida = 8;

	ArbolDeReglas abr;
	abr.agRegla(regla3);
	assert(abr.tieneRegla(d3) == true);


}

void testInterfazDeSalida(){}
void testCopiaArbol(){}



#endif
