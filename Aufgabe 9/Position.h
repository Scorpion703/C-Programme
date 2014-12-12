#pragma once
#include <string>
#include <stdlib.h>
#include <iostream>
#include <sstream>

class Position
{
private:
	int x;
	int y; 
public:
	Position();
	~Position();
	void setX(int x);
	void setY(int y);
	int getX()const;
	int getY() const;

	std::string toString();
};

