#include<iostream>
#include<typeinfo>

using namespace std;


template <typename T1, typename T2>
class Map{

    private:
        // Key Value node, der en key peker til en value 
        struct Node{
            T1 key;
            T2* value;

            void set(const T1 newkey, const T2 newValue = nullptr){
                key = newkey; value = new T2(newValue); 
            }
        };

        
        Node* listOfNodes; //list of nodes 
        int kapasitet; //Lenght of the array nodes 
        int antall; //Antall noder med KeyValue 


        //Get the index of a key
        int getKeyIndex(const T1 key){
            for(int i = 0; i<antall; i++){
                if(listOfNodes[i].key == key){
                    return i; //Return the index of the key
                }
            }

            return -1; // Return -1 if not found
        }



    public: 

        Map(const int given = 200){
            listOfNodes = new Node[given]; 
            kapasitet = given;
            antall = 0; 
        };

        //Map destruct
        ~Map(){
            delete[] listOfNodes; 
        }

        

        //Metoder

        T2 nothing(){
            if(typeid(T2) == typeid(char) ){
                return ' ';
            }
            return 0; 
        }

        //Set a new key value pair 
        void put(const T1 key, const T2 value){
            if (!hasKey(key)){
                listOfNodes[antall++].set(key, value);
            }else{
                int index = getKeyIndex(key);
                if(index <= 0){
                    listOfNodes[getKeyIndex(key)].set(key,value);
                }
            }
            

        }

        //Get a value from key 
        T2 get(const T1 givenKey){
            for(int i = 0; i<antall; i++){
                if(listOfNodes[i].key == givenKey) return *listOfNodes[i].value;
            }
            return nothing(); 

        }

        //Returns true if it has the key given 
        bool hasKey(const T1 findKey){
            for(int i = 0; i<antall; i++){
                if(listOfNodes[i].key == findKey) return true; 
            }

            return false; 
        }

        bool remove(const T1 key){
            for(int i = 0; i<antall;i++){
                if(listOfNodes[i].key = key){
                    for(int j = i; j < antall;j++){
                        listOfNodes[j] = listOfNodes[j+1];
                    }
                    antall --; 
                    return true; 
                }
            }

            return false; 
        }

        //Return the capacity of the map
        int capacity(){
            return kapasitet;
        }

        //Return the amount of key-value pairs 
        int size(){
            return antall;
        }

        //Method for display all of the content in the map 
        void toString(){
            cout<< "MAP OF {size: " << antall << ", kapasitet: "<< kapasitet<< " }" << endl;
            for (int i = 0; i < antall; i++){
                cout << "{key: " << listOfNodes[i].key << ", value: " << *listOfNodes[i].value << " }"<< endl; 
            }
        }


};


int main(){

    Map<char, int> myMap; 

    myMap.put('d', 10);
    myMap.put('f',123);

    myMap.toString();

    myMap.put('d', 23);

    myMap.toString();

    myMap.remove('f');
    myMap.toString();

    char t = 'r';
    cout << "Has key: " << t << " => " << myMap.hasKey(t) << endl;

    
    return 0;
}