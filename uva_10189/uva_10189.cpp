/* UVa problem: <10189>
 *
 * Topic: Data Structure
 *
 * Level: challenging
 *
 * Brief problem description:

 The input will consist of an arbitrary number of fields. The first line of each field contains two integers
n and m (0 < n, m ≤ 100) which stands for the number of lines and columns of the field respectively.
The next n lines contains exactly m characters and represent the field.
Each safe square is represented by an ‘.’ character (without the quotes) and each mine square
is represented by an ‘*’ character (also without the quotes). The first field line where n = m = 0
represents the end of input and should not be processed.
 *
 *   For each field, you must print the following message in a line alone:
Field #x:
Where x stands for the number of the field (starting from 1). The next n lines should contain the
field with the ‘.’ characters replaced by the number of adjacent mines to that square. There must be
an empty line between field outputs.
 *
 * Solution Summary:
 *
 *  array to store the board
 *
 * Used Resources:
 *
 *   StackOverflow
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *
 * --------------------- (Steven Lu)
 */
~



#include <iostream>
#include <cstring>


using namespace std;

int n,m;
int board[101][101];


void increment(int i, int j){
	int x_dir[] = {-1, 0, 1};
	int y_dir[] = {-1, 0, 1};

	board[i][j] = -1;

	for (int x : x_dir){
		for (int y : y_dir){
			if ((x || y) && (i+x >= 0) && (j+y >= 0)){
				if (board[i+x][j+y] != -1){
					board[i+x][j+y]++;
				}
			}
		}
	}
}


int main(){
	int t = 1;
	cin >> n >> m;
	while(true){
		if (n==0 && m==0){
			return 0;
		}

		memset(board, 0, sizeof(board));
		char temp;

		// Input
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin >> temp;
				if (temp == '*'){
					increment(i,j);
				}
			}
		}

		// Output
		cout << "Field #" << t << ":" << endl;
		int b;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				b = board[i][j];
				if ( b == -1){
					cout << '*';
				}
				else{
					cout << b;
				}
			}
			cout << endl;
		}

		cin >> n >> m;
		if(n==0 && m==0){
			return 0;
		}
		cout << endl;
		t++;
	}
	return 0;
}