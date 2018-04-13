
/* UVa problem: <10026>
 *
 * Topic: sorting
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Given a set of task of time and fine, find the least fine management.
 *
 * Solution Summary:
 *
 *   Only the relative ratio of fine and time matters. Sort by this.
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
#include <cstring>

using namespace std;

#define MAX_N 1050



struct TASK{
	double ft_ratio; // Ratio of f per t
	int id;
};

bool cmp(TASK a, TASK b){
	return a.ft_ratio > b.ft_ratio;
}

int main(){

	int tc, n;
	cin >> tc;
	while(tc--){
		cin >> n;
		int t[MAX_N];
		int f[MAX_N];
		TASK tasks[MAX_N];
		memset(t,0,sizeof(t));
		memset(f,0,sizeof(f));
		memset(tasks,0,sizeof(tasks));
		for (int i=0; i<n; i++){
			cin >> t[i] >> f[i];
			tasks[i].ft_ratio = 1.0*f[i] / t[i];
			tasks[i].id = i;
		}

		sort(tasks, tasks+n, cmp);

		cout << tasks[0].id+1;
		for(int i=1; i<n;i++){
			cout << " " << tasks[i].id+1;
		}
		cout << endl;
		if(tc){
			cout << endl;
		}

	}

	return 0;
}