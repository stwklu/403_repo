
/* kattis problem: <r2>
 *
 * Topic: arithmetic
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   given the mean of 2 int and one of them, find the other.
 *
 * Solution Summary:
 *
 *   Direct formula : r2 = 2*s - r1
 *
 * Used Resources:
 *
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *
 * --------------------- (Steven Lu)
 */


#include <iostream>

using namespace std;

int main(){
	int s,r;
	cin >> r >> s;
	cout << (2*s - r);

	return 0;
}