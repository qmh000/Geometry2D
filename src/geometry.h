#pragma once

#include <sys/types.h>
#include <cstddef>

class Point {
public:
	Point();
	Point(double xx, double yy);
	~Point();

private:
	double x;
	double y;
};

class VertexSequence {
public:
	VertexSequence();
	~VertexSequence();

private:
	size_t size{ 0 };
	Point* p{ nullptr };
};

class Polygon {
public:
	Polygon();
	~Polygon();

	bool contain(Point& p);
	bool contain(Polygon& target);

	bool intersect(Polygon& target);
	
	double distance(Point& p);
	double distance(Polygon& target);
private:
	VertexSequence* boundary{ nullptr };
};

