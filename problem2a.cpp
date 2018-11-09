#include <iostream>
#include <chrono>

#define SIZE 1999999

using namespace std;


void heap(int array[], int n, int i) {
    int root = i;  
    int left = 2*i + 1; 
    int right = 2*i + 2;  
 
    // left child > root
    if (left < n && array[left] > array[root]){
        root = left;
    }
 
    // right child > root so far
    if (right < n && array[right] > array[root]){
        root = right;
    }
 
    // root != initial root
    if (root != i){
        swap(array[i], array[root]);
        heap(array, n, root); // recursive heap
    }
}

void heapsort(int array[], int n) {
    // Creating the heap
    for (int i = n / 2 - 1; i >= 0; i--){
        heap(array, n, i);
    }
 
    // Removing element to sort
    for (int i = n - 1; i >= 0; i--){
        swap(array[0], array[i]); // Moving the largest number(root) to end
        heap(array, i, 0); 
    }
}

int main(){

	srand(1);

	int array[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		array[i] = (rand() % 100);
	}

 	clock_t start = clock();
    heapsort(array, SIZE);
 	clock_t finish = clock();
 	double sec = (double)(finish - start)/CLOCKS_PER_SEC;

    /*cout << "Sorted array is \n";
    for (int i = 0; i < SIZE; ++i){
        cout << array[i] << " ";
    }
    cout << "\n";*/
    cout << "Seconds: " << sec << endl;
}