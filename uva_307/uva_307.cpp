
/* UVa problem: <307>
 *
 * Topic: backtracking
 *
 * Level: hallenging
 * 
 * Brief problem description: 
 *
 *   George took sticks of the same length and cut them randomly until all parts became at most 50 units
long. Now he wants to return sticks to the original state, but he forgot how many sticks he had originally
and how long they were originally. Please help him and design a program which computes the smallest
possible original length of those sticks. All lengths expressed in units are integers greater than zero.
 *
 * Solution Summary:
 *		Backtracking. Try all length combination
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

#define MAX_N 500


int n, this_sum, length, this_max, i, local_sum;
int sticks[MAX_N];
bool seen[MAX_N];

// Need this to avoid TLE
bool cmp(const int& a, const int& b){
    return a>b;
}

// Backtracking combinations
int backtrack(int x, int l, int a){
	if (x==local_sum){return 1;}
	for(int j=a; j<n;j++){
		if(!seen[j] && !(j && !seen[j-1] && sticks[j]==sticks[j-1])){
			if(l+sticks[j]==length){
				seen[j] = 1;
				if(backtrack(x+1,0,0)){
					return 1;
				}else{
					seen[j] = false;
					return false;		
				}
			}
			else if (l+sticks[j]<length){
				seen[j] = 1;
				if(backtrack(x, l+sticks[j], j+1)){
					return 1;
				}
				else{
					seen[j] = 0;
					if(l==0){
						return 0;
					}
				}
			}
		}
	}
	return 0;
}


int main(){
	
	while(true){
		cin >> n;
		if(n==0){return 0;}
		this_max = 0;
		this_sum = 0;
		for(i=0;i<n;i++){
			cin >> sticks[i];
			//this_max = max(this_max, sticks[i]);
			this_sum += sticks[i];
		}
		sort(sticks, sticks+n, cmp);

		for (i=sticks[0]; i<=this_sum; i++){
			if(this_sum%i){continue;}
			length = i;
			local_sum = this_sum/i;
			memset(seen, 0, sizeof(seen));
			if(backtrack(0,0,0)){break;}
		}


		cout << length << endl;

	}

	return 0;
}