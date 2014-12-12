#include "Raumschiff.h"

using namespace std;

// Konstruktoren und Destruktor
Raumschiff::Raumschiff(int leben, Panzerung* panzer) : leben(leben) {
	this->name = "WiesoGehtDasNicht";
	this->geld = 3000;
	this->leben = leben;
	this->setPanzerung(panzer);
}

Raumschiff::Raumschiff(int leben, int geld, Panzerung* panzer) : leben(leben) {
	this->name = "testname";
	this->geld = geld;
	this->leben = leben;
	this->setPanzerung(panzer);
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
	if (this->panzer == NULL){ 
		if (this->getGeld() >= panzer->getKosten()){
			this->setGeld(this->getGeld() - panzer->getKosten());
			this->panzer = new Panzerung(panzer->getName(), panzer->getSchutz(), panzer->getKosten());
		}
		else{
			cout << "Panzer kauf nicht moeglich, nicht genug Geld!" << endl;
		}
	}else {
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
	if (this->getGeld() >= waffe.getKosten()){
		this->setGeld(this->getGeld() - waffe.getKosten());
		this->waffen.push_back(waffe);
	}
	else{
		cout << "Sie haben nicht genug Geld um sich eine weitere Waffe zu kaufen!" << endl;
	}
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
	ss << "<--------_RAUMSCHIFF_---------->"
		<< "\nName: " << this->getName()
		<< "\nLeben: " << this->getLeben()
		<< "\nSchaden: " << this->getGesamtSchlagkraft()
		<< "\nGeld: " << this->getGeld() 
		<< this->panzer->toString() 
		<< "\n<------------------------------>"<< endl;
	return ss.str();
}

void Raumschiff::setGeld(int geld){
	this->geld = geld;
}

int Raumschiff::getGeld() const{
	return this->geld;
}

void Raumschiff::setName(string name){
	this->name = name;
}

string Raumschiff::getName()const{
	return this->name;
}