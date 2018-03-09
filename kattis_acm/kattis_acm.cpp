/* kattis problem: <acm>
 *
 * Topic: data structure
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Input
The input contains n lines for 0≤n≤100, with each line describing a particular log entry. A log entry has three parts: an integer m, with 1≤m≤300, designating the number of minutes at which a submission was received, an uppercase letter designating the problem, and either the word right or wrong. The integers will be in nondecreasing order and may contain repeats. After all the log entries is a line containing just the number −1.

Output
Output two integers on a single line: the number of problems solved and the total time measure (including penalties).
 *
 * Solution Summary:
 *
 *   trivial. Use vector and map for each questionss
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
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<char> qr;
map<char, int> pen;


int main(){
	int time, score=0;
	char prob;
	string correct;

	//memset(qr, 0, sizeof(qr));
	//memset(pen, 0, sizeof(pen));

	while(true){
		cin >> time >> prob >> correct;

		if (time == -1){
			break;
		}

		// Solved already
		if (find(qr.begin(), qr.end(), prob) != qr.end()){
			continue;
		}

		if (correct == "right"){
			score += time;
			qr.push_back(prob);
			if (pen.find(prob) != pen.end()){ // Wrong before
				score += 20 * pen[prob];
			}
		}

		else if (correct == "wrong"){
			// wrong before, still wrong
			if ((pen.find(prob) != pen.end())){
				pen[prob]++;
			}
			// first time wrong
			else if((pen.find(prob) == pen.end())){
				pen[prob] = 1;
			}
		}
	}

	int n = qr.size();

	cout << n << " " << score;


	return 0;
}