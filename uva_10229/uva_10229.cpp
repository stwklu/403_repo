
/* UVa problem: <10229>
 *
 * Topic: arithmetic
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   Given m,n , find F_n mod 2^m where F_n is the nth fibonacci number
 *
 * Solution Summary:
 *
 *   Using Fibonacci Q-matrix multiplication for fast fibonacci computation.
 * 				 Q^(n+1) * Q^(n) = Q^(2n+1)
 *				 Q^(m) * Q^(n-1) = Q^(n+m-1)
 *
 * Used Resources:
 *
 *   StackOverflow
 *   Competitive Programming 3: Steven Halim, Felix Halim
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *
 * --------------------- (Steven Lu)
 */

#include <iostream>

using namespace std;

typedef long long ll;

struct matrix{
	ll m[2][2];
	ll mod;

	void print_matrix(matrix& a){
		cout << "[" << a.m[0][0] << " " << a.m[0][1] << "]" << endl;
		cout << "[" << a.m[1][0] << " " << a.m[1][1] << "]" << endl << endl;
	}

	// Matrix multiplication
	matrix operator*(matrix& a){
		matrix output;
		//print_matrix(*this);
		//cout << "multiply" << endl;
		//print_matrix(a);
		output.m[0][0] = (m[0][0]*a.m[0][0] + m[0][1]*a.m[1][0]) % mod;
		output.m[0][1] = (m[0][0]*a.m[1][0] + m[0][1]*a.m[1][1]) % mod;
		output.m[1][0] = (m[1][0]*a.m[0][0] + m[1][1]*a.m[1][0]) % mod;
		output.m[1][1] = (m[1][0]*a.m[0][1] + m[1][1]*a.m[1][1]) % mod;
		output.mod = mod;
		//cout << "equals" << endl;
		//print_matrix(output);
		return output;
	}

	// Matrix power
	matrix operator^(ll p){
		matrix q, tmp;
		// start from identity matrix
		q.m[0][0] = 1;
		q.m[0][1] = 0;
		q.m[1][0] = 0;
		q.m[1][1] = 1;
		q.mod = mod;
		// Deal with edge cases
		if(p==0){
			return q;
		}
		else if (p==1){
			return *this * q;
		}
		// Reduce power by the fact that:
		// Q^(n+1) * Q^(n) = Q^(2n+1)
		// Q^(m) * Q^(n-1) = Q^(n+m-1)
		tmp = *this;
		for (;p;p>>=1,tmp = tmp * tmp){
			if(p & 1){// p is odd
				q = q * tmp;
			}
			
		}
		return q;
	}

	// Matrix assignment
	matrix operator=(matrix a){
		mod = a.mod;
		m[0][0] = a.m[0][0];
		m[0][1] = a.m[0][1];
		m[1][0] = a.m[1][0];
		m[1][1] = a.m[1][1];
		return *this;
	}
};

int main(){

	ll m, n, mod;
	matrix q;
	
	while(cin >> n >> m){

		// Q-matrix
		q.m[0][0] = 1;
		q.m[0][1] = 1;
		q.m[1][0] = 1;
		q.m[1][1] = 0;
		q.mod = 1 << m;

		q = q^n;

		mod = q.m[0][1];
		cout << mod << endl;

	}


	return 0;
}