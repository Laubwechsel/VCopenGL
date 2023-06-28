#pragma once
#include <string>

class Color {
public:
	Color();
	Color(Color * color);
	Color(float red,float green, float blue);
	Color(float red, float green, float blue, float alpha);
	Color(float * color);
	void add(Color * otherColor);
	void add(float red, float green, float blue);
	void set(Color * newColor);
	void set(float red, float green, float blue);
	float* getColor();
	float* getColorNoAlpha();

private:
	float color[4] = {0,0,0,1};
};

static Color red = Color(1, 0, 0, 1);
static Color green = Color(0, 1, 0, 1);
static Color blue = Color(0, 0, 1, 1);
static Color yellow = Color(1, 1, 0, 1);
static Color aqua = Color(0, 1, 1, 1);
static Color fuchsia = Color(1, 0, 1, 1);
static Color white = Color(1, 1, 1, 1);
static Color black = Color(0, 0, 0, 1);
static Color grey = Color(0.4, 0.4, 0.4, 1);
static Color brown = Color(0.4, 0.2, 0.0, 1);

static std::string redString = "red";
static std::string greenString = "green";
static std::string blueString = "blue";
static std::string yellowString = "yellow";
static std::string aquaString = "aqua";
static std::string fuchsiaString = "fuchsia";
static std::string whiteString = "white";
static std::string blackString = "black";
static std::string greyString = "gray";
static std::string brownString = "brown";
