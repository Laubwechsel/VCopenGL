#include "CompositeMesh.h"
#include <string>

CompositeMesh::CompositeMesh(std::string newName) : name(newName)
{

}

void CompositeMesh::addMesh(Mesh* toAdd)
{
	meshs.push_back(Mesh(toAdd));
}

std::vector<float>* CompositeMesh::getVerticies2dWithColor()
{
	std::vector<float> *result = new std::vector<float>;
	for (size_t i = 0; i < meshs.size(); i++)
	{
		std::vector<Point>* points = meshs[i].getPoints();
		for (size_t i = 0; i < points->size(); i++)
		{
			float* position2d = points->at(i).getPosition2D();
			for (size_t o = 0; o < 2; o++)
			{
				result->push_back(position2d[o]);
			}
			delete[] position2d;

			Color* color = points->at(i).getColor();
			float* colorNoAlpha = color->getColorNoAlpha();
			for (size_t o = 0; o < 3; o++)
			{
				result->push_back(colorNoAlpha[o]);
			}
			delete color;
			delete[] colorNoAlpha;
		}
	}
	return result;
}

std::vector<float>* CompositeMesh::getVerticies3dWithColor()
{
	std::vector<float>* result = new std::vector<float>;
	for (size_t i = 0; i < meshs.size(); i++)
	{
		std::vector<Point>* points = meshs[i].getPoints();
		for (size_t i = 0; i < points->size(); i++)
		{
			float* position3d = points->at(i).getPosition3D();
			for (size_t o = 0; o < 3; o++)
			{
				result->push_back(position3d[o]);
			}
			delete[] position3d;

			Color* color = points->at(i).getColor();
			float* colorNoAlpha = color->getColorNoAlpha();
			for (size_t o = 0; o < 3; o++)
			{
				result->push_back(colorNoAlpha[o]);
			}
			delete color;
			delete[] colorNoAlpha;
		}
	}
	return result;
}

std::vector<unsigned int>* CompositeMesh::getIndicies()
{
	std::vector<unsigned int>* result = new std::vector<unsigned int>();
	unsigned int offset = 0;

	for (size_t i = 0; i < meshs.size(); i++)
	{

		std::vector<std::array<unsigned int, 3>>* indicies = meshs.at(i).getConnections();
		for (size_t i = 0; i < indicies->size(); i++)
		{
			for (size_t o = 0; o < 3; o++)
			{
				result->push_back(indicies->at(i)[o] + offset);
			}
		}
		offset += meshs.at(i).getPointsCount();
	}
	indiciesAmmount = result->size();
	return result;
}

unsigned int CompositeMesh::getIndiciesAmount()
{
	return indiciesAmmount;
}
