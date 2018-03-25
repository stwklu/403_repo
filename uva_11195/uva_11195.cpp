/* UVa problem: <11195>
 *
 * Topic: backtracking
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   Classic n-queens problem but with slight difference that:
 * 		- Some positions are banned
 *		- Those banned positions doesn't stop queens from attacking
 *
 * Solution Summary:
 *
 *   BackTracking with bitmask to speed up
 *
 * Used Resources:
 *
 *   StackOverflow
 *   Competitive Programming 3: Steven Halim, Felix Halim
 *
 *   Disclaimer: I used highly optimized code from CP3 book for classic n-queens problem.
 *					Modified myself to add column check to handle banned positions.
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *
 * --------------------- (Steven Lu)
 */



#include <iostream>
#include <cstring>


using namespace std;

#define MAX_SIZE 15

// Global variables
int ans, valid;
bool board[MAX_SIZE][MAX_SIZE];

// Read the board
void read_board(int n){
	char c;
	for(int row=0; row<n;row++){
		for(int column=0; column<n; column++){
			cin >> c;
			if(c=='*'){
				board[row][column] = 0;
			}
		}
	}
}

// Recursive backtracking
void backtrack(int row, int column, int left_diag, int right_diag, int n){
	// Base case
	if((row&valid)==valid){
		ans++;
		return;
	}
	int pos = valid & (~(row|left_diag|right_diag));

	// Recursion
	for (int rw=0; rw < n; rw++){ // Try for each row
		if(1 & (pos >> rw) & board[rw][column]){ // Empty position
			backtrack((row|(1<<rw)), column+1, (left_diag|(1<<rw))<<1, (right_diag|1<<rw)>>1, n);
		}
		//int p = pos & -pos;
		//pos -= p;
		//backtrack(row|p, (left_diag|p) << 1, (right_diag|p) >> 1);
	}
}

int main(){
	int n, t=1;
	while (true){
		cin >> n;
		if(n==0){break;}

		// Initialization
		memset(board, 1, sizeof(board));
		ans = 0;
		valid = (1 << n) - 1;

		read_board(n);

		// Start searching at corner
		backtrack(0,0,0,0,n);

		cout << "Case " << t++ << ": " << ans << endl;
	}
	
}












