/* UVa problem: <10608>
 *
 * Topic: Data Structures
 *
 * Level: challenging
 * 
 * Brief problem description: 
 * -There is a town with N citizens. It is known that some pairs of people are friends.
 * -According to the famous saying that “The friends of my friends are my friends, too” it follows that if A and B are friends and B and C are friends then A and C are friends, too.
 * -Task is to count how many people there are in the largest group of friends.
 *
 * Solution Summary:
 *  - Use a queue(vector) to store all the direct friends of a person.
 *  - Recursively search down a person's friends.
 *  - Once a friend is encountered this branch is pruned globally.
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
#include <vector>
#include <map>

using namespace std;

int search(int target, vector<vector<int>> &gangs, map<int, bool> &seen){
	if (seen[target]){return(0);}

	seen[target] = true;

	int total_gangs = gangs[target].size(), friends = 1;

	for (int i=0; i < total_gangs; i++){
		//cout << "total gangs: " << total_gangs << " current: " << i << endl;
		friends += search(gangs[target][i], gangs, seen);
	}

	return(friends);
}


int main(){
	int t;
	cin >> t;
	while(t--){
		int N, M, max_gang = 1;
		map<int, bool> seen;
		vector<vector<int>> gangs;
		cin >> N >> M;

		N++;

		for (int i=0; i < N; i++){
			seen[i] = false;
			gangs.push_back(vector<int>());
		}

		//cout << "initializing pass" << endl;

		while(M--){
			int guy1, guy2;
			cin >> guy1 >> guy2;
			gangs[guy1].push_back(guy2);
			gangs[guy2].push_back(guy1);
		}

		//cout << "add friends pass" << endl;

		int tmp;
		for (int i=0; i < N; i++){
			tmp = search(i, gangs, seen);
			if (tmp > max_gang){max_gang = tmp;}
		}

		cout << max_gang << endl;
	}
	return(0);
}















