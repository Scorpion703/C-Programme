#pragma once
#include "Position.h"
class Punkt : public GeoObject
{
private:
public:
	Punkt();
	virtual ~Punkt();
	Punkt operator=(const Punkt punkt);

	virtual void Punkt::verschieben(int dx, int dy);
	virtual void Punkt::zeichnen();
	virtual Position Punkt::getPos();
	virtual void Punkt::setPos(Position pos);

};

