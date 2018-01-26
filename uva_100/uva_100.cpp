/*
* Created by Steven Weikai Lu on 2018/01/15
* 
* UVa problem: <100>
*
* Topic: arithmetic
*
* Level: challenging
* 
* Brief problem description: 
* 	Consider following procedure
* 	input n
* 	print n
* 	if n = 1 then STOP
* 	if n is odd then n ←− 3n + 1
* 	else n ←− n/2 GOTO 2
* 
*	The input will consist of a series of pairs of integers i and j, one pair of integers per line.
*	All integers will be less than 10,000 and greater than 0.
*	You should process all pairs of integers and for each pair determine the maximum cycle length over all integers between and including i and j.
*
* Solution Summary:
* - Natively go into loop and count cycles, surprisingly passed..
*
* Used Resources:
* -StackOverflow
*
* I hereby certify that I have produced the following solution myself
* using only the resources listed above in accordance with the CMPUT
* 403 collaboration policy.
*
* --------------------- (Steven Weikai Lu)
*/
#include <iostream>
#include <algorithm>

using namespace std;



int main(){
	int it, k, i, j, max_cycle, cycle, i_orignial, j_original;
	while(cin >> i){
		cin >> j;
		// find the smaller and larger integer
		i_orignial = i;
		j_original = j;
		if (i > j){
			swap(i,j);
		}

		// Go through cycles and count
		max_cycle = 0;
		for(it = i; it<=j; it++){
			k = it;
			cycle = 1;
			while(k != 1){
				if (k % 2 == 1){
					k = 3*k+1;
				}
				else{
					k = k / 2;
				}
				cycle += 1;
			}

			max_cycle = max(max_cycle, cycle);
		}
		cout << i_orignial << " " << j_original << " " << max_cycle << endl;
	}
	return(0);
}