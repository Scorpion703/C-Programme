#pragma once
#include "Person.h"
class Angestellter : public Person{
private:
	int gehalt;
public:
	Angestellter();
	Angestellter(std::string name, std::string nachname, int gehalt);
	~Angestellter();
	int getGehalt();
	void setGehalt(int gehalt);
	std::string toString();
};

