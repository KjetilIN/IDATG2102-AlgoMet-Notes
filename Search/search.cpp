#include <iostream>          //  cout
#include <iomanip>           //  setw
#include <cstdlib>           //  (s)rand
using namespace std;

const int N = 20; // amount of elements in the array


int  searchBinary(const int arr[], const int value, const int n);
int  searchSequence(const int arr[], const int value, const int n);


/**
 * @brief Diplay content of array 
 * 
 * @param arr given array
 * @param n size
 */
void display(const int arr[], int n){
    for(int i = 1; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}




/* Main Program for testing */
int main() {
    int array[N+1];                //  Array som skal sorteres.
                                   //  Bruker indeksene 1 til N,
                                   //   da 0 (null) betyr: "Intet funn". 

    srand(0);                      //  Brukes ifm. tilfeldighet/randomisering.

    for (int i = 1;  i <= N;  i++) //  Array med tilfeldige tall 1-100:
        array[i] = (rand() % 100) + 1;

    cout << "\n\nArrayen m/indekser:\n";
    display(array, N);

    cout << "\n54 har indeks nr." << searchSequence(array, 54, N) << '\n';
    cout << "\n56 har indeks nr." << searchSequence(array, 56, N) << '\n';
    cout << "\n39 har indeks nr." << searchSequence(array, 39, N) << '\n';
    cout << "\n17 har indeks nr." << searchSequence(array, 17, N) << '\n';
    cout << "\n 4 har indeks nr." << searchSequence(array,  4, N) << '\n';


// ***************************************************************************

    for (int i = 1; i <= N; i++)  //  Omgjør til en sortert array med partall.
        array[i] = i*2;

    cout << "\n\n\nSORTERT arrayen m/partall:\n";
    display(array, N);

    cout << "\n24 har indeks nr." << searchBinary(array, 24, N) << '\n';
    cout << "\n 8 har indeks nr." << searchBinary(array,  8, N) << '\n';
    cout << "\n 7 har indeks nr." << searchBinary(array,  7, N) << '\n';
    cout << "\n98 har indeks nr." << searchBinary(array, 98, N) << '\n';
    
    cout << "\n\n";
    return 0;
}