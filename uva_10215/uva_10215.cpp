
/* UVa problem: <10215>
 *
 * Topic: Artithmetic
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   Given a box of set width and length, find the height x that it can be cut and foled into box with max/min volume
 *
 * Solution Summary:
 *
 *   Use direct formula.
 *   min x is trivial, eithr 0 or min(width, length)
 *   To find max, minimize the objective function -(w-2x)*(l-2x)*x
 *	 luclily we can find the inverse of this and the root:
 *		(l + w - sqrt(l*l - l*w +w*w)) / 6    for max volume
 *      (l + w + sqrt(l*l - l*w +w*w)) / 6    for min volume
 *
 * Used Resources:
 *
 *   StackOverflow
 *   Competitive Programming 3: Steven Halim, Felix Halim
 *
 * Collaborator:
 *		Wyatt Praharenka
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

const double EPS = 1e-8;


int main(){

	cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	cout.precision(3);

	double l,w,x;


	while(cin >> l >> w){

		x = (l + w - sqrt(l*l - l*w +w*w)) / 6;

		cout << x+EPS << " 0.000 " << min(l,w)/2 + EPS << endl;

	}

	return 0;
}