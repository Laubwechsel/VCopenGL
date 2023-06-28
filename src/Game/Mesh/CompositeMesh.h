#pragma once

#include <vector>
#include "Mesh.h"
#include <string>

class CompositeMesh {
public:
	CompositeMesh(std::string newName);

	void addMesh(Mesh* toAdd);


	std::vector<float>* getVerticies2dWithColor();
	std::vector<float>* getVerticies3dWithColor();
	/*
	float* getVerticies2dWithoutColor();
	float* getVerticies3dWithoutColor();
	*/
	std::vector<unsigned int>* getIndicies();
	unsigned int getIndiciesAmount();
	std::string name;
private:
	std::vector<Mesh> meshs;
	unsigned int indiciesAmmount = 0;
};

