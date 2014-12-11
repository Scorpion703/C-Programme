#include "Raumschiff.h"

using namespace std;

// Konstruktoren und Destruktor
Raumschiff::Raumschiff(int leben, Panzerung* panzer) : leben(leben) {
	this->panzer = new Panzerung(panzer->getName(), panzer->getSchutz(), panzer->getKosten());
}
Raumschiff::Raumschiff(const Raumschiff& raumschiff) {
	this->operator=(raumschiff);
}

// Getter- und Setter-Methoden
Panzerung* Raumschiff::getPanzerung() const {
	return this->panzer;
}
int Raumschiff::getGesamtSchlagkraft() const {
	int schaden = 0;
	for (unsigned int i = 0; i < this->waffen.size(); i++) {
		schaden += this->waffen[i].getSchaden();
	}
	return schaden;
}

int Raumschiff::getGesamtMunition() const {
	int Munition = 0;
	for (unsigned int i = 0; i < this->waffen.size(); i++) {
		Munition += this->waffen[i].getMunition();
	}
	return Munition;
}
int Raumschiff::getLeben() const {
	return this->leben;
}

void Raumschiff::setPanzerung(Panzerung *panzer) {
	if (this->panzer == NULL) this->panzer = new Panzerung(panzer->getName(), panzer->getSchutz(), panzer->getKosten());
	else {
		this->panzer->setKosten(panzer->getKosten());
		this->panzer->setName(panzer->getName());
		this->panzer->setSchutz(panzer->getSchutz());
	}
	// this->panzer = panzer;
}
void Raumschiff::setLeben(int leben) {
	this->leben = leben;
}
void Raumschiff::addWaffe(const Waffe waffe) {
	this->waffen.push_back(waffe);
}

void Raumschiff::angriff(Raumschiff& raumschiff){
	// while() ist blödsinn die funktion soll nur einmal aufgerufen werden und dann rekursiv
	if (this->getLeben() >= 0 && raumschiff.getLeben() >= 0 && this->getGesamtMunition() > 0 && raumschiff.getGesamtMunition() > 0){
		this->munitionReduzieren();
		//this->verteidigen(raumschiff);
		raumschiff.verteidigen(*this);
	}
}

void Raumschiff::verteidigen(Raumschiff& verteidiger){
	// wenn die schlagkraft geringer ist als der schutz derpanzerung macht es kein sind das leben zu reduzieren, da die panzerung den schaden auf null fallen läst
	if (this->getGesamtSchlagkraft() > verteidiger.getPanzerung()->getSchutz()) 
		verteidiger.setLeben(verteidiger.getLeben() - (this->getGesamtSchlagkraft() - verteidiger.getPanzerung()->getSchutz()));
	
	cout << this->toString() << endl;
	cout << verteidiger.toString() << endl;
	this->angriff(verteidiger);
}

void Raumschiff::munitionReduzieren(){
	for (int i = 0; i < this->waffen.size(); i++){
		this->waffen.at(i).setMunition(this->waffen.at(i).getMunition() - this->waffen.at(i).getSchaden());
	}
}

//Opperatoren ueberschreiben
Raumschiff Raumschiff::operator=(const Raumschiff& raumschiff) {
	this->leben = raumschiff.getLeben();
	if (raumschiff.panzer != NULL) this->setPanzerung(raumschiff.getPanzerung());
	if (raumschiff.waffen.size() != 0) {
		for (unsigned int i = 0; i < raumschiff.waffen.size(); i++) {
			this->addWaffe(raumschiff.waffen.at(i));
		}
	}
	return *this;
}

//Andere Methoden
string Raumschiff::toString() {
	stringstream ss;
	ss << "Leben: " << this->getLeben() << "\nInsges. Schaden: " << this->getGesamtSchlagkraft() << "\n" << this->panzer->toString() << endl;
	return ss.str();
}