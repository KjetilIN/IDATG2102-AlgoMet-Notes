#include <iostream>
#include <cstdlib>           //  (s)rand
using namespace std;


/**
 * Selection sort:
 *  - Find the smallest element of the array ->loop
 *  - Swap with current index
 *  - increment index until the end of array 
 * 
 */

const int N = 20;


void display(int arr[],const int n){
    for(int i = 0; i<n;i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void swap(int & a, int & b){
    int temp = a;
    a = b;
    b = temp; 
}

void selectionSort(int arr[], const int n){
    int minIndex;
    for(int i = 0; i<n; i++){
        minIndex = i;
        for(int j = i; j<n; j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}


/**
 *  Hovedprogrammet:
 */
int main() {
    int array[N];                  //  Array som skal sorteres.

    srand(0);                      //  Brukes ifm. tilfeldighet/randomisering.

    for (int i = 0;  i < N;  i++)  //  Fyller array med tilfeldige tall 1-100:
        array[i] = (rand() % 100) + 1;

    cout << "\n\nArray Before sort:\n\t";
    display(array, N);             //  Skriver array FØR sortering.


    selectionSort(array, N);       //  SELECTION SORTERER !!!


    cout << "\n\nArrayen AFTER sort with selectsort:\n\t";
    display(array, N);             //  Skriver array ETTER sortering.

    cout << "\n\n";
    return 0;
}