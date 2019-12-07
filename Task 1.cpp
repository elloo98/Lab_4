#include <iostream>
#include <string>
#include "MotorVehicle.h"
/*
int main(){
	char input_char[50];
	int input_int,coordinate=0,size=0;
	cout << "How many vehicles do you want? ";
	cin >> size;
	MotorVehicle* vehicle = new MotorVehicle[size];
	while (1) {
		printf("\n\n+--------+\n|  MENU  |\n+--------+\n\n");
		printf("1:Show info\n2:Edit engine\n3:Edit body\n4:Edit wheels\n5:Edit owner\n6:Edit model\n7:Change active vehicle\n8:Quit\n\n");
		scanf_s("%s", input_char, _countof(input_char));
		input_int = input_char[0] - 48;

		//Show info
		if (input_int == 1) {
			vehicle[coordinate].printCar();
			system("pause");
		}

		//Edit engine
		else if (input_int == 2) {
			float liters;
			int cylinders;
			cout << "How many liters is the engine? ";
			cin >> liters;
			cout << "How many cylinders does the engine have? ";
			cin >> cylinders;
			vehicle[coordinate].setEngine(liters, cylinders);
		}

		//Edit body
		else if (input_int == 3) {
			string colour;
			float width, height;
			cout << "What colour is the vehicle? ";
			cin >> colour;
			cout << "How wide is the vehicle (in meters)? ";
			cin >> width;
			cout << "How high is the vehicle (in meters)? ";
			cin >> height;
			vehicle[coordinate].setBody(colour, width, height);
		}

		//Edit wheels
		else if (input_int == 4) {
			int size,count=0;
			float tire;
			cout << "How many wheels does your vehicle have? ";
			cin >> size;
			vehicle[coordinate].setTireNumber(size);
			cout << "Now enter the size of the " << size << " tires\n";
			while (count < size) {
				cin >> tire;
				vehicle[coordinate].setTireDiameter(count, tire);
				count++;
			}
		}

		//Edit owner
		else if (input_int == 5) {
			string name, adress;
			char yesno;
			cin.ignore(256, '\n');
			cout << "What is the name of the owner?"<<endl;
			getline(cin, name);
			cout << "What is their address?"<<endl;
			getline(cin,adress);
			cout << "Are they allowed to drive? (y/n) ";
			cin >> yesno;
			if (yesno == 'y') {
				vehicle[coordinate].setPerson(name, adress, true);
			}
			else if (yesno == 'n') {
				vehicle[coordinate].setPerson(name, adress, false);
			}
			else {
				cout << "The input isn't recognized, value set to false\n";
				vehicle[coordinate].setPerson(name, adress, false);
			}
		}

		//Edit model
		else if (input_int == 6) {
			string model;
			cout << "What is the model of the vehicle?\n";
			cin >> model;
			vehicle[coordinate].setModel(model);
		}

		//Change Vehicle
		else if (input_int == 7) {
			cout << "Please enter a number to edit: ";
			cin >> input_int;
			if (input_int > size) {
				cout << "That vehicle doesn't exist\n";
				system("pause");
			}
			else if (input_int <= 0) {
				cout << "Please enter a non-zero positive number\n";
				system("pause");
			}
			else {
				coordinate = input_int - 1;
			}
		}

		//Quit
		else if (input_int == 8) {
			cout << "The program will now exit";
			delete[]vehicle;
			return 0;
		}
		else {
			cout << "That isn't an available option, please select something else\n";
			system("pause");
		}
	}
}
*/