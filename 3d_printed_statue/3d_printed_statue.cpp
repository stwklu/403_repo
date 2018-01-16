/*
Created by Steven Weikai Lu on 2018/01/15

Problem ID: 

CPU Time limit: 1 second
Memory limit: 1024 MB
Difficulty: 1.6
*/

#include <iostream>
#include <tgmath.h>

using namespace std;

int main(){

	int t;
	cin >> t;

	cout << ceil(log2(t))+1 << endl;

	return(0);
}