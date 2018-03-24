
/* UVa problem: <11955>
 *
 * Topic: arithmetic
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *  
Input
There is a number of tests T (T ≤ 100) on the first line. After T test follows. Each test is written on a
single line in form of ‘(a+b)^k’. Where a and b are same variables names. Variables names are strings
constructed from ‘a’–‘z’ characters. And k (1 ≤ k ≤ 50) is a power that you need to raise the sum.
You can assume that there are no lines longer than 100 characters.
Output
For each test output a single line ‘Case N: T’. Where N is the test number (starting from 1) and T
is an expanded expression (see examples for clarification). By the way, you shouldn’t output coefficients
and powers equal to one.
 *
 * Solution Summary:
 *
 *   Only tricky part is avoiding overflow when computing factorials.
 *		Figure out which part can be cancelled out and use parallel multiplication and division to handle this.
 *
 * Used Resources:
 *
 *   StackOverflow
 *	 https://stackoverflow.com/questions/9330915/number-of-combinations-n-choose-r-in-c
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
#include <cstring>

using namespace std;

#define ll unsigned long long


ll combination2(ll n, ll r){
	ll a, b;
	ll out = 1;

 	// Bound for non-cancelling part
	if(n-r >= r+1){
		a = r;
		b = n-r+1;
	}
	else{
		a = n-r;
		b = r+1;
	}

	for (ll i = b; i < n+1; i++){
		out *= i;
	}
	for (ll i = 1; i<a+1; i++){
		out /= i;
	}
	return out;
}

ll combination( ll n, ll k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    ll result = n;
    for( ll i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}


int main(){

	ll t, deg, j;
	string str, a, b, n;
	char c;
	cin >> t;
	for (int i=0;i<t;i++){
		cin >> str;
		a = "";
		b = "";
		j = 1;
		// Read a
		while(true){
			if(str[j] != '+'){
				a += str[j];
				j++;
			}
			else{
				j++;
				break;
			}
		}
		// Read b
		while(str[j] != ')'){
			b += str[j];
			j++;
		}
		// Read degree
		n = str.substr(j+2, str.length());
		deg = stoi(n);
		
		// Output
		if (deg == 1){
			cout << "Case " << i+1 << ": " << a << "+" << b << endl;
			continue;
		}
		else if (deg == 2){
			cout << "Case " << i+1 << ": " << a << "^2+2*" << a << "*" << b << "+" << b << "^2" << endl;
			continue;
		}
		cout << "Case " << i+1 << ": " << a << "^" << deg;
		cout << "+" <<  deg << "*" << a << "^" << deg-1 << "*" << b;
		for (ll k = 2; k < deg-1; k++){
			cout << "+" << combination(deg, k) << "*" << a << "^" << deg-k << "*" << b << "^" << k;
		}
		cout << "+" << deg << "*" << a << "*" << b << "^" << deg-1;
		cout << "+" << b << "^" << deg << endl;

	}



	return 0;
}