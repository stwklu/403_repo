
#include <iostream>
#include <cmath>

using namespace std;


int main(){

	cout << "{";

	for (int i=2; i<200000; i++){
	    for (int j=2; j*j<=i; j++){
	        if (i % j == 0) 
	            break;
	        else if (j+1 > sqrt(i)) {
	            cout << "," << i;
	        }

	    }  
	}

	cout << "}" << endl;
}