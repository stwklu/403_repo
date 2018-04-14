
/* kattis problem: <pot>
 *
 * Topic: arithmetic
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Given sequence of concatenated np, find sum of n^p
 *
 * Solution Summary:
 *
 *   Trivial. Mod to extract power
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
#include <cmath>

using namespace std;


int main(){
	int ans=0, n, p, t;

	cin >> t;
	while(t--){
		cin >> n;
		p = n%10;
		n -= p;
		n /= 10;
		ans += pow(n,p);
		//cout << n << " " << p << " ";
	}

	cout << ans;
	//cout << endl;

}