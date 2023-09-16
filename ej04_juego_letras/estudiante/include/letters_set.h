/**
 *  @file   letters_set.h
 *  @brief  Archivo de especificación del letters_set.h
 *  @author EMILIO GUILLÉN, ALBERTO RODRÍGUEZ Y EMIL ZAINULLIN
*/

#ifndef   LETTERS_SET_H
#define   LETTERS_SET_H
#include  <map>
#include  <string>
#include  <iostream>
#include  <iterator>

using namespace std;

/**
 * @brief TDA LetterInfo
 *
 * @details Contiene información sobre un determinado carácter del juego de las letras. En concreto, almacena información
 * sobre el número de repeticiones de la letra en la partida y de la puntuación que otorga al utilizarse en una palabra.
 *
 * @author Emilio Guillen
 * @author Alberto Rodriguez
 * @author Emil Zainullin
 * @date November 2022
 */
struct LetterInfo{

    /**
     *  @brief Numero de repetición de la letra
    **/
    int repetitions;

    /**
    *   @brief Numero de puntos que contiene la letra
    **/
    int score;

    /**
    *  @brief Constructor por defecto
    *  @post El objeto creado con repeticiones y puntuacion
    **/
    LetterInfo();

    /**
    *  @brief Constructor con parámetros
    *  @param s: Puntuación de cada letra
    *  @param r: Repeticiones de cada letra
    *  @post EL objeto creado con argumentos pasados como parámetros
    **/
    LetterInfo(int s, int r);

};


/**
 * @brief TDA LettersSet
 *
 * @details Este TDA representa un conjunto de letras, con la información necesaria para jugar una partida al juego de
 * las letras, es decir, el número de repeticiones que tenemos de la letra y la puntuación que dicha letra otorga cuando
 * se utiliza en una palabra
 *
 * @author Emilio Guillen
 * @author Alberto Rodriguez
 * @author Emil Zainullin
 * @date November 2022
 */

class LettersSet{

private:

     /**
     * @brief Un map que contiene claves (letra) y valores correspondientes de LetterInfo
     */
    map <char,LetterInfo>letters;

public:

    /**
     * @brief Constructor por defecto
     * @post Crea un LetterSet vacio
     */
    LettersSet();

    /**
     * @brief Constructor de copia
     * @param other: LetterSet a copiar
     */
    LettersSet(const LettersSet & other);

    /**
     * @brief Inserta un elemento en el LettersSet
     * @param val: Pareja de letra y LetterInfo asociada a insertar
     * @pre La letra solo se inserta correctamente si no estaba aún incluida en la colección
     * @return booleano que marca si se ha podido insertar la letra en ele LettersSet.
     */
    bool insert(const pair <char,LetterInfo> & val);

    /**
     * @brief Elemina un caracter del LetterSet
     * @param key: Carater a eliminar
     * @return Booleano que indica si se ha podido eliminar correctamente la letra del LettersSet
     */
    bool erase(const char & key);

    /**
     *  @brief Limpia el contenido del LettersSet
     *  @post Elimina el contenido del LettersSet
     */
    void clear();

    /**
     * @brief Consulta si el LettersSet es vacio
     * @return true si el LetterSet esta vacio, falso en caso contrario
     */
    bool empty();

    /**
     * @brief Tamaño del LettersSet
     * @return Numero de elementos en el LettersSet
     */
    unsigned int size() const;

    /**
     * @brief Calcula la puntuación dada una palabra
     * @param word String con la palabra cuya puntación queremos calcular
     * @return Puntación de la palabra, calculada como la suma de las puntaciones de cada una de sus letras
     */
    int getScore(string word);

    /**
     * @brief Devuelve las ocurrencias de una letra (método auxiliar)
     * @param clave La letra de la cual se sacan las repeticiones
     * @return Repeticiones de una letra
     */
    int getrep(char clave)const;

    /**
     * @brief Obtiene la letra mediante un iterador (método auxiliar)
     * @param est Iterador para el LettersSet
     * @return Devuelve la letra del conjunto map
     */
    char getclave(map<char,LetterInfo>::const_iterator est) const;

    /**
     * @brief Sobrecarga del operador de asignación
     * @param cl: LettersSet a copiar
     * @return Referencia al objeto this para poder encadenar el operador
     */
    LettersSet& operator=(const LettersSet& cl);

    /**
     * @brief Sobrecarga del operador de consulta. Permite acceder a los elementos del map que hay en nuestra clase
     * @param val: Caracter a consultar
     * @return Estructura de tipo LetterInfo con la información del caracter consultado: Número de repeticiones y score
     */
    LetterInfo& operator[](const char & val);

    /**
     * @brief Sobrecarga del operador de salida para LettersSet
     * @param os: Flujo de salido, donde escribir el LetterSet
     * @param cl: LetterSet que se escribe
     * @return operador de salida
     */
    friend ostream& operator<<(ostream& os, const LettersSet& cl);

    /**
    * @brief Sobrecarga del operador de salida para LetterInfo (auxiliar)
    * @param os: Flujo de salido, donde escribir el LetterInfo
    * @param cl: LetterInfo que se escribe
    * @return operador de salida
    */
    friend ostream& operator<<(ostream& os , const LetterInfo& cl);

    /**
     * @brief Sobrecarga del operador de entrada
     * @param is: Flujo de entrada, del que leer el LettersSet
     * @param cl: LettersSet en el que almacenar la información leída
     * @return operador de entrada
     */
    friend istream& operator>>(istream& is, LettersSet& cl);

    /**
     * @brief Iterador de inicio de diccionario (letters)
     * @return Dirección de memoria de inicio de diccionario
     */
    map<char,LetterInfo>::const_iterator  begin() const;

    /**
     * @brief Interador que nos da dirreción de memoria de valor de clave
     * @param clave: clave de diccionario (letters)
     * @return  Dirección de dirreción de memoria de valor de clave
     */
    map<char,LetterInfo>::const_iterator  find(const key_t & clave) const;

    /**
     * @brief Iterador de fin de diccionario (letters)
     * @return Dirección de memoria de fin de diccionario
     */
    map<char,LetterInfo>::const_iterator  end() const;

    map<char,LetterInfo>::const_iterator  ki();

};

#endif //LETTERS_SET_H