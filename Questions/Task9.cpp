#include <iostream>
using namespace std; 


/**
 * GIVEN AN ARRAY OF NUMBERS;
 *  - Find a permutation that has no value that is +- 1 on each side 
 *  - Valid: 53241
 *  - unvalid: 12452
 */

/**
 * @brief Display the array to console 
 * 
 * @param arr the given array to display
 * @param n the length of the array
 */
void display(int arr[], const int n){
    for(int i = 0; i<n;i++){
        cout << arr[i] << " ";
    }
    cout  << "\n";
}

/**
 * @brief Swap to values by refrence
 * 
 */
void swap(int & a, int & b){
    int temp = a; 
    a = b;
    b = temp; 
}

/**
 * @brief Leftshift the array 
 * 
 * @param arr array given
 * @param i index to shift left
 * @param n length of array 
 */

void left(int arr[], int i, int n){
    int leftVal = arr[i];
    for(int t = i+1; t<n;t++){
        arr[t-1] = arr[t];
    }
    arr[n-1] = leftVal;
}

/**
 * @brief Check if current permutation is valis
 * 
 * @param arr array given
 * @param n size of N
 * @return true if there is no neighboor with a value of +-1
 */

bool isValid(int arr[], int n){
    for(int i = 0; i<n-1;i++){
        if(arr[i] + 1 == arr[i+1] || arr[i] - 1 == arr[i+1] ) return false; 
    }
    return true; 
}

/**
 * @brief Main algorithm to display all lineups that is valid
 * 
 * @param arr array given
 * @param i start index
 * @param n length of array
 */

void findLineUp(int arr[], const int i, const int n){
    if((i == n-1)){
        if(isValid(arr,n)) display(arr, n);
    }else{
        findLineUp(arr, i+1,n);

        for(int k = i+1;k<n;k++){
            swap(arr[i],arr[k]);
            findLineUp(arr, i+1,n);
        }
        left(arr, i, n);
    }
}

/**
 * @brief Main program for testing
 * 
 * @return int status as int 
 */

int main(){

    int arr[6] = {1,2,3,4,5,6};

    findLineUp(arr,0,6);

    return 0; 
}