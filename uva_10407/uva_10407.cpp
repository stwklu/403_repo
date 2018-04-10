
/* UVa problem: <10407>
 *
 * Topic: number theory
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   Find the largest divisor that produce same remainder for a set of integer
 *
 * Solution Summary:
 *
 *   If a mod d = r, b mod d = r, then b-a mod d = 0, namely the gcd
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
#include <cstring>
#include <cmath>

using namespace std;


int gcd(int a, int b){
	while (b){
		a = a%b;
		swap(a,b);
	}
	return a;
}


int main(){

	int n[1100], i, d, count, diff;
	while(true){
		memset(n, 0, sizeof(n));
		cin >> n[0];
		if(n[0]==0){return 0;}
		count = 1;

		while(true){
			cin >> n[count];
			if(n[count]==0){break;}
			count++;
		}

		d = 0;
		for(int i=0; i < count-1; i++){
			d = gcd(d, n[i+1]-n[i]);
		}
		d = abs(d);
		cout << d << endl;

	}


	return 0;
}