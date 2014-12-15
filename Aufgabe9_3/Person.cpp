#include "Person.h"

using namespace std;

Person::Person()
{
	this->name = "Max";
	this->nachname = "Mustermann";
}

Person::Person(string name, string nachname){
	this->name = name;
	this->nachname = nachname;
}

Person::~Person()
{
}

string Person::getName() const {
	return this->name;
}

string Person::getNachname() const{
	return this->nachname;
}

void Person::setName(std::string name){
	this->name = name;
}

void Person::setNachname(std::string nachname){
	this->nachname = nachname;
}

string Person::toString(){
	stringstream ss;
	ss << "Name: " << this->getName() << "\nNachname: " << this->getNachname() << endl;
	return ss.str();
}