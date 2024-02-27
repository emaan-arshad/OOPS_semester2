/*
Emaan Arshad 23I-2560 
Q 1
*/



#include <iostream>
#include <string>

using namespace std;

class Pet {
    string name;
  //  string species;
    string healthstatus = "Healthy";
    int hungerlevel = 1;  // (1-5) 5 being the most hungry
    int happinesslevel = 1;  // (1-10) 10 being the happiest
    string skills[10];

public:
	    string species;
    Pet() {}

    Pet(string name, string species) : name(name), species(species) {
        for (int i = 0; i < 10; i++) {
            skills[i] = "";
        }
    }

    string getName() const {
        return name;
    }

    void displayPetDetails() {
        cout << "\nPet Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Species: " << species << endl;
        cout << "Health Status: " << healthstatus << endl;
        cout << "Hunger Level: " << hungerlevel << endl;
        cout << "Happiness Level: " << happinesslevel << endl;
        cout << "SKILLS:" << endl;
        for (int i = 0; i < 10; i++) {
            if (skills[i] == "") break;
            cout << skills[i] << endl;
        }
        cout << endl;
    }

    void updateSkill(string skill) {
        for (int i = 0; i < 10; i++) {
            if (skills[i] == "") {
                skills[i] = skill;
                cout << "Skill updated" << endl;
                return;
            }
        }
        cout << "Cannot have more than 10 special skills" << endl;
    }

    void updateHealth() {
        healthstatus = (hungerlevel <= 3 && happinesslevel >= 4) ? "Healthy" : "Sick";
    }

    void updateHappiness(int a) {
        if (a == 0) {
            if (hungerlevel < 3) {
                happinesslevel--;
                if (happinesslevel < 1) happinesslevel = 1;
            }
        } else {
            happinesslevel++;
            if (happinesslevel > 10) happinesslevel = 10;
        }
    }

    void updateHunger() {
        hungerlevel--;
        if (hungerlevel < 1) hungerlevel = 1;
    }

    void interact() {
        for (;;) {
            int choice;
            cout << "Pet details before interactions\n";
            displayPetDetails();
            cout << "Choose your interaction options: " << endl;
            cout << "Press 1 to feed " << name << endl;
            cout << "Press 2 to play with " << name << endl;
            cout << "Press 3 to take " << name << " on a walk " << endl;
            cout << "Press 0 to quit interacting " << endl;
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "You fed the pet!" << endl;
                    updateHunger();
                    updateHappiness(1);
                    updateHealth();
                    break;
                case 2:
                    cout << "You played with the pet!" << endl;
                    updateHappiness(1);
                    updateHealth();
                    break;
                case 3:
                    cout << "You took the pet on a walk!" << endl;
                    updateHappiness(1);
                    updateHealth();
                    break;
                case 0:
                    updateHappiness(0);  // called after interaction is finished
                    cout << "Pet details after interactions: \n";
                    displayPetDetails();
                    cout << "Taking back to the older menu" << endl;
                    break;
                default:
                    cout << "Please enter a valid choice" << endl;
            }

            if (choice == 0) break;
        }
    }
};

class Adopter {
    string adoptername;
    string adopterno;
    Pet adoptedPets[3]; 

public:
    Adopter() {}

    Adopter(string name, string adopterno) : adoptername(name), adopterno(adopterno) {}

    void adoptPet(Pet& pet) {
        for (int i = 0; i < 3; i++) {
            if (adoptedPets[i].getName() == "") {
                adoptedPets[i] = pet;
                cout << "Pet " << pet.getName() << " adopted successfully by " << adoptername << endl;
                return;
            }
        }
        cout << "Sorry, " << adoptername << ", you cannot adopt more pets." << endl;
    }

    void returnPet(Pet& pet) {
        for (int i = 0; i < 3; i++) {
            if (adoptedPets[i].getName() == pet.getName()) {
                adoptedPets[i] = Pet(); // Clear the slot by assigning a default-constructed Pet
                cout << "Pet " << pet.getName() << " returned successfully by " << adoptername << endl;
                return;
            }
        }
        cout << pet.getName() << " is not adopted by " << adoptername << endl;
    }

    void displayAdoptedPets() {
        cout << adoptername << "'s adopted pets:" << endl;
        for (int i = 0; i < 3; i++) {
            if (!adoptedPets[i].getName().empty()) {
                cout << "- " << adoptedPets[i].getName() << " (" << adoptedPets[i].species << ")" << endl;
            }
        }
    }
};

int main() {
    Pet p1("Crookshanks", "Cat");
    Pet p2("Padfoot", "Dog");
    Pet p3("Scabbers", "Rat");

    p1.updateSkill("Play with a string");
    p1.updateSkill("Play with a ball");
    p1.updateSkill("Play with a toy");
    p2.updateSkill("Play with a bone");
    p2.updateSkill("Play with a stick");
    p3.updateSkill("Play with a toy");

    Adopter a1("Emaan", "03308473254");
    Adopter a2("Afnan", "03302471152");
	cout<<"EMAAN ARSHAD 23I2560\n";
    cout << "Welcome to our pet adoption center!" << endl;

    int choice;
    string name;

    for (;;) {
        cout << "Press 1 to be a visitor, 2 to be an adopter, or 3 to quit program" << endl;
        cin >> choice;

        if (choice == 3) break;

        if (choice == 2) {
            for (;;) {
                cout << "Press 1 to interact with a pet" << endl;
                cout << "Press 2 to adopt a Pet" << endl;
                cout << "Press 3 to return a Pet" << endl;
                cout << "Press 4 to display adopted pets" << endl;
                cout << "Press 0 to go back to the main menu" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        cout << "Enter the name of the pet to interact" << endl;
                        cin >> name;
                        if (name == "Crookshanks") p1.interact();
                        if (name == "Padfoot") p2.interact();
                        if (name == "Scabbers") p3.interact();
                        break;
                    case 2:
                        cout << "Enter the name of the pet to adopt" << endl;
                        cin >> name;
                        if (name == "Crookshanks") a1.adoptPet(p1);
                        if (name == "Padfoot") a1.adoptPet(p2);
                        if (name == "Scabbers") a1.adoptPet(p3);
                        break;
                    case 3:
                        cout << "Enter the name of the pet to return" << endl;
                        cin >> name;
                        if (name == "Crookshanks") a1.returnPet(p1);
                        if (name == "Padfoot") a1.returnPet(p2);
                        if (name == "Scabbers") a1.returnPet(p3);
                        break;
                    case 4:
                        a1.displayAdoptedPets();
                        break;
                    case 0:
                        cout << "Taking you back to the main menu...." << endl;
                        break;
                    default:
                        cout << "Invalid choice. Try again." << endl;
                }

                if (choice == 0) break;
            }
        }

        if (choice == 1) {
            cout << "You are here as a visitor but you can interact with the pet" << endl;

            for (;;) {
                cout << "Press 1 to interact with a pet" << endl;
                cout << "Press 2 to exit " << endl;

                int a;
                cin >> a;
                cin.ignore();

                if (a == 1) {
                    cout << "Enter the name of the pet to interact" << endl;
                    getline(cin, name);
                    if (name == "Crookshanks") p1.interact();
                    else if (name == "Padfoot") p2.interact();
                    else if (name == "Scabbers") p3.interact();
                    else {
                        cout << "Wrong name, taking back to the menu" << endl;
                    }
                }

                if (a == 2) break;
            }
        }
    }

    return 0;
}
