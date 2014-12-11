#ifndef H_WAFFE
#define H_WAFFE
#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>

class Waffe {
	private:
		std::string name;
		int schaden;
		int munition;
		int kosten;
	public:
		// Konstruktoren und Destruktor
		Waffe() : name(""), schaden(0), munition(0), kosten(0){};
		Waffe(std::string name,int schaden, int munition, int kosten);
		Waffe(const Waffe& _Waffe);
		virtual ~Waffe(){};

		// Getter- und Setter-Methoden
		std::string& getName() const;
		int getSchaden() const;
		int getMunition() const;
		int getKosten() const;

		void setName(std::string& _name);
		void setSchaden(int schaden);
		void setMunition(int munition);
		void setKosten(int kosten);

		//Opperatoren ueberschreiben
		Waffe operator=(const Waffe& waffe);

		//Andere Methoden
		std::string toString();
};
#endif