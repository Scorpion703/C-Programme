#include "Student.h"

using namespace std;

Student::Student()
{
	this->setName("Student_Max");
	this->setNachname("Student_Mustermann");
	this->matrNr = 0001;
}

Student::Student(string name, string nachname, int matrNr) {
	this->setName(name);
	this->setNachname(nachname);
	this->matrNr = matrNr;
}

Student::~Student()
{
}

void Student::setMatrNr(int matrNr){
	this->matrNr = matrNr;
}
int Student::getMatrNr(){
	return this->matrNr;
}

string Student::toString(){
	stringstream ss;
	ss << "Name: " << this->getName() << "\nNachname: " << this->getNachname() <<
		"MatNr: " << this->getMatrNr() << endl;
	return ss.str();
}