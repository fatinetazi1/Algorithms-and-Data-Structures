#include <iostream>
#include <string>
#include "problem1a.h"

using namespace std;

int main(int argc, char** argv){ 
	Stack<int> a;
	a.push(25);
	a.pop();

	Stack<int> b(14);
	for (int i = 0; i < 15; ++i){
		b.push(i);
	}
	cout << b.isEmpty() << endl;
	for (int i = 0; i < 15; ++i){
		b.pop();
	}
	cout << b.isEmpty() << endl;


	Stack<char> c;
	c.push('a');
	c.pop();

	Stack<char> d(14);
	for (int i = 97; i < 112; ++i){
		d.push(i);
	}
	cout << d.isEmpty() << endl;
	for (int i = 0; i < 15; ++i){
		d.pop();
	}
	cout << d.isEmpty() << endl;
	return 0;
}