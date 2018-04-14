
/* kattis problem: <karte>
 *
 * Topic: data structure
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Given a string of card, determine how many of each kind missing, or if duplicate.
 *
 * Solution Summary:
 *
 *   Boolean array, counter
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
#include <string>
#include <set>
#include <cstring>

#define N_CARD 13

using namespace std;


int main(){
	string str;
	int n, p=N_CARD, k=N_CARD, h=N_CARD, t=N_CARD;
	cin >> str;

	bool P[N_CARD+1];
	bool K[N_CARD+1];
	bool H[N_CARD+1];
	bool T[N_CARD+1];

	memset(P, 0, sizeof(P));
	memset(K, 0, sizeof(K));
	memset(H, 0, sizeof(H));
	memset(T, 0, sizeof(T));

	for(int i=0; i<str.size()-2; i++){
		n = 10*(str[i+1]-'0') + (str[i+2]-'0');
		switch(str[i]){
			case 'P':
				if(P[n]){
					cout << "GRESKA";
					return 0;
				}
				P[n] = 1;
				p -= 1;
				break;
			case 'K':
				if(K[n]){
					cout << "GRESKA";
					return 0;
				}
				K[n] = 1;
				k -= 1;
				break;
			case 'H':
				if(H[n]){
					cout << "GRESKA";
					return 0;
				}
				H[n] = 1;
				h -= 1;
				break;
			case 'T':
				if(T[n]){
					cout << "GRESKA";
					return 0;
				}
				T[n] = 1;
				t -= 1;
				break;
		}
	}
	cout << p << " " << k << " " << h << " " << t;
 
	return 0;
}