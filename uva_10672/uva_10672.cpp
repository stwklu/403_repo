
/* UVa problem: <10672>
 *
 * Topic: Graph Traversal
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Given n nodes with k marbles in graph, find operation(move one marble to adjacent node) needed so each node has exactly one marble
 *
 * Solution Summary:
 *
 *   Number of bypass marbles is just the number of lack/excessive marble of children
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
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

#define MAX_N 100000

struct node{
	int number;
	vector<int> child;
};

node tree[MAX_N];
int used[MAX_N];
long long ans;

int traverse(int x){
	used[x] = 1;
	int count = 0;
	// Find the number of lack/excessive in children
	for(auto c : tree[x].child){
		if(!used[c]){
			count += traverse(c);
			tree[x].number += tree[c].number;
		}
	}
	count++;
	ans += abs(tree[x].number-count);
	return count;
}


int main(){
	int n, v, m, d, c;
	while(true){
		cin >> n;
		if(n==0){return 0;}
		memset(tree, 0, sizeof(tree));
		memset(used, 0, sizeof(used));
		for(int i=0;i<n;i++){
			cin >> v >> m >> d;
			tree[v].number = m;
			while(d--){
				cin >> c;
				tree[v].child.push_back(c);
				tree[c].child.push_back(v);
			}
		}
		ans=0;
		traverse(1);
		cout << ans << endl;
	}


	return 0;
}