#include <iostream>
#include "maxstack.h"

using namespace std;

int main(int argc, char *argv[]){

     // Run the current exercise
     MaxStack stack;

     for(int i = 1; i < argc; i++){
         if (argv[i][0] == '.'){
             cout << stack.top() << endl;
             stack.pop();
         } else {
             stack.push(atoi(argv[i]));
         }
     }
     return 0;
//    MaxStack stack;
//    stack.push(2);
//    cout << stack.top() << endl;
//    stack.push(1);
//    cout << stack.top() << endl;
//    stack.push(3);
//    cout << stack.top() << endl;
//    stack.pop();
//    cout << stack.top() << endl;
//    stack.pop();
//    cout << stack.top() << endl;

}
