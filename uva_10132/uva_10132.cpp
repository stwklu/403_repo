/* UVa problem: <10132>
 *
 * Topic: Data Structure
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   Input
?The input begins with a single positive integer on a line by itself indicating the number of the cases
following, each of them as described below. This line is followed by a blank line, and there is also a
blank line between two consecutive inputs.
Input will consist of a sequence of “file fragments”, one per line, terminated by the end-of-file marker.
Each fragment consists of a string of ASCII 1’s and 0’s.
Output
For each test case, the output must follow the description below. The outputs of two consecutive cases
will be separated by a blank line.
Output is a single line of ASCII 1’s and 0’s giving the bit pattern of the original files. If there are
2N fragments in the input, it should be possible to concatenate these fragments together in pairs to
make N copies of the output string. If there is no unique solution, any of the possible solutions may
be output.
Your friend is certain that there were no more than 144 files on the tray, and that the files were all
less than 256 bytes in size.
 *
 * Solution Summary:
 *
 *   Brute Force on all combinations of longest fragments and shortest fragments
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


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <string.h>

using namespace std;

vector<string> frag;

bool validate(string str){
	vector<string> temp(frag);
	int len = str.length();
	for (int f=0;f<frag.size();f++){
		for (int k=0;k<frag.size();k++){
			if(f==k || frag[f].length()+frag[k].length() != len){
				continue;
			}
			if(frag[f]+frag[k] == str || frag[k]+frag[f] == str){
				temp.erase(remove(temp.begin(), temp.end(), frag[k]), temp.end());
				temp.erase(remove(temp.begin(), temp.end(), frag[f]), temp.end());
			}
			if (temp.empty()){
				return true;
			}
		}
		if (temp.empty()){
			return true;
		}
	}

	if (temp.empty()){
		return true;
	}
	else {
		return false;
	}
}


int main(){
	
	int t;
	string input;
	cin >> t;

	while(t--){

		frag.clear();

		while(input.length()==0){
			getline(cin, input);
		}

		int max_length = 0;
		int min_length = 1 << 30;
		vector<string> max_str;
		vector<string> min_str;
		while(input.length()!=0){
			frag.push_back(input);
			if(input.length() > max_length){
				max_str.clear();
				max_str.push_back(input);
				max_length = input.length();
			}
			else if (input.length() == max_length){
				max_str.push_back(input);
			}
			if(input.length() < min_length){
				min_str.clear();
				min_str.push_back(input);
				min_length = input.length();
			}
			else if (input.length() == min_length){
				min_str.push_back(input);
			}
			getline(cin, input);
		}


		string combo;
		bool success = true;
		for (string i : max_str){
			for (string j : min_str){
				combo = i+j;
				success = validate(combo);
				if (!success){
					combo = j+i;
					success = validate(combo);
				}
				if(success){break;}
			}
			if (success){
				break;
			}
		}

		cout << combo << endl;
		if (t){
			cout << endl;
		}

	}


	return 0;
}