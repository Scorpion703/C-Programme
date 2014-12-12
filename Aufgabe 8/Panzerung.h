#ifndef H_PANZERUNG
#define H_PANZERUNG
#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <string.h>
class Panzerung {
	private:
		std::string name;
		int schutz;
		int kosten;
	public:
		// Konstruktoren und Destruktor
		Panzerung() : name(""), schutz(0),kosten(0){}; 
		Panzerung(std::string name,int schutz, int kosten);
		Panzerung(const Panzerung& panzerung);
		virtual ~Panzerung();

		// Getter- und Setter-Methoden
		std::string& getName() const;
		int getSchutz() const;
		int getKosten() const;

		void setName(std::string& name);
		void setSchutz(int schutz);
		void setKosten(int kosten);
		void setSchutz(double faktor);

		//Opperatoren ueberschreiben
		Panzerung operator=(const Panzerung& raumschiff);

		//Andere Methoden
		std::string toString();
};
#endif