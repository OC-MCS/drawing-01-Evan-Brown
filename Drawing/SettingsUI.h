#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

// finish this code; add functions, data as needed

class SettingsUI
{
private:
	SettingsMgr *mgr;
	CircleShape red;
	CircleShape blue;
	CircleShape green;
	CircleShape newCircle;
	RectangleShape newSquare;

public:
	SettingsUI(SettingsMgr *mgr)
	{
		
	}

	//draw
	//draws the interface
	//return type:void
	void draw(RenderWindow& win)
	{
		// first have to load font
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");

		// title
		Text title("Drawing Color", font, 25);
		title.setPosition(30, 25);
		win.draw(title);

	}

	// die function
	// takes a message as a string
	// return type: void
	void die(string msg)
	{
		cout << msg << endl;
		exit(-1);
	}


};
