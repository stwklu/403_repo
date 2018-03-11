/* UVa problem: <701>
 *
 * Topic: arithmetic
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   Given a number, find a power of 2 that start with those number and strictly twice longer than that number
 *
 * Solution Summary:
 *
 *   Using power of 10 to bound the desired power.
 			// To avoid overflow: 
			//  	log(a^b) = b*log(a)
			// 		log(a*b) = log(a) + log(b)
 *
 * Used Resources:
 *
 *   StackOverflow,
 // https://www.johndcook.com/blog/2017/06/20/leading-digits-of-powers-of-2/
 * 
 * Collaborator: Wyatt Praharenka
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
#include <cmath>
#include <cstdlib>

using namespace std;

double _log102 = log(10)/log(2);
double _log2 = log(2);

int main(){

	string n;
	double d, low, high;
	int length;
	long out;
	while(cin >> n){
		d = stod(n);
		length = n.length() + 1;
		while (true){
			// To avoid overflow: 
			//  	log(a^b) = b*log(a)
			// 		log(a*b) = log(a) + log(b)
			low = log(d)/_log2 + length*_log102;
			high = log(d+1)/_log2 + length*_log102;
			//cout << low << " " << high << endl;
			if((int)low < (int)high){
				break;
			}
			length++;
		}
		//cout << "Final: " << low << " " << high << endl;
		out = long(ceil(low));
		cout << out << endl;

	}

	return 0;
}