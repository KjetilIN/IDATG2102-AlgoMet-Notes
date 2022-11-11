#include <iostream>

using namespace std;




const int s1 = 12;
int arr1[s1+1] = {0,1,1,2,2,3,4,5,6,7,7,7,8};



void display(int a[], const int n){
    cout << "N = "<<n<< ": [ ";

    for(int i = 1; i<n+1;i++){
        cout << a[i] <<" ";
    }
    cout << "]" << endl;
}


/**
 * Fjern alle duplikater i listen og erstatt dei med 0
 * Alle "0ere"/duplikater skal ligge bakerst i arrayen
 * 
 * 
 * @param a den gitte arrayen
 * @param n størrelse på arrayen 
 * @return int returner antall unike elementer
 */
int fjernDuplikater(int a[], const int n){

    //Base case
    if(n == 0 || n == 1) return n; 


    int dobble = 0; 

    for(int i = 1; i<n-dobble+1;i++){

        int curr = a[i]; 
        int neste = a[i+1];

    
        if(curr == neste){
            
            //FLytt alle en fram
            int j = i; 
            for(j = i; j<n-dobble;j++){
                a[j] = a[j+1];
            }
            a[j] = 0; 
            
            //Dersom element nr i ikkje var 0, så kan det være fleire doble, så vi går tilbake en plass
            if(a[i] != 0) i = i - 1; 

            //Øker antall duplikater 
            dobble++; 

            
        }
    }

    //Returnerer det orginale antall elementer (n - 1), minus antall duplikater (SKAL EGENTLIG VÆRE N - DOBBLE, MEN PGA SLIK DET ER SATT OPP)
    return n - dobble; 
}






int main(){

    cout << "BEFORE: " << endl; 
    display(arr1,s1);
    

    cout << "\n\nAFTER: " << endl; 
    cout << "Unike Verdier: " << fjernDuplikater(arr1, s1) << endl;
    display(arr1,s1);

    return 0; 
}