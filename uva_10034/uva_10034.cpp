
/* UVa problem: <10034>
 *
 * Topic: Graph Algorithm
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Given a set of freckles (x,y), find the minimum ink needed to connect them all
 *
 * Solution Summary:
 *
 *   Simple minimum spanning tree. Solved by Greedy
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
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>  

using namespace std;

#define MAX_N 110


struct EDGE{	// Edge structure
	double len;
	int f1, f2;
	bool operator<(const EDGE a) const { // For sorting
		return len < a.len;
	}
};

EDGE edges[MAX_N * MAX_N];	// All candidare edges
bool componets[MAX_N]; 			// Connected component
double total;				// Total line length
double x,y, fx[MAX_N], fy[MAX_N];		// x, y coordinate for freckels
int comp_size;
int n_edge;

// Euclidean distance between 2 freckles
double Euclidean_dist(int f1, int f2){
	//cout << "(" << fx[f1] << "," << fy[f1] << ") , (" << fx[f2] << "," << fy[f2] << ") : " << sqrt((fx[f1]-fx[f2])*(fx[f1]-fx[f2]) + (fy[f1]-fy[f2])*(fy[f1]-fy[f2])) << endl;
	return sqrt((fx[f1]-fx[f2])*(fx[f1]-fx[f2]) + (fy[f1]-fy[f2])*(fy[f1]-fy[f2]));
}

// Add edge to connected component
void connect(EDGE e){
	componets[e.f1] = 1;
	componets[e.f2] = 1;
}

void greedy(){
	for(int i=1;;i++){
		if(componets[edges[i].f1] ^ componets[edges[i].f2]){
			//cout << "connect: " << edges[i].f1 << " " << edges[i].f2 << " " << "comp_size: " << comp_size << endl;
			connect(edges[i]);
			total += edges[i].len;
			comp_size++;
			return;
		}
	}
	return;
}

int main(){
	cout << setprecision(2) << std::fixed;

	int t, n;
	double dist;
	cin >> t;
	while(t--){
		cin >> n;
		memset(fx, 0, sizeof(fx));
		memset(fy, 0, sizeof(fy));
		memset(componets, 0, sizeof(componets));
		memset(edges, 0, sizeof(edges));
		total = 0;
		for (int i=0;i<n;i++){
			cin >> fx[i] >> fy[i];
			//cout << fx[i] << " " << fy[i] << endl;
		}

		// Find all candidate edges
		n_edge = 0;
		for (int i=0; i<n; i++){
			for (int j=0; j<i; j++){
				dist = Euclidean_dist(i,j);
				edges[n_edge].len = dist;
				edges[n_edge].f1 = i;
				edges[n_edge].f2 = j;
				n_edge++;
				//cout << "Edge: " << n_edge << "(" << i << "," << j << ") distance: " <<  dist << endl;
			}
		}

		// Greedy algorithm for MST
		comp_size = 2;
		sort(edges, edges+n_edge);
		connect(edges[0]);
		total += edges[0].len;
		while(comp_size < n){
			greedy();
		}
		cout << total << endl;
		if(t){cout << endl;}
	}

	return 0;

}