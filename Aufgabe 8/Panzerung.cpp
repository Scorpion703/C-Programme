#include "Panzerung.h"

using namespace std;


// Konstruktoren und Destruktor


Panzerung::Panzerung(std::string name, int schutz, int kosten){
	this->name = name;
	this->schutz = schutz;
	this->kosten = kosten;
}

Panzerung::Panzerung(const Panzerung& panzerung){
	this->name = panzerung.getName();
	this->schutz = panzerung.getSchutz();
	this->kosten = panzerung.getKosten();
}

Panzerung::~Panzerung(){

}

// Getter- und Setter-Methoden
string& Panzerung::getName() const{
	return const_cast<string&>(this->name);
}

int Panzerung::getSchutz() const{
	return this->schutz;
}

int Panzerung::getKosten() const{
	return this->kosten;
}

void Panzerung::setName(string& name){
	this->name = name;
}

void Panzerung::setSchutz(int schutz){
	this->schutz = schutz;
}

void Panzerung::setKosten(int kosten){
	this->kosten = kosten;
}

//Opperatoren ueberschreiben
Panzerung Panzerung::operator=(const Panzerung& panzerung){
	this->setKosten(panzerung.getKosten());
	this->setName(panzerung.getName());
	this->setSchutz(panzerung.getSchutz());
	return *this;
}

//Andere Methoden
string Panzerung::toString(){
	stringstream ss;
	ss << "\n\n#####Panzerung#####\n" <<
		"\nName: " << this->getName() <<
		"\nSchutz: " << this->getSchutz() <<
		"\nKosten: " << this->getKosten() << "$" <<endl;

	return ss.str();
}