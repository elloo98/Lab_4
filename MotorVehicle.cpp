#include <iostream>
#include <string>
#include "MotorVehicle.h"

using namespace std;



	MotorVehicle::MotorVehicle(){
		engine.sizeInLiters = 4;
		engine.numberOfCylinders = 8;

		body.colour = "Black";
		body.width = 1.76;
		body.height = 1.43;

		person.name = "Lars Olle Eugensson";
		person.address = "Klintvagen 95";
		person.allowedToDrive = true;

		numberOfTires = 4;
		tireDiameters[0] = tireDiameters[1] = tireDiameters[2] = tireDiameters[3] = 0.185;
		tireDiameters[4] = 0;
		model = "SAAB 9000";
	}

	/*MotorVehicle:: ~MotorVehicle() {
		
	}*/

	void MotorVehicle::setEngine(float sizeInLiters, int numberOfCylinders) {
		engine.sizeInLiters = sizeInLiters;
		engine.numberOfCylinders = numberOfCylinders;
	}

	void MotorVehicle::setBody(string colour, float width, float height) {
		body.colour = colour;
		body.width = width;
		body.height = height;
	}

	void MotorVehicle::setPerson(string name, string address, bool allowedToDrive) {
		person.name = name;
		person.address = address;
		person.allowedToDrive = allowedToDrive;
	}

	void MotorVehicle::setTireNumber(int Tires) {
		numberOfTires = Tires;
		tireDiameters[Tires] = 0;
	}

	void MotorVehicle::setTireDiameter(int tire_num, float tire_size) {
		tireDiameters[tire_num] = tire_size;
	}

	void MotorVehicle::setModel(string model_name) {
		model = model_name;
	}


	void  MotorVehicle::printCar() {
		int count_2 = 0;
		cout << "Model: " << model << "\nColour: " << body.colour << "\nEngine size (in liters): " << engine.sizeInLiters << "\nNumber of cylinders: " << engine.numberOfCylinders << "\nBody width (in meters): " << body.width;
		cout << "\nBody height (in meters): " << body.height << "\nNumber of tires: " << numberOfTires << "\nTire diameter(s):";
		while (tireDiameters[count_2] != 0) {
			cout << ' ' << tireDiameters[count_2];
			count_2++;
		}
		cout << "\n\nOwner: " << person.name << "\nOwner's adress: " << person.address;
		if (person.allowedToDrive == true) {
			printf("\nOwner is allowed to drive\n");
		}
		else {
			printf("\nOwner is not allowed to drive\n");
		}
	}

	