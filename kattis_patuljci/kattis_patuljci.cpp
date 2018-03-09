/* kattis problem: <patuljci>
 *
 * Topic: others
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Given 9 int, pick 7 that sums up to 100
 *
 * Solution Summary:
 *
 *   Brute Force
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


using namespace std;


int main(){

	int ds[9], d, sum=0;
	for(int i=0;i<9;i++){
		cin >> d;
		sum += d;
		ds[i] = d;
	}

	for(int i=0;i<9;i++){
		for (int j=i+1;j<9;j++){
			if (sum - ds[i] - ds[j] == 100){
				for(int k=0; k<9; k++){
					if ((k!=i) && (k!=j)){
						cout << ds[k] << endl;
					}
				}
				return 0;
			}
		}
	}

	return 0;
}