/**
 *  @file   letters_bag.h
 *  @brief  Archivo de especificación del letters_bag.h
 *  @author EMILIO GUILLÉN, ALBERTO RODRÍGUEZ Y EMIL ZAINULLIN
*/

#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__
#include  <string>
#include  <iostream>
#include  <iterator>
#include "letters_set.h"
#include "bag.h"

using namespace std;

/**
 * @brief TDA LettersBag
 *
 * @details Este TDA almacena un conjunto de chars utilizado en el juego de letras. La estructura de datos subyacente es una lista de chars.
 *
 * @author Emilio Guillen
 * @author Alberto Rodriguez
 * @author Emil Zainullin
 * @date November 2022
 */
class LettersBag {

private:

    /**
     * @brief Una Bag que contiene las letras de LetterSet
     */
    Bag<char> letters_bag;

public:

    /**
     * @brief Constructor por defecto
     * @post Crea un LettersBag vacio
     */
    LettersBag();

    /**
     * @brief Dado un LettersSet como argumento, este constructor debe rellenar la LettersBag con las letras qeu contiene
     * el LettersSet, introduciendo cada letra el número de veces indicando por el campo LetterInfo::repetitions.
     * @param ls: TDA LetterSet a parsear
     * @post Copia el parametro
     */
    LettersBag(const LettersSet &ls);

    /**
     * @brief Introduce una letra en la bolsa.
     * @param I: letra a añadir a la LettersBag
     */
    void insertLetter( const char & I);

    /**
     * @brief Extrae una letra aleatoria de la bolsa
     * @post La letra extraída debe ser eliminada del conjunto
     * @return char representa la letra extraida
     */
    char extractLetter();

    /**
     * @brief Extrae un conjunto de letras
     * @param num: Número de letras a extraer
     * @post Las letras extraídas deben ser eliminadas del conjunto
     * @return Lista con letras extraídas
     */
    vector<char> extractLetters(int num);

    /**
     *  @brief Vacia la LettersBag
     *  @post Elimina todo el contenido de la LettersBag
     */
    void clear();

    /**
     * @brief Tamaño de la bolsa
     * @return int con el tamaño de la bolsa
     */
    unsigned int size() const;

    /**
     * @brief Sobrecarga del operador de asignación
     * @param other: LettersBag a copiar
     * @post Destruye cualquier información que contuviera previamente LettersBag que llama al operador de asignación.
     * @return Referencia al objeto this para poder encadenar el operador
     */
    LettersBag& operator= (const LettersBag & other);

    /**
    * @brief Sobrecarga del operador de salida para LettersBag
    * @param os: Flujo de salido, donde escribir el LettersBag
    * @param cl: LettersBag que se escribe
    * @return operador de salida
    */
    friend ostream& operator<<(ostream& os , const LettersBag& cl);
};

#endif //__LETTERS_BAG_H__