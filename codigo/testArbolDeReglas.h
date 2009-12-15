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
	regla1.interfazSalida = 1;

	DirIp d2(2);
	d2[0] = 208;
	d2[1] = 0;
	ReglaDir regla2(d2);
	regla2.cantBits = 4;
	regla2.interfazSalida = 2;

	DirIp d3(2);
	d3[0] = 192;
	d3[1] = 140;
	ReglaDir regla3(d3);
	regla3.cantBits = 8;
	regla3.interfazSalida = 3;

	DirIp d4(2);
	d4[0] = 254;
	d4[1] = 0;
	ReglaDir regla4(d4);
	regla4.cantBits = 7;
	regla4.interfazSalida = 4;

	DirIp d5(2);
	d5[0] = 197;
	d5[1] = 0;
	ReglaDir regla5(d5);
	regla5.cantBits = 2;
	regla5.interfazSalida = 5;

	ReglaDir regla6(d1);
	regla6.cantBits = 0;
	regla6.interfazSalida = 6;

	DirIp d7(2);
	d7[0] = 1;
	d7[1] = 0;
	ReglaDir regla7(d7);
	regla7.cantBits = 8;
	regla7.interfazSalida = 7;

	ArbolDeReglas abr;
	abr.agRegla(regla3);
	assert(abr.tieneRegla(d1) == false);	
	assert(abr.tieneRegla(d2) == false);
	assert(abr.tieneRegla(d3) == true);
	assert(abr.tieneRegla(d4) == false);
	assert(abr.tieneRegla(d5) == false);
	assert(abr.tieneRegla(d7) == false);


	abr.agRegla(regla1);
	assert(abr.tieneRegla(d1) == true);	
	assert(abr.tieneRegla(d2) == false);
	assert(abr.tieneRegla(d3) == true);
	assert(abr.tieneRegla(d4) == false);
	assert(abr.tieneRegla(d5) == false);
	assert(abr.tieneRegla(d7) == false);

	abr.agRegla(regla4);
	assert(abr.tieneRegla(d1) == true);	
	assert(abr.tieneRegla(d2) == false);
	assert(abr.tieneRegla(d3) == true);
	assert(abr.tieneRegla(d4) == true);
	assert(abr.tieneRegla(d5) == false);
	assert(abr.tieneRegla(d7) == false);

	abr.agRegla(regla2);
	assert(abr.tieneRegla(d1) == true);	
	assert(abr.tieneRegla(d2) == true);
	assert(abr.tieneRegla(d3) == true);
	assert(abr.tieneRegla(d4) == true);
	assert(abr.tieneRegla(d5) == false);
	assert(abr.tieneRegla(d7) == false);

	abr.agRegla(regla5);
	assert(abr.tieneRegla(d1) == true);	
	assert(abr.tieneRegla(d2) == true);
	assert(abr.tieneRegla(d3) == true);
	assert(abr.tieneRegla(d4) == true);
	assert(abr.tieneRegla(d5) == true);
	assert(abr.tieneRegla(d7) == false);

	abr.agRegla(regla6);
	assert(abr.tieneRegla(d1) == true);	
	assert(abr.tieneRegla(d2) == true);
	assert(abr.tieneRegla(d3) == true);
	assert(abr.tieneRegla(d4) == true);
	assert(abr.tieneRegla(d5) == true);
	assert(abr.tieneRegla(d7) == true);


	abr.agRegla(regla7);
	assert(abr.tieneRegla(d1) == false);	
	assert(abr.tieneRegla(d2) == false);
	assert(abr.tieneRegla(d3) == false);
	assert(abr.tieneRegla(d4) == false);
	assert(abr.tieneRegla(d5) == false);
	assert(abr.tieneRegla(d7) == true);

	abr.agRegla(regla2);
	assert(abr.tieneRegla(d1) == false);	
	assert(abr.tieneRegla(d2) == true);
	assert(abr.tieneRegla(d3) == false);
	assert(abr.tieneRegla(d4) == false);
	assert(abr.tieneRegla(d5) == false);
	assert(abr.tieneRegla(d7) == true);

}

