//Fatine Tazi

#include <iostream>
#include <stdlib.h>     
#include <time.h> 

using namespace std;

void Selectionsort(int arr[], int size) {
    /*//Printing the unsorted array by looping through it.
    cout << "Array before sorting: " << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;*/

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

    /*//Printing the sorted array by looping through it.
    cout << "Array after sorting: " << endl;
    for (int z = 0; z < size; ++z) {
        cout << arr[z] << "  ";
    }
    cout << endl;*/
}

int main() {

    srand((unsigned)time(0));

    //Duration
    int time;
    int start;
    int finish;

    //Random length of input sequences.
    int n; 
    n=(rand()%10000)+2; //Ensures that there are atleast two elements in the array. 
    cout << "The length of the array is: " << n << "." << endl;
    cout << endl;

    //Best Case - the array is sorted in an ascending order
    int* best = new int [n];
    if (best == nullptr) {
        return 1;
    }

    best[0] = (rand()%10);

    for (int i = 1; i < n; i++)
    { 
        best[i] = best[i-1] + 1;
    }

    cout << "Best Case" << endl;
    start = clock();
    Selectionsort(best, n);
    finish = clock();
    time = (finish-start)/double(CLOCKS_PER_SEC)*1000;
    cout << "Time: "<< time << endl;
    cout << endl;

    //Average Case - the array is sorted in a random order
    int* avg = new int [n];
    if (avg == nullptr) {
        return 1;
    }

    for (int j = 0; j < n; ++j)
    { 
        avg[j] = (rand()%10);
    }

    cout << "Average Case" << endl;
    start = clock();
    Selectionsort(avg, n);
    finish = clock();
    time = (finish-start)/double(CLOCKS_PER_SEC)*1000;
    cout << "Time: "<< time << endl;
    cout << endl;

    //Worst Case - the array is sorted in a descending order
    int* worst = new int [n];
    if (best == nullptr) {
        return 1;
    }

    worst[0] = (rand()%10);

    for (int i = 1; i < n; i++)
    { 
        worst[i] = worst[i-1] - 1;
    }

    cout << "Worst Case" << endl;
    start = clock();
    Selectionsort(worst, n);
    finish = clock();
    time = (finish-start)/double(CLOCKS_PER_SEC)*1000;
    cout << "Time: "<< time << endl;
    cout << endl;


    delete[] best;
    delete[] worst;
    delete[] avg;
    return 0;
}