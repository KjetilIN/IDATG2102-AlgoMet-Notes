#include <iostream> 


using namespace std;

//Constants for creating a constrain 
const int MAX = 5;

//Exsample of simple recursion where the it calls itself uttil it prints the max value
void display(int n){
    cout << " " << n;
    if(n < MAX) display(n+1);
}

//Factory method using recursion
int factory(int n){
    if(n == 1 || n == 0) return 1;
    return n*factory(n-1);
}



// --------------------------------------------------------------------------
// Fibonacci-numbers:
//  Nr:    0    1    2    3    4    5    6    7    8    9   10   11   12   13
//         1    1    2    3    5    8   13   21   34   55   89  144  233  377

int fibonacci(int n){
    if(n <= 1 ) return 1;
    return fibonacci(n-1)+fibonacci(n-2); 
}

int main(){

    int factoryNumber = 5;
    cout << "\n" << factoryNumber << "!  =  ";
    cout << factory(5); cout << "\n";


    int fibNumber = 5;
    cout << "\n\nFibonacci nr. " << fibNumber << " is : ";
    cout << fibonacci(5); cout << "\n";

    return 0;
}