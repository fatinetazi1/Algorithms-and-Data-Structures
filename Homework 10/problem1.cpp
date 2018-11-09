#include <iostream>
#include <vector>
using namespace std;
 
void func(int arr[], int n)
{
    // Create n vectors of vector
    vector<vector<int> > V(n);
 
    V[0].push_back(arr[0]);
 
    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if ((arr[i] > arr[j]) && (V[i].size() < V[j].size() + 1)){
                V[i] = V[j];
            }
        }
        V[i].push_back(arr[i]);
    }
 
    // V[i] stores increasing sub-sequence of arr[0..i] that ends with arr[i]
    vector<int> maximum = V[0];
 
    // Finding the vector with greatest length
    for (int i = 0; i < n; i++){
        vector<int> x = V[i];
        if (x.size() > maximum.size())
            maximum = x;
    }

    // Printing
    for (int i = 0; i < maximum.size(); ++i){
        cout << maximum[i] << " ";
    }
    cout << endl;
}

int main(){

    int arr[] = {8, 3, 6, 50, 10, 8, 100, 30, 60, 40, 80};
    int n = sizeof(arr)/sizeof(arr[0]);
    func(arr, n);

    return 0;
}

 