/*
Created by Steven Weikai Lu on 2018/01/15

Problem ID: 3dprinter

CPU Time limit: 1 second
Memory limit: 1024 MB
Difficulty: 2.1
*/
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(){

	int size = 3;
	int integers[size];
	char letters[size];
	map<char, int> map;

	map['A'] = 0;
	map['B'] = 1;
	map['C'] = 2;

	for (int i=0;i<size;i++){
		cin >> integers[i];
	}

	for (int i=0;i<size;i++){
		cin >> letters[i];
	}

	sort(integers, integers + size);

	for (int i=0;i<size;i++){
		cout << integers[map[letters[i]]] << " ";
	}

	cout << endl;


	return(0);
}