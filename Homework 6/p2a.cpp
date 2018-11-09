#include<iostream>
#include <stdio.h>
#define digit(k, i) ((k) >> ((i)*CHAR_BIT) & UCHAR_MAX)

using namespace std;

void help ( int arr[], int a[], int first, int last, int d )
{
    if ( d >= 0 )
    {  
        int i, count[UCHAR_MAX + 2] = {0}; 
         
        for ( i = first; i <= last; i++ ) 
        {
            count[digit ( arr[i], d ) + 1]++;
        } 

        for ( i = 1; i <= UCHAR_MAX; i++ )
        { 
            count[i] += count[i - 1];
        } 

        for ( i = first; i <= last; i++ )
        { 
            a[count[digit ( arr[i], d )]++] = arr[i];
        } 

        for ( i = first; i <= last; i++ )
        { 
            arr[i] = a[i - first];
        } 
         
        help ( arr, a, first, first + count[0] - 1, d - 1 );
         
        for (i = 0; i < sizeof ( int ); i++) 
        {
            help ( arr, a, first + count[i], first + count[i + 1] - 1, d - 1 ); 
        }   
         
    }
}
void radixsort ( int arr[], int first, int last )
{
    int d = sizeof(int) - 1;
    int* a = (int*) malloc((last - first + 1)*sizeof(int));
    help ( arr, a, first, last, d );    
    free (a);
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
 
int main ( void ) 
{
    int arr[] = {100, 2000, 221, 210, 333};
    int last = sizeof(arr)/sizeof(arr[0]);
    radixsort(arr, 0, last);
    print(arr, last);
}