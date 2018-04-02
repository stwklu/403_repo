
/* UVa problem: <105>
 *
 * Topic: other
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   Consider a 2d point of view, given set of buildings (L, H, R) where 
 *		building has height H on y-coord from l to r on x-coord. 
 * 		Output the 2d sketch of the skylines
 *
 * Solution Summary:
 *
 *   Use a static array to store discrete height. Output x and y when encounter different height.
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
#include <cstdlib>
#include <cmath>

using namespace std;

#define MAX_BUILDiNG 1000000


int main(){
	int l, h, r, max_r=-1, this_h;
	int skyline[MAX_BUILDiNG];

	memset(skyline, 0, sizeof(skyline));

	// Read buildings
	while(cin >> l >> h >> r){
		for(int i=l;i<r;i++){
			skyline[i] = max(skyline[i], h);
		}
		max_r = max(max_r, r);
	}

	// Start from 1
	for(int i=1; i < max_r; i++){
		if(skyline[i] != skyline[i-1]){
			cout << i << " " << skyline[i] << " ";
		}
	}

	cout << max_r << " 0" << endl;

	return 0;
}