#pragma once
#include <string.h>

class Position
{
public:
	Position();
	~Position();
	void setX(int x);
	void setY(int y);
	int getX()const;
	int getY() const;

	virtual std::string toString();
private:
	int x;
	int y; 

};

