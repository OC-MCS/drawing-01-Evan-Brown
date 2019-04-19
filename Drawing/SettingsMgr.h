#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

// die function
	// takes a message as a string
	// return type: void
void die(string msg)
{
	cout << msg << endl;
	exit(-1);
}
enum ShapeEnum { CIRCLE, SQUARE };
// finish this code; add functions, data as needed

class SettingsMgr
{
private:
	ShapeEnum curShape;
	Color curColour;
public:
	SettingsMgr(Color startingColor, ShapeEnum startingShape)
	{
		curShape = startingShape;
		curColour = startingColor;
	}

	// gets the current colour
	// returns colour
	Color getCurColor()
	{
		return curColour;
	}

	// gets the current shape
	// returns shape
	ShapeEnum getCurShape()
	{
		return curShape;
	}

	void setColour(Color c)
	{
		curColour = c;
	}
	void setShape(ShapeEnum s)
	{
		curShape = s;
	}

	void fileWrite(fstream& file)
	{
		unsigned int newColour;
		newColour = curColour.toInteger();
		file.write(reinterpret_cast<char*>(&newColour), sizeof(newColour));
		file.write(reinterpret_cast<char*>(&curShape), sizeof(curShape));
	}

	void fileRead(fstream& file)
	{
		unsigned int newColour;
		
		file.read(reinterpret_cast<char*>(&newColour), sizeof(newColour));
		file.read(reinterpret_cast<char*>(&curShape), sizeof(curShape));
		curColour = Color(newColour);
	}

};
