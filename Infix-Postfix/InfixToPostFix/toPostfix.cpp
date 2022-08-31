#include <iostream>
#include <stack>

using namespace std; 


/**
 * The alogoryhm to write from Infix to Postfix
 * 
 * 
 * DEMANDS;
 *  - "+" or "*" as operators only
 *  - Whole equation must be inside perentheses
 *  - At least one black space between each operator
 *  - At least one black space after a number 
 * 
 * 
 * @author Kjetil K. Indrehus 
 * @return int status 
 */

int main (){

    stack<char> operatorStack; //Stack of operators 
    char curChar; //Current char from stack

    cout << "\n\n Type Infix to be translated: \n"; 

    //Loop while 
    while((curChar = cin.get()) != '\n'){ 

        //Loop until not empty 
        while(curChar == ' ') curChar = cin.get(); 
        
        //Pop operator on or off the stack 
        if (curChar == ')'){
            cout << operatorStack.top(); operatorStack.pop(); 
        } else if (curChar == '+' || curChar == '*'){
            operatorStack.push(curChar); 
        }
        
        //Cout a complete number 
        while(curChar >= '0' && curChar <= '9'){
            cout << curChar; 
            curChar = cin.get(); 
        }

        //Cout a blank
        if(curChar != '('){
            cout << " "; 
        }
    }

    return 0; 
}