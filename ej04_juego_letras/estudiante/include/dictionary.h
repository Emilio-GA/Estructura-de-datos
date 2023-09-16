/**
 *  @file   dictionary.h
 *  @brief  Archivo de especificación del dictionary.h
 *  @author EMILIO GUILLÉN, ALBERTO RODRÍGUEZ Y EMIL ZAINULLIN
*/

#ifndef TREE_DICTIONARY_HPP
#define TREE_DICTIONARY_HPP

#include "tree.h"
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

/**
 * @brief -----------------------------------
 *
 * @details ---------------------------------
 *
 * @author Emilio Guillen
 *
 * @author Alberto Rodriguez
 *
 * @author Emil Zainullin
 *
 * @date December 2022
 */
class Dictionary {

private:

    /**
     * @brief Struct to represent a character inside the tree.
     *
     * @details The struct contains information about the character it that node, and information marking if a valid
     * word of the dictionary finishes in that character.
     */
    struct char_info {

        /**
         * @brief -------------------
         */
        char character;

        /**
         * @brief ---------------------
         */
        bool valid_word;

        /**
         * Default constructor.
         */
        inline char_info() : character(0), valid_word(false) {}

        /**
         * @brief Parameters constructor.
         *
         * @param character Character to be inserted.
         *
         * @param valid Marker for word validity.
         */
        inline char_info(char character, bool valid = false) : character(character), valid_word(valid) {}

        /**
         * @brief ---------------------
         *
         * ----------------------------
         *
         * @param ------------------------
         *
         * @return ----------------------
         */
        inline bool operator==(const char_info &rhs) {

            return this->character == rhs.character && this->valid_word == rhs.valid_word;
        }

        /**
         * @brief ---------------------
         *
         * ----------------------------
         *
         * @param ------------------------
         *
         * @return ----------------------
         */
        inline bool operator!=(const char_info &rhs) { return !(*this == rhs); }

        /**
         * @brief ---------------------
         *
         * ----------------------------
         *
         * @return ----------------------
         */
        inline bool operator*() { return this->character; }

        /**
         * @brief ---------------------
         *
         * ----------------------------
         *
         * @return ----------------------
         */
        inline friend std::ostream &operator<<(std::ostream &os, const char_info &other) {

            os << other.character << (other.valid_word ? "✓" : "×");
            return os;
        }
    };

    /**
     * @brief ---------------
     */
    tree<char_info> words;

    /**
     * @brief -----------------
     */
    int total_words;

    /**
     * @brief ---------------------
     */
    typedef tree<char_info>::node node;

    /**
     * @brief Find the lower bound of a character among the children of the current node.
     *
     * If the character exists among the children of the current node, that node is returned. If not,
     * the returned node is the one with the biggest character (in terms of alphabetical order) smaller
     * than the searched one.
     *
     * @param character Character to be found.
     *
     * @param current Reference node, the one whose children are going to be explored.
     *
     * @return Lower bound node for the seeked character.
     */
    node findLowerBoundChildNode(char character, node current);

    /**
     * @brief Insert character as children of the current node.
     *
     * This method tries to insert a new character in the tree, as a child of the current node.
     * If there already exists a node with that character, instead of inserting a new node, the
     * already existing node with the character is returned.
     *
     * @param character Character to be inserted.
     *
     * @param current Reference node, the one that will be parent of the new inserted node.
     *
     * @return Node corresponding to the inserted character.
     */
    node insertCharacter(char character, node current);

    /**
     * @brief ---------------------
     *
     * ----------------------------
     *
     * @param ------------------------
     *
     * @param ------------------------
     *
     * @return ----------------------
     */
    int getOccurrences(node curr_node, char c);

    /**
     * @brief ---------------------
     *
     * ----------------------------
     *
     * @param ------------------------
     *
     * @param ------------------------
     *
     * @return ----------------------
     */
    std::pair<int, int> getTotalUsages(node curr_node, char c);

public:

    /**
     * @brief Constructor por defecto.
     *
     * Crea un Dictionary vacío.
     */
    Dictionary();

    /**
     * @brief Constructor de copia.
     *
     * Crea un Dictionary con el mismo contenido que el que se pasa como argumento.
     *
     * @param other Dictionary que se quiere copiar.
     */
    Dictionary(const Dictionary &other);

    /**
     * @brief Destructor.
     *
     * Limpia todos los elementos del Dictionary antes de borrarlo.
     */
    ~Dictionary();

    /**
     * @brief Limpia el Dictionary.
     *
     * Elimina todas las palabras contenidas en el conjunto.
     */
    void clear() { this->words.clear(); this->total_words = 0; }

