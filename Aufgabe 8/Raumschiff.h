#ifndef H_RAUMSCHIFF
#define H_RAUMSCHIFF
#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include "Panzerung.h"
#include "Waffe.h"
class Raumschiff {
private:
	std::string name;
	Panzerung *panzer;
	std::vector<Waffe> waffen;
	int leben;
	int geld;
public:
	// Konstruktoren und Destruktor
	Raumschiff() : leben(100), panzer(NULL){ waffen.reserve(10); }
	Raumschiff(int leben, Panzerung* panzer);
	Raumschiff(int leben, int geld, Panzerung* panzer);
	Raumschiff(const Raumschiff&);
	virtual ~Raumschiff() { delete panzer; };

	// Getter- und Setter-Methoden
	Panzerung* getPanzerung() const;
	Waffe getWaffen();
	int getLeben() const;
	int getGeld() const;
	std::string getName() const;
	// hilfs Methode zur berechnung des Schadens des Schiffes
	int getGesamtSchlagkraft() const;
	int Raumschiff::getGesamtMunition() const;

	void setPanzerung(Panzerung *panzer);
	void setLeben(int leben);
	void setName(std::string name);
	void setGeld(int geld);

	void addWaffe(const Waffe waffe);
	void munitionReduzieren();
	

	void angriff(Raumschiff& raumschiff);
	void verteidigen(Raumschiff& verteidigen);

	//Opperatoren ueberschreiben
	Raumschiff operator=(const Raumschiff& raumschiff);

	//Andere Methoden
	std::string toString();
};
#endif