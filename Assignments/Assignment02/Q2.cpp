#include <iostream>
#include <string>
using namespace std;

class Player {
protected:
    int playerId;
    string playerName;
    int health;

public:
    Player(int playerId, string playerName) :
        playerId(playerId), playerName(playerName), health(100) {}

    void displayDetails() {
        cout << "Player ID: " << playerId << ", Player Name: " << playerName << ", Health: " << health << endl;
    }
};

class Weapon {
protected:
    string weaponsList[5];

public:
    Weapon() {
        weaponsList[0] = "sword";
        weaponsList[1] = "bow";
        weaponsList[2] = "axe";
        weaponsList[3] = "staff";
        weaponsList[4] = "dagger";
    }

    void use() {
        cout << "Available weapons:" << endl;
        for (int i = 0; i < 5; ++i)
            cout << i + 1 << ". " << weaponsList[i] << endl;

        int choice;
        cout << "Enter the number corresponding to the weapon you want to use: ";
        cin >> choice;

        if (choice < 1 || choice > 5) {
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
            return;
        }

        cout << "You chose to use a " << weaponsList[choice - 1] << "..." << endl;
    }
};

class Character : public Player {
private:
    int level;
    string experience;
    int points;

public:
    Character(int playerId, string playerName) :
        Player(playerId, playerName), level(0), experience("Beginner"), points(0) {}

    void levelUp() {
        points += 10;

        if (experience == "Beginner"){
			 cout << "Congratulations! You've reached the Intermediate level!" << endl;;
            experience = "Intermediate"; }
        else if (experience == "Intermediate") {
		
            experience = "Advanced";
            	 cout << "Congratulations! You've reached the Advanced level!" << endl;;
        }else if (experience == "Advanced") {		
            experience = "Expert";
		
			 cout << "Congratulations! You've reached the Expert level!" << endl;
}

        level++;
    }
string getExperience () {
	return experience;
}
    void playGame(Weapon& w) {
        cout << "Player " << playerName << " is playing the game..." << endl;
        w.use();
        levelUp();
    }

    void attacked(int n) {
        cout << "Player " << playerName << " is attacked! Health is decreasing by "<<n<<"..." << endl;
        health -= n;
    }
};

class Enemy : public Player {
private:
    int damage;

public:
    Enemy(int playerId, string playerName, int damage) :
        Player(playerId, playerName), damage(damage) {}

    void attack(Character& c) {
        cout << "Enemy " << playerName << " is attacking..." << endl;
        c.attacked(damage);
    }

    void attacked() {
        cout << "Enemy " << playerName << " is attacked!  Enemy s Health is decreasing by 5..." << endl;
        health -= 5;
    }
};

int main() {
    
    Character player(1, "Hero");


    Enemy enemy(1, "Goblin", rand() % 10 +1);

    Weapon weapon;
    player.displayDetails();
   // enemy.displayDetails();

 
   
  
   while (player.getExperience() != "Expert") {
        cout << endl;
        player.playGame(weapon);
        cout << endl;
        if(player.getExperience() =="Expert") break;
    enemy.attack(player);
    }

   // cout << "Congratulations! You've reached the Expert level!" << endl;


    

    return 0;
}
