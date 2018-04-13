
/* UVa problem: <674>
 *
 * Topic: Dynamic Programming
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Given coin[5] = {1,5,10,25,50}, find how many ways can make up one amount
 *
 * Solution Summary:
 *
 *   Use DP to precompute all values
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

#define MAX_N 7500

int coin[5] = {1,5,10,25,50};
int amount[MAX_N];
int n, ans;


int main(){

	// Precompute all 
	fill(amount, amount+MAX_N, 1);

	for(int i=1; i<5; i++){
		for(int j=1;j<MAX_N;j++){
			if(j>=coin[i]){
				amount[j] += amount[j-coin[i]]; // total of 5 recurrence outcome
			}
		}
	}

	// Directly output
	while(cin >> n){
		cout << amount[n] << endl;
	}

	return 0;
}