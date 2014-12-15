#include "Hiwi.h"

using namespace std;

Hiwi::Hiwi()
{
}

Hiwi::Hiwi(std::string name, std::string nachname, int matrnr, int gehalt, int stunden) :
Student(name, nachname, matrnr), Angestellter("", "", gehalt) {
	this->stunden = stunden;
}

Hiwi::~Hiwi()
{
}

int Hiwi::getStunden(){
	return this->stunden;
}

void Hiwi::setStunden(int stunden){
	this->stunden = stunden;
}

string Hiwi::toString(){
	stringstream ss;
	ss << "Name: " << Student::getName() << "\nNachname: " << Student::getNachname() <<
		"\nMatrNr: " << this->getMatrNr() <<
		"\nGehalt: " << this->getGehalt() <<
		"\nStunden: " << this->getStunden() << endl;
	return ss.str();
}