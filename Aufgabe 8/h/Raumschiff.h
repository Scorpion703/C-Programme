#ifndef H_RAUMSCHIFF
#define H_RAUMSCHIFF
#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>

#include "Panzerung.h"
#include "Waffe.h"
class Raumschiff {
private:
	Panzerung *panzer;
	std::vector<Waffe> waffen;
	int leben;
public:
	// Konstruktoren und Destruktor
	Raumschiff() : leben(100), panzer(NULL){ waffen.reserve(10); }
	Raumschiff(int leben, Panzerung* panzer);
	Raumschiff(const Raumschiff&);
	virtual ~Raumschiff() { delete panzer; };

	// Getter- und Setter-Methoden
	Panzerung* getPanzerung() const;
	Waffe getWaffen();
	int getLeben() const;
	// hilfs Methode zur berechnung des Schadens des Schiffes
	int getGesamtSchlagkraft() const;
	int Raumschiff::getGesamtMunition() const;

	void setPanzerung(Panzerung *panzer);
	void setLeben(int leben);
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