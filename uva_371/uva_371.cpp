

#include <iostream>
#include <map>

using namespace std;

long L, H, V, S, temp, lg;
map<long, long> seq;


long recurse(long a){
	if (a == 1){
		return 0;
	}

	long output;
	if (seq.find(a) != seq.end()){
		return seq[a];
	}

	if (a % 2 == 0){ // Even number
		output = 1 + recurse(a/2);
		seq[a] = output;
	}
	else{ // Odd number
		output = 1 + recurse(3*a + 1);
		seq[a] = output;
	}

	return output;
}


int main(){

	while(true){
		cin >> L >> H;
		if((L==0) && (H==0)){
			return 0;
		}

		if (L > H){
			temp = H;
			H = L;
			L = temp;
		}

		cout << "Between " << L << " and " << H << ", ";

		S = -1;
		V = -1;
		for(temp=L; temp<=H; temp++){
			lg = recurse(temp);
			if (temp == 1){
				lg = 3;
			}
			if(lg > S){
				S = lg;
				V = temp;
			}
		}

		cout << V <<  " generates the longest sequence of " << S << " values." << endl;

	}



	return 0;
}