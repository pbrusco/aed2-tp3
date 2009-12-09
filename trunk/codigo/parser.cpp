#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>
#include "parser.h"
#include "enrutador.h"

#include <cassert>
#include <cstdlib>
//#include "testArregloDimensionable.h"
#include "testSecu.h"
#include "testConj.h"

using namespace std;

int main(int argc, const char* argv[]){

 	testSecu();
//	testConj();
//	testArreglo();

/*
	int i;
	string nombreArchivoEntrada, nombreArchivoSalida, textLine, cmd, elem_str;
	Nat elem_nat;
	bool esPrimerComando = true;
	Decoder decode;
    ifstream ifs;
    ofstream ofs;
	Enrutador* router;
 
	if( argc < 3 ){
		cout << "Modo de uso: " << argv[0] << " archivo.in archivo.out" << endl;
		return 1;
	}

    nombreArchivoEntrada = argv[1];
    nombreArchivoSalida = argv[2];

    ifs.open( nombreArchivoEntrada.c_str() );
    ofs.open( nombreArchivoSalida.c_str() );

    getline(ifs, textLine);
    tolowerstr(trim(textLine));

	while( !ifs.eof() ){

		if( !textLine.empty() and textLine[0] != '#' and textLine[0] != '/' ){

			istringstream ist(textLine);
			boolalpha(ist); // usar true y false en vez de 1 y 0

			ist >> cmd;

			if( !decode[cmd] ) // chequeo que el comando sea correcto, si no, termino con error
				return 1;

			if( (esPrimerComando) and (decode(cmd) != nuevo)  ){ // chequeo que el primer comando sea "NUEVO", si no, termino con error
				cout << "ERROR -> El archivo " << nombreArchivoEntrada << " no comienza con el comando: NUEVO" << endl;
				return 1;
			}

            switch( decode(cmd) ){

                // -------------- OBSERVADORES -------------- //

				case versiones: // router -> conj(nat)
					ofs << router->versiones() << endl;
					break;


				case interfaces: // router -> conj(interfaces)
					ofs << router->interfaces() << endl;
					break;

				case enrutar:{ // router x DirIp -> respuestaDir
					vector<Nat> ipAux;
					ist >> elem_str; // leo el (
					if( !check(elem_str, "(") )
						return 1;
					while ( ist >> elem_nat )
						ipAux.push_back(elem_nat); // leo los números
					ist.clear(); // Limpio el FAIL bit de leer el )
					ist >> elem_str; // leo el )
					if( !check(elem_str, ")") )
						return 1;
					DirIp ip(ipAux.size());
					for( i = 0; i < ipAux.size(); i++ ) // genero la DirIp
						ip[i] = ipAux[i];
					ofs << router->enrutar(ip) << endl;
					}
					break;

				case eventos: // router x interfaz -> secu(eventos)
					ist >> elem_nat; // leo la interfaz
					ofs << router->eventos(elem_nat) << endl;
					break;

                // -------------- GENERADORES -------------- //

				case nuevo: // conj(interfaz) -> router
					ist >> elem_nat; // leo las interfaces
					router = new Enrutador(elem_nat); // genero el enrutador
					break;

				case estaCaida: // conj(interfaz) -> router
					ist >> elem_nat; // leo la interfaz
					ofs << (router->estaCaida(elem_nat) ? "CAIDA" : "NOCAIDA") << endl;
					break;

				case tiempoCaida: // conj(interfaz) -> router
					ist >> elem_nat;
					ofs << router->tiempoCaida(elem_nat) << endl;
					break;

				case agVersion: // router x version -> router
					ist >> elem_nat; // leo la version
					router->agVersion(elem_nat);
					break;

				case agRegla:{ // router x reglaDir -> router
					ist >> elem_str; // leo el <
					if( !check(elem_str, "<") )
						return 1;
					// comienzo a leer la DirIp
					vector<Nat> ipAux;
					ist >> elem_str; // leo el (
					if( !check(elem_str, "(") )
						return 1;
					while (ist >> elem_nat)
						ipAux.push_back(elem_nat);
					ist.clear(); // Limpio el FAIL bit de leer el )
					ist >> elem_str; // leo el )
					if( !check(elem_str, ")") )
						return 1;
					DirIp ip(ipAux.size());
					for ( i = 0; i < ipAux.size(); i++ ){ // genero la DirIp
						ip[i] = ipAux[i];
					}
					ReglaDir regla(ip);
					// leo CantBits y Inter
					ist >> elem_nat;
					regla.cantBits = elem_nat;
					ist >> elem_nat;
					regla.interfazSalida = elem_nat;
					router->agRegla(regla);
					ist >> elem_str; // leo el >
					if( !check(elem_str, ">") )
						return 1;
					}
					break;

				case agEvento:{ // router x evento -> router
					Evento evento;
					ist >> elem_str; // leo el <
					if( !check(elem_str, "<") )
						return 1;
					// leo la Caida
					ist >> elem_str; // leo el CAIDA o NOCAIDA
					if( elem_str == "caida" )
						evento.esCaida = true;
					else if( elem_str == "nocaida" )
							evento.esCaida = false;
						 else if( !check(elem_str, "CAIDA o NOCAIDA") )
								return 1;
 					// leo TimeStamp e Inter
					ist >> elem_nat;
					evento.timestamp = elem_nat;
					ist >> elem_nat;
					evento.interfaz = elem_nat;
					ist >> elem_str; // leo el >
					if( !check(elem_str, ">") )
						return 1;
					router->agEvento(evento);
					}
					break;
			}

			if( esPrimerComando )
				esPrimerComando = false;
		}

		getline(ifs, textLine);
		tolowerstr(trim(textLine));
	}

	ifs.close();
	ofs.close();
*/
	return 0;
}
