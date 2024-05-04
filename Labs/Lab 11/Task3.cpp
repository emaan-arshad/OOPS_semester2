#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    string make;
    string model;
    int speed;

public:
    Vehicle(string make, string model, int speed) : make(make), model(model), speed(speed) {}

    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void calculateFuelEfficiency() = 0;

    string getMake() {
        return make;
    }

    string getModel() {
        return model;
    }

    int getSpeed() {
        return speed;
    }
};

class Car : public Vehicle {
private:
    double fuelCapacity;

public:
    Car(string make, string model, int speed, double fuelCapacity) : Vehicle(make, model, speed), fuelCapacity(fuelCapacity) {}

    void accelerate() override {
        speed += 10;
    }

    void brake() override {
        speed -= 10; 
        if (speed < 0) {
            speed = 0; 
        }
    }

    void calculateFuelEfficiency() override {
       
        cout << "Fuel efficiency of car is dependent on its fuel capacity" << endl;
    }
};

class Truck : public Vehicle {
private:
    int cargoCapacity;

public:
    Truck(string make, string model, int speed, int cargoCapacity) : Vehicle(make, model, speed), cargoCapacity(cargoCapacity) {}

    void accelerate() override {
        speed += 5;
    }

    void brake() override {
        speed -= 5; 
        if (speed < 0) {
            speed = 0; 
        }
    }

    void calculateFuelEfficiency() override {
    
        cout << "Fuel efficiency of truck is dependent  on its cargo capacity" << endl;
    }
};
