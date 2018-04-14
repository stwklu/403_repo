/* kattis problem: <autori>
 *
 * Topic: string
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Output the shorterm of a - separated string
 *
 * Solution Summary:
 *
 *   trivial
 *
 * Used Resources:
 *
 *   StackOverflow
 *   Competitive Programming 3: Steven Halim, Felix Halim
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *
 * --------------------- (Steven Lu)
 */

#include <iostream>
#include <string>

using namespace std;


int main(){
	string str;
	cin >> str;

	cout << str[0];
	for(int i=1; i<str.size(); i++){
		if(str[i]=='-'){cout<<str[i+1];}
	}

	return 0;
}