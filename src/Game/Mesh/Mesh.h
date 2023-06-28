#pragma once
#include "Point.h"
#include <vector>
#include <array>
class Mesh {
public:
	Mesh();
	Mesh(Mesh * toCopy);
	void addTriangle(Point * newPoints);
	void addPoints(std::vector<Point> newPoints);
	void addPoints(Point* newPoints,int amount);
	void addPoint(Point * newPoint);
	void addConnections(std::vector<std::array<unsigned int, 3>>* toAdd);
	void addConnections(unsigned int* newConnections, unsigned int amount);
	void addConnection(unsigned int* newConnection);
	void addConnection(std::array<unsigned int,3>* newConnection);
	void addConnection(unsigned int a, unsigned int b, unsigned int c);
	std::vector<Point>* getPoints();
	std::vector<std::array<unsigned int, 3>>* getConnections();
	unsigned int getPointsCount();
	void translate2d(float x, float y);
	void translate2d(Point* amount);
	void translate3d(float x, float y,float z);
	void translate3d(Point* amount);
	void scale3d(float factor);
	void scale3d(float x,float y,float z);
private:
	std::vector<Point> points = std::vector<Point>();
	std::vector<std::array<unsigned int,3>> connections = std::vector<std::array<unsigned int, 3>>();
};