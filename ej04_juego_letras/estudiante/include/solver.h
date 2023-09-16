//
// Created by egalv on 02/01/2023.
//

#ifndef P04_JUEGO_LETRAS_SOLVER_H
#define P04_JUEGO_LETRAS_SOLVER_H

#include "dictionary.h"
#include "letters_set.h"
#include <vector>
#include <string>
using namespace std;

class Solver {
private:
    Dictionary dict;
    LettersSet letters_set;
public:
    Solver(const Dictionary & dict, const LettersSet & letters_set);
    pair< vector<string>, int > getSolutions(const vector<char> & available_letters, bool score_game);
    pair< vector<string>, int > getSolutionsEficiente(const vector<char> & available_letters, bool score_game);
    bool se_puede(string palabra, const vector<char> & available_letters);
};


#endif //P04_JUEGO_LETRAS_SOLVER_H