    /**
     * @brief Tamaño del diccionario.
     *
     * @return Número de palabras guardadas en el diccionario.
     */
    unsigned int size() const { return this->total_words; }

    /**
     * @brief Comprueba si el diccionario está vacio.
     *
     * @return true si el diccionario está vacío, false en caso contrario.
     */
    bool empty() const { return this->total_words == 0; }

    /**
     * @brief Indica si una palabra esta en el diccionario o no.
     *
     * Este método comprueba si una determinada palabra se encuentra o no en el dicccionario.
     *
     * @param palabra: la palabra que se quiere buscar.
     *
     * @return Booleano indicando si la palabra existe o no en el diccionario.
     */
    bool exists(const string &val);

    /**
     * @brief Inserta una palabra en el diccionario.
     *
     * @param val palaba a insertar en el diccionario.
     *
     * @return Booleano que indica si la inserción ha tenido éxito. Una palabra se inserta con éxito si no existía
     * previamente en el diccionario.
     */
    bool insert(const string &val);

    /**
     * @brief Elimina una palabra del diccionario.
     *
     * @param val Palabra a borrar del diccionario.
     *
     * @return Booleano que indica si la palabra se ha borrado del diccionario.
     */
    bool erase(const string &val);

    /**
     * @brief Sobrecarga del operador de asignación.
     *
     * Permite igualar un diccionario a otro.
     *
     * @param dic Diccionario con el cual se compara.
     *
     * @return Referencia al objeto de la clase diccionario
     */
    Dictionary &operator=(const Dictionary &dic);

    /**
     * @brief Sobrecarga del operador de entrada.
     *
     * Permite leer las palabras de un fichero de texto e introducirlas en el diccionario.
     *
     * @param is Flujo de entrada.
     *
     * @param dic Diccionario a rellenar.
     *
     * @return Flujo de entrada para poder encadenar el operador.
     */
    friend istream &operator>>(istream &is, Dictionary &dic);

    /**
     * @brief Sobrecarga del operador de salida.
     *
     * Permite imprimir el diccionario completo a un flujo de salida.
     *
     * @param os Flujo de salida, donde imprimir el diccionario.
     *
     * @param dic Diccionario a imprimir.
     *
     * @return Flujo de salida, para poder encadenar el operador.
     */
    friend ostream &operator<<(ostream &os, const Dictionary &dic);





    //////////////////////////////////////////////// Recursive functions ///////////////////////////////////////////////

    /**
     * @brief ---------------------
     *
     * ----------------------------
     *
     * @param ------------------------
     *
     * @return ----------------------
     */
    int getOccurrences(const char c);

    /**
     * @brief ---------------------
     *
     * ----------------------------
     *
     * @param ------------------------
     *
     * @return ----------------------
     */
    int getTotalUsages(const char c);





    ///////////////////////////////////////////////////// Iterator /////////////////////////////////////////////////////

    /**
     * @brief -----------------------------------
     *
     * @details ---------------------------------
     *
     * @author Emilio Guillen
     *
     * @author Alberto Rodriguez
     *
     * @author Emil Zainullin
     *
     * @date December 2022
     */
    class iterator {

    private:

        /**
         * @brief --------------
         */
        std::string curr_word;

        /**
         * @brief --------------
         */
        tree<char_info>::const_preorder_iterator iter;

    public:

        /**
         * @brief ---------------------
         *
         * ----------------------------
         *
         * @return ----------------------
         */
        iterator();

        /**
         * @brief ---------------------
         *
         * ----------------------------
         *
         * @param ------------------------
         *
         * @return ----------------------
         */
        iterator(tree<char_info>::const_preorder_iterator iter);

        /**
         * @brief ---------------------
         *
         * ----------------------------
         *
         * @return ----------------------
         */
        std::string operator*();

        /**
         * @brief ---------------------
         *
         * ----------------------------
         *
         * @return ----------------------
         */
        iterator &operator++();

        /**
         * @brief ---------------------
         *
         * ----------------------------
         *
         * @param ------------------------
         *
         * @return ----------------------
         */
        bool operator==(const iterator &other);

        /**
         * @brief ---------------------
         *
         * ----------------------------
         *
         * @param ------------------------
         *
         * @return ----------------------
         */
        bool operator!=(const iterator &other);

    };

    /**
     * @brief ---------------------
     *
     * ----------------------------
     *
     * @return ----------------------
     */
    iterator begin() const;

