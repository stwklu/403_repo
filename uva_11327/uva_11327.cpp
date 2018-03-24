/* UVa problem: <11327>
 *
 * Topic: number theory
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Consider the following method of enumerating all rational numbers be-
tween 0 and 1 (inclusively).
for d = 1 to infinity do
  for n = 0 to d do
    if gcd(n,d) = 1 then print n/d
where gcd(n, d) is the greatest common divisor of n and d. For example, the start of the sequence looks like:
0/1, 1/1, 1/2, 1/3, 2/3, 1/4, 3/4, 1/5, 2/5, 3/5, 4/5, 1/6, 5/6, 1/7, . . .


	Find the k-th element in this sequence
 *
 * Solution Summary:
 *
 *  1. Use EulerPhi to find the number of fractions before using some denominator d.
 *	2. Search for numerator til reach number
 *
 *	Note: Calculate all primes from 0 to 20000 once. To save time for EulerPhi
 *
 * Used Resources:
 *
 *   StackOverflow, Quora, cplusplus
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
#include <cmath>

using namespace std;

#define ll unsigned long long

// Precompute primes range
const ll MAX_PRIME = 200000;

// Comopute all primes
int primes[MAX_PRIME];

// return the gcd of a and b
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Count the number of positive integers < n, and coprime with n
ll EulerPhi(ll n){

	ll PF_dix=0, PF = primes[PF_dix], ans = n;
	while(PF * PF <= n){
		if(n % PF == 0){
			ans -= ans/PF;
		}
		while (n % PF ==0){
			n /= PF;
		}
		PF = primes[++PF_dix];
	}
	if(n != 1){
		ans -= ans / n;
	}
	return ans;
}

// Generate all primes from 2 to MAX_PRIME
void all_primes(){
	primes[0] = 2;
	primes[1] = 3;
	int idx = 2;
	for (int i=2; i<MAX_PRIME; i++){
	    for (int j=2; j*j<=i; j++){
	        if (i % j == 0) 
	            break;
	        else if (j+1 > sqrt(i)) {
	            primes[idx++] = i;
	        }

	    }  
	}
}


int main(){

	ll k;

	all_primes();

	while(true){
		// Read input
		cin >> k;
		if (k==0){break;}
		if (k==1){
			cout << "0/1" << endl;
			continue;
		}

		// Find denominaor
		ll n=1, denominator=1, temp=0;
		while(n+temp<k){ // Check if number of fraction exceed k
			n += temp;
			temp = EulerPhi(denominator++);
		}
		denominator -= 1;


		//cout << "denominator, n: " << " " << denominator << " " << n << " " << endl;
		
		ll i=0, numarator;
		for(numarator=1; i+n < k;numarator++){
			if(gcd(numarator,denominator)==1){
				i++;
			}
		}

		cout << numarator-1 << "/" << denominator << endl;

		//cout << "i, denominator, n, k: " << i << " " << denominator << " " << n << " " << k << endl;


	}

	return 0;
}















