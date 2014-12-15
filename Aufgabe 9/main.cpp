#include <iostream>
#include "GeoObject.h"
#include <Vector>
#include "Punkt.h"
#include "Linie.h"
#include "Kreis.h"
#include "Rechteck.h"
using namespace std;
int main(){
	cout << "haloo Welt" << endl;
	
	vector<GeoObject*> geoobjekte;
	//2 Punkt‐, 3 Linie‐, 1 Kreis‐ und 1 Rechteck‐Objekt
	//Objekte erstellen:
	Punkt p1 = Punkt();
	Punkt p2 = Punkt();
	
	Linie l1 = Linie();
	Linie l2 = Linie();
	Linie l3 = Linie();
	
	Kreis k1 = Kreis();
	
	Rechteck r1 = Rechteck();
	
	//Erstellte Obejkte zum Vector hinzufuegen
	geoobjekte.push_back(p1);
	geoobjekte.push_back(p2);
	
	geoobjekte.push_back(l1);
	geoobjekte.push_back(l2);
	geoobjekte.push_back(l3);
	
	geoobjekte.push_back(k1);

	geoobjekte.push_back(r1);

	//Aufruf der zeichnen() Methode der einzelnen GeoObjekte im Vector:
	for (int i = 0; i < geoobjekte.size(); i++){
		cout << geoobjekte[i]->zeichnen() 
			<< "\nObjekt: " << geoobjekte[i].typeID();
	}

	system("pause");
	return 0;
} 