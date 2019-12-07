#pragma once
#include <iostream>
#include <string>
using namespace std;


class Engine {
public:
	float sizeInLiters;
	int numberOfCylinders;
};

class Body {
public:
	string colour;
	float width, height;
};

class Person {
public:
	string name;
	string address;
	bool allowedToDrive;
};

class MotorVehicle {
public:
	MotorVehicle();
	//~MotorVehicle();
	void setEngine(float sizeInLiters, int numberOfCylinders);
	void setBody(string colour, float width, float height);
	void setPerson(string name, string address, bool allowedToDrive);
	void setTireNumber(int Tires);
	void setTireDiameter(int tire_num, float tire_size);
	void setModel(string model_name);
	void printCar();

private:
	Engine engine;
	Body body;
	Person person;
	int numberOfTires;
	float tireDiameters[50];
	string model;
};
