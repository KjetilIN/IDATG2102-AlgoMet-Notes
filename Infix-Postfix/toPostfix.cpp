#include <iostream>
#include <stack>

using namespace std; 

int main (){

    stack<char> operatorStack; //Stack of operators 
    char curChar; //Current char from stack

    cout << "\n\n Type Infix to be translated: \n"; 

    //Loop while 
    while((curChar = cin.get()) != '\n'){ 

        //Operator is pushed to stack 
        if (curChar == '+' || curChar == '*'){
            operatorStack.push(curChar); 
        }

        if (curChar == ')'){
            cout << operatorStack.top(); operatorStack.pop(); 
        }
        
        

        if(curChar >= '0' && curChar <= '9'){
            cout << curChar; 
            //curChar = cin.get(); 
        }

        if(curChar != '('){
            cout << " "; 
        }
        
        
    }

    return 0; 
}