#include <iostream>          //  cout
#include <iomanip>           //  setw
#include <cstdlib>           //  (s)rand
using namespace std;

const int N = 20; // amount of elements in the array

/**
 * @brief Search SEQUENCE in a unsorted array
 * 
 * @param arr sorted array
 * @param value value we are looking for
 * @param n elements in the array
 * @return Index returned or 0 if not found 
 */

int  searchSequence(const int arr[], const int value, const int n){
    int index = n+1; //start all the way to the left 

    //iterate trhough the array and check if current index gives correct value
    while(index > 0 && value != arr[index]) index -=1; //if not reduce index with 1

    return index; //return correct index or 0 if not founf
};


/**
 * @brief Search BINARY in a sorted array
 * 
 * @param arr sorted array
 * @param value value we are looking for
 * @param n elements in the array
 * @return Index returned or 0 if not found 
 */
int  searchBinary(const int arr[], const int value, const int n){
    int left = 1; // left index
    int right = n+1; //right index
    int mid; //Index in the middel of the array 

    while(left <= right){ //if left == right => we have searched the array with no result

        mid = (left+right)/2; //calculate mid index

        //Mid index gives correct value        
        if(value == arr[mid]) return mid;

        if(value < arr[mid]){
            //The value is in the LEFT side of mid
            right = mid-1; 
            
        }else{
            //The value is in the RIGHT side of mid
            left = mid+1; 
        }
    }


    return 0; // Not found and return 0
}



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