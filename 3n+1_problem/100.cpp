/*
Created by Steven Weikai Lu on 2018/01/15

https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=36
solving rate: 73.17%
*/
#include <iostream>
#include <algorithm>

using namespace std;



int main(){
	int it, k, i, j, max_cycle, cycle, i_orignial, j_original;
	while(cin >> i){
		cin >> j;
		i_orignial = i;
		j_original = j;
		if (i > j){
			swap(i,j);
		}

		// For each i, j
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