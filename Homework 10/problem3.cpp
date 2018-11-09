#include <iostream>
#include <cstdio>
using namespace std;

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

const int WEIGHT = 100000000;

int main () {
  int tc, o, n, c;
  int oxygen[1000], nitrogen[1000], weight[1000], dp[1000][22][80];

  cin >> tc;

  for (int z = 0; z < tc; z++) {

    cin >> o >> n >> c;

    for (int i = 0; i < c; i++){
      cin >> oxygen[i] >> nitrogen[i] >> weight[i];
    }

    for (int i = 0; i < c; i++){
      	for (int j = 0; j <= o; j++){
	        for (int k = 0; k <= n; k++) {
		        dp[i][j][k] = WEIGHT;
		        if (j == 0 && k == 0){
		        	dp[i][j][k] = 0;
		        }
	        }
      	}
    }

    for (int j = 0; j <= o; j++){
		for (int k = 0; k <= n; k++){
		    if (j <= oxygen[0] && k <= nitrogen[0] && (j > 0 || k > 0)){
		      dp[0][j][k] = weight[0];
		    }
		}
    }

    for (int i = 1; i < c; i++){
		for (int j = 0; j <= o; j++){
			for (int k = 0; k <= n; k++) {
				dp[i][j][k] = dp[i-1][j][k];
				if (j <= oxygen[i] && k <= nitrogen[i]){
					dp[i][j][k] = MIN(dp[i][j][k], weight[i]);
				} else{
					dp[i][j][k] = MIN(dp[i][j][k], weight[i] + dp[i-1][MAX(0,j-oxygen[i])][MAX(0,k-nitrogen[i])]);

				}
			}
		}
    }
    cout << dp[c-1][o][n] << endl;
  }
}