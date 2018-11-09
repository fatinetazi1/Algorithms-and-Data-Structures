#include <iostream>
using namespace std;
 
//Node class
class Node {

    public:
        int value;
        int key;

    //Constructor 
    Node(int key, int value) {
        this->value = value;
        this->key = key;
    }

};
 
//HashTable class
class HashTable {

    private:
        Node **arr;
        int maxSize;
        int currentSize;
 
    public:
        //Constructor
        HashTable() {
            maxSize = 10;
            currentSize = 0;
            arr = new Node*[maxSize];
             
            for(int i = 0 ; i < maxSize ; i++){
                arr[i] = NULL;
            }
        
        }
        
        //Hash function
        int hashCode(int key) {
            return key % maxSize;
        }
         
        //Inserting node function
        void insertNode(int key, int value) {
            Node *temp = new Node(key, value);
             
            //Hash function to find index 
            int hashIndex = hashCode(key);
             
            //Finding the next free slot 
            while(arr[hashIndex] != NULL && arr[hashIndex]->key != key) {
                hashIndex++;
                hashIndex %= maxSize;
            }
             
            //Increase the current size by 1
            if(arr[hashIndex] == NULL){
                currentSize++;
            }

            arr[hashIndex] = temp;
        }
         
        //Getting value of given key function
        int get(int key) {
            //Hash function to find index 
            int hashIndex = hashCode(key);
            int value = -1;
            while(arr[hashIndex] != NULL) {
                if(arr[hashIndex]->key == key){
                    value = arr[hashIndex]->value;
                }
                hashIndex++;
                hashIndex %= maxSize;
            }
             
            //Return -1 if not found
            return value;
        }
         
         
        //Return 1 if currentSize is 0
        bool isEmpty() {
            return currentSize == 0;
        }
         
        //Display function
        void display() {
            for(int i = 0 ; i < maxSize ; i++)
            {
                if(arr[i] != NULL)
                    cout << "key = " << arr[i]->key 
                         <<"  value = "<< arr[i]->value << endl;
            }
        }
};

int main() {
    HashTable *h = new HashTable();

    h->insertNode(0,1);
    h->insertNode(1,2);
    h->insertNode(1,3);

    h->display();

    cout << h->get(1) << endl;
    cout << h->get(2) << endl;
    cout << h->isEmpty() << endl;
    
 
    return 0;
}