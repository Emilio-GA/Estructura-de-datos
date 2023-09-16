/**
 *  @file   dictionary.cpp
 *  @brief  Archivo de especificación de la clase Dictionary
 *  @author EMILIO GUILLÉN, ALBERTO RODRÍGUEZ Y EMIL ZAINULLIN
*/

#include <string>
#include <vector>
#include <utility>
#include <set>
#include "dictionary.h"
#include <cmath>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
//                             Private functions                             //
///////////////////////////////////////////////////////////////////////////////

Dictionary::node Dictionary::findLowerBoundChildNode(char character, Dictionary::node current) {

  node prev_child, curr_child = current.left_child();

  for (; !curr_child.is_null() && (*curr_child).character <= character; curr_child = curr_child.right_sibling()){
    prev_child = curr_child;
    if ((*curr_child).character == character) {
      return curr_child;
    }
  }
  if (!prev_child.is_null()) {
    return prev_child;
  }

  return current;
}

Dictionary::node Dictionary::insertCharacter(char character, Dictionary::node current) {
  node insertion_position = findLowerBoundChildNode(character, current);
  if (insertion_position == current){
    this->words.insert_left_child(current, char_info(character));
    return insertion_position.left_child();
  } else if ((*insertion_position).character != character){
    this->words.insert_right_sibling(insertion_position, char_info(character));
    return insertion_position.right_sibling();
  } else {
    return insertion_position;
  }
}

int Dictionary::getOccurrences(node curr_node, char c){

      int ocurrencias = 0;

      if (!curr_node.left_child().is_null()) {

          ocurrencias += getOccurrences(curr_node.left_child(), c);
      }

      if (!curr_node.right_sibling().is_null()) {

          ocurrencias += getOccurrences(curr_node.right_sibling(), c);

      }

      if (curr_node.operator*().character == c) {

          ocurrencias++;
      }

      return ocurrencias;

}

pair<int, int> Dictionary::getTotalUsages(node curr_node, char c){

    // Devuelve un pair con nº n_usos y nºpalabras por debajo de nodo actual
    pair <int, int > sol;

    // Nº n_usos del caracter vale 0
    int n_usos = 0;

    // Nº palabras por debajo de nodo actual vale 0
    int palabras_completas = 0;

    // Llamada de manera recursiva al hermano y al hijo si no son nulos
    pair <int, int> lc = {0, 0};
    pair <int, int> rs = {0, 0};

    // LLamada de forma recursiva sobre hijo a la izquierda si no es nulo
    if (! curr_node.left_child().is_null()) {

        lc = getTotalUsages(curr_node.left_child(), c);

    }

    // LLamada de forma recursiva sobre hermano a la derecha si no es nulo
    if (! curr_node.right_sibling().is_null()) {

        rs = getTotalUsages(curr_node.right_sibling(), c);

    }

    // Nº PALABRAS COMPLETAS = suma del número de palabras completas en nuestro hermano a la derecha y
    // nuestro hijo a la izquierda.
    // Si en el nodo actual termina una palabra, tendremos que aumentar el número de palabras completas.

    palabras_completas += lc.second;

    palabras_completas += rs.second;

    if (curr_node.operator*().valid_word) {

        palabras_completas++;

    }

    sol.second = palabras_completas;

    // Nº DE USOS = suma del número de usos en nuestro hermano a la derecha y nuestro hijo a la izquierda
    // Si en el nodo actual el carácter que tenemos coincide con el carácter que estamos buscando, aumentamos el
    // número de usos de la letra en tantas unidades como palabras terminen en nuestro hijo de la izquierda.
    // Si además el carácter del nodo actual coincide con el buscado, el número de usos de la letra se aumenta en 1

    if (curr_node.operator*().character == c) {

        n_usos += lc.second;
        if (curr_node.operator*().valid_word) {

            n_usos++;
        }
    }

    n_usos += lc.first;

    n_usos += rs.first;

    sol.first = n_usos;

    return sol;
}





