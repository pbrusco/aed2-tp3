#ifndef __TEST__ARREGLODIMENSIONABLE__
#define __TEST__ARREGLODIMENSIONABLE__


using namespace std;


void testArreglo();
void testLongitud();
void testCopia();
void sonIguales(ArregloDimensionable<Nat>& ar1, ArregloDimensionable<Nat>& ar2);
void randArreglo(ArregloDimensionable<Nat> & a);
void testOperador();

void testArreglo(){

	cout << "Realizando testLongitud...";
	testLongitud();
	cout << "OK" << endl;

	cout << "Realizando testCopia...";
	testCopia();
	cout << "OK" << endl;

	cout << "Realizando testOperador...";
	testOperador();
	cout << "OK" << endl;

	cout << "MODULO ARREGLO DIMENSIONABLE FUNCIONA CORRECTAMENTE" << endl << endl;
}


void testLongitud(){

	Nat tamanio = rand()%10000;
	ArregloDimensionable<Nat> arreglo(tamanio);
	assert(arreglo.tam() == tamanio);

	tamanio = rand()%10000;
	ArregloDimensionable<Nat> arreglo2(tamanio);
	assert(arreglo2.tam() == tamanio);

	ArregloDimensionable<Nat> arreglo3(arreglo2);
	assert(arreglo3.tam() == arreglo2.tam());

	arreglo = arreglo3;
	assert(arreglo.tam() == arreglo3.tam());
	

}


void testCopia(){

	Nat tamanio = rand()%1000;
	ArregloDimensionable<Nat> arreglo(tamanio);
	assert(arreglo.tam() == tamanio);

	for(int i=0;i<tamanio;i++)
		arreglo[i] = rand()%10000;

	ArregloDimensionable<Nat> arr(arreglo);
	assert(arr.tam() == arreglo.tam());

	sonIguales(arreglo,arr);

}

void sonIguales(ArregloDimensionable<Nat>& ar1, ArregloDimensionable<Nat>& ar2){

	ostringstream os1,os2;
	ar1.escribir(os1);
	ar2.escribir(os2);
	string s,t;
	s = os1.str();
	t = os2.str();
	assert(s == t);
}


void testOperador(){

	Nat tamanio = 20;
	ArregloDimensionable<Nat> arreglo(tamanio);
	for(int i=0;i<arreglo.tam();i++)
		arreglo[i] = i;

	for(int i=0;i<arreglo.tam();i++)
		assert(arreglo[i] == i);

	ArregloDimensionable<Nat> primero(4);
	for(int i=0;i<primero.tam();i++)
		primero[i] = i + 1;

	ArregloDimensionable<Nat> segundo(4);
	for(int i=0;i<segundo.tam();i++)
		segundo[i] = i*i;

	ArregloDimensionable< ArregloDimensionable<Nat> > matriz(2);
	matriz[0] = primero;
	matriz[1] = segundo;

	assert(matriz[0][0] == primero[0]);
	assert(matriz[1][0] == segundo[0]);	

	sonIguales(primero, matriz[0]);
	sonIguales(segundo, matriz[1]);

}

void randArreglo(ArregloDimensionable<Nat> & a){

	for(int i=0;i<a.tam();i++)
		a[i] = rand()%100 * i;
}


#endif
