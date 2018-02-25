/* UVa problem: <111>
 *
 * Topic: String
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   Given the correct chronological order of n events 1,2,...,n as c1,c2,...cn where 1 ≤ ci ≤ n denotes the ranking of event i in the correct chronological order and a sequence of student responses r1, r2, . . . , rn where 1 ≤ ri ≤ n denotes the chronological rank given by the student to event i; determine the length of the longest (not necessarily contiguous) sequence of events in the student responses that are in the correct chronological order relative to each other.
 *
 * Solution Summary:
 *
 *  Convert the problem into Longest increasing subsequence.
 *	Solve by DP.
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


// Longest increasing subsequence

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_SEQ 21

int correct[MAX_SEQ];
int student[MAX_SEQ];
int dp[MAX_SEQ];
int n;

// Find the LIS by DP
int LIS(){
	memset(dp, 0, sizeof(dp));
	dp[1] = 1;
	student[0] = 0;
	int output = 0;

	for (int i=2; i<=n; i++){
		for (int j=0; j < i; j++){
			if (student[i] > student[j]){
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
	}

	for (int i=1; i<=n; i++){
		output = max(output, dp[i]);
	}

	return output;

}


int main(){
	
	// cin correct rank
	int temp, output;
	cin >> n;
	for (int i=1; i<n+1; i++) {
		cin >> temp;
		correct[i] = temp;
	}

	// cin student rank
	while(true){
		memset(student, 0, sizeof(student));
		for (int i=1; i<n+1; i++){
			if (!(cin >> temp)){
				return 0;
			}
			else{
				//cout << temp << " ";
				student[temp] = correct[i]; // index of correct event index
			}
		}

		/*
		cout << endl << "student rank: ";
		for (int i=0; i < n+1; i++){
			cout << student[i] << " ";
		}
		cout << endl;
		*/

		// Find the LIS
		output = LIS();

		cout << output << endl;

	}

	return 0;
}