///////////////////////////////////////////////////////////////////////////////
//                              Public functions                             //
///////////////////////////////////////////////////////////////////////////////

Dictionary::Dictionary() {
  this->words.set_root(char_info());
  this->total_words = 0;
}

Dictionary::Dictionary(const Dictionary &other) {
  this->words = other.words;
  this->total_words = other.total_words;
}

Dictionary::~Dictionary() {
  this->words.clear();
}

bool Dictionary::exists(const std::string & word) {
  node current = this->words.get_root();
  for (int i = 0; i < word.size(); ++i){
    current = this->findLowerBoundChildNode(word[i], current);
    if ((*current).character != word[i]) {
      return false;
    }
  }

  return (*current).valid_word;
}

bool Dictionary::insert(const std::string &word) {
  node current = this->words.get_root();
  for (int i = 0; i < word.size(); ++i){
    current = this->insertCharacter(word[i], current);
  }

  if (!(*current).valid_word) {
    (*current).valid_word = true;
    this->total_words++;
    return true;
  }

  return false;
}

bool Dictionary::erase(const std::string & val){
  node current = this->words.get_root();
  for (int i = 0; i < val.size(); ++i){
    current = this->findLowerBoundChildNode(val[i], current);
    if ((*current).character != val[i]) {
      return false;
    }
  }
  if ((*current).valid_word){
    (*current).valid_word = false;
    this->total_words--;
    return true;
  }
  return false;
}

Dictionary &Dictionary::operator=(const Dictionary &dic){
  if (this != &dic){
    this->words.clear();
    this->words = dic.words;
    this->total_words = dic.total_words;
  }
  return *this;
}





///////////////////////////////////////////////////////////////////////////////
//                               I/O overload                                //
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream &os, const Dictionary &dict){
  for(Dictionary::iterator it = dict.begin();it != dict.end(); ++it){
    os << *it << std::endl;
  }
  return os;
}

std::istream& operator>>(std::istream &is, Dictionary &dict){
  std::string curr_word;
  while (getline(is, curr_word)){
    dict.insert(curr_word);
  }
  return is;
}





///////////////////////////////////////////////////////////////////////////////
//                            Recursive counters                             //
///////////////////////////////////////////////////////////////////////////////

int Dictionary::getOccurrences(const char c){

    return getOccurrences(words.get_root(), c);
}

int Dictionary::getTotalUsages(const char c){

    return getTotalUsages(words.get_root(), c).first;
}





///////////////////////////////////////////////////////////////////////////////
//                                 Iterator                                  //
///////////////////////////////////////////////////////////////////////////////

Dictionary::iterator::iterator() {

    tree<char_info>::const_preorder_iterator ini;
    iter = ini;
    curr_word = "";

}

Dictionary::iterator::iterator(tree<char_info>::const_preorder_iterator iter){

    this->iter = iter;
    curr_word = "";
}

string Dictionary::iterator::operator*() {

    return curr_word;
}

Dictionary::iterator &Dictionary::iterator::operator++() {

    do {
        tree<char_info>::const_preorder_iterator aux(iter);
        iter.operator++();
        if(iter.get_level() < aux.get_level()) {

            for (int cont = -1; cont < (aux.get_level() - iter.get_level()); cont++) {
                curr_word.pop_back();
            }
            if (iter.get_level() == 0){return *this;}
            curr_word.push_back((*iter).character);

        }else if (iter.get_level() == aux.get_level()){
            curr_word.pop_back();
            curr_word.push_back((*iter).character);
        }else{

            curr_word.push_back((*iter).character);

        }
    } while ( (*iter).valid_word == false);

    return *this;
}

bool Dictionary::iterator::operator==(const iterator &other) {

    if (iter == other.iter){
        return true ;
    } else {return false;}
}

bool Dictionary::iterator::operator!=(const iterator &other) {

    if(*this == other){
        return false;
    }else{return true;}
}

Dictionary::iterator Dictionary::begin() const {

    Dictionary::iterator aux(this->words.cbegin_preorder());
    aux.operator++();
    return aux;

}

