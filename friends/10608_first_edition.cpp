/* UVa problem: <10608>
 *
 * Topic: Data Structures
 *
 * Level: challenging
 * 
 * Brief problem description: 
 * -There is a town with N citizens. It is known that some pairs of people are friends.
 * -According to the famous saying that “The friends of my friends are my friends, too” it follows that if A and B are friends and B and C are friends then A and C are friends, too.
 * -Task is to count how many people there are in the largest group of friends.
 *
 * Solution Summary:
 *
 *   Algorithmic idea, data structures ...
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
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int N, M, max_gang = 1;
		cin >> N;
		cin >> M;
		vector<set<int>> gangs;
		//cout << "N: " << N << " M: " << M << endl;
		while(M--){
			int guy1, guy2, index, new_guy, old_guy;
			bool exist = false;
			cin >> guy1;
			cin >> guy2;

			// Iterate through sets to find existing group
			for (int i=0; i < gangs.size(); i++){
				set<int> gang = gangs[i];
				if(gang.count(guy1)){
					index = i;
					new_guy = guy2;
					exist = true;
					break;
				}
				else if (gang.count(guy2)){
					index = i;
					new_guy = guy1;
					exist = true;
					break;
				}
			}

			if (exist){
				bool combine = false;
				if (!(gangs[index].count(new_guy))){// Combine the sets
					for (int i=0; i < gangs.size(); i++){
						if ((gangs[i].count(new_guy)) && (index != i)){
							combine = true;
							gangs[index].insert(gangs[i].begin(), gangs[i].end());
							gangs.erase(gangs.begin() + i);
							if(gangs[index].size() > max_gang){max_gang = gangs[index].size();}
							break;
						}
					}
				}
				if(!combine){// Insert new element into sets
					gangs[index].insert(new_guy);
					if(gangs[index].size() > max_gang){max_gang = gangs[index].size();}
				}
			}

			// Create new set
			else{
				set<int> new_gang;
				new_gang.insert(guy1);
				new_gang.insert(guy2);
				gangs.push_back(new_gang);
				if(2 > max_gang){max_gang = 2;}
			}
		}
		cout << max_gang << endl;
	}
	return(0);
}















