#pragma once
#include "Student.h";
#include "Angestellter.h"
class Hiwi : public Student, public Angestellter
{
private:
	int stunden;
public:
	Hiwi();
	Hiwi(std::string name, std::string nachname, int matrnr, int gehalt, int stunden);
	~Hiwi();
	int getStunden();
	void setStunden(int stunden);
	std::string toString();
};

