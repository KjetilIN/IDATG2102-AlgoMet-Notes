#include <iostream>
#include <string>            //  string
#include <cstdlib>           //  (s)rand
using namespace std;

/**
 * Shell sort:
 * 
 * 
 * - Has sentinatal key at index 0 
 * - Usese h values 1, 4, 13, 49, 121, ...
 */

const int N = 10; 


void display(const char arr[], const int n){
    for(int i = 0; i<n;i++){
        cout << arr[i] << " ";
    }

    cout << "\n";

}

void shellsort(char arr[], const int n){
    int j; // moving index for moving elements back 
    int h; // H is the index where sub arrays are devided into (h sub arrays)
    char value; // value to be moved 

    for(h = 1; h <= n/9; h = (3*h)+1); // Increment H until the h <= size divided by 9. H is at top value when done. 

    while(h > 0){ //While there are sub arrays  
        for(int i = h+1;i<n;i++){ //Loop subarray -> index start at h+1

            //Uses insertion sort for each sub array!!

            value = arr[i]; //element that could be moved

            j = i; //Set index for moving the element back

            while(j>h && arr[j-h] > value){ // while the index is bigger than H and the value is bigger
                arr[j] = arr[j-h]; // move element h placeses up 
                j-= h; //decrease with H
            }
            arr[j] = value; //set the value that should be moved back, to the back

        } 

        h /= 3; //Set new h to be the 


    }



}


/**
 *  Hovedprogrammet:
 */
int main() {
    char array[N+1];               

    srand(0);                  

    array[0] = ' '; //Set setninal key

    for (int i = 1;  i <= N;  i++) //  array of random letters 
        array[i] =  static_cast <char> ('A' + (rand() % 26));

    cout << "\n\nBefore Shellsort:\n\t";
    display(array, N+1);    

    shellsort(array, N+1);




    cout << "\n\nAfter Shellsort:\n\t";
    display(array, N+1);           

    cout << "\n\n";
    return 0;
}