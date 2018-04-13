
/* UVa problem: <11330>
 *
 * Topic: combinatoric
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Given a set of pair of shoes, find the minimum swap that they all match
 *
 * Solution Summary:
 *
 *   Greedy algorithm. Only swap the shoes with correct color
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

#define MAX_N 10100


int l[MAX_N];
int r[MAX_N];
int color_l[MAX_N];
int color_r[MAX_N];

int main(){

	int t, n, move, temp;
	cin >> t;
	while(t--){
		cin >> n;
		move = 0;
		memset(l, 0, sizeof(l));
		memset(r, 0, sizeof(r));
		memset(color_l, 0, sizeof(color_l));
		memset(color_r, 0, sizeof(color_r));
		for (int i=0;i<n;i++){
			cin >> color_l[i] >> color_r[i];
			l[color_l[i]] = i;
			r[color_r[i]] = i;
			//cout << color_l[i] << " " << color_r[i] << endl;
		}

		// Greedy
		for(int i=0; i<MAX_N;i++){
			if(l[i]==r[i]){continue;}
			temp = l[i];
			color_l[temp] = color_l[r[i]];
			l[color_l[r[i]]] = temp;
			move++;
		}

		cout << move << endl;

	}

	return 0;
}