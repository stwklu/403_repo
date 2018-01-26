/*
* Created by Steven Weikai Lu on 2018/01/15
* 
* UVa problem: <227>
*
* Topic: string
*
* Level: challenging
* 
* Brief problem description: 
* 	A children’s puzzle that was popular 30 years ago consisted of a 5×5 frame which contained 24 small squares of equal size.
* 	A unique letter of the alphabet was printed on each small square.
* 	Since there were only 24 squares within the frame, the frame also contained an empty position which was the same size as a small square.
* 	A square could be moved into that empty position if it were immediately to the right, to the left, above, or below the empty position.
*	The object of the puzzle was to slide squares into the empty position so that the frame displayed the letters in alphabetical order.
* 
*
* Solution Summary:
* 	- represent the puzzle by a string vector
*	- use map to make corresponding move
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

int main(){

	map<char, int> horizontal = {{'A', 0},{'B', 0},{'L', -1},{'R', 1}};
	map<char, int> vertical = {{'A', -1},{'B', 1},{'L', 0},{'R', 0}};

	int n = 1;
	while(n){

		// Build initial puzzle
		vector<string> puzzle(5);
		string row;
		char empty_x, empty_y;
		for (int y=0; y < 5; y++){
			getline(cin, row);
			puzzle[y] = row;
			for(int x=0; x < 5; x++){
				if(row[x] == 'Z'){return(0);}
				if(row[x] == ' '){
					empty_y = y;
					empty_x = x;
				}
			}
		}

		if (n > 1){
			cout << endl;
		}
		cout << "" << "Puzzle #" << n++ << ":" << endl;
		// Handle movements
		char move;
		int x_new, y_new;
		bool legal = true;
		cin >> move;
		while(move != '0'){

			x_new = empty_x + horizontal[move];
			y_new = empty_y + vertical[move];

			// illegal move
			if ( x_new < 0 || x_new > 4 || y_new < 0 || y_new >4){
				legal = false;
			}

			if (legal){
				swap(puzzle[empty_y][empty_x], puzzle[y_new][x_new]);
				empty_x = x_new;
				empty_y = y_new;
			}
			cin >> move;
		}

		//Print final configuration
		if (legal){
			for (int y=0; y < 5; y++){
				for(int x=0; x < 5; x++){
					cout << puzzle[y][x];
					if (x<4){cout << " ";}
				}
				if(y<4){cout << endl;}
			}
			cout << endl;
		}
		else{
			cout << "This puzzle has no final configuration." << endl;
		}

		cin.ignore();
	}
	return(0);
}












