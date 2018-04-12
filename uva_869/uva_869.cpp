
/* UVa problem: <869>
 *
 * Topic: Graph Algorithm
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Given two sets of airline, determine if they are equivalent if transition considered
 *
 * Solution Summary:
 *
 *   Place is vertex, airline is edge. Use Floyd Warshall algorithm to build a graph. See if identical.
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
#include <vector>

using namespace std;

#define MAX_N 30

int main(){

	int t,n,m;
	char a,b;
	cin >> t;
	while(t--){
		vector<vector<bool>> com_1(MAX_N, vector<bool>(MAX_N, 0));
		vector<vector<bool>> com_2(MAX_N, vector<bool>(MAX_N, 0));
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> a >> b;
			com_1[int(a-'A')][int(b-'A')] = 1;
			//cout << "C1: a,b," << a << " " << b << " " << int(a-'A') << " " << int(b-'A') << endl;
		}
		cin >> m;
		for(int i=0;i<m;i++){
			cin >> a >> b;
			com_2[int(a-'A')][int(b-'A')] = 1;
			//cout << "C2: a,b," << a << b << int(a-'A') << int(b-'A') << endl;
		}

		//cout << "Done reading" << endl;

		// Connect all flights
		// Floyd Warshall
		for(int k=0;k<MAX_N;k++){
			for(int i=0;i<MAX_N;i++){
				for(int j=0;j<MAX_N;j++){
					//cout << i << " " << j << " " << k << endl;
					if(com_1[i][k] && com_1[k][j]){com_1[i][j]=1;}
					if(com_2[i][k] && com_2[k][j]){com_2[i][j]=1;}
				}
			}
		}

		//cout << "Done connecting" << endl;

		// Validate
		bool same = true;
		for(int i=0;i<MAX_N;i++){
			for(int j=0;j<MAX_N;j++){
				//cout << i << " " << j << " " << com_1[i][j] << " " <<  com_2[i][j] << endl;
				if(com_1[i][j] != com_2[i][j]){same=false;}
			}
		}
		cout << (same?"YES":"NO") << endl;
		if(t){cout << endl;}
	}

	return 0;
}