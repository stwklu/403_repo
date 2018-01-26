/*
* Created by Steven Weikai Lu on 2018/01/15
* 
* Kattis problem: <kattis_abc>
*
* Topic: sorting
*
* Level: simple
* 
* Brief problem description: 
* You will be given three integers AA, BB and CC. The numbers will not be given in that exact order,
* but we do know that AA is less than BB and BB less than CC.
* In order to make for a more pleasant viewing, we want to rearrange them in a given order.
* 
* Solution Summary:
* - Sort integers
* - Print the integer by desired index
* 
*
* Used Resources:
* -StackOverflow
*
* I hereby certify that I have produced the following solution myself
* using only the resources listed above in accordance with the CMPUT
* 403 collaboration policy.
*
* --------------------- (Steven Weikai Lu)
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