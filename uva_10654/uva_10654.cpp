
/* UVa problem: <10654>
 *
 * Topic: Dynamic Programming
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   There are 3 stones deciding the outcome of 3 decision.
 *		Each priest voted in sequence by flipping at least and only one of three stones 
 *		Predict the outcome of 3 events given the voting order and their preference of the 2^3=8 possible outcome.
 *
 * Solution Summary:
 *
 *  Dynamic Programming from start to end. Recurrence: dp(order, outcome) = sum of dp(order-1, outcome)
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

#define MAX_N 105
#define MAX_OUT 8


int vote[MAX_N][MAX_OUT];
int pref[MAX_N][MAX_OUT];

int dp(int a, int b, int m){ // dp(order, preference)
	int tmp, tmp2, ans;
	if(a >= m) return b;
	if(vote[a][b] != -1) return vote[a][b];
	ans = -1;
	for(int i = 0;i < 3;i++){	// Iterate throught 8 possible outcome. Speed up with bit representation
		tmp = b^(1<<i);
		tmp2 = dp(a+1 , tmp, m); // Next round
		if(ans == -1){
			ans = tmp2;
		}
		if(pref[a][ans] > pref[a][tmp2]){
			ans = tmp2;
		}
	}
	vote[a][b] = ans;
	return ans;
}


int main(){
	int t, m;
	cin >> t;
	while(t--){
		memset(vote, 0, sizeof(vote));
		memset(pref, 0, sizeof(pref));
		for(int i = 0;i < MAX_N;i++){
			for(int j = 0;j < MAX_OUT;j++){
				vote[i][j] = -1;	// -1 means un-visited
				pref[i][j] = -1;
			}
		}
		cin >> m;
		for (int i=0; i<m; i++){
			for(int j=0; j<MAX_OUT;j++){
				cin >> pref[i][j];
			}
		}
		int ans = dp(0,0,m); // start from first round
		for(int i=2; i>=0; i--){
			cout << (ans&(1<<i)?"Y":"N");
		}
		cout << endl;
	}

	return 0;
}