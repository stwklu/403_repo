
/* UVa problem: <10622>
 *
 * Topic: arithmetic
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   Find the max p for x such that x = b^p
 *
 * Solution Summary:
 *
 *   Iterate through all possible estimate. Use fast power to avoid TLE
 *
 * Used Resources:
 *
 *   StackOverflow
 *   Competitive Programming 3: Steven Halim, Felix Halim
 *	 eeksforgeeks.org
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

#define MAX_X 50010
#define EPS 0.01

typedef long long ll;

// Reference: geeksforgeeks.org
/* Iterative Function to calculate (x^y) in O(log y) */
int power(int x, int y)
{
    int res = 1;     // Initialize result
  
    while (y > 0){
        // If y is odd, multiply x with result
        if (y & 1)
            res = res*x;
        // n must be even now
        y = y>>1; // y = y/2
        x = x*x;  // Change x to x^2
    }
    return res;
}


int main(){

	int x, p;
	while(true){
		cin >> x;
		if(!x){break;}

		int succ = false;
		for(int b=2; b<MAX_X; b++){ // Try all possible b, p
			p = (log10(fabs(x))/log10(b)) + EPS;	// Estimate
			if (power(b,p)==x || power(-b,p)==x){ // Validate
				//cout << x << " " << p << " " << p << endl;
				succ = true;
				break;
			}
		}
		if(!succ){p=1;}

		cout << p << endl;

	}

	return 0;
}