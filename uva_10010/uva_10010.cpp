/*
* Created by Steven Weikai Lu on 2018/01/15
* 
* UVa problem: <uva_10010>
*
* Topic: string
*
* Level: challenging
* 
* Brief problem description: 
*	- Given a grid of character, find the words.
* 	- words can be found on any direction, including diagonal
* 
*
* Solution Summary:
* 	- Search for each initial character, if match check next
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
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool directionSearch(vector<vector<char>> &grid, int x, int y, string str, int length, vector<int> direction);

bool search(vector<vector<char>> &grid, int i, int j, string str, map<string, int> &x_index, map<string, int> &y_index, map<string, bool> &founded);

// Search for words on a given direction
bool directionSearch(vector<vector<char>> &grid, int x, int y, string str, int length, vector<int> direction){
	int grid_width = grid.size();
	int grid_height = grid[0].size();
	for(int i=1; i<length; i++){
		x += direction[0];
		y += direction[1];
		if ( (x < 0) || (x>=grid_width) || (y < 0) || (y>=grid_height)){
			return false;
		}
		else if ((grid[x][y] != str[i])){
			return false;
		}
	}

	return(true);
}

// For each grid, if first char match, send to direction search
bool search(vector<vector<char>> &grid, int i, int j, string str, map<string, int> &x_index, map<string, int> &y_index, map<string, bool> &founded){
	int length = str.length();
	vector<int> direction;
	bool found;

	for(int x=-1; x < 2; x++){
		for (int y=-1; y<2; y++){
			direction = {x, y};
			found = directionSearch(grid, i, j, str, length, direction);
			if(found && !(founded[str])){
				x_index[str] = i + 1;
				y_index[str] = j + 1;
				founded[str] = true;
				return(true);
			}
		}
	}

	return(false);
}

int main(){
	int t;
	cin >> t;
	for (int i=0;i<t;i++){
		int m, n, k;
		cin >> m;
		cin >> n;
		vector<vector<char>> grid;
		grid.resize(m);

		// Read grid
		char tmp;
		for(int j=0;j<m;j++){
			grid[j].resize(n);
			for(int l=0;l<n;l++){
				cin >> tmp;
				grid[j][l] = tolower(tmp);
			}
		}

		// Read words to find
		cin >> k;
		string words[k];
		map<string, bool> founded;
		string temp_word;
		for(int j=0;j<k;j++){
			cin >> temp_word;
			transform(temp_word.begin(), temp_word.end(), temp_word.begin(), ::tolower);
			founded[temp_word] = false;
			words[j] = temp_word;
		}

		// Search
		char first_char;
		map<string, int> x_index;
		map<string, int> y_index;
		for(int j=0;j<m;j++){
			for(int l=0;l<n;l++){
				for(int it=0; it < k ; it++){
					first_char = words[it][0];
					if (first_char == grid[j][l]){
						string str = words[it];
						bool found = search(grid, j, l, str, x_index, y_index, founded);
					}
				}
			}
		}

		// Output solution
		for (int j=0; j<k; j++){
			string word = words[j];
			int x = x_index[word];
			int y = y_index[word];
			cout << x << " " << y << endl;
		}

		if (i < (t-1)){
			cout << "" << endl;
		}
	}

	return(0);
}

