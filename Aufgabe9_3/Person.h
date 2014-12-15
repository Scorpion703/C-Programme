#pragma once

#include <string>
#include <sstream>

class Person
{
private: 
	std::string name;
	std::string nachname;
public:
	Person();
	Person(std::string, std::string);
	~Person();

	std::string getName() const;
	std::string getNachname() const;

	void setName(std::string name);
	void setNachname(std::string nachname);
	std::string Person::toString();
};

