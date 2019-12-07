#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class Point2D {
public:
	Point2D() {
		x = 0;
		y = 0;
	}
	Point2D(float nx, float ny) {
		x = nx;
		y = ny;
	}
	Point2D(const Point2D & p) {
		x = p.x;
		y = p.y;
	}
	float distanceBetween(Point2D otherPoint) {
		//Chosen because of pythagoran theorem
		float A=x-otherPoint.x;
		float B=y-otherPoint.y;
		float C;
		C = sqrt(pow(A, 2) + pow(B, 2));
		return C;
	}

	string toString() {
		string output="[";
		output = output + to_string(x) + "," + to_string(y) + "]";
		return output;
	}

	Point2D operator+(const Point2D &p) {
		Point2D point;
		point.x = x + p.x;
		point.y = y + p.y;
		return point;
	}

	Point2D operator-(const Point2D& p) {
		Point2D point;
		point.x = x - p.x;
		point.y = y - p.y;
		return point;
	}

	Point2D& operator=(const Point2D& p) {
		x = p.x;
		y = p.y;
		return *this;
	}

	bool operator==(const Point2D &p) {
		return (x == p.x && y == p.y);
	}

	bool operator!=(const Point2D& p) {
		return !(x == p.x && y == p.y);
	}


	float x;
	float y;
};
/*
int main() {
	float ans;
	Point2D p1(1, 2);
	Point2D p2(3, 4);
	ans=p1.distanceBetween(p2);
	cout << ans << "\nShould be ~2.82, or more precisely the square root of 8\n";
	system("pause");
	Point2D p3;
	p3 = p1;
	cout << "p3 has the values: " << p3.toString() << "\n" << "it is ";
	if (p1 == p3) {
		cout << "true that p3 and p1 have the same value\nAnd it is ";
	}
	else {
		cout << "untrue that p3 and p1 have the same value\nAnd it is ";
	}
	if (p2 == p3) {
		cout << "true that p3 and p2 have the same value\n";
	}
	else {
		cout << "untrue that p3 and p2 have the same value\n";
	}
	system("pause");
	Point2D p4 = p1 + p3;
	cout << "p4 has the value " << p4.toString() << " and is " << p4.distanceBetween(p1) << " from p1\nIt is ";
	if (p1 == p4) {
		cout << "true that p4 and p1 have the same value\nAnd it is ";
	}
	else {
		cout << "untrue that p4 and p1 have the same value\nAnd it is ";
	}
	if (p2 == p4) {
		cout << "true that p4 and p2 have the same value\nAnd it is ";
	}
	else {
		cout << "untrue that p4 and p2 have the same value\nAnd it is ";
	}
	if (p3 == p4) {
		cout << "true that p4 and p3 have the same value\n";
	}
	else {
		cout << "untrue that p4 and p3 have the same value\n";
	}
	system("pause");
	return 0;
}
*/