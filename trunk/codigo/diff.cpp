#include<iostream>
#include<fstream>

using namespace std;

int main(int argc, const char* argv[]) {

	ifstream original;
	ifstream resultado;
	ofstream diff;
	string linea_o;
	string linea_r;	

	bool hay_dif = false;

	original.open(argv[1]);
	resultado.open(argv[2]);
	diff.open(argv[3]);	

	int i = 1;

	while(!original.eof()) {
		getline(original, linea_o);
		getline(resultado, linea_r);
		
		if(linea_o != linea_r) {
			diff << i << endl;
			hay_dif = true;	
		}	
		i++;
	}

	if(!hay_dif)
		diff << "Los archivos son iguales" << endl;

	return 0;
}
