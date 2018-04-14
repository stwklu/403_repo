
/* kattis problem: <filip>
 *
 * Topic: trivial
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Out put the max of the inverse of two numbers
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
#include <algorithm>
#include <cmath>


using namespace std;

int reverse(int x) {
    int res = 0, rem;
    while(x > 0) {
            rem = x % 10;
            x = x / 10;
            res = res * 10 + rem;
    }
    return res;
}

int main(){
	int a, b;
	cin >> a >> b;

	a = reverse(a);
	b = reverse(b);

	cout << max(a,b);

 return 0;
}