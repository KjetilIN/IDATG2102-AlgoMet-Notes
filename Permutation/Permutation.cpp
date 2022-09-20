#include <iostream>

using namespace std; 


const int N = 4; //Max


void display(int arr[]){
    for(int i = 0; i<N; i++){
        cout << arr[i] << " ";
    }
    cout <<"\n";
}


/**
 * Swap to integers given
 * 
 * @param a refrence of int a 
 * @param b refrence of int b 
 */

void swap(int & a, int & b){
    int temp = a;
    a = b;
    b = temp; 
}

/**
 * Move the leftmost element to the back and move everything else on step in front 
 * 
 * @param arr array given
 * @param i index to be left switched 
 * @param n size of array 
 */

void leftShift(int arr[],const int i,const int n){
    int left = arr[i];

    for(int k = i+1; k<N;k++){
        arr[k-1] = arr[k];
    }
    arr[n-1] = left;  
}

/**
 * @brief Uses display to print all permutations of the int array
 * 
 * @param arr array given
 * @param i index of start 
 * @param n length of array
 */

void perm(int arr[], const int i, const int n){
    if (i == n-1)                       //  Nådd en ny permutasjon:
        display(arr);                //  Skriver ut arrayens innhold.
    else {                              //  Skal permutere:
        perm(arr, i+1, n);          //  Beholder nåværende nr.'i'.
                                        //    Permuterer resten.
        for (int t = i+1;  t < n;  t++) {
            swap(arr[i], arr[t]);       //  Bytter nr.'i' etter tur med
                                        //    ALLE de andre etterfølgende.
            perm(arr, i+1, n);      //  For hver av ombyttene: permuterer
        }

        leftShift(arr, i, n);        //  Gjenoppretter opprinnelig array!!!
    }
}





/**
 * Main program
 * 
 * @return int return an int as status 
 */
int main(){

    int myArr[4];

    for(int i = 0; i<N; i++){
        myArr[i] = i+1;
    }

    perm(myArr,0,N);

    cout << "\nLeftShifted: ";
    display(myArr);

    return 0; 
}