/*
Emaan Arshad 23I-2560 
Q 2
*/



#include <iostream>

using namespace std;

class Table {
private:
    const int capacity;
    int occupiedSeats;
    bool clean;

public:
    Table() : capacity(4), occupiedSeats(0), clean(true) {}

    Table(int capacity) : capacity((capacity == 8) ? 8 : 4), occupiedSeats(0), clean(true) {}

    bool isAvailable() const {
        return (occupiedSeats == 0 && clean);
    }

    void occupyTable(int groupSize) {
        if (isAvailable() && capacity >= groupSize) {
            occupiedSeats = capacity;
            clean = false;
            cout << "Table with capacity " << capacity << " assigned to a group of " << groupSize << " friends." << endl;
        } else {
            cout << "No available table for a group of " << groupSize << " friends." << endl;
        }
    }

    void haveLunch() {
        if (!clean) {
            clean = true;
            cout << "Lunch finished at the table." << endl;
        } else {
            cout << "The table is already clean." << endl;
        }
    }

    void leaveTable() {
        if (occupiedSeats > 0) {
            occupiedSeats = 0;
            cout << "People left the table." << endl;
        }
    }

    void cleanTable() {
        if (occupiedSeats == 0) {
            clean = true;
            cout << "Table cleaned." << endl;
        } else {
            cout << "Cannot clean the table while people are still seated." << endl;
        }
    }

    int getCapacity() const {
        return capacity;
    }
};

void OccupyTable(Table tables[], int groupSize) {
    bool tableFound = false;
    for (int i = 0; i < 5; ++i) {
        if (tables[i].isAvailable() && tables[i].getCapacity() >= groupSize) {
            tables[i].occupyTable(groupSize);
            tableFound = true;
            break;
        }
    }
    if (!tableFound) {
        cout << "No available table for a group of " << groupSize << " friends." << endl;
    }
}

void EmptyTable(Table tables[], int tableNumber) {
    if (tableNumber >= 0 && tableNumber < 5) {
        tables[tableNumber].leaveTable();
        tables[tableNumber].cleanTable();
    } else {
        cout << "Invalid table number." << endl;
    }
}

int main() {
    Table tables[5] = { Table(4), Table(4), Table(8), Table(8), Table(4) };
	cout<<"EMAAN ARSHAD 23I2560\n";
    OccupyTable(tables, 4);
    OccupyTable(tables, 6);

    tables[0].occupyTable(4);
    tables[0].haveLunch();
    tables[0].leaveTable();
    tables[0].cleanTable();

    EmptyTable(tables, 1);

    return 0;
}
