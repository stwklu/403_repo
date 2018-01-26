/*
* Created by Steven Weikai Lu on 2018/01/15
* 
* Kattis problem: <3dprinter>
*
* Topic: Arithmetic
*
* Level: simple
* 
* Brief problem description: 
* - You have a single 3D printer, and would like to use it to produce nn statues.
* - However, printing the statues one by one on the 3D printer takes a long time,
* - so it may be more time-efficient to first use the 3D printer to print a new printer.
* - That new printer may then in turn be used to print statues or even more printers.
* - Print jobs take a full day, and every day you can choose for each printer in your possession to have it print a statue,
* - or to have it 3D print a new printer (which becomes available for use the next day).
*
* What is the minimum possible number of days needed to print at least nn statues?
*
* Solution Summary:
* - Since if all printers print another printers at day k, then all print statue at day k+1 is the fastest way for any amount
* - Log2 as the layer of printing new printers, +1 for the day all print statues
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
#include <tgmath.h>

using namespace std;

int main(){

	int t;
	cin >> t;

	cout << ceil(log2(t))+1 << endl;

	return(0);
}