#include <iostream>
#include <string>

using namespace std;

class DarazPersonData {
protected:
    string lastName;
    string firstName;
    string address;
    string city;
    string state;
    string zip;
    string phone;

public:
 DarazPersonData(string lName, string fName, string add, string c, string s, string z, string ph)
        : lastName(lName), firstName(fName), address(add), city(c), state(s), zip(z), phone(ph)
		 {
		 }
    string getLastName() { 
	return lastName; }
    string getFirstName() {
	 return firstName; }
    string getAddress() {
	 return address; }
    string getCity() {
	 return city; }
    string getState() {
	 return state; }
    string getZip() {
	 return zip; }
    string getPhone() {
	 return phone; }


};

class DarazCustomerData:public DarazPersonData  {
private:
    int customerNumber;
    int loyaltyPoints;

public:
  DarazCustomerData(string lName, string fName, string add, string c, string s, string z, string ph,int custNum, int points) : 
  DarazPersonData(lName, fName, add, c, s, z, ph), customerNumber(custNum), loyaltyPoints(points)
   {}
    int getCustomerNumber() {
	 return customerNumber; }
    int getLoyaltyPoints() {
	 return loyaltyPoints; }

   
    void setCustomerNumber(int num) { 
	customerNumber = num; }
    void setLoyaltyPoints(int points) {
	
	 loyaltyPoints = points; 
	 }
};

class DarazLoyaltyProgram {
public:
    static void addLoyaltyPoints(DarazCustomerData& customer, int points) {
        if (points > 0) {
            customer.setLoyaltyPoints(customer.getLoyaltyPoints() + points);
            cout << points << " loyalty points added for customer " << customer.getCustomerNumber() << endl;
        } else {
            cout << "Invalid loyalty points value. Points should be greater than 0." << endl;
        }
    }

   
    static void redeemLoyaltyPoints(DarazCustomerData& customer, int points) {
        if (points > 0 && points <= customer.getLoyaltyPoints()) {
            customer.setLoyaltyPoints(customer.getLoyaltyPoints() - points);
            cout << points << " loyalty points redeemed for customer " << customer.getCustomerNumber() << endl;
        } else {
            cout << "Invalid loyalty points to redeem or not enough points available." << endl;
        }
    }

  
    static void displayTotalLoyaltyPoints(DarazCustomerData& customer) {
        cout << "Total loyalty points for customer " << customer.getCustomerNumber() << ": " << customer.getLoyaltyPoints() << endl;
    }
};

int main() {
    int customerNumber;
    do {
        cout << "Enter customer number (should be non-negative): ";
        	cin >> customerNumber;
        if (customerNumber < 0) {
           		 cout << "Invalid customer number! Please enter a non-negative value.\n";
        }
    } while (customerNumber < 0);
    
    
 DarazCustomerData customerData("Afnan", "Khan", "123 Khi ", "Karachi", "Pak", "4904", "1234567890", customerNumber, 100);

    int choice;
    do {
    	
       cout << "\nMenu:\n 1. Purchase (Add loyalty points) \n 2. Avail  discount (Redeem loyalty  points)\n 3. See total loyalty points\n 4.  Exit \n Enter your choice:  ";
        cin >> choice;

        switch (choice) {
            case 1: 
            
                int points;
                cout << "Enter loyalty points to add for purchase: ";
                cin >> points;
                DarazLoyaltyProgram::addLoyaltyPoints(customerData, points);
                
				break;
            
            case 2: 
                int pointsToRedeem;
                cout << "Enter loyalty points to redeem for discount: ";
               	 cin >> pointsToRedeem;
                		DarazLoyaltyProgram::redeemLoyaltyPoints(customerData, pointsToRedeem);
                break;
            
            case 3: 
            
              	  DarazLoyaltyProgram::displayTotalLoyaltyPoints(customerData);
                break;
            
            case 4:
                cout << "  Exiting program...\n";
              break;
                
            default:
                cout << "Invalid choice! Please enter a number from 1 to 4.   \n";
        }
    } while (choice != 4);


system("pause>0");

    return 0;
}
