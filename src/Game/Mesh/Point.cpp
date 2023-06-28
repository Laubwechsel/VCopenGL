#include "Point.h"

Point::Point()
{
}

Point::Point(Point* point)
{
	set(point);
}

Point::Point(Point* point, Color* color)
{
	setPosition(point);
	setColor(color);
}

Point::Point(float x, float y)
{
	setPosition2d(x,y);
}

Point::Point(float x, float y, Color* color)
{
	setPosition2d(x, y);
	setColor(color);
}

Point::Point(float x, float y, float z)
{
	setPosition3d(x, y, z);
}

Point::Point(float x, float y, float z, Color* color)
{
	setPosition3d(x, y, z);
	setColor(color);
}

float* Point::getPosition2D()
{
	return new float[2]{ position[0],position[1] };
}

float* Point::getPosition3D()
{
	return new float[3]{position[0],position[1],position[2]};
}

Color* Point::getColor()
{
	return new Color(&color);
}

void Point::set(Point* point)
{
	float* newPosition = point->getPosition3D();
	position[0] = newPosition[0];
	position[1] = newPosition[1];
	position[2] = newPosition[2];
	delete newPosition;
	Color* newColor = point->getColor();
	color = Color(newColor);
	delete newColor;
}

void Point::setPosition(Point* point)
{
	float* newPosition = point->getPosition3D();
	position[0] = newPosition[0];
	position[1] = newPosition[1];
	position[2] = newPosition[2];
	delete newPosition;
}

void Point::setPosition2d(float x, float y)
{
	position[0] = x;
	position[1] = y;
	position[2] = 0;
}

void Point::setPosition3d(float x, float y, float z)
{
	position[0] = x;
	position[1] = y;
	position[2] = z;

}

void Point::translate2d(float x, float y)
{
	position[0] += x;
	position[1] += y;
}

void Point::translate2d(Point* amount)
{
	float* direction = amount->getPosition2D();
	position[0] += direction[0];
	position[1] += direction[1];
	delete[] direction;
}

void Point::translate3d(float x, float y, float z)
{
	position[0] += x;
	position[1] += y;
	position[2] += z;
}

void Point::translate3d(Point* amount)
{
	float* direction = amount->getPosition2D();
	position[0] += direction[0];
	position[1] += direction[1];
	position[2] += direction[2];
	delete[] direction;

}

void Point::scale3d(float factor)
{
	scale3d(factor, factor, factor);
}

void Point::scale3d(float x, float y, float z)
{
	position[0] *= x;
	position[1] *= y;
	position[2] *= z;
}

void Point::setColor(Point* point)
{
	Color* newColor = point->getColor();
	color.set(newColor);
	delete(newColor);
}

void Point::setColor(Color* newColor)
{
	color.set(newColor);
}