Dictionary::iterator Dictionary::end() const {

    Dictionary::iterator aux(this->words.cend_preorder());
    return aux;

}





///////////////////////////////////////////////////////////////////////////////
//                            Letters Iterator                               //
///////////////////////////////////////////////////////////////////////////////

Dictionary::possible_words_iterator Dictionary::possible_words_begin(vector<char> available_characters) const {

    Dictionary::possible_words_iterator aux(this->words.get_root(),available_characters);
    return ++aux;
}

Dictionary::possible_words_iterator Dictionary::possible_words_end() const {

    Dictionary::possible_words_iterator aux;
    return aux;
}

Dictionary::possible_words_iterator::possible_words_iterator() {

    this->current_word = "";
    this->level=0;
}

Dictionary::possible_words_iterator::possible_words_iterator(node current_node, vector<char> available_letters)

        :available_letters(available_letters.begin(), available_letters.end()) {

    this->current_word = "";

    this->current_node = current_node;

    this->level = 0;

}

Dictionary::possible_words_iterator::possible_words_iterator(const possible_words_iterator &other){

    this->current_word = other.current_word;
    this->available_letters = other.available_letters;
    this->level = other.level;
    this->current_node = other.current_node;
}

Dictionary::possible_words_iterator &Dictionary::possible_words_iterator::operator=(const Dictionary::possible_words_iterator &other) {

    if (this != &other) {

        this->current_word = other.current_word;
        this->available_letters = other.available_letters;
        this->level = other.level;
        this->current_node = other.current_node;
    }

    return *this;
}

bool Dictionary::possible_words_iterator::operator==(const Dictionary::possible_words_iterator &other) const {

    bool esigual = false;

    if (this->current_node == other.current_node && this->available_letters == other.available_letters) {

        esigual = true;
    }

    return esigual;

}

bool Dictionary::possible_words_iterator::operator!=(const Dictionary::possible_words_iterator &other) const {

    return !operator==(other);
}

void Dictionary::possible_words_iterator::extract_letter() {

    this->available_letters.insert(this->current_word.back());
    this->current_word.pop_back();

}

bool Dictionary::possible_words_iterator::disponible(Dictionary::node current) {

    bool disp = false;

    if (!current.is_null()) {

        for (multiset<char>::iterator it = this->available_letters.begin(); it != this->available_letters.end() && !disp; ++it) {

            if ((*it) == current.operator*().character) {

                disp = true;
            }
        }
    }

    return disp;
}

bool Dictionary::possible_words_iterator::nodo_encontrado(Dictionary::node current) {

    bool enc = false;

    while (!current.is_null() && !enc) {

        if (this->disponible(current)) {

            enc = true;

        } else {

            current = current.right_sibling();
        }
    }

    if (enc) {

        this->current_node = current;

        this->current_node.operator*().character = current.operator*().character;

        this->available_letters.erase(this->available_letters.lower_bound(current.operator*().character));

        this->current_word.push_back(current.operator*().character);
    }

    return enc;

}

void Dictionary::possible_words_iterator::next_node() {

    if (!nodo_encontrado(this->current_node.left_child())) {

        this->extract_letter();

        if (!nodo_encontrado(this->current_node.right_sibling())) {

            bool enc = false;

            while (!this->current_node.parent().is_null() && !enc) {

                current_node = current_node.parent();
                this->extract_letter();

                if (nodo_encontrado(this->current_node.right_sibling())) {

                    enc = true;
                }
            }

            if (this->current_node.parent().is_null()) {

                this->current_node = this->current_node.parent();
            }
        }
    }
}

Dictionary::possible_words_iterator &Dictionary::possible_words_iterator::operator++() {

    do {

        this->next_node();

    } while (!this->current_node.is_null() && !this->current_node.operator*().valid_word);

    if (this->current_node.is_null()) {

        *this = possible_words_iterator();
    }

    return *this;
}

std::string Dictionary::possible_words_iterator::operator*() const {

    return this->current_word;

}