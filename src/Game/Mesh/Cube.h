#pragma once
#include "Mesh.h"
#include <string>

class Cube: public Mesh {
public:
	Cube();
	Cube(Color &color);
	static const std::string name;
};