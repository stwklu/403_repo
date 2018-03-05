/* UVa problem: <10137>
 *
 * Topic: other
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   Input
Standard input will contain the information for several trips. The information for each trip consists of
a line containing a positive integer, n, the number of students on the trip, followed by n lines of input,
each containing the amount, in dollars and cents, spent by a student. There are no more than 1000
students and no student spent more than $10,000.00. A single line containing 0 follows the information
for the last trip.
Output
For each trip, output a line stating the total amount of money, in dollars and cents, that must be
exchanged to equalize the students’ costs
 *
 * Solution Summary:
 *
 *   C++ STL, casting, precision handling
 *
 * Used Resources:
 *
 *   StackOverflow, udebug
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *
 * --------------------- (Steve Lu)
 */



#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

#define epsilon 1e-11


int main(){
	cout << fixed;
	cout << setprecision(2);
	int n;
	while(true){
		cin >> n;
		if (!n){
			return 0;
		}


		double x, avg=0.0,neg=0.0, pos=0.0;;
		double total[n];
		for(int i=0; i<n; i++){
			cin >> x;
			total[i] = x;
			avg += x ;
		}
		avg /= n;

		double diff;
		for(int i=0;i<n;i++){
			diff = total[i] - avg;
			diff = trunc(100 * diff) / 100;
			if (diff > 0){
				pos += diff;
			}
			else{
				neg += -diff;
			}
		}

		double out = max(pos, neg);
		cout << "$" << out << endl;
	}


	return 0;
}