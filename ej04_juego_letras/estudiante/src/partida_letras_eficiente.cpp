/**
 *  @file   palabras_validas_eficiente.cpp
 *  @brief  Archivo de especificación de la clase Dictionary
 *  @author EMILIO GUILLÉN, ALBERTO RODRÍGUEZ Y EMIL ZAINULLIN
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>


#include "solver.h"
#include "letters_bag.h"

using namespace std;

int main(int nargs, char *argv[]) {
    Dictionary d;
    LettersSet l;
    ifstream f1, f2;

    if (nargs != 5) {

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
    bool score_game;
    if (*argv[3] == 'P'){
        score_game = true;

    }else if (*argv[3] == 'L'){
        score_game = false;
    }else{
        cerr<< "No existe ese modo de juego";
        exit(-1);
    }
    LettersBag letras(l);
    const vector<char> available_letters(letras.extractLetters(atoi(argv[4])));

    cout << "LETRAS DISPONIBLES:" << endl;
    for(int i= 0 ; i<atoi(argv[4]); i++ ){
        cout<<available_letters[i]<<" ";
    }
    cout<< endl;



    Solver sol(d,l);
    pair<vector<string>, int> result;

    result = sol.getSolutionsEficiente(available_letters, score_game);

    cout<<"SOLUCIONES:"<<endl;
    for(int i= 0 ; i<result.first.size(); i++ ){
        cout<<result.first[i]<<endl;
    }
    cout<<"PUNTUACION:"<<endl;
    cout<<result.second<<endl;
    return 0;
}