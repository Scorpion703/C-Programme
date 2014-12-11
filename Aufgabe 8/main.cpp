#include <iostream>
#include <stdio.h>

#include "Raumschiff.h"
#include "Waffe.h"


using namespace std;

void gewonnen(int tmp){
	if (tmp == 1) cout << "Spieler gewonne!" << endl;
	else cout << "Computer gewonnen" << endl;
}

bool ende(Raumschiff& a, Raumschiff& b){
	if ((a.getLeben() > 0 && b.getLeben() <= 0) ||( a.getGesamtMunition() > 0 && b.getGesamtMunition() <= 0)){
		gewonnen(1);
		return true;
	}else{
		return false;
	}
}

int main(int argc, const char* argv[])
{
	cout << "hallo Welt " << endl;
	string s = "Spieler";
	string p = "Schiffrumpf";
	Raumschiff a = Raumschiff(1000, new Panzerung(p, 0, 100));
	a.addWaffe(Waffe("Todesstrahl", 100, 10000, 1500));
	s = "Spieler2";
	Raumschiff b = Raumschiff(1000, new Panzerung(p, 0, 100));
	b.addWaffe(Waffe("Todesstrahl", 100, 10000, 1500));

	while (!ende(a, b)){
		a.angriff(b);
		cout << "-----Spieler----- \n" << a.toString() << endl;
		cout << "-----Computer---- \n" << b.toString() << endl;
		b.angriff(a);
		cout << "-----Spieler----- \n" << a.toString() << endl;
		cout << "-----Computer---- \n" << b.toString() << endl;
		//system("CLS");
	}

	system("pause");
}