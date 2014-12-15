#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "Angestellter.h"
#include "Hiwi.h"
#include "Person.h"
#include "Student.h"

using namespace std;

int main(){
	Angestellter a("Hugo", "Meier", 1200);

	Hiwi h("Hans", "Mueller", 1001, 1400, 45);

	Person p("Erndt", "Ikke");

	Student s("Daniel", "P", 1214);

	cout << "----Angestellter-----" << endl;
	cout << a.toString() << endl;
	cout << "-------Hiwi----------" << endl;
	cout << h.toString() << endl;
	cout << "-------Person--------" << endl;
	cout << p.toString() << endl;
	cout << "--------Student-------" << endl;
	cout << s.toString() << endl;

	cout << "\n\n" << s.getName() << endl;

	cout << "\n" << h.getNachname() << endl;

	cout << "Hallo Welt!" << endl;
	system("pause");
	return 0;
}