void testInterfazDeSalida(){

	DirIp d1(2);
	d1[0] = 255;
	d1[1] = 0;
	ReglaDir regla1(d1);
	regla1.cantBits = 8;
	regla1.interfazSalida = 1;

	DirIp d2(2);
	d2[0] = 208;
	d2[1] = 0;
	ReglaDir regla2(d2);
	regla2.cantBits = 4;
	regla2.interfazSalida = 2;

	DirIp d3(2);
	d3[0] = 192;
	d3[1] = 140;
	ReglaDir regla3(d3);
	regla3.cantBits = 8;
	regla3.interfazSalida = 3;

	DirIp d4(2);
	d4[0] = 254;
	d4[1] = 0;
	ReglaDir regla4(d4);
	regla4.cantBits = 7;
	regla4.interfazSalida = 4;

	DirIp d5(2);
	d5[0] = 197;
	d5[1] = 0;
	ReglaDir regla5(d5);
	regla5.cantBits = 2;
	regla5.interfazSalida = 5;

	ReglaDir regla6(d1);
	regla6.cantBits = 0;
	regla6.interfazSalida = 6;

	DirIp d7(2);
	d7[0] = 1;
	d7[1] = 0;
	ReglaDir regla7(d7);
	regla7.cantBits = 8;
	regla7.interfazSalida = 7;


	ArbolDeReglas abr;

	abr.agRegla(regla3);
	assert(abr.interfazDeSalida(d3) == 3);


	abr.agRegla(regla1);
	assert(abr.interfazDeSalida(d1) == 1);
	assert(abr.interfazDeSalida(d3) == 3);

	abr.agRegla(regla4);
	assert(abr.interfazDeSalida(d1) == 4);
	assert(abr.interfazDeSalida(d3) == 3);
	assert(abr.interfazDeSalida(d4) == 4);

	abr.agRegla(regla2);
	assert(abr.interfazDeSalida(d1) == 4);	
	assert(abr.interfazDeSalida(d2) == 2);
	assert(abr.interfazDeSalida(d3) == 3);
	assert(abr.interfazDeSalida(d4) == 4);

	abr.agRegla(regla5);
	assert(abr.interfazDeSalida(d1) == 5);	
	assert(abr.interfazDeSalida(d2) == 5);
	assert(abr.interfazDeSalida(d3) == 5);
	assert(abr.interfazDeSalida(d4) == 5);
	assert(abr.interfazDeSalida(d5) == 5);

	abr.agRegla(regla6);
	assert(abr.interfazDeSalida(d1) == 6);	
	assert(abr.interfazDeSalida(d2) == 6);
	assert(abr.interfazDeSalida(d3) == 6);
	assert(abr.interfazDeSalida(d4) == 6);
	assert(abr.interfazDeSalida(d5) == 6);
	assert(abr.interfazDeSalida(d7) == 6);


	abr.agRegla(regla7);
	assert(abr.interfazDeSalida(d7) == 7);

	abr.agRegla(regla2);
	assert(abr.interfazDeSalida(d2) == 2);
	assert(abr.interfazDeSalida(d7) == 7);

}





void testCopiaArbol(){

	DirIp d1(2);
	d1[0] = 255;
	d1[1] = 0;
	ReglaDir regla1(d1);
	regla1.cantBits = 8;
	regla1.interfazSalida = 1;

	DirIp d2(2);
	d2[0] = 208;
	d2[1] = 0;
	ReglaDir regla2(d2);
	regla2.cantBits = 4;
	regla2.interfazSalida = 2;

	DirIp d3(2);
	d3[0] = 192;
	d3[1] = 140;
	ReglaDir regla3(d3);
	regla3.cantBits = 8;
	regla3.interfazSalida = 3;

	DirIp d4(2);
	d4[0] = 254;
	d4[1] = 0;
	ReglaDir regla4(d4);
	regla4.cantBits = 7;
	regla4.interfazSalida = 4;

	DirIp d5(2);
	d5[0] = 197;
	d5[1] = 0;
	ReglaDir regla5(d5);
	regla5.cantBits = 2;
	regla5.interfazSalida = 5;

	ReglaDir regla6(d1);
	regla6.cantBits = 0;
	regla6.interfazSalida = 6;

	DirIp d7(2);
	d7[0] = 1;
	d7[1] = 0;
	ReglaDir regla7(d7);
	regla7.cantBits = 8;
	regla7.interfazSalida = 7;


	ArbolDeReglas abr;

	abr.agRegla(regla3);
	abr.agRegla(regla1);
	abr.agRegla(regla4);
	abr.agRegla(regla2);
	abr.agRegla(regla5);
	abr.agRegla(regla6);
	abr.agRegla(regla7);
	abr.agRegla(regla2);

	ArbolDeReglas abr2(abr);

	assert(abr.tieneRegla(d1) == abr2.tieneRegla(d1));	
	assert(abr.tieneRegla(d2) == abr2.tieneRegla(d2));
	assert(abr.tieneRegla(d3) == abr2.tieneRegla(d3));
	assert(abr.tieneRegla(d4) == abr2.tieneRegla(d4));
	assert(abr.tieneRegla(d5) == abr2.tieneRegla(d5));
	assert(abr.tieneRegla(d7) == abr2.tieneRegla(d7));


	assert(abr.interfazDeSalida(d2) == abr2.interfazDeSalida(d2));
	assert(abr.interfazDeSalida(d7) == abr2.interfazDeSalida(d7));

	ArbolDeReglas abr3 = abr2;

	assert(abr.tieneRegla(d1) == abr3.tieneRegla(d1));	
	assert(abr.tieneRegla(d2) == abr3.tieneRegla(d2));
	assert(abr.tieneRegla(d3) == abr3.tieneRegla(d3));
	assert(abr.tieneRegla(d4) == abr3.tieneRegla(d4));
	assert(abr.tieneRegla(d5) == abr3.tieneRegla(d5));
	assert(abr.tieneRegla(d7) == abr3.tieneRegla(d7));


	assert(abr.interfazDeSalida(d2) == abr3.interfazDeSalida(d2));
	assert(abr.interfazDeSalida(d7) == abr3.interfazDeSalida(d7));
	
}



#endif