    /**
     * @brief ---------------------
     *
     * ----------------------------
     *
     * @return ----------------------
     */
    iterator end() const;





    ///////////////////////////////////////////////// Letters Iterator /////////////////////////////////////////////////

    /**
     * @brief Clase Possible_words_iterator
     *
     * @details Está formado por un multiset, que es una bolsa con las letras disponibles, un nivel actual, un nodo
     * actual, un nodo actual y una palabra actual.
     *
     * @author Emilio Guillen
     *
     * @author Alberto Rodriguez
     *
     * @author Emil Zainullin
     *
     * @date December 2022
     */
    class possible_words_iterator {

    public:

        /**
         * @brief Constructor por defecto.
         *
         * @post Construye iterador vacío.
         */
        possible_words_iterator();

        /**
         * @brief Constructor por parámetros.
         *
         * Construye un possible_words_iterator con los parámetros dados.
         *
         * @param current_node nodo actual.
         *
         * @param available_letters vector de caracteres disponibles.
         *
         * @post Possible_words_iterator construido con los argumentos dados.
         */
        possible_words_iterator(node current_node, vector<char> available_letters);

        /**
         * @brief Constructor por copia.
         *
         * Construye un possible_words_iterator a partir de otro.
         *
         * @param other possible_words_iterator a copiar.
         *
         * @post Possible_words_iterator a partir de otro copiado.
         */
        possible_words_iterator(const possible_words_iterator &other);

        /**
         * @brief Operador =.
         *
         * Permite igualar un iterador a otro.
         *
         * @param other possible_words_iterator a comparar.
         *
         * @return Possible_words_iterator con los datos del otro iterador.
         */
        possible_words_iterator &operator=(const possible_words_iterator &other);

        /**
         * @brief Operador ==.
         *
         * Compara si un iterador es igual a otro o no.
         *
         * @param other iterador a comparar.
         *
         * @return Devuelve si el iterador es igual al otro o no.
         */
        bool operator==(const possible_words_iterator &other) const;

        /**
         * @brief Operador !=.
         *
         * Compara si un iterador es distinto a otro o no.
         *
         * @param other iterador a comparar.
         *
         * @return Devuelve si el iterador es distinto al otro o no.
         */
        bool operator!=(const possible_words_iterator &other) const;

        /**
         * @brief Operador++.
         *
         * Avanzará el iterador a la siguiente palabra válida.
         *
         * @return Devuelve un iterador a la siguiente posición.
         */
        possible_words_iterator &operator++();

        /**
         * @brief Método auxiliar.
         *
         * Avanzará al siguiente nodo de manera eficiente.
         *
         * @post Consigue avanzar por el siguiente nodo.
         */
        void next_node();

        /**
         * @brief Método auxiliar.
         *
         * Informa acerca de la disponibilidad de un nodo.
         *
         * @param current nodo por el que se busca.
         *
         * @return Booleano indicando la disponibilidad o no del nodo.
         */
        bool disponible (node current);

        /**
         * @brief Método auxiliar.
         *
         * Extrae letras y las inserta en el multiset available_letters.
         *
         * @post Consigue la extracción y posterior inserción en available_letters.
         */
        void extract_letter();

        /**
         * @brief Método auxiliar.
         *
         * Informa acerca de si se ha encontrado un nodo.
         *
         * @param current nodo por el que se busca.
         *
         * @return Booleano indicando si se ha encontrado o no el nodo.
         */
        bool nodo_encontrado(node current);

        /**
         * @brief Operador*.
         *
         * Permite acceder a la palabra actual.
         *
         * @return Devuelve un string (palabra válida actual).
         */
        std::string operator*() const;

    private:

        /**
         * @brief Bolsa con valores no repetidos y ordenados de las letras disponibles.
         */
        multiset<char> available_letters;

        /**
         * @brief Nivel actual.
         */
        int level;

        /**
         * @brief Nodo actual.
         */
        node current_node;

        /**
         * @brief Palabra actual.
         */
        string current_word;

    };

    /**
     * @brief Possible_words_iterator begin.
     *
     * Apunta al principio de la estructura.
     *
     * @param available_characters vector de letras disponibles.
     *
     * @return Devuelve iterador al principio de la estructura.
     */
    possible_words_iterator possible_words_begin(vector<char> available_characters) const;

    /**
     * @brief Possible_words_iterator end.
     *
     * Apunta al final de la estructura.
     *
     * @return Devuelve iterador al final de la estructura.
     */
    possible_words_iterator possible_words_end() const;


};

#endif //TREE_DICTIONARY_HPP