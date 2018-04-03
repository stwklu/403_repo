
/* UVa problem: <190>
 *
 * Topic: Geometry
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   Find the circle through 3 points. Output two form of formula.
 *
 * Solution Summary:
 *
 *   origin <- Intersection of perpendiculer bisectors
 *	 Radius <- Euclidean distance from origin to any point
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
#include <vector>
#include <cmath>

using namespace std;

#define INF 625245735


struct line {
	double slope;
	double bias;
};

struct point{
	double x;
	double y;
};


// Euclidean Distance between two points
double eu_distance(point p1, point p2){
	return sqrt( (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y) );
}


// Intersection of two lines
point intersection(line l1, line l2){

	double x = (l1.bias-l2.bias) / (l2.slope-l1.slope);
	double y = l1.slope * x + l1.bias;

	point p;
	p.x = x;
	p.y = y;

	return p;
}


// Perpendiculer bisector
line perp_bisect(point p1, point p2){
	double midpoint_x, midpoint_y, slope, bias;
	line l;

	midpoint_x = (p1.x+p2.x)/2;
	midpoint_y = (p1.y+p2.y)/2;

	// Deal with zeros here
	if(p2.y==p1.y){
		l.slope = INF;
		l.bias = midpoint_x;
		return l;
	}
	
	// Normal cases
	slope = - (p2.x-p1.x) / (p2.y-p1.y);
	bias = midpoint_y - slope * midpoint_x;

	l.slope = slope;
	l.bias = bias;

	return l;
}


int main(){
	cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	cout.precision(3);
	
	double x1, y1, x2, y2, x3, y3, radius;
	point p1, p2, p3, origin;
	line l1, l2;

	vector<double> tmp;

	while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3){
		p1.x = x1;
		p2.x = x2;
		p3.x = x3;
		p1.y = y1;
		p2.y = y2;
		p3.y = y3;

		vector<point> pts = {p1, p2, p3};

		// Find circle
		l1 = perp_bisect(p1, p2);
		l2 = perp_bisect(p1, p3);
		if(l1.slope == INF){
			l1 = perp_bisect(p2, p3);
		}
		else if(l2.slope == INF){
			l2 = perp_bisect(p2, p3);
		}
		
		origin = intersection(l1, l2);
		radius = eu_distance(origin, p1);

		//cout << origin.x << " " << origin.y << " " << radius << endl;

		// Equation 1
		char operand_1 = origin.x<0?'+':'-';
		char operand_2 = origin.y<0?'+':'-';
		char operand_3;
		if(origin.x != 0){
			cout << "(x " << operand_1 <<  " " << abs(origin.x) << ")^2 ";
		}
		else{
			cout << "x^2 ";
		}
		if(origin.y != 0){
			cout << "+ (y " << operand_2 << " " << abs(origin.y) << ")^2 = ";
		}
		else{
			cout << "+ y^2 = ";
		}
		cout << radius << "^2" << endl;


		// Equation 2
		operand_1 = (2*origin.x>0)?'-':'+';
		operand_2 = (2*origin.y>0)?'-':'+';
		operand_3 = ( origin.x*origin.x + origin.y*origin.y - radius*radius )>0?'+':'-';
		cout << "x^2 + y^2";
		if(2*origin.x != 0){
			cout << " " << operand_1 << " " << abs(2*origin.x) << "x";
		}
		if(2*origin.y != 0){
			cout << " " << operand_2 << " " <<  abs(2*origin.y) << "y";
		}
		if(origin.x*origin.x + origin.y*origin.y - radius*radius != 0){
			cout << " " << operand_3 << " " << abs( origin.x*origin.x + origin.y*origin.y - radius*radius );
		}
		cout << " = 0" << endl << endl;
		 
	}

	return 0;
}






















