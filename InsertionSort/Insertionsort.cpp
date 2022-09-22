#include <iostream>
using namespace std; 

const int N = 20; 

void display(int arr[], const int n){
    for(int i = 1; i<n;i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void swap(int & a, int & b){
    int temp = a;
    a = b;
    b = temp;
}

void insertSort(int arr[], const int n){
    int i, j, value;

    for(i = 2; i<n; i++){
        j = i;
        value = arr[i];

        while(arr[j-1]>value){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = value;
    }

}

int main(){

    int array[N+1];                

    srand(0);                      //  Brukes ifm. tilfeldighet/randomisering.

    array[0] = -1;                 //  Legger inn SENTINEL KEY !!!

    for (int i = 1;  i <= N;  i++) //  Fyller array med tilfeldige tall 1-100:
        array[i] = (rand() % 100) + 1;

    cout << "\n\nArray Before sort:\n\t";
    display(array, N+1);           //  Skriver array FØR sortering.


    insertSort(array, N+1);     


    cout << "\n\nArrayen After insertion sort:\n\t";
    display(array, N+1);           //  Skriver array ETTER sortering.

    cout << "\n\n";

    return 0; 
}