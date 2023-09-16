/**
 *  @file   cantidad_letras.cpp
 *  @brief  Archivo de especificación de las funciones de conteo de letras implementadas
 *  @author EMILIO GUILLÉN, ALBERTO RODRÍGUEZ Y EMIL ZAINULLIN
*/

#include <fstream>
#include <iostream>
#include <cstdlib>
#include "dictionary.h"
#include "letters_set.h"

using namespace std;

int main(int nargs, char** argv) {

     Dictionary d;
     LettersSet l;
     ifstream f1, f2;

    if (nargs != 3) {

        cerr << "El numero de parametros es incorrecto" << endl;
        return -1;
    }

    // El argumento 0 es el nombre del programa

    f1.open(argv[1]);
    if (f1.is_open()) {

        f1 >> d;

    } else {

        cerr << "El fichero de diccionario no se ha abierto correctamente" << endl;
        return -1;
    }
    f1.close();

    f2.open(argv[2]);
    if (f2.is_open()) {

        f2 >> l;

    } else {

        cerr << "El fichero de letras no se ha abierto correctamente" << endl;
        return -1;
    }
    f2.close();

    // Para cada letra del diccionario se calculará sus usos y ocurrencias
    cout << "Letra\tUsos\tOcurrencias" << endl;

    map<char, LetterInfo>::const_iterator it;
    for (it = l.begin(); it != l.end(); ++it) {

        char n = toupper(it->first);
        cout << n << '\t' << d.getTotalUsages(it->first) << '\t' << d.getOccurrences(it->first) << endl;

    }

    return 0;
}