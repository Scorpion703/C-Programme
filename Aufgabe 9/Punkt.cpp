#include "Punkt.h"


Punkt::Punkt()
{
}


Punkt::~Punkt()
{
}

void Punkt::verschieben(int dx, int dy){ //virtual

}
void Punkt::zeichnen(){ //virtual

}
Position Punkt::getPos(){
	return this->pos;
}
void Punkt::setPos(Position pos){
	this->pos = pos;
}
