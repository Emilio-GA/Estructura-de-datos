/**
 * @file   letters_bag.cpp
 * @brief  Archivo de especificación del letters_bag.cpp
 * @author EMILIO GUILLÉN, ALBERTO RODRÍGUEZ Y EMIL ZAINULLIN
 */

#include "letters_bag.h"
#include "letters_set.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iterator>

using namespace std;

// Constructor por defecto
LettersBag::LettersBag():letters_bag(){}

// Constructor de copia
LettersBag::LettersBag(const LettersSet &ls) {

    map<char, LetterInfo>::const_iterator it;

    for (it = ls.begin(); it != ls.end(); it++){
        for(int i = 0; i < ls.getrep(ls.getclave(it)); i++){
            letters_bag.add(ls.getclave(it));
        }
    }
}

// Método insert para LettersBag
void LettersBag::insertLetter(const char & I){

    letters_bag.add(I);
}

// Método extractLetter para LettersBag
char LettersBag::extractLetter() {

    return letters_bag.get();
}

// Método extractLetters para LettersBag
vector<char>  LettersBag::extractLetters(int num){

    vector<char> conjunto;
    for(int i=0; i< num; i++){

        conjunto.push_back(letters_bag.get());
    }
    return conjunto;
}

// Método clear para LettersBag
void LettersBag::clear(){

    letters_bag.clear();
}

// Método size para LettersBag
unsigned int  LettersBag::size() const{

    return letters_bag.size();
}

// Operador = para LettersBag
LettersBag&  LettersBag::operator= (const LettersBag & other){

    if(this != &other) {

        letters_bag = other.letters_bag;
    }

    return *this;

}

// Operador << para LettersBag
ostream& operator<<(ostream& os , const LettersBag& cl){

    LettersBag copia=cl;
    for(int i=0;cl.size();i++) {

        os << copia.letters_bag.get() << std::endl;
    }
    return os;
}