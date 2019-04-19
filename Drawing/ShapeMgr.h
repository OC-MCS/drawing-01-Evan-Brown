#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class.

class ShapeMgr
{
private:
	vector<DrawingShape*> list;
	
public:
	ShapeMgr()
	{
		// le nothing
	}

	// function to add a shape
	// takes position, shape type, and colour
	// return type: void
	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		if (whichShape == CIRCLE)
		{
			list.push_back(new Circle(color, pos));
		}
		else
		{
			list.push_back(new square(color, pos));
		}
	}

	void fileWrite(fstream& file)
	{
		myShape New;
		for (int i = 0; i < list.size(); i++)
		{
			New = list[i]->getFileRecord();
			file.write(reinterpret_cast<char*>(&New), sizeof(New));
		}
	}

	void fileRead(fstream& file)
	{
		myShape New;
		while (file.read(reinterpret_cast<char*>(&New)), sizeof(New))
		{
			addShape(Vector2f(New.xPos, New.yPos), New.Shape, Color(New.colour));
		}
	}

	const vector<DrawingShape*> &getList()
	{
		return list;
	}
	
};
