
/* UVa problem: <200>
 *
 * Topic: graph traversal
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   Given a alphabeta ordered list, find the correct sorting order for alphabet that appeared
 *
 * Solution Summary:
 *
 *   Consider each alphabet as vertex and order as node. Then the vertex with least in-degree is lowest-ordered, then second, so on so forth
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
#include <cstring>

using namespace std;

#define MAX_SIZE 50
#define MAXN 26

vector<vector<int>> edge(MAX_SIZE);
bool seen[MAX_SIZE], have[MAX_SIZE];
vector<int> order;

void dfs(int x){
	seen[x] = 1;
	int bound = edge[x].size();
	for(int i=0; i<bound; i++){
		if(!seen[edge[x][i]]){
			dfs(edge[x][i]);
		}
	}
	order.push_back(x);
}


int main(){


	//edge.assign(MAX_SIZE, vector<int>());

	string prev_str, str;

	while(cin >> prev_str){
		memset(seen, 0, sizeof(seen));
		memset(have, 0, sizeof(have));
		edge.clear();
		order.clear();
		while(true){
			cin >> str;
			if(str=="#"){
				break;
			}
			int bound = min(str.size(), prev_str.size());

			for(int i=0; i<bound; i++){
				if(prev_str[i] != str[i]){
					have[prev_str[i]-'A'] = 1;
					have[str[i]-'A'] = 1;
					edge[prev_str[i]-'A'].push_back(str[i]-'A');
					break;
				}
			}
			prev_str = str;
		}

		//cout << "input pass" << endl;

		for(int i=0; i<MAXN; i++){
			if(!seen[i] && have[i]){
				dfs(i);
			}
		}

		//cout << "dfs pass" << endl;

		char out;
		for(int i=order.size()-1; i>=0; i--){
			out = order[i]+'A';
			cout << out;
		}
		cout << endl;
	}
	return 0;
}