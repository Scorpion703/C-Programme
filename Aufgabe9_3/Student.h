#pragma once
#include "Person.h"
#include <string>
#include <sstream>

class Student : public Person{
private:
	int matrNr;
public:
	Student();
	Student::Student(string name, string nachname, int matrNr);
	~Student();
	void setMatrNr(int matrNr);
	int getMatrNr();
	std::string toString();
};

