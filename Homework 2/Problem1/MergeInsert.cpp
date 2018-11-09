//Fatine Tazi
//Used http://www.cplusplus.com/ for finding the time

#include <climits>
#include <iostream>
#include <chrono>
#include <ctime> 
#include <cstdlib>
#include <fstream> 
#include <ratio>
using namespace std;
using namespace std::chrono;

//Insertion sort
void insertionsort(int arr[], const int &first, const int &last){
    if(last == first){
        return;
    }
    for (int i = first + 1; i < last; ++i){
        if (arr[i] < arr [i-1]){
            int j = i;
            while((j > first) && (arr[j] < arr[j-1])){
                int temp = arr[j];
                arr[j] = arr [j - 1];
                arr[j - 1] = temp;
                j--;
            }
        }
    }
}

//Merging two arrays together
void merge(int arr[], const int &first, const int &middle, const int &last){
    int sizeone = middle - first + 2;
    int sizetwo = last - middle + 1;

    int* one = new int[sizeone];
    if(one == NULL){
        exit(1);
    }
    int* two = new int[sizetwo];
    if(two == NULL){
        exit(1);
    }

    int j = 0;
    for (int i = first; i < middle; ++i){
        one[j] = arr[i];
        ++j;
    }
    one[sizeone] = INT_MAX;
    j = 0;
    for (int i = middle; i < last; ++i){
        two[j] = arr[i];
        ++j;
    }
    two[sizetwo] = INT_MAX;

    int i = j = 0;
    for (int k = first; i < last; ++k){
        if (one[i] > two[j]){
            arr[k] = two[j];
            ++j;
        } else {
            arr[k] = one[i];
            ++i;
        }
    }
    delete[] one;
    delete[] two;
}

//Merge sort
void mergesort(int arr[], const int &first, const int &last){
    int middle = (last + first)/2;
    if (last - first < 10000){
        insertionsort(arr, first, last);
        return;
    } else {
        mergesort(arr, first, middle);
        mergesort(arr, middle, last);
    }
    merge(arr, first, middle, last);
}

//Function that randomly initializes an array
void random(int* arr, const int &size){
    srand(static_cast <unsigned int>(time(0)));
    for (int i = 0; i < size; ++i){ 
       int random = rand()%1000 + 1;
       arr[i] = random;
    }
}

//Function that reverses an array
void reverse(int arr[], const int &size){
    int* help = new int[size];
    if(help == NULL){
        exit(1);
    }
    for (int i = 0; i < size; ++i){
        help[size - 1 - i] = arr[i];
        arr[i] = help[i];
    }
}


int main() {

    ofstream outdata;
    outdata.open("timing.csv", ios::app);

    for (int i = 0; i <= 20000; i += 100){
        int* arr = new int[i];
        if(arr == NULL){
            exit(1);
        }   
        double best = 0;
        double avg = 0;
        double worst = 0;
        for (int j = 0; j < 3; ++j){ //taking the average
            random(arr, i); // initializing an array with random values

            //Average Case - after the random value initialization
            high_resolution_clock::time_point start = high_resolution_clock::now();
            mergesort(arr, 0, i);
            high_resolution_clock::time_point end = high_resolution_clock::now();
            duration<double> duration = (end - start);
            avg += duration.count();
            

            //Best Case - after sorting the array
            start = high_resolution_clock::now();
            mergesort(arr, 0, i);
            end = high_resolution_clock::now();
            duration = (end - start);
            best += duration.count();

            //Worst Case - reversing the best case
            reverse(arr, i);
            start = high_resolution_clock::now();
            mergesort(arr, 0, i);
            end = high_resolution_clock::now();
            duration = (end - start);
            worst += duration.count();
        }
        avg /= 3;
        best /= 3;
        worst /= 3;
        cout << "Average: " << avg << endl; 
        cout << "Best: " << best << endl;
        cout << "Worst: " << worst << endl;
        delete[] arr;
    }
    return 0;
}