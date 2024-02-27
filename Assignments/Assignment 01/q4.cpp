/*
Emaan Arshad 23I-2560 
Q 4
*/





#include <iostream>
#include <cmath>

using namespace std;

class RollerCoaster {
private:
    string name; // Name of the roller coaster
    double height; // Maximum height of the roller coaster
    double length; // Total length of the roller coaster track
    int speed; // Speed of the roller coaster
    int capacity; // Maximum number of people that can ride at once
    int currentNumRiders; // Number of riders currently seated in the roller coaster
    bool rideInProgress; // Indicates whether the ride is currently in progress

public:
    // Default constructor
    RollerCoaster() : name("Roller Coaster"), height(500), length(2000), speed(0), capacity(20), currentNumRiders(0), rideInProgress(false) {}

    // Parameterized constructor
    RollerCoaster(string name, double height, double length, double speed, int capacity) : 
        name(name), height(height), length(length), speed(speed), capacity(capacity), currentNumRiders(0), rideInProgress(false) {
            // Ensure capacity is in multiples of two or three and greater than 3
            if (capacity <= 3) {
                this->capacity = 4;
            } else if (capacity % 2 != 0 && capacity % 3 != 0) {
                this->capacity = round(capacity / 2) * 2; // Round to the closest multiple of 2
            }
    }

    // Getter functions
    string getName() const { return name; }
    double getHeight() const { return height; }
    double getLength() const { return length; }
    double getSpeed() const { return speed; }
    int getCapacity() const { return capacity; }
    int getCurrentNumRiders() const { return currentNumRiders; }
    bool isRideInProgress() const { return rideInProgress; }

    // Setter function for capacity
    void setCapacity(int capacity) {
        if (capacity <= 3) {
            this->capacity = 4;
        } else if (capacity % 2 != 0 && capacity % 3 != 0) {
            this->capacity = round(capacity / 2) * 2; // Round to the closest multiple of 2
        } else {
            this->capacity = capacity;
        }
    }

    // Function to load/seat the riders into the roller coaster
    int loadRiders(int numRiders) {
        if (!rideInProgress && currentNumRiders + numRiders <= capacity) {
            currentNumRiders += numRiders;
            return 0; // All riders successfully seated
        } else {
            return numRiders - (capacity - currentNumRiders); // Return number of riders not seated
        }
    }

    // Function to start the ride
    int startRide() {
        if (!rideInProgress) {
            if (currentNumRiders < capacity) {
                return capacity - currentNumRiders; // Return number of empty seats
            } else {
                rideInProgress = true;
                return 0; // Ride started successfully
            }
        }
        return -1; // Ride already in progress
    }

    // Function to stop the ride
    void stopRide() {
        if (rideInProgress) {
            rideInProgress = false;
        }
    }

    // Function to unload the riders from the roller coaster
    void unloadRiders() {
        if (!rideInProgress) {
            currentNumRiders = 0;
        }
    }

    // Function to accelerate the roller coaster
    void accelerate() {
        double lastDigit = abs(speed) %10;
        speed += lastDigit;
    }

    // Function to apply brakes to slow down the roller coaster
    void applyBrakes() {
        string rollNumber = "2040"; // Change to your roll number
        int firstNonZeroDigit = 0;
        for (char digit : rollNumber) {
            if (digit != '0') {
                firstNonZeroDigit = digit - '0';
                break;
            }
        }
        speed -= firstNonZeroDigit;
    }
};

int main() {
	cout<<"Emaan Arshad\n";
		// Using default constructor
    RollerCoaster coaster1;

    // Using parameterized constructor
    RollerCoaster coaster2("Thunderbolt", 700, 2500, 0, 17); // Capacity will be rounded to 18 (closest multiple of 2 greater than 3)

    // Load riders onto coaster1
    int remainingRiders = coaster1.loadRiders(15); // Trying to load 15 riders
    if (remainingRiders == 0) {
        cout << "All riders seated on " << coaster1.getName() << endl;
    } else {
        cout << "Only " << 15 - remainingRiders << " riders seated on " << coaster1.getName() << ", " << remainingRiders << " riders could not be seated due to capacity." << endl;
    }

    // Load riders onto coaster2
    remainingRiders = coaster2.loadRiders(20); // Trying to load 20 riders
    if (remainingRiders == 0) {
        cout << "All riders seated on " << coaster2.getName() << endl;
    } else {
        cout << "Only " << 20 - remainingRiders << " riders seated on " << coaster2.getName() << ", " << remainingRiders << " riders could not be seated due to capacity." << endl;
    }

    // Start the ride on coaster1
    int emptySeats = coaster1.startRide();
    if (emptySeats == 0) {
        cout << "Ride started on " << coaster1.getName() << endl;
    } else {
        cout << "Ride could not start on " << coaster1.getName() << " due to " << emptySeats << " empty seats." << endl;
    }

    // Start the ride on coaster2
    emptySeats = coaster2.startRide();
    if (emptySeats == 0) {
        cout << "Ride started on " << coaster2.getName() << endl;
    } else {
        cout << "Ride could not start on " << coaster2.getName() << " due to " << emptySeats << " empty seats." << endl;
    }

    // Stop the ride on coaster1
    coaster1.stopRide();
    cout << "Ride stopped on " << coaster1.getName() << endl;

    // Stop the ride on coaster2
    coaster2.stopRide();
    cout << "Ride stopped on " << coaster2.getName() << endl;

    return 0;
}
