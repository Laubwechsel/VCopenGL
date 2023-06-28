#pragma once

#include "Color.h"
class Point {
public:
	Point();
	Point(Point* point);
	Point(Point* point, Color* color);
	Point(float x, float y);
	Point(float x, float y, Color* color);
	Point(float x, float y,float z);
	Point(float x, float y,float z, Color* color);

	float* getPosition2D();
	float* getPosition3D();
	Color* getColor();

	void set(Point* point);
	void setPosition(Point* point);
	void setPosition2d(float x, float y);
	void setPosition3d(float x, float y, float z);

	void translate2d(float x, float y);
	void translate2d(Point* amount);

	void translate3d(float x, float y,float z);
	void translate3d(Point* amount);

	void scale3d(float factor);
	void scale3d(float x,float y, float z);

	void setColor(Point* point);
	void setColor(Color* color);
private:
	float position[3] = { 0,0,0 };
	Color color = Color();
};

