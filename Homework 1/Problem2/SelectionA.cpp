//Fatine Tazi

#include <iostream>

using namespace std;

int main() {

    int arr[] = {34, 17, 23, 35, 45, 9, 1}; //An array with size 7.
    int size = 7; //Size of the array.

    //Printing the unsorted array by looping through it.
    cout << "Array before sorting: " << endl;
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << "  ";
    }
    cout << endl;

    // Selection sort
    for (int x = 0; x < size - 1; ++x) { //First loop used to move through the array.
        int low = x;
        for (int j = x + 1; j < size; ++j) { //Second loop used to find the smallest number in the array.
            if (arr[low] > arr[j]) {
                low = j;
            }
        }
        //Moving the smallest element in the xth index
        int swap = arr[low];
        arr[low] = arr[x];
        arr[x] = swap;
    }

    //Printing the sorted array by looping through it.
    cout << "Array after sorting: " << endl;
    for (int z = 0; z < size; ++z) {
        cout << arr[z] << "  ";
    }
    cout << endl;

    //cin.get();
    return 0;
}