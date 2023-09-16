/**
 *  @file   bag.h
 *  @brief  Archivo de especificación del bag.h
 *  @author EMILIO GUILLÉN, ALBERTO RODRÍGUEZ Y EMIL ZAINULLIN
*/

#ifndef __BAG_H__
#define __BAG_H__
#include  <vector>
#include  <string>
#include  <iostream>
#include  <iterator>
#include  <cstdlib>
#include  <ctime>

using namespace std;

/**
 *  @brief TDA abstracto Bolsa
 *
 *  @details Este TDA abstracto nos permite trabajar con una colección de elementos que permite la extracción de elementos
 *  de forma aleatoria sin reemplazamiento.
 *
 *  @author Emilio Guillen
 *  @author Alberto Rodriguez
 *  @author Emil Zainullin
 *  @date November 2022
 */

template < class T>

class Bag {

private:

    /**
     * @brief Un vector que contiene las letras de la bolsa
     */
    vector<T> v;

public:

    /**
     * @brief Constructor por defecto
     * @post Crea un Bag vacio
     */
    Bag():v(){};

    /**
     * @brief Constructor de copia
     * @param other: Objeto de tipo Bag<T> del que se va a realizar la copia
     * @post Crea una copia exacta de otro objeto de tipo Bag
     */
    Bag(const Bag<T> & other){

        v = other.v;
    }

    /**
     * @brief Añade un elemento en la bolsa
     * @param element: elemento tipo T a añadir a la bolsa
     */
    void add(const T & element) {

        this->v.push_back(element);
    }

    /**
     * @brief Extrae un elemento aleatorio de la bolsa. Devuelve elemento aleatorio de la bolsa y lo elimina de la misma
     * @pre La bolsa no está vacía
     * @post El elemento devuelto se ha elminado de la bolsa
     * @return Elemento de tipo T extraído de la bolsa
     */
    T get(){

        int pos = rand()%v.size();
        T elem = v[pos];
        v.erase(v.begin()+pos);
        return elem;
    }

    /**
     *  @brief Elimina todos los elementos de la bolsa. Borra todos los elementos almacenados en la bolsa
     */
    void clear() {

        this->v.clear();
    }

    /**
     * @brief Tamaño de la bolsa
     * @return Numero de elementos que hay en la bolsa
     */
    unsigned int size() const {

        return this->v.size();
    }

    /**
     * @brief Comprueba si la bolsa está vacía
     * @return true si la bolsa esta vacio, falso en caso contrario
     */
    bool empty() {

        return this->v.empty();
    }

    /**
     * @brief Sobrecarga del operador de asignación
     * @param other : Bag a copiar
     * @post Destruye cualquier información que contuviera previamente Bag que llama al operador de asignación.
     * @return Referencia al objeto this para poder encadenar el operador
     */
    const Bag <T> & operator=(const Bag<T> & other) {

        if(this != &other) {

            v = other.v;
        }
        return *this;
    }

};

#endif //__BAG_H__