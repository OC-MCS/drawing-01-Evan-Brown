#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;
#include <iostream>

// finish this code; add functions, classes, data as needed

// DrawingShape should be an abstract base class 
// for Circle and Square
struct myShape 
{
	int colour;
	float xPos;
	float yPos;
	ShapeEnum Shape;
};
class DrawingShape 
{
public:
	// draw function
	// takes &win
	// return type: void
	virtual void draw(RenderWindow &win) = 0;

	// get file function
	// return type: void
	virtual myShape getFileRecord() = 0;



};

// add Circle, Square classes below. These are derived from DrawingShape

class Circle : public DrawingShape
{
private:
	CircleShape circle1; //CircleShape is a Graphics lib class

public:
	Circle(Color c, Vector2f pos)
	{
		circle1.setFillColor(c);
		circle1.setPosition(pos);
		circle1.setRadius(7);
	}

	// draw (circle) function
	// takes &win
	// return type: void
	void draw(RenderWindow& win, Vector2f pos, float size)
	{
		circle1.setPosition(pos);
		circle1.setRadius(size);
		circle1.setOutlineThickness(2);
		circle1.setOutlineColor(Color::Blue);
		// for just an outlined button
		circle1.setFillColor(Color::Blue);

		// The following renders the circle on the screen
		// win is a RenderWindow (see provided code)
		win.draw(circle1);

	}

	// get file function
	// return type: void
	myShape getFileRecord()
	{
		myShape newCircle;
		newCircle.colour = circle1.getFillColor().toInteger();
		newCircle.xPos = circle1.getPosition().x;
		newCircle.yPos = circle1.getPosition().y;
		newCircle.Shape = CIRCLE;
		return newCircle;
	}
};

class square : public DrawingShape
{
private:
	RectangleShape RECTANGLE1; // RectangleShape is Graphics lib class
public:
	// draw (square) function
	// takes &win
	// return type: void
	square(Color c, Vector2f pos)
	{
		RECTANGLE1.setFillColor(c);
		RECTANGLE1.setPosition(pos);
		RECTANGLE1.setSize(Vector2f(14, 14));
	}
	void draw(RenderWindow& win, Vector2f pos, float size)
	{
		Vector2f sqPos;
		RECTANGLE1.setPosition(sqPos);
		RECTANGLE1.setOutlineColor(Color::White);
		RECTANGLE1.setOutlineThickness(2);
		RECTANGLE1.setSize(Vector2f(size, size));
		RECTANGLE1.setFillColor(Color::White);

		// renders a RectangleShape
		win.draw(RECTANGLE1);

	}

	// get file function
	// return type: void
	myShape getFileRecord()
	{
		myShape newRec;
		newRec.colour = RECTANGLE1.getFillColor().toInteger();
		newRec.xPos = RECTANGLE1.getPosition().x;
		newRec.yPos = RECTANGLE1.getPosition().y;
		newRec.Shape = SQUARE;
		return newRec;
	}
};
