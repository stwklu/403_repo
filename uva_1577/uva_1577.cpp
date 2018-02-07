/* UVa problem: <1577>
 *
 * Topic: sorting
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   You have a stockpile of 2nk batteries that you want to assign to the chips. It might not be possible to allocate the batteries so that in every machine both chips have equal power outputs, but you want to allocate them so that the differences are as small as possible. To be precise, you want to tell your customers that in all machines the difference of power outputs of the two chips is at most d, and you want to make d as small as possible. To do this you must determine an optimal allocation of the batteries to the machines.
 *
 * Solution Summary:
 *
 *   Binary Search, Greedy
 *
 * Used Resources:
 *
 *   ...
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *
 * --------------------- (Steven Weikai Lu)
 */
#include <iostream>
#include <algorithm>

#define INF 1<<30
using namespace std;
typedef long long ll;


int main(){

	ll n;
	while(cin >> n){
		// read input
		ll k, len;
		cin >> k;
		len = 2 * n * k;
		int bs[len];
		for (int i=0; i < len; i++){
			cin >> bs[i];
		}

		sort(bs, bs+len);

		// Binary Search
		ll left = bs[1] - bs[0];
		ll right = bs[len-1] - bs[0];
		ll d = INF;
		while(left <= right){
			ll mid = (left + right) / 2;
			ll count = 0;
			ll taken = 0;
			// Count 
			for (int i=0; i < len-1; i++){
				if (bs[i+1] - bs[i] <= mid){
					count++;
					taken += 2;
					i++;
				}
				else{
					taken++;
				}
				if (taken > 2*count*k || count==n ){break;}
			}

			// Satisfied, keep looking for smaller
			if (count==n){
				d = min(d, mid);
				right = mid - 1;
			}
			else{
				left = mid + 1;
			}
		}

		cout << d << endl;

		
	}


	return(0);
}