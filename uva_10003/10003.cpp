/* UVa problem: <10003>
 *
 * Topic: Dynamic Programming
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 * Input:
 * The input will consist of several input cases.
 * The first line of each test case will contain a positive number l that represents the length of the stick to be cut.
 * You can assume l < 1000. The next line will contain the number n (n < 50) of cuts to be made.
 * The next line consists of n positive numbers ci (0 < ci < l) representing the places where the cuts have to be done, given in strictly increasing order.
 * An input case with l = 0 will represent the end of the input.
 *
 * Output:
 * You have to print the cost of the optimal solution of the cutting problem, that is the minimum cost of cutting the given stick. Format the output as shown below.
 *
 * Solution Summary:
 *
 *   Dynamic Programming
 * Used Resources:
 *
 *   ...
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
#include <vector>
#include <map>

using namespace std;

// Recursion function
// Return the minimum cost to cut between left and right
int cut(int left, int right, vector<int> &points, map<pair<int, int>, int> &table){
	// Base cases
	if (left+1 == right){
		return(0);
	}

	// Check dynamic programming table
	int cost = table[make_pair(left, right)];
	if (cost){
		return cost;
	}

	// Recursive case
	cost = 99999999;
	for (int i = left+1; i<right; i++){
		cost = min(cost, cut(left, i, points, table) + cut(i, right, points, table) + points[right] - points[left]);
	}
	table[make_pair(left, right)] = cost;

	return cost;

}


int main(){

	while(true){
		int l, n, c;
		cin >> l;
		if (l == 0){break;}
		cin >> n;
		vector<int> points(n+2);
		map<pair<int, int>, int> table;

		points[0] = 0;
		points[n+1] = l;
		for (int i=1; i < n+1; i++){
			cin >> c;
			points[i] = c;
		}
		

		cout << "The minimum cutting is " << cut(0,n+1, points, table) << "." << endl;
	}


	return(0);
}