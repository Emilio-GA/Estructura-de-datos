/**
 * @file maxstack.h
 * @brief  Archivo de especificación del TDA MaxStack
 * @author
 */

#ifndef _MAXSTACK_H_
#define _MAXSTACK_H_

#include <queue>
#include <string>


class MaxStack{

    struct element {
        int value; // Current value to store
        int maximum; // Current max value in the structure
    };
private:

    std::queue  <element> cola;




public:
    MaxStack();

    //Dice el top
    std::string top() const;
    //Elemena
    void pop();

    //Añade nuevo elemento al cola
    void push(int num);



};

#endif// _MAX_STACK_
