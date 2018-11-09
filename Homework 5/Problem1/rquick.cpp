#include <iostream>
#include <ctime>
#define SIZE 10

using namespace std;

// Quicksort function
void quicksort(int* array, int size) {

    // If the size is 1 then it is sorted
    if (size <= 1) {
        return;
    }

    // Randomly select the pivot element
    srand((unsigned int)time(0));
    int pivot = array[(rand() % (size - 1))];

    // Index of elements that will be swapped
    int lower = -1;
    int upper = size;

    // Sort
    while (lower <= upper) {
        do {
            ++lower;
        } while (array[lower] < pivot);

        do {
            --upper;
        } while (array[upper] > pivot);

        // Swap
        if (lower <= upper) {
            int temp = array[lower];
            array[lower] = array[upper];
            array[upper] = temp;
        }
    }

    // Sort every subarray
    if(size%3 == 0){
        quicksort(array, size/3);
        quicksort(&(array[size/3]), size/3);
        quicksort(&(array[2*(size/3)]), size/3);
    } else {
        quicksort(array, lower);
        quicksort(&(array[lower]), size - lower);
    }
    
}

// Printing function
void print(int* a, int size){
    for (int i = 0; i < size; i++){
        cout << a[i] << "  ";
    }
    cout << endl;
}

int main() {
    srand((unsigned int)time(0));
    int array[SIZE];

    // Initialize array randomly
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 10;
    }

    // Print the unsorted array
    print(array, SIZE);

    quicksort(array, SIZE);

    // Print the sorted array
    print(array, SIZE);

    return 0;
}