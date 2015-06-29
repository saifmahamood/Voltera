#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

class Point
{
public:
	double x;
	double y;

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	Point() {}
	~Point();

	/* data */
};


class Polygon {
	const static double epsilon = 0.0000001;
	const static double twopi = 6.283185307179586476925287;
public:
	Polygon() {}
	Polygon(vector<Point> vertices) {
		this->vertices = vertices;
	}
	vector<Point> vertices;

	vector<Point> getVertices() {
		return this->vertices;
	}

	bool pointInPolygon(Point p) {
		double angSum = angleSum(p);
		if(angSum - this->twopi <= epsilon)
			return true;
		else return false;
	}

	double modulus(Point p) {
		return sqrt(pow(p.x,2) + pow(p.y,2));
	}

	double angleSum(Point p) {
		double sum = 0;
		Point v1;
		Point v2;
		double m1, m2, costheta;
		vector<Point>::iterator i; 
		this->vertices[0].x;
		for (int i = 0; i < this->vertices.size(); i++)
		{
			v1.x = this->vertices[i].x - p.x;
			v1.y = this->vertices[i].y - p.y;
			v2.x = this->vertices[i+1].x - p.x;
			v2.y = this->vertices[i+1].y - p.y;
			m1 = modulus(v1);
			m2 = modulus(v2);

			if(m1 * m2 <= this->epsilon)
				return this->twopi;
			else
				costheta = (pow(v1.x,2) + pow(v1.y,2))/(m1 * m2);
			sum += acos(costheta);
		}
		return sum;
	}
	~Polygon(){}

};

class regularOctagon: public Polygon
{
public:
	regularOctagon();

	void contract(double distance) {

		Point v1;
		v1.x = abs(this->vertices[0].x - this->vertices[1].x);
		v1.y = abs(this->vertices[0].y - this->vertices[1].y); 
		double lengthEdge = modulus(v1);

		double sideChange = sqrt(lengthEdge/distance);

		for (int i = 0; i < vertices.size(); ++i)
		{
			this->vertices[i].x /= sideChange;
			this->vertices[i].y /= sideChange;
		}
	}
	~regularOctagon();

	/* data */
};


/* test cases
For the point in polygon, I will make sure to test for whether the point is
outside, inside and on the edges of the polygon. 

As for the contract method, I will calculate the area of the old and new polygon
and check if it's the expected reduction 
*/



int main(void) {
	return 0;
}