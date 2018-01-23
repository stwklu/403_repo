/* UVa problem: <10815>
 *
 * Topic: Data Structures
 *
 * Level: simple
 * 
 * Brief problem description: 
 *  Input:  - The input file is a text with no more than 5000 lines.
 *          - An input line has at most 200 characters.
 * 			- Input is terminated by EOF.
 *
 *	Output: - Your output should give a list of different words that appears in the input text, one in a line.
 * 			- The words should all be in lower case, sorted in alphabetical order.
 *			- You can be sure that he number of distinct words in the text does not exceed 5000.
 *
 * Solution Summary:
 *			- simply parse everything into lowercase words and put them into a set.
 *			- Then print everything from the set.
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
#include <string>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;

int main(){
	string line;
	set<string> tokens;
	while(getline(cin, line)){

		replace_if(line.begin(), line.end(), ::ispunct, ' ');
		replace_if(line.begin(), line.end(), ::isdigit, ' ');
		transform(line.begin(), line.end(), line.begin(), ::tolower);

		string buffer;
		stringstream ss(line);

		while(ss >> buffer){
			tokens.insert(buffer);
		}
	}

	for (auto word : tokens){
		cout << word << endl;
	}

	return(0);
}




























