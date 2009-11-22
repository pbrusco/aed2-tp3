#ifndef __TP3_PARSER__
#define __TP3_PARSER__

#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

string& trim(string& s){
    const string white = " \t\v";	// space, tab, vertical tab
    string::size_type
    ini = s.find_first_not_of(white),
          end = s.find_last_not_of(white) - ini + 1;
    return (s = (ini <= end)? string(s, ini, end): "");
}

string& tolowerstr(string& s){
    for (string::iterator si = s.begin(); si != s.end(); si++)
        *si = tolower(*si);
    return s;
}

string& toupperstr(string& s){
    for (string::iterator si = s.begin(); si != s.end(); si++)
        *si = toupper(*si);
    return s;
}

enum Type{ // TAD Enrutador
    nuevo,
    agVersion,
    agRegla,
    agEvento,
    versiones,
    interfaces,
    enrutar,
    eventos,
    estaCaida,
    tiempoCaida
};

class Decoder{
	private:
		std::map<string, Type> codes;
	public:
		Decoder();
		Type operator()(string cmdTypeStr){ // PRECONDICIÓN: operator[] == true !!
			return codes.find(cmdTypeStr)->second;
		}
		bool operator[](string cmdTypeStr){
			if (codes.find(tolowerstr(cmdTypeStr)) == codes.end()){
				cout << "ERROR -> Comando desconocido: " << cmdTypeStr << endl;
				return false;
			}
			return true;
		}
};

Decoder::Decoder(){ // TAD Enrutador
	codes["nuevo"] 			= nuevo;
	codes["agversion"] 		= agVersion;
	codes["agregla"] 		= agRegla;
	codes["agevento"] 		= agEvento;
	codes["versiones"] 		= versiones;
	codes["interfaces"] 	= interfaces;
	codes["enrutar"] 		= enrutar;
	codes["eventos"] 		= eventos;
	codes["estacaida"] 		= estaCaida;
	codes["tiempocaida"] 	= tiempoCaida;
}

bool check( string elem1, string elem2 ){
	if( elem1 != elem2 ){
		cout << "ERROR -> se esperaba un: " << elem2 << endl;
		return false;
	}
	return true;
}

#endif
