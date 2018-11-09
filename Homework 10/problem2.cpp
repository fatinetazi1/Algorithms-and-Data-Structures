#include <iostream>
using namespace std;
#define N 5
#define MAX(a,b) (((a)>(b))?(a):(b))

//  Finding maximum sum function
int triSum(int tri[][N], int n)
{
  int arr[N][N];
    
  for(int i = 0; i < n + 1; i++){
      for (int j = 0; j < n + 1; j++){
          arr[i][j] = tri[i][j];
      }
  }

  for(int i = n - 1; i >= 0; i--){
    for(int j = 0; j <= i; j++){
      arr[i][j] += MAX(arr[i+1][j], arr[i+1][j+1]);
    }
  }

  cout << arr [0][0] << endl;

  int j = 0;
  for(int i = 0; i < n + 1; i++){
    cout << tri[i][j] << " ";
    if(arr[i+1][j] < arr[i+1][j+1]) j++;
  }
  cout << endl;

  return arr[0][0];
}
 
/* Driver program to test above functions */
int main()
{
  int tri[N][N] = {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
  triSum(tri, 4);
  return 0;
}