/* UVa problem: <10129>
 *
 * Topic: Graph Theory
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   Given a list of words, determine whether it is possible to arrange all the plates in a sequence such that the first letter of each word is equal to the last letter of the previous word.
 *
 * Solution Summary:
 *
 *   Euler Path eixsitence check. Used degree constraint and DFS.
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
 * --------------------- (Steven Lu)
 */



// Euler graph property check
// O(E + V)

#include <iostream>
#include <string>
#include <vector>
#include <cstring>


using namespace std;

#define N_NODE 26

int in_degree[N_NODE];
int out_degree[N_NODE];
bool in_graph[N_NODE];
bool found[N_NODE];
int n_in, n_out;
int t, n, head, tail, start_node;
bool connected;
string word;
vector<int> graph[N_NODE];

// Depth-first Search
void dfs(int start){
	found[start] = true;
	for (int i=0; i < graph[start].size(); i++){
		int child = graph[start][i];
		if(!found[child]){
			dfs(child);
		}
	}
}


// Traverse graph to see if Euler Path exist
bool traverse_graph(int start){
	if (n_out == 1){ // Traverse from the starting point
		dfs(start);
	}
	else if (n_out == 0){ // No unique starting point, traverse from any node
		for (int i = 0; i < N_NODE; i++){
			if (out_degree[i] > 0){
				dfs(i);
				break;
			}
		}
	}

	// Check if all node reachable
	for (int i=0; i < N_NODE; i++){
		if (in_graph[i] && !found[i]){
			return false;
		}
	}

	return true;
}

void initialize_case(){
	memset(in_degree, 0, sizeof(in_degree));
	memset(out_degree, 0, sizeof(out_degree));
	memset(in_graph, false, sizeof(in_graph));
	memset(found, false, sizeof(found));
	memset(graph, 0, sizeof(graph));
	connected = true;
	n_in = n_out = head = tail = start_node = 0;
	word = "";
}

// Find starting node and end node.
// Set connected to false if in/out degree doesn't agree
int find_start(){
	for (int i=0; i<N_NODE; i++){
		if(in_degree[i] != out_degree[i]){
			if (in_degree[i] == out_degree[i] + 1){
				n_in++;
			}
			else if (in_degree[i] + 1 == out_degree[i]){
				start_node = i;
				n_out++;
			}
			else{
				connected = false;
				break;
			}
		}
	}

	return start_node;
}

// Check if number of in/out node agree
bool check_in_out_node(){
	connected = true;
	if (n_in != n_out){
		connected = false;
	}
	else if (n_in > 1){
		connected = false;
	}
	else if (n_out > 1){
		connected = false;
	}
	return connected;
}

int main(){
	
	cin >> t;

	while(t--){
		cin >> n;

		initialize_case();

		// cin
		while(n--){
			cin >> word;
			head = word[0] - 'a';
			tail = word[word.length()-1] - 'a';

			in_degree[tail]++;
			out_degree[head]++;
			in_graph[head] = true;
			in_graph[tail] = true;
			graph[head].push_back(tail);
		}

		// Check node degree
		start_node = find_start();
		char as = start_node + 'a';

		// Check number of in/out_node
		if(connected){
			connected = check_in_out_node();
		}

		// Traverse graph using DFS
		if (connected){
			connected = traverse_graph(start_node);
		}

		// Output
		if (connected){
			cout << "Ordering is possible." << endl;	
		}
		else{
			cout << "The door cannot be opened." << endl;
		}
	}



	return 0;
}