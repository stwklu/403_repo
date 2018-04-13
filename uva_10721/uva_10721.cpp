
/* UVa problem: <10721>
 *
 * Topic: Dynamic Programming
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   BC(n, k, m) is the set of all symbols with
k bars that together extend over exactly n units, each bar being at
most m units wide

	Find total number of symbols classified BC(n, k, m)
 *
 * Solution Summary:
 *
 *   Dynamic programming: Pascal's Theorem BC(n, m) = BC(n-1, m) + BC(n-1, m-1)
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
#include <algorithm>


using namespace std;

#define MAX_N 52

typedef long long ll;

ll bc[MAX_N][MAX_N];


int main(){

	int n,k,m;
	while(cin >> n >> k >> m){
		memset(bc, 0, sizeof(bc));
		bc[0][0] = 1;
		for (int i=1; i<=n; i++){	// n
			for (int j=1; j<=k; j++){	// k
				for(int l=1; l<=min(m, i); l++){
					bc[i][j] += bc[i-l][j-1];
				}
			}
		}

		cout << bc[n][k] << endl;
	}

	return 0;
} 