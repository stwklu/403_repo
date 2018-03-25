/* UVa problem: <10327>
 *
 * Topic: sorting
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   output number of swapping two element to sort an array, assuming knowing correct order.
 *
 * Solution Summary:
 *
 *   It is exactly like counting number of key-comparison in insertion sort
 *	 For each i element in array, number of swap = number of element preceeding i that is larger than i.
 *
 * Used Resources:
 *
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


using namespace std;


int main(){

	int n, tmp, num;
	while(cin >> n){
		int arr[n];
		for(int i=0; i<n; i++){
			cin >> tmp;
			arr[i] = tmp;
		}

		num = 0;

		for(int i=0;i<n;i++){
			for(int j=0; j<i; j++){
				if(arr[j]>arr[i]){
					num++;
				}
			}
		}

		cout << "Minimum exchange operations : " << num << endl;
	}


	return 0;
}