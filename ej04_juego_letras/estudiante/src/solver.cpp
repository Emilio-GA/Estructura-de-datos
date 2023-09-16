//
// Created by egalv on 02/01/2023.
//

#include "solver.h"

Solver::Solver(const Dictionary &dict, const LettersSet &letters_set) {
    this->dict = dict;
    this->letters_set = letters_set;
}

bool Solver::se_puede(string palabra, const vector<char> & available_letters ){
    vector<char> conjletr = available_letters;
    bool encont = true;
    vector <int> pos;
    char letra;
    for(int i = 0; i < palabra.size() && encont==true; i++){
        letra = palabra[i];
        encont = false;
        for(int j = 0; j < available_letters.size() && encont==false; j++){
            if(letra == conjletr[j]){
                encont = true;
                conjletr[j]=-1;
                //conjletr.erase(conjletr.begin()+j);
            }
        }
    }
   return encont;
}

pair<vector<string>, int> Solver::getSolutions(const vector<char> & available_letters, bool score_game) {
pair<vector<string>, int> result;
result.second = 0;
Dictionary::iterator it = dict.begin();

if (score_game){
    //A puntuación
    int punt;
    while(it != dict.end()){
        punt = letters_set.getScore(*it);

        if (punt >= result.second && se_puede(*it,available_letters) ){
            if (punt > result.second){
                result.first.clear();
                result.first.push_back(*it);
                result.second=punt;
            }else{
                result.first.push_back(*it);
            }
        }

        ++it;
    }

}else{
    //A longitud
    int tam;
    while(it != dict.end()){
        tam = (*it).size();

        if ((tam >= result.second) && (se_puede(*it,available_letters)) ){

            if (tam > result.second){

                result.first.clear();
                result.first.push_back(*it);
                result.second=tam;

            }else{

                result.first.push_back(*it);

            }
        }


        ++it;

    }


}
return result;
}

pair< vector<string>, int > Solver::getSolutionsEficiente(const vector<char> & available_letters, bool score_game){
    pair<vector<string>, int> result;
    result.second = 0;
   auto it = dict.possible_words_begin(available_letters);

    if (score_game){
        //A puntuación
        int punt;
        while(it != dict.possible_words_end()){
            punt = letters_set.getScore(*it);
            if (punt > result.second){
                result.first.clear();
                result.first.push_back(*it);
                result.second=punt;
            }else if (punt == result.second){
                result.first.push_back(*it);
            }

            ++it;
        }

    }else{
        //A longitud
        int tam;
        while(it != dict.possible_words_end()){
            tam = (*it).size();

            if (tam > result.second){

                result.first.clear();
                result.first.push_back(*it);
                result.second=tam;

            }else if (tam == result.second){

                result.first.push_back(*it);

            }

            ++it;

        }

    }
    return result;


}