/* UVa problem: <1753>
 *
 * Topic: Arithmetic
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 * INPUT:
 *  - The input file contains several test cases, each of them as described below.
 *  - The first line of input contains two integers n (1 ≤ n ≤ 1000), the number of sections in Sheila’s journey
 *  - and t (1 ≤ t ≤ 106), the total time.
 *  - This is followed by n lines, each describing one segment of Sheila’s journey.
 *  - The i-th of these lines contains two integers di (1 ≤ di ≤ 1000) and si (|si| ≤ 1000), the distance and speedometer reading for the i-th segment of the journey.
 *  - Time is speci ed in hours, distance in miles, and speed in miles per hour.
 *
 * OUTPUT: 
 *  - For each test case, on a line by itself, display the constant c in miles per hour.
 *  - Your answer should have an absolute or relative error of less than 10−6.
 *
 * Solution Summary:
 *
 *   Binary Search
 *
 * Used Resources:
 *
 *   StackOverflow, cplusplus
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *
 * --------------------- (Steven Weikai Lu)
 */

#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){

	std::cout << std::fixed;
    std::cout << std::setprecision(7);

	int n;
		
	while(cin >> n){
		double t;
		double min_s = 99999;
		cin >> t;

		double distance[n];
		double speed[n];
		double d, s;
		double c, old_c = 0;
		for (int i = 0 ; i < n ; i++){
			cin >> d >> s;
			distance[i] = d;
			speed[i] = s;
			c += (d/s)/n;
			min_s = min(s, min_s);
		}

		// Binary Search
		double left, right, t_hat;
		left = -min_s;
		right = pow(10,6)+1001;
		double threshold = pow(10,-7);

		do{
			old_c = c;
			c = (left + right) / 2;

			t_hat = 0;
			for (int i=0;i<n;i++){
				t_hat += (distance[i] / (speed[i] + c));
			}

			if (t_hat > t){ // C is too small
				left = c;
			} 
			else{ // C is too big
				right = c;
			}

			//cout << "c, old_c: " << c << " " << old_c << " t_hat: "  << t_hat << endl;

		}
		while( abs(old_c - c) > threshold);

		cout << c << endl;

	}


	return(0);
}