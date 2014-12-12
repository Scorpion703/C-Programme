#include <iostream>
#include <stdio.h>

#include "Raumschiff.h"
#include "Waffe.h"


using namespace std;

void gewonnen(int tmp){
	if (tmp == 1) cout << "Spieler gewonnen!" << endl;
	else cout << "Computer gewonnen" << endl;
}

// Wenn der Spieler entweder mehr Leben/Munition al sder gegner hat oder wenn der Spieler gleichviel hat
bool ende(Raumschiff& a, Raumschiff& b){
	if ((a.getLeben() >= 0 && b.getLeben() <= 0) ||( a.getGesamtMunition() >= 0 && b.getGesamtMunition() <= 0)){
		gewonnen(1);
		return true;
	}else{
		return false;
	}
}

void auswertung(Raumschiff& a, Raumschiff& b){
	if (a.getLeben() > 0 && b.getLeben() <= 0 || a.getGesamtMunition() > 0 && b.getGesamtMunition() <= 0){
		cout << "\n\nRaumschiff " << a.getName() << " hat gewonnen!\n" << endl;
		a.setGeld(a.getGeld() + b.getGeld());
		b.setGeld(0);

		//HIER NOCH SCHIDLE RÜBERSCHAUFELN
	}
	else{
		cout << "\n\nRaumschiff " << b.getName() << " hat gewonnen!\n" << endl;
		b.setGeld(b.getGeld() + a.getGeld());
		a.setGeld(0);

		//HIER NOCH SCHIDLE RÜBERSCHAUFELN
	}

	cout << "\n" << endl;
	cout << a.toString();
	cout << b.toString();
}

int main(int argc, const char* argv[])
{
	string s = "Spieler";
	string p = "Schiffrumpf";
	Raumschiff a = Raumschiff(1250, new Panzerung(p, 50, 100));
	a.addWaffe(Waffe("Todesstrahl", 100, 10000, 1500));
	s = "Spieler2";
	Raumschiff b = Raumschiff(1000, new Panzerung(p, 25, 100));
	b.addWaffe(Waffe("Todesstrahl", 100, 10000, 1500));
	
	//rekursion
	a.angriff(b);
	
	system("pause");
	auswertung(a, b);
	system("pause");
	return 0;
}