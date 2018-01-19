

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	int i, t, period;
	string line;
	cin >> t;
	for (i=0; i < t; i++){
		cin >> line;
		int len = line.length();

		// Iterate through every possible period
		bool isPeriod = true;
		for (period = 1; period < len; period++)
		{
			// length of period has to be the fraction of length of string
			string str = line.substr(0, period);
			if (len % period != 0){
				continue;
			}

			// Iterate through each char
			for (int j = period; j < len; j++){
				if(line[j] != str[j % period]){
					isPeriod = false;
					break;
				}
			}

			if (isPeriod){
				break;
			}
			isPeriod = true;

		}
		// No periodic substring
		cout << period << endl;

		// print blank line if not finished
		if (i < t-1){
			cout << endl;
		}
	}
	return(0);
}



