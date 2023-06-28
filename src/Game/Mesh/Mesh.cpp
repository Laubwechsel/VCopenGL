#include "Mesh.h"

Mesh::Mesh()
{
}

Mesh::Mesh(Mesh* toCopy)
{
	std::vector<Point>* copyPoints = toCopy->getPoints();
	for (size_t i = 0; i < copyPoints->size(); i++)
	{
		addPoint(&copyPoints->at(i));
	}
	std::vector<std::array<unsigned int, 3>>* copyConnections = toCopy->getConnections();
	addConnections(copyConnections);
}

void Mesh::addTriangle(Point* newPoints)
{
	for (size_t i = 0; i < 3; i++)
	{
		points.push_back(Point(newPoints[i]));
	}
	size_t size = points.size();
	unsigned int newConnections[3] = { size - 3,size - 2,size - 1 };
	addConnection(newConnections);
}

void Mesh::addPoints(std::vector<Point> newPoints)
{
	points.insert(points.begin(), newPoints.begin(), newPoints.end());
}

void Mesh::addPoints(Point* newPoints, int amount)
{
	for (size_t i = 0; i < amount; i++)
	{
		addPoint(&newPoints[i]);
	}
}

void Mesh::addPoint(Point* newPoint)
{
	points.push_back(Point(newPoint));
}

void Mesh::addConnections(std::vector<std::array<unsigned int, 3>>* toAdd)
{
	for (size_t i = 0; i < toAdd->size(); i++)
	{
		connections.push_back(std::array<unsigned int, 3>(toAdd->at(i)));
	}
}


void Mesh::addConnections(unsigned int* newConnections, unsigned int amount)
{
	for (size_t i = 0; i < amount; i++)
	{
		addConnection(&newConnections[i * 3]);
	}
}

void Mesh::addConnection(unsigned int* newConnection)
{
	connections.push_back(std::array<unsigned int, 3>());
	connections.back()[0] = newConnection[0];
	connections.back()[1] = newConnection[1];
	connections.back()[2] = newConnection[2];
}

void Mesh::addConnection(std::array<unsigned int, 3>* newConnection)
{
	connections.push_back(std::array<unsigned int, 3>(*newConnection));
}

void Mesh::addConnection(unsigned int a, unsigned int b, unsigned int c)
{
	connections.push_back({ a, b, c });
}

std::vector<Point>* Mesh::getPoints()
{
	return &points;
}

std::vector<std::array<unsigned int, 3>>* Mesh::getConnections()
{
	return &connections;
}

unsigned int Mesh::getPointsCount()
{
	return points.size();
}

void Mesh::translate2d(float x, float y)
{
	for (size_t i = 0; i < points.size(); i++)
	{
		points.at(i).translate2d(x, y);
	}
}

void Mesh::translate2d(Point* amount)
{
	for (size_t i = 0; i < points.size(); i++)
	{
		points.at(i).translate2d(amount);
	}

}

void Mesh::translate3d(float x, float y, float z)
{
	for (size_t i = 0; i < points.size(); i++)
	{
		points.at(i).translate3d(x, y,z);
	}

}

void Mesh::translate3d(Point* amount)
{
	for (size_t i = 0; i < points.size(); i++)
	{
		points.at(i).translate3d(amount);
	}

}

void Mesh::scale3d(float factor)
{
	scale3d(factor, factor, factor);
}

void Mesh::scale3d(float x, float y, float z)
{
	for (size_t i = 0; i < points.size(); i++)
	{
		points.at(i).scale3d(x,y,z);
	}
}
