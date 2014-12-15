#include "Angestellter.h"

using namespace std;

Angestellter::Angestellter() : Person("A_Max", "A_Mustermann")
{
	this->gehalt = 100;
}


Angestellter::~Angestellter()
{
}

Angestellter::Angestellter(string name, std::string nachname, int gehalt) : Person(name, nachname){
	this->setName(name);
	this->setNachname(nachname);
	this->gehalt = gehalt;
}


int Angestellter::getGehalt(){
	return this->gehalt;
}

void Angestellter::setGehalt(int gehalt){
	this->gehalt = gehalt;
}

string Angestellter::toString(){
	stringstream ss;
	ss << "Name: " << this->getName() << "\nNachname: " << this->getNachname() <<
		"\nGehalt: " << this->getGehalt() << endl;
	return ss.str();
}