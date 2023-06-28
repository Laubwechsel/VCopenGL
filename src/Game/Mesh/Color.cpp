#include "Color.h"

Color::Color()
{
}

Color::Color(Color* color)
{
	set(color);
}

Color::Color(float red, float green, float blue)
{
	color[0] = red;
	color[1] = green;
	color[2] = blue;
}

Color::Color(float red, float green, float blue, float alpha)
{
	color[0] = red;
	color[1] = green;
	color[2] = blue;
	color[3] = alpha;
}

Color::Color(float* color)
{
	color[0] = color[0];
	color[1] = color[1];
	color[2] = color[2];
	color[3] = color[3];

}


void Color::add(Color * otherColor)
{
	float * otherColorArray = otherColor->getColor();
	color[0] += otherColorArray[0];
	color[1] += otherColorArray[1];
	color[2] += otherColorArray[2];
	delete[] otherColorArray;
}

void Color::add(float red, float green, float blue)
{
	color[0] += red;
	color[1] += green;
	color[2] += blue;

}

void Color::set(Color * newColor)
{
	float* newColorArray = newColor->getColor();
	color[0] = newColorArray[0];
	color[1] = newColorArray[1];
	color[2] = newColorArray[2];
	color[3] = newColorArray[3];
	delete[] newColorArray;
}

void Color::set(float red, float green, float blue)
{
	color[0] = red;
	color[1] = green;
	color[2] = blue;

}

float* Color::getColor()
{
	float* copy = new float[4]{ color[0], color[1], color[2], color[3]};
	return copy;
}

float* Color::getColorNoAlpha()
{
	float* copy = new float[3]{ color[0], color[1], color[2] };
	return copy;
}

