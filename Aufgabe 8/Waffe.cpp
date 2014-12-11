#include "Waffe.h"

using namespace std;

Waffe::Waffe(string name, int schaden, int munition, int kosten){
	this->name = name;
	this->schaden = schaden;
	this->munition = munition;
	this->kosten = kosten;
}

Waffe::Waffe(const Waffe& waffe){
	//this->operator=(const_cast<Waffe&>(waffe));
	this->kosten = waffe.getKosten();
	this->name = waffe.getName();
	this->schaden = waffe.getSchaden();
	this->munition = waffe.getMunition();
}

// Getter- und Setter-Methoden
string& Waffe::getName() const{
	return const_cast<string&>(this->name);
}

int Waffe::getSchaden() const{
	return this->schaden;
}

int Waffe::getMunition() const{
	return this->munition;
}
int Waffe::getKosten() const{
	return this->kosten;
}

void Waffe::setName(std::string& _name){
	this->name = _name;
}

void Waffe::setSchaden(int schaden){
	this->schaden = schaden;
}

void Waffe::setMunition(int munition){
	this->munition = munition;
}

void Waffe::setKosten(int kosten){
	this->kosten = kosten;
}

//Opperatoren ueberschreiben
Waffe Waffe::operator=(const Waffe& waffe){
	this->setKosten(waffe.getKosten());
	this->setMunition(waffe.getMunition());
	this->setName(waffe.getName());
	this->setSchaden(waffe.getSchaden());
	return *this;
}

//Andere Methoden
string Waffe::toString(){
	stringstream ss;
	ss << "Waffenbezeichnung " << this->getName() << ", schaden: " << this->getSchaden() << ", Magazin " << this->getMunition() << ", Kosten " << this->getKosten();
	return ss.str();
}