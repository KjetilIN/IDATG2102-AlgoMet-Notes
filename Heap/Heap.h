#include <iostream>          //  cout
#include <limits>            //  numeric_limits::max
using namespace std;


template <typename T>
class Heap{
    private:
        T* data;
        int length, amount;
        T sentinelKey;

        void upHeap(int keynr){
            T value = data[keynr]; // The value to be moved up
            data[0] = sentinelKey; // We set the sentinel key at index 0
            while(data[keynr/2] < value){
                data[keynr] = data[keynr/2];
                keynr = keynr/2;
            }
            data[keynr] = value; 
        };

    public:
        //Constructor 
        Heap(const int len = 200){
            data = new T[len]; 
            length = len;
            amount = 0;
            sentinelKey = numeric_limits<T>::max(); // Max value for the key
        }    
        
        //Destrucktor
        ~Heap(){delete [] data}

        //Task 15
        void change(const int keynr, const T newValue);

        //display all data in the array 
        void display(){
            for (int i = 1; i<=antall; i++){
                cout << data[i] << " ";
            }
            cout << "\n";
        }

        //Downheap an element
        void downHeap(T arr[], const int ant, int keyNr);

        //Task 15
        void exstract(const int keyNr);

        void insert(const T value);

        T remove();

        T replace(const T value);




};