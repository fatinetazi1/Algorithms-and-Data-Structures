#include <iostream>
#include <string>

using namespace std;

// Print Function
void print(string arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
 
// Getting maximum value in arr[]
int maximum(string arr[], int n)
{
    int mx = stoi (arr[0]);
    for (int i = 1; i < n; i++)
        if (stoi (arr[i]) > mx)
            mx = stoi (arr[i]);
    return mx;
}
 
// Counting sort of arr[] according to the current digit
void countsort(string arr[], int n, int exp)
{
    string output[n]; 
    int count[10] = {0};
 
    // Count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(stoi (arr[i])/exp)%10]++;
 
    // Count[i] now contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(stoi (arr[i])/exp)%10] - 1] = arr[i];
        count[(stoi (arr[i])/exp)%10]--;
    }
 
    // Copy output[] to arr[]
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
 
// Sorts arr[] using radix sort
void radixsort(string arr[], int n)
{
    // Find the maximum number
    int m = maximum(arr, n);
 
    // Do counting sort for every digit. N
    for (int exp = 1; m/exp > 0; exp *= 10)
        countsort(arr, n, exp);

    // Print sorted arr[]
    print(arr, n);
}

int main()
{
    string arr[] = {"abc", "cba", "bac"};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixsort(arr, n);
    return 0;
}