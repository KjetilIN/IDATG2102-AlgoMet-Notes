#include <iostream>
using namespace std;

const int N = 30; 

int arr[N];

/**
 * @brief Display the array
 * 
 * @param arr 
 */
void display(int arr[]){
    for(int i = 0; i<N;i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

/**
 * @brief Swap two elements by refrence
 * 
 * @param a 
 * @param b 
 */
void swap(int & a, int & b){
    int temp = a;
    a = b;
    b = temp; 
}


int part(char arr[], const int left, const int right){
    return 0; //TODO
}




/**
 * @brief Quicksort method 
 * 
 * @param arr array given
 * @param left left index
 * @param right right index
 */

void quicksort(int arr[], int left, int right){
    if(right > left){
        int index = 0;
        quicksort(arr, left, index-1);
        quicksort(arr, index+1, right);
    }

}


int main(){
    return 0;
}