
/* kattis problem: <sibice>
 *
 * Topic: trivial
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Check if matches can fit in bottom of box
 *
 * Solution Summary:
 *
 *   trivial
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
#include <cmath>

using namespace std;

int main(){
	double n, w, h, tmp;
	cin >> n >> w >> h;

	double m = sqrt(w*w+h*h);
	while(n--){
		cin >> tmp;
		cout << (tmp<=m?"DA":"NE") << endl;
	}
}