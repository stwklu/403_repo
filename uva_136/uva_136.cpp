/* UVa problem: <136>
 *
 * Topic: Dynamic Programming
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   Ugly numbers are numbers whose only prime factors are 2, 3 or 5.
 * 	 find and print the 1500’th ugly number.
 *
 * Solution Summary:
 *
 *   Dynamic Programming. Keep pointer for 2, 3, 5 that point to the last ugly number that product of that ugly number and pointer is just over n-1 ugly number.
 *	 So each recursion we only search for a small amunt of candidate and skip useless step.
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

#define MAX_NUM 1500
#define ll unsigned long long

ll ugly[MAX_NUM+100];

int main(){

	ugly[1] = 1;
	ll p2=1, p3=1, p5=1;

	for (int i=2;i<MAX_NUM+1;i++){
		while(2 * ugly[p2] <= ugly[i-1]){
			p2++;
		}
		while(3 * ugly[p3] <= ugly[i-1]){
			p3++;
		}
		while(5 * ugly[p5] <= ugly[i-1]){
			p5++;
		}

		ugly[i] = min(min(2 * ugly[p2], 3 * ugly[p3]), 5 * ugly[p5]);

	}

	cout << "The 1500'th ugly number is " <<  ugly[MAX_NUM] << "." << endl;


	return 0;
}