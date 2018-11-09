/*
CH08-320201
a5 p2.c
Fatine Tazi
f.tazi@jacobs-university.de
Homework 3: Problem 1: Fibonacci numbers 
Created by Fatine Tazi on 2/24/18.
Copyright © 2018 Fatine Tazi. All rights reserved.

*/

#include <stdio.h> 
#include <iostream>     
#include <math.h> 
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

// Computing fibonacci numbers using the naive recursive approach
int naive(int n){
	if(n < 2){
		return n;
	} else {
		return naive(n-1) + naive(n-2);
	}
}

// Computing fibonacci numbers using the bottom up approach
int bottom(int n){
	int* array = new int[n];
	if(array == NULL){
		exit(1);
	}
	for (int i = 0; i <= n; ++i){
		if(i < 2){
			array[i] = i;
		}else{
			array[i] = array[i-1] + array[i-2];
		}
		array[n] = array[i];
	}
	return array[n];
}

// Computing fibonacci numbers using the closed form approach
int closed(int n){
	double sqrt_five = sqrt((double)5);
	int result = (pow((1+sqrt_five)/2, n) - pow((1-sqrt_five)/2, n))/sqrt_five;
	return result;
}

// Computing fibonacci numbers using the matrix representation approach
long long matrix(int n){
    long long fib[2][2] = {{1,1},{1,0}}, r[2][2] = {{1,0},{0,1}}, temp[2][2] = {{0,0},{0,0}};
    int i, j, k;
    while(n){
        if(n & 1){
            memset(temp, 0, sizeof(temp));
            for(i=0; i<2; i++){ 
            	for(j=0; j<2; j++) for(k=0; k<2; k++){
                    temp[i][j]=(temp[i][j]+r[i][k]*fib[k][j]);
                }
            }
            for(i=0; i<2; i++){ 
            	for(j=0; j<2; j++){ 
            		r[i][j]=temp[i][j];
            	}
            }
        }

        memset(temp, 0, sizeof(temp));
        for(i=0; i<2; i++){
        	for(j=0; j<2; j++){
        	 	for(k=0; k<2; k++){
                    temp[i][j]=(temp[i][j]+fib[i][k]*fib[k][j]);
        	 	}
        	}
        }

        for(i=0; i<2; i++){
         	for(j=0; j<2; j++){
         		fib[i][j]=temp[i][j];
         	} 
        }
        n /= 2;
    }
    return (r[0][1]);
}

int main(){
	clock_t begin;
	int r;
	clock_t end;
	double elapsed_secs;

	begin = clock();
	for (int i = 0; i < 45; i+=5){
		// Naive Recursive Approach
		r = naive(i);
		end = clock();
		elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		if (elapsed_secs > 5){
			cout << "5 seconds exceeded." << endl;
			break;
		}
		cout << elapsed_secs << " seconds to computed the fibanacci number(" << r << ") of " << i << " using the naive recursive approach." << endl;
	}

	begin = clock();
	for (int i = 0; i < 100000; i+=1500){
		// Bottom Up Approach
		r = bottom(i);
		end = clock();
		elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		if (elapsed_secs > 5){
			cout << "5 seconds exceeded." << endl;
			break;
		}
		cout << elapsed_secs << " seconds to computed the fibanacci number(" << r << ") of " << i << " using the bottom up approach." << endl;
	}

	begin = clock();
	for (int i = 0; i < 100000; i+=1500){
		// Closed Form Approach
		r = closed(i);
		end = clock();
		elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		if (elapsed_secs > 5){
			cout << "5 seconds exceeded." << endl;
			break;
		}
		cout << elapsed_secs << " seconds to computed the fibanacci number(" << r << ") of " << i << " using the closed form approach." << endl;
	}

	begin = clock();
	for (int i = 0; i < 100000; i+=1500){
		// Matrix Representation Approach
		r = matrix(i);
		end = clock();
		elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		if (elapsed_secs > 5){
			cout << "5 seconds exceeded." << endl;
			break;
		}
		cout << elapsed_secs << " seconds to computed the fibanacci number(" << r << ") of " << i << " using the matrix representation approach." << endl;
		cout << endl;
	}
	return 0;
}