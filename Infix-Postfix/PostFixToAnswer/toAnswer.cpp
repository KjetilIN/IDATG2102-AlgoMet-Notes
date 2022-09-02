#include <iostream>
#include <stack>

using namespace std;


/**
 * From postfix to a Answer.
 * Prints the answer in the end
 * 
 * DEMANDS;
 *  - Space between + , * and numbers. (Space not needed at the start and the end, just between)
 * 
 * 
 * 
 * @author Kjetil K Indrehus
 * @return int status
 */

int main(){

    stack<int> numberStack;
    char curChar;
    int number; 


    cout << "\n Type PostFix to be translated: \n"; 

    while ((curChar = cin.get()) != '\n'){
        //Set the cur number to be 0 
        number = 0;

        //Loops Until it finds not an empty string 
        while(curChar == ' ') curChar = cin.get();

        //Build number 
        while(curChar >= '0' && curChar <= '9'){
            number = number * 10 + (curChar - '0');
            curChar = cin.get();
        }

        //If operator 
        if(curChar == '+'){
            //Takes the two numbers that is on top of the stack, and adds them to the number 
            number = numberStack.top(); numberStack.pop(); //Adds the top to number and removes it; 
            number += numberStack.top(); numberStack.pop();
        }else if(curChar == '*'){
            //Takes the two numbers that is on top of the stack, and multiply them to the number 
            number = numberStack.top(); numberStack.pop(); //Adds the top to number and removes it; 
            number *= numberStack.top(); numberStack.pop();
        }

        //Pushes the final number to the stack 
        numberStack.push(number); 



    } 

    //The number on top of the stack is the answer; 
    cout << "ANSWER : " << numberStack.top() << endl; 





    return 0;
}