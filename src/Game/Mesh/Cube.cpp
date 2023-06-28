#include "Cube.h"

const std::string Cube::name = std::string("Cube");
Cube::Cube()
{
	Point a = Point(1, 1, 1, &red);
	Point b = Point(-1, 1, 1, &blue);
	Point c = Point(1, -1, 1, &green);
	Point d = Point(-1, -1, 1, &white);

	Point e = Point(1, 1, -1, &white);
	Point f = Point(-1, 1, -1, &red);
	Point g = Point(1, -1, -1, &blue);
	Point h = Point(-1, -1, -1, &green);

	Point p[8] = { a,b,c,d,e,f,g,h };
	addPoints(p, 8);

	addConnection(2, 0, 1);
	addConnection(1, 3, 2);

	addConnection(5, 4, 6);
	addConnection(5, 6, 7);

	addConnection(0, 4, 5);
	addConnection(0, 5, 1);

	addConnection(7, 6, 2);
	addConnection(7, 2, 3);

	addConnection(1, 5, 7);
	addConnection(1, 7, 3);

	addConnection(0, 2, 6);
	addConnection(0, 6, 4);

	//translate3d(0, 0, 1);
	scale3d(0.5);
}

Cube::Cube(Color& color)
{
	Point a = Point(1, 1, 1, &color);
	Point b = Point(-1, 1, 1, &color);
	Point c = Point(1, -1, 1, &color);
	Point d = Point(-1, -1, 1, &color);

	Point e = Point(1, 1, -1, &color);
	Point f = Point(-1, 1, -1, &color);
	Point g = Point(1, -1, -1, &color);
	Point h = Point(-1, -1, -1, &color);

	Point p[8] = { a,b,c,d,e,f,g,h };
	addPoints(p, 8);

	addConnection(2, 0, 1);
	addConnection(1, 3, 2);

	addConnection(5, 4, 6);
	addConnection(5, 6, 7);

	addConnection(0, 4, 5);
	addConnection(0, 5, 1);

	addConnection(7, 6, 2);
	addConnection(7, 2, 3);

	addConnection(1, 5, 7);
	addConnection(1, 7, 3);

	addConnection(0, 2, 6);
	addConnection(0, 6, 4);

	//translate3d(0, 0, 1);
	scale3d(0.5);

}
