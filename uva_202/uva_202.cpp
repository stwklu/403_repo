/* UVa problem: <202>
 *
 * Topic: Arithmetic
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   Write a program that reads numerators and denominators of fractions and determines their repeating cycles.
 *
 * Solution Summary:
 *
 *   long division
 *
 * Used Resources:
 *
 *   StackOverflow, Cplusplus
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

#define MAX_DECIMAL 50
#define MAX_RANGE 30001

int a, b, i, range, a_d, b_d;
int remainder[MAX_RANGE];
int quotient[MAX_RANGE];


int main(){

	while(cin >> a){
		cin >> b;
		a_d = a;
		b_d = b;

		memset(remainder, 0, sizeof(remainder));
		memset(quotient, 0, sizeof(quotient));


		// Long division til repeat
		a %= b;
		i = 1;
		while(a && !remainder[a]){
			remainder[a] = i;
			quotient[i] = (10*a) / b;
			a *= 10;
			a %= b;
			i++;
			//cout << a << " " << i << " " << (10*a) / b << (10*a) % b << endl;
		}

		// Output
		cout << a_d << "/" << b << " = " << a_d/b << ".";
		if(a){	// Have repetition
			int j;
			for(j=1; j < remainder[a]; j++){
				cout << quotient[j];
			}
			cout << "(";
			range = min(i, MAX_DECIMAL+1);
			for(int k=j; k<range; k++){
				cout << quotient[k];
			}
			string temp = range == i ? ")": "...)";
			cout << temp << endl;
		}
		else{ // No repetition
			for (int j=1; j < i; j++){
				cout << quotient[j];
			}
			cout << "(0)" << endl;
		}
		int rep = a? (i - remainder[a]):1;
		cout << "   " << rep << " = number of digits in repeating cycle" << endl << endl;

	}

	return 0;
}