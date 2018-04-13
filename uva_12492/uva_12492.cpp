
/* UVa problem: <12492>
 *
 * Topic: Combinatorics
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Given a sequence of move of rubik circle, find the number of repeat tile back to original position
 *
 * Solution Summary:
 *
 *   Pure simulation
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
#include <string>
#include <cstring>

#define N_LABEL 54
#define MAX_MOVE 80


using namespace std;


int cube[N_LABEL];
string sequence;
int ans;

void face(int a, int b, int c, int d, int e, int f, int g, int h) {
	// The 8 face label
	/*
	a b c
	a   e
	f g h
	*/
    int x = cube[h], y = cube[g];
    cube[h] = cube[f];
    cube[g] = cube[e];

    cube[f] = cube[d];
    cube[e] = cube[c];

    cube[d] = cube[b];
    cube[c] = cube[a];

    cube[b] = x;
    cube[a] = y;
}

void side(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l) {
	// the 12 side label
    int x = cube[j], y = cube[k], z = cube[l];
    
    cube[j] = cube[g];
    cube[k] = cube[h];
    cube[l] = cube[i];

    cube[g] = cube[d];
    cube[h] = cube[e];
    cube[i] = cube[f];
    
    cube[d] = cube[a];
    cube[e] = cube[b];
    cube[f] = cube[c];

    cube[a] = x;
    cube[b] = y;
    cube[c] = z;
}


void F() {
    face(0, 1, 2, 5, 8, 7, 6, 3);
    side(33, 34, 35, 45, 48, 51, 11, 10, 9, 44, 41, 38);
}

void B() {
    face(26, 25, 24, 21, 18, 19, 20, 23);
    side(29, 28, 27, 36, 39, 42, 15, 16, 17, 53, 50, 47);
}

void L() {
    face(36, 37, 38, 41, 44, 43, 42, 39);
    side(0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33);
}

void R() {
    face(45, 46, 47, 50, 53, 52, 51, 48);
    side(8, 5, 2, 35, 32, 29, 26, 23, 20, 17, 14, 11);
}

void U() {
    face(27, 28, 29, 32, 35, 34, 33, 30);
    side(2, 1, 0, 38, 37, 36, 24, 25, 26, 47, 46, 45);
}

void D() {
    face(9, 10, 11, 14, 17, 16, 15, 12);
    side(6, 7, 8, 51, 52, 53, 20, 19, 18, 42, 43, 44);
}

void f(){
	F();
	F();
	F();
}
void b(){
	B();
	B();
	B();
}
void r(){
	R();
	R();
	R();
}
void l(){
	L();
	L();
	L();
}
void u(){
	U();
	U();
	U();
}
void d(){
	D();
	D();
	D();
}

void repeat(){
	for(auto m : sequence){
		switch(m){
		    case 'F': F(); break;
	        case 'B': B(); break;
	        case 'R': R(); break;
	        case 'L': L(); break;
	        case 'U': U(); break;
	        case 'D': D(); break;
	        case 'f': f(); break;
	        case 'b': b(); break;
	        case 'r': r(); break;
	        case 'l': l(); break;
	        case 'u': u(); break;
	        case 'd': d(); break;
		}
	}
}

bool validate(){
	for(int i=0; i<N_LABEL; i++) {
        if (cube[i] != i){
        	return false;
        }
    }
    return true;
}


int main(){

	while(cin >> sequence){
		ans = 1;
		memset(cube, 0, sizeof(cube));
		for(int i=0; i<N_LABEL; i++){
			cube[i] = i;
		}

		repeat();
		while(!validate()){
			repeat();
			ans++;
		}
		cout << ans << endl;
	}


	return 0;
}