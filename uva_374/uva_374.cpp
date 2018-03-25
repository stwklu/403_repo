/* UVa problem: <374>
 *
 * Topic: Number Theory
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Calculate b^p mod m for some big number. Make it in time and avoid overflow.
 *
 * Solution Summary:
 *
 *   Intuition: (a * b) mod m = ( (a mod m) * (b mod m) ) mod m
 *
 * 	 Then use this property to reduce power to be smaller than 2.
 *   Note that to avoid overflow has to get mod directly in recursive steps
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




// (a * b) mod m = ( (a mod m) * (b mod m) ) mod m

#include <iostream>

using namespace std;

#define ll long long

// Revursive function
ll mod_pow(ll b, ll p, ll m){
	// Base cases
	if(p==0){
		return 1;
	}
	else if (p==1){
		return b % m;
	}

	// Recursive cases
	ll recur = mod_pow(b, p/2, m);
	if (p % 2){
		return recur * recur * b % m;
	}
	else{
		return recur * recur % m;
	}

}

int main(){

	ll b, p, m;

	while(cin >> b >> p >> m){
		b = mod_pow(b,p,m);
		cout << b << endl;
	}

	return 0;
}




