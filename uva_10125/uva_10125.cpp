
/* UVa problem: <10125>
 *
 * Topic: number theory
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   Given S, a set of integers, find the largest d such that a + b + c = d
 *	 where a, b, c, and d are distinct elements of S.
 *
 * Solution Summary:
 *
 *   Pure Brute Force, didn't expect to get accepted...
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
#include <algorithm>

using namespace std;

#define NO_SOLU 536870999

int n, temp, a,b,c,d;

int find(int s[], int n){
	for(d=n-1; d>=0; d--){
		for(a=0; a<n; a++){
			for(b=a+1;b<n;b++){
				for(c=b+1;c<n;c++){
					if((s[d]==s[a]+s[b]+s[c]) && a!=d && b!=d && c!=d){
						return s[d];
					}
				}
			}
		}
	}
	return NO_SOLU;
}

int main(){

	
	while(true){
		cin >> n;
		if(!(n)){break;}
		int s[n];
		for(int i=0;i<n;i++){
			cin >> s[i];
		}
		sort(s, s+n);

		d = find(s, n);

		cout << (d==NO_SOLU?"no solution":to_string(d)) << endl;

	}


	return 0;
}