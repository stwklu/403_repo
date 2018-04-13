
/* UVa problem: <10494>
 *
 * Topic: Combinatoric
 *
 * Level:  challenging
 * 
 * Brief problem description: 
 *
 *   Do integer division and mod for big numbers
 *
 * Solution Summary:
 *
 *   Long division. Keep updating quotient and remainder
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

using namespace std;


#define MAX_N 10010

int main(){

	long long quotient[MAX_N], idx, b, remainder, pt;
	char op, a[MAX_N];

	while(cin >> a >> op >> b){
		memset(quotient, 0, MAX_N);
		idx = 0;
		remainder = 0;
		for(int i=0; a[i]; i++){ // Long division
			remainder = remainder*10 + (a[i]-'0'); // Division digits one by one
			quotient[idx] = remainder / b; // quotient digit
			remainder = remainder % b;
			idx++;	// Length of number
		}
		/*
		for(int i=0; i<idx; i++){
			cout << quotient[i] << " ";
		}
		cout << endl;
		*/
		//cout << op << endl;
		if(op=='/'){
			pt = 0;
			while(true){ // Find the first non-zero digit
				if(pt >= idx || quotient[pt]!=0){break;}
				pt++;
			}
			if(pt == idx){cout << "0" << endl;} // Nominator is smaller than denominator
			else{
				while(true){
					if(pt >= idx){break;}
					cout << quotient[pt];
					pt++;
				}
				cout << endl;
			}
		}
		else{
			cout << remainder << endl;
		}


	}

	return 0;
}