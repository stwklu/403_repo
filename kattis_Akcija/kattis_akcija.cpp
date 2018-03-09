/* kattis problem: <akcija>
 *
 * Topic: sorting
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Input
The first line of input contains the integer N (1≤N≤100 000), the number of books the customer bought. Each of the following N lines contains a single integer Ci (1≤Ci≤100 000), the price of each book.

Output
The first and only line of output must contain the required minimal price.
 *
 * Solution Summary:
 *
 *   sort the price and group books into 3
 *
 * Used Resources:
 *
 *   StackOverflow
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


int main(){

	int n, b, price=0;
	cin >> n;
	int bks[n];
	for(int i=0;i<n;i++){
		cin >> b;
		bks[i] = b;
	}

	sort(bks, bks+n);

	int n_round = n % 3;
	for(int i=0;i<n_round;i++){
		price += bks[i];
	}

	for (int i=n_round;i<n-2;i+=3){
		price += bks[i+1];
		price += bks[i+2];
	}

	cout << price;


	return 0;
}