
/* kattis problem: <hissingmicrophone>
 *
 * Topic: string
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Find if there are 2 consecutive 's' in a string
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
	string s;

	cin >> s;

	for(int i=0; i<s.size()-1;i++){
		if(s[i]=='s' && s[i+1]=='s'){
			cout << "hiss";
			return 0;
		}
	}
	cout << "no hiss";

	return 0;
}