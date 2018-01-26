/*
* Created by Steven Weikai Lu on 2018/01/15
* 
* Kattis problem: <uva_455>
*
* Topic: string
*
* Level: challenging
* 
* Brief problem description: 
*	Find the shortest repeating period of string
*	e.g. shortest periodic string of "abcabcabcabc" should be "abc"
* 
*
* Solution Summary:
* 	- exhaustic search all possible period from the shortest
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
#include <string>

using namespace std;

int main(){
	int i, t, period;
	string line;
	cin >> t;
	for (i=0; i < t; i++){
		cin >> line;
		int len = line.length();

		// Iterate through every possible period
		bool isPeriod = true;
		for (period = 1; period < len; period++)
		{
			// length of period has to be the fraction of length of string
			string str = line.substr(0, period);
			if (len % period != 0){
				continue;
			}

			// Iterate through each char
			for (int j = period; j < len; j++){
				if(line[j] != str[j % period]){
					isPeriod = false;
					break;
				}
			}

			if (isPeriod){
				break;
			}
			isPeriod = true;

		}
		// No periodic substring
		cout << period << endl;

		// print blank line if not finished
		if (i < t-1){
			cout << endl;
		}
	}
	return(0);
}



