/* UVa problem: 220
 *
 * Topic: Data Structure
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   The first line of the input is the number of games to be processed. Each game consists of a board configuration followed by a list of commands. The board configuration consists of 9 lines. The first 8 specify the current state of the board. Each of these 8 lines contains 8 characters, and each of these characters will be one of the following:
‘-’ indicating an unoccupied square
‘B’ indicating a square occupied by a black disk ‘W’ indicating a square occupied by a white disk
The ninth line is either a ‘B’ or a ‘W’ to indicate which is the current player. You may assume that the data is legally formatted.
Then a set of commands follows. The commands are to list all possible moves for the current player, make a move, or quit the current game. There is one command per line with no blanks in the input.
 *
 * Solution Summary:
 *
 *   Data Structure. Multi-dimensional array
 *
 * Used Resources:
 *
 *   StackOverflow
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *
 * --------------------- (Steven Lu)
 */
#include <iostream>

using namespace std;


#define MAXN 9

char board[MAXN][MAXN];
char player;
int direction[8][2];


void print_num(){
	int white = 0;
	int black = 0;
	for(int y = 1; y < MAXN; y++){
		for (int x = 1; x < MAXN; x++){
			if (board[y][x] == 'W'){
				white++;
			}
			else if (board[y][x] == 'B'){
				black++;
			}
		}
	}

	cout << "Black - ";
	if (black < 10){
		cout << " ";
	}
	cout << black << " White - ";
	if (white < 10){
		cout << " ";
	}

	cout << white << endl;
}

void print_board(){
	for(int y = 1; y < MAXN; y++){
		for (int x = 1; x < MAXN; x++){
			cout << board[y][x];
		}
		cout << endl;
	}
}

bool inside(int x){
	return (0 < x && x < 9);
}

bool validate_move(int x, int y){
	//cout << "Validating " << player << " " << y << " " << x << endl;
	// Outside of board
	if (!inside(x) || !inside(y)){
		//cout << y << " " << x << " outside" << endl;
		return false;
	}

	// Position occupied
	if (board[y][x] != '-'){
		//cout << y << " " << x << " occupied" << endl;
		return false;
	}

	// Iterate 8 possible directions
	for (auto dir : direction){
		//cout << "Direction " << dir[1] << " " << dir[0] << endl;
		int x1 = x + dir[0];
		int y1 = y + dir[1];

		// Check if next position is different color
		if (board[y1][x1] == player || board[y1][x1] == '-' || !inside(x1) || !inside(y1)){
			//cout << "Not valid at: " << y1 << " " << x1 << endl;
			continue;
		}
		// Check if bracket close
		while (inside(x1) && inside(y1)){
			x1 = x1 + dir[0];
			y1 = y1 + dir[1];
			if (board[y1][x1] == player){
				//cout << y1 << " " << x1 << " close" << endl;
				return true;
			}
			if (board[y1][x1] == '-'){
				//cout << "Not valid at: " << y1 << " " << x1 << endl;
				break;
			}
		}
	}

	return false;
}

bool make_move(int x, int y){
	if (! validate_move(x, y)){
		//cout << "Invalid move: " << y << " " << x << endl;
		player = (player == 'W')? 'B' : 'W';
	}

	//cout << "Valid move: " << y << " " << x << endl;

	board[y][x] = player;

	// Iterate 8 possible directions
	for (auto dir : direction){
		int x1 = x + dir[0];
		int y1 = y + dir[1];

		// Check if next position is different color
		if (board[y1][x1] == player || board[y1][x1] == '-'){
			continue;
		}
		// Check if bracket close
		//bool dir_done = false;
		while (inside(x1) && inside(y1)){
			x1 = x1 + dir[0];
			y1 = y1 + dir[1];
			if (board[y1][x1] == player){ // Valid path
				// Change all disk on this path
				int x_ptr = x + dir[0];
				int y_ptr = y + dir[1];
				while(true){
					if (board[y_ptr][x_ptr] == player){
						//dir_done = true;
						break;
					}
					else{
						//cout << "(y,x) " << y << " " << x << " (y_ptr, x_ptr) " << y_ptr << " " << x_ptr << " (y1,x1) " << y1 << " " << x1 <<  endl; 
						board[y_ptr][x_ptr] = player;
						x_ptr = x_ptr + dir[0];
						y_ptr = y_ptr + dir[1];
					}
				}
			}
			else if (board[y1][x1] == '-'){ // Invalid path
				break;
			}
		}
	}
	player = (player == 'W')? 'B' : 'W';
	print_num();

	return true;
}

bool list_moves(){
	bool legal = false;
	for(int y = 1; y < MAXN; y++){
		for (int x = 1; x < MAXN; x++){
			if (validate_move(x, y)){
				if (legal){
					cout << " ";
				}
				cout << '(' << y << ',' << x << ")";
				legal = true;
			}
		}
	}

	if (legal){
		cout << endl;
	}
	else{
		cout << "No legal move." << endl;
	}
	
	return legal;
}


int main(){
	
	int n;
	cin >> n;

	// Initialize all possible direction
	int ptr = 0;
	for(int i = -1; i < 2; i++){
		for (int j = -1; j<2; j++){
			if (i != 0 || j != 0){
				direction[ptr][0] = i;
				direction[ptr][1] = j;
				ptr++;
			}
		}
	}
	//cout << "Pass direction setting" << endl;

	char pos;
	while(n--){
		// Read Board
		for(int y=1; y < MAXN; y++){
			for (int x=1; x< MAXN; x++){
				cin >> pos;
				board[y][x] = pos;
			}
		}

		//cout << "Pass board reading" << endl;

		// Read player
		cin >> player;

		// Read command
		char command;
		int m_x, m_y;
		char c_x, c_y;
		while(true){
			cin >> command;
			if (command == 'L'){
				list_moves();
			}

			else if (command == 'M'){
				cin >> c_y >> c_x;
				m_x = c_x - '0';
				m_y = c_y - '0';
				make_move(m_x, m_y);
				//print_board();
			}

			else if (command == 'Q'){
				print_board();
				break;
			}
		}
		if (n > 0){
			cout << endl;
		}
	}

	return(0);
}











