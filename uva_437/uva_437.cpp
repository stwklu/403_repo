
/* UVa problem: <437>
 *
 * Topic: Graph Traversal
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Given set of block size x, y, z find the highest they reach by stacking one with base strictly smaller than other
 *
 * Solution Summary:
 *
 *  Dynamic programming
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
#include <tuple>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX_N 300

int dp[MAX_N];

struct Block{
	int x,y,z;
};

bool compareBlock(Block& a, Block& b){
	return (a.x==b.x?a.y>b.y:a.x>b.x);
}

Block blocks[MAX_N];

void add_block(int i, int x, int y, int z){
    blocks[i*6].x = x, blocks[i*6].y = y, blocks[i*6].z = z;
    blocks[i*6+1].x = x, blocks[i*6+1].y = z, blocks[i*6+1].z = y;
    blocks[i*6+2].x = y, blocks[i*6+2].y = x, blocks[i*6+2].z = z;
    blocks[i*6+3].x = y, blocks[i*6+3].y = z, blocks[i*6+3].z = x;
    blocks[i*6+4].x = z, blocks[i*6+4].y = x, blocks[i*6+4].z = y;
    blocks[i*6+5].x = z, blocks[i*6+5].y = y, blocks[i*6+5].z = x;
}


int main(){

	int n, x, y, z, height, t=1;

	while(true){
		cin >> n;
		if(n==0){return 0;}
		memset(blocks, 0, sizeof(blocks));
		memset(dp, 0, sizeof(dp));
		for(int i=0;i<n;i++){
			cin >> x >> y >> z;
			add_block(i, x, y, z);
		}
		sort(blocks, blocks + n*6, compareBlock);
		height = 0;
		// Dynamic Programming
		dp[0] = blocks[0].z;
		for(int i=1; i<n*6;i++){
			dp[i] = blocks[i].z;
			for(int j=0; j<i; j++){
				if(blocks[i].x < blocks[j].x && blocks[i].y < blocks[j].y && dp[i]<dp[j]+blocks[i].z){
					dp[i] = dp[j] + blocks[i].z; // Find a legal block that increase height
				}
			}
			height = max(height, dp[i]);
		}
		cout << "Case " << t++ << ": maximum height = " << height << endl;
	}

	return 0;
}























