#ifndef __TEST__ARREGLODIMENSIONABLE__
#define __TEST__ARREGLODIMENSIONABLE__


using namespace std;


void testArreglo();
void testLongitud();
void testCopia();
void sonIguales(ArregloDimensionable<Nat>& ar1, ArregloDimensionable<Nat>& ar2);



void testArreglo(){

	cout << "Realizando testLongitud..." << endl;
	testLongitud();
	cout << "Finalizando testLongitud..." << endl;

	cout << "Realizando testCopia..." << endl;
	testCopia();
	cout << "Finalizando testCopia..." << endl;

}


void testLongitud(){

	Nat tamanio = rand()%10000;
	ArregloDimensionable<Nat> arreglo(tamanio);
	assert(arreglo.tam() == tamanio);

	tamanio = rand()%10000;
	ArregloDimensionable<Nat> arreglo2(tamanio);
	assert(arreglo2.tam() == tamanio);

	tamanio = rand()%10000;
	ArregloDimensionable<Nat> arreglo3(tamanio);
	assert(arreglo3.tam() == tamanio);
	

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


#endif
