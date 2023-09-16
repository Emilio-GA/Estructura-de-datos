/**
 * @file   letters_set.cpp
 * @brief  Archivo de especificación del letters_set.cpp
 * @author EMILIO GUILLÉN, ALBERTO RODRÍGUEZ Y EMIL ZAINULLIN
 */

#include "letters_set.h"
#include <map>
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// Constructor por defecto de LetterInfo
LetterInfo::LetterInfo(){

    repetitions=0;
    score=0;
}

// Constructor por parametros de LetterInfo
LetterInfo::LetterInfo(int s, int r){

    repetitions=r;
    score=s;
}

// Constructor por defecto para LettersSet
LettersSet::LettersSet():letters(){}

// Constructor de copia para LettersSet
LettersSet::LettersSet(const LettersSet &other) {

    letters = other.letters;
}

// Método insert para LettersSet
bool LettersSet::insert(const pair <char,LetterInfo> & val){

    pair< map<char,LetterInfo>::iterator,bool > ret;
    ret = letters.insert( val );
    if (ret.second==false) {

        return false;

    } else {

        return true;
    }
}

// Método erase para LettersSet
bool LettersSet::erase(const char &key) {

    return letters.erase(key);
}

// Método clear para LettersSet
void LettersSet::clear() {

    letters.clear();
}

// Método empty para LettersSet
bool LettersSet::empty() {

    bool empty = false;

    if (letters.size() == 0) {

        empty = true;
    }

    return empty;
}

// Método size para LettersSet
unsigned int LettersSet::size() const {

    return letters.size();
}

// Método getScore para LettersSet
int LettersSet::getScore(string word){

    int puntos = 0;

    for(int i=0; i<word.size(); i++){

        letters[word[i]].repetitions--;

        if (letters[word[i]].repetitions < 0) {

            assert(letters[word[i]].repetitions < 0);
        }

        puntos += letters[word[i]].score;
    }

    return puntos;
}

// Método auxiliar getrep para LettersSet
int LettersSet::getrep(char clave)const{

    return letters.find(clave)->second.repetitions;
};

// Método auxiliar getclave para LettersSet
char LettersSet::getclave(map<char,LetterInfo>::const_iterator  est) const{

    return est->first;
};

// Operador = para LettersSet
LettersSet& LettersSet::operator=(const LettersSet& cl) {

    if (this != &cl) {

        letters = cl.letters;

    } else {

        cerr << "Error, son el mismo objeto." << endl;
    }

    return *this;
}

// Operador [] para LettersSet
LetterInfo& LettersSet::operator[](const char& val) {

    return letters[val];
}

// Operador << para LetterInfo
ostream& operator<<(ostream& os , const LetterInfo& cl){
    os << "Repeticiones posibles: "<< cl.repetitions << "  Puntos: "<< cl.score << endl;
    return os;
}

// Operador << para LettersSet
ostream& operator<<(ostream& os, const LettersSet& cl) {

    map <char, LetterInfo>::const_iterator it;

    os << "Letras" << " " << "Cantidad" << " " << "Puntos" << endl;

    for (it = cl.begin(); it != cl.end(); ++it) {

        os << it->first << " " << it->second.repetitions << " " << it->second.score << endl;
    }

    return os;
}

// Operador >> para LettersSet
istream& operator>>(istream& is, LettersSet& cl) {

    pair <char, LetterInfo> nuevo;
    string encabezado;

    getline(is, encabezado);

    while (is) {

        is >> nuevo.first;
        nuevo.first = tolower(nuevo.first);

        is >> nuevo.second.repetitions;
        is >> nuevo.second.score;
        cl.insert(nuevo);

    }

    return is;
}

// Iterador begin
map<char, LetterInfo>::const_iterator LettersSet::begin() const{

    map<char, LetterInfo>::const_iterator it;

    it= letters.begin();

    return it;
}

// Iterador find
map<char, LetterInfo>::const_iterator LettersSet::find(const key_t & clave) const {

    map<char, LetterInfo>::const_iterator it;

    it= letters.find(clave);

    return it;
}

// Iterador end
map<char, LetterInfo>::const_iterator LettersSet::end() const {

    map<char, LetterInfo>::const_iterator it;

    it= letters.end();

    return it;
}