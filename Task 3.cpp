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
	Point2D(const Point2D& p) {
		x = p.x;
		y = p.y;
	}
	float distanceBetween(Point2D otherPoint) {
		//Chosen because of pythagoran theorem
		float A = x - otherPoint.x;
		float B = y - otherPoint.y;
		float C;
		C = sqrt(pow(A, 2) + pow(B, 2));
		return C;
	}

	string toString() {
		string output = "[";
		output = output + to_string(x) + "," + to_string(y) + "]\n";
		return output;
	}

	Point2D operator+(const Point2D& p) {
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

	bool operator==(const Point2D& p) {
		return (x == p.x && y == p.y);
	}

	bool operator!=(const Point2D& p) {
		return !(x == p.x && y == p.y);
	}


	float x;
	float y;
};

class Polyline {
public:
	int position=0;
	int size;
	Point2D* line;
	Polyline(int size_input) {
		line = new Point2D[size_input];
		size = size_input;
	}
	
	void add(float x_var, float y_var) {
		if (position < size) {
			line[position].x = x_var;
			line[position].y = y_var;
			position++;
		}
		else {
			cout << "Your array is too big, either restart and chose a bigger array\nor delete some values\n";
		}
	}
	Point2D findPoint(int place) {
		Point2D point;
		point.x = line[place].x;
		point.y = line[place].y;
		return point;
	}
	void remove() {
		if (position >= 0) {
			line[position].x = line[position].y = 0;
			position--;
		}
		else {
			cout << "You can't delete a point that doesn't exist";
		}
	}
	bool containsPoint() {
		if (position > 0)
			return true;
		else
			return false;
	}
	int numberOfPoints() {
		return position;
	}
	float lineLenght() {
		float ans=0,catcher=0;
		int count = 0;
		while (count+1 < position) {
			
			catcher = line[count].distanceBetween(findPoint(count+1));
			ans = catcher + ans;
			cout << ans << " ";
			count++;
		}
		return ans;
	}
	void printContent() {
		int count = 0;
		while (count < position) {
			cout << line[count].toString();
			count++;
		}
	}
	/*~Polyline() {
		delete[] line;
	}*/
};
/*
int main() {
	int size;
	float xvariable, yvariable;
	cout << "Please enter how many points you want as a maximum: ";
	cin >> size;
	Polyline p_line(size);
	cout << "Enter values for the first point, start with x: ";
	cin >> xvariable;
	cout << "and now y: ";
	cin >> yvariable;
	p_line.add(xvariable, yvariable);
	cout << "For the second point, x: ";
	cin >> xvariable;
	cout << "and now y: ";
	cin >> yvariable;
	p_line.add(xvariable, yvariable);
	cout << "And the third, x: ";
	cin >> xvariable;
	cout << "and now y: ";
	cin >> yvariable;
	p_line.add(xvariable, yvariable);
	cout << "Your values are:\n";
	p_line.printContent();
	cout << "and contains " << p_line.numberOfPoints() << " points\n";
	cout << "\nThe line created by the points is " << p_line.lineLenght() << " long\nNow to test remove, how many points do you want to remove?\n";
	cin >> size;
	while (size > 0) {
		p_line.remove();
		size--;
	}
	cout << "Now we will check wether there still exists points, it is ";
	if (p_line.containsPoint()) {
		cout << "true that there are still points\nThere are currently " << p_line.numberOfPoints()<<" points saved";
	}
	else {
		cout << "untrue that there still are points\n";
	}
	system("pause");
	return 0;
	
}
*/