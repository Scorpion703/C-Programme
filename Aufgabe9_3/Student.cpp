#include "Student.h"

using namespace std;

Student::Student() : Person("S_Max", "S_Mustermann")
{
	this->matrNr = 0001;
}

Student::Student(string name, string nachname, int matrNr) :
Person(name, nachname){
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
		"\nMatNr: " << this->getMatrNr() << endl;
	return ss.str();
}