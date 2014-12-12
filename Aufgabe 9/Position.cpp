#include "Position.h"
using namespace std;

Position::Position()
{
}


Position::~Position()
{
}

Position Position::operator=(const Position& pos){
	this->x = pos.getX();
	this->y = pos.getY();
	return *this;
}

void Position::setX(int x){
	this->y = y;
}

void Position::setY(int y){
	this->y = y;
}
int Position::getX() const{
	return this->x;
}
int Position::getY() const{
	return this->y;
}

string Position::toString(){
	stringstream ss;
	ss << "X: " << this->getX() << "| Y: " << this->getY();
	return ss.str();
}