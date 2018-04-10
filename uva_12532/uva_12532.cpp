
/* UVa problem: <12532>
 *
 * Topic: data structure
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Given an array of integer and some command allowing changes to the array element
 *		Return if product within a range is 0, positive or negative upon query in real time
 *		
 *
 * Solution Summary:
 *		Use 2 Fenwick trees to represent negative values and zero values in array since those are the only things matter
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
#include <cstdio>
#include <vector>

using namespace std;

int arr[100000];


class BI_tree{
public:
	BI_tree(int n);
	BI_tree(int *arr, int n);
	~BI_tree();
	void update(int idx, int val);
	int getSum(int idx);
	int getSum(int idx1, int idx2);
	void visualize();
private:
	int* tree;
	int size;
};

// Default constructor
// Initialize a BI tree of n element to zero
BI_tree::BI_tree(int n){
	size = n;
	tree = new int[size+1];
	fill_n(tree, size+1, 0);
}

// Initialize a BI tree of elements in a given array
BI_tree::BI_tree(int *arr, int n){
	size = n;
	tree = new int[size+1];
	fill_n(tree, size+1, 0);

	// Update each value
	for (int i=0; i<size; i++){
		update(i+1, arr[i]);
	}
}

// Destructor
BI_tree::~BI_tree(){
	delete [] tree;
}

// Update node in BI tree at a given index
// Given val is added to i-th element and all of its ancester
void BI_tree::update(int idx, int val){

	// Traverse all ancestors and add 'val'
	for(;idx <= size; idx += idx & (-idx)){
		tree[idx] += val; // Current node
		 // update index to parent
	}
}

// Return sum of arr[0...idx]
int BI_tree::getSum(int idx){
	int sum = 0;

	// Traverse all ancesters
	for(;idx; idx -= idx & (-idx)){
		sum += tree[idx];
	}
	return sum;
}

// Return sum of elements in range [idx1, idx2]
int BI_tree::getSum(int idx1, int idx2){
	return getSum(idx2) - (idx1 == 1 ? 0 : getSum(idx1 - 1));
}

// Print size and tree
void BI_tree::visualize(){

	cout << "size: " << size << endl << "elements: ";

	for(int i=0; i < size+1; i++){
		cout << tree[i] << " ";
	}
	cout << endl;
}




int main(){

	int n, k, a, b;
	char q;
	while(cin >> n >> k){
		// Read input
		// Keep record of zero and negative values in array
		BI_tree zero = BI_tree(n);
		BI_tree neg = BI_tree(n);
		for(int i=1;i<=n;i++){
			cin >> arr[i];
			if(arr[i] < 0){
				neg.update(i,1);
			}
			else if(arr[i] == 0){
				zero.update(i,1);
			}
		}

		while(k--){
			cin >> q >> a >> b;
			if(q == 'C'){
				// Changeing negative values
				if((arr[a] >= 0 && b < 0)||(arr[a] < 0 && b >= 0)){neg.update(a, 1);}
				// Changing zero values
				if(arr[a] != 0 && b == 0){zero.update(a,1);}
				else if (arr[a]==0 && b != 0){zero.update(a,-1);}
				arr[a] = b;
			}

			else if (q=='P'){
				// Zero if there is any zero in range
				if(zero.getSum(a,b)){cout << "0";}
				// Negative if there are odd number of negative number in range
				else if(neg.getSum(a, b) % 2 == 0){cout << "+";}
				else{cout << "-";}
			}
		}
		cout << endl;
	}

	return 0;
}



















