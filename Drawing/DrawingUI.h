#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

// finish this code; add functions, data as needed

class DrawingUI
{
private:
	CircleShape colorBtn;

public:
	DrawingUI(Vector2f p)
	{

	}

	//function that adds the shape
	//takes render window and a pointer to an instance of ShapeMgr
	//return type: void
	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		if (isMouseInCanvas)
		{
			addShape(mousePos, whichShape, color);
		}
	}
	
	// function that checks if the mouse is in the canvas
	// takes the mouse position vector
	// return type: bool
	bool isMouseInCanvas(Vector2f mousePos)
	{
		if (colorBtn.getGlobalBounds().contains(mousePos))
		{
			return true;
		}
		else
		{
			return false;
		}
	}


};

