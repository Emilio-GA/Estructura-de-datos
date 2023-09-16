/**
 * @file maxstack.cpp
 * @brief  Archivo de implementación del TDA MaxStack
 * @author
 */
#include <iostream>
#include <fstream>
#include <string>
#include <queue>

#include "maxstack.h"


using namespace std;
//private




//public
MaxStack::MaxStack(){
    element front;
    front.value=0;
    front.maximum=0;
    cola.push(front);
}
std::string MaxStack::top() const{
//    string frase;
//    frase = to_string(front.value) + ',' + to_string(front.maximum);
    element front=cola.back();
    return to_string(front.value) + ',' + to_string(front.maximum);
}
void MaxStack::push(int num){
    element front=cola.back();
    front.value=num;
    if(front.maximum<num)
        front.maximum=num;

    cola.push(front);
}
void MaxStack::pop(){
   // if(!cola.empty()) {

//        std::queue  <element> copia;
//        for(element * it=&cola.back()-1;it>=&cola.front();it--){
//            copia.push(*it);
//        }
//
//        cola=copia;
//        element *copia_front=&cola.back();
//        cola.pop();
//        element *copia_front1=&cola.front();
//        cout << copia_front-copia_front1 << endl;
        int count= &cola.back()- &cola.front();

        //cout << count << endl;
        for(int i=0;i<count;i++){
            //cout << "e" << endl;
            cola.push(cola.front());
            cola.pop();
        }
        cola.pop();
        //cout << &cola.back()- &cola.front() <<endl;

  //  }
}
