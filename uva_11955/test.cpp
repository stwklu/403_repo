
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define ll unsigned long long

ll overflow = (1ULL << 60);

int main(){
	ll n, r , a, b;
	ll out = 1;
	bool divide = false;

	cin >> n >> r;

	if(n-r >= r+1){
		a = r;
		b = n-r+1;
	}
	else{
		a = n-r;
		b = r+1;
	}

	for (ll i = b; i < n+1; i++){
		out *= i;
		if (out > overflow){
			for (ll i = 1; i<a+1; i++){
				out /= i;
			}
			divide = true;
		}
	}
	if(divide){
		cout << out << endl;
		return 0;
	}
	for (ll i = 1; i<a+1; i++){
		out /= i;
	}

	cout << out << endl;

	return 0;
}