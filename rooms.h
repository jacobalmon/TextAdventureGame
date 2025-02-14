#include "player.h"
#include "goober.h"
#include <iostream>
#include <unordered_set> // For tracking visited rooms

// Rules: Path to success = path player needs to take in order to complete the game.

class Room1 {
public:
    bool enter(Player& player) {
        std::cout << "You entered Room 1.\n";
        std::cout << "You have encountered an enemy!\n";
        std::cout << "-------- Choose: 1 - To flee or 2 - To attack --------\n";
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            std::cout << "You fled to another room!\n";
            return true;
        } else {
            std::cout << "You chose to fight with your bare hands... Bad idea!\n";
            player.takeDamage(100);
            return false;
        }
    }
};

class Room2 {
public:
    bool enter(Player& player) {
        std::cout << "You entered Room 2.\n";
        std::cout << "A group of Goobers appear!\n";
        if (!player.hasItem("Rusty Sword")) {
            std::cout << "You have no weapon to defend yourself!\n";
            player.takeDamage(100);
            return false;
        }
        std::cout << "You fight off the Goobers and barely survive!\n";
        return true;
    }
};

class Room3 {
public:
    void enter(Player& player) {
        std::cout << "You step into a dimly lit room. The air is thick with an odd, greasy smell.\n";
        std::cout << "A grotesque creature stands in the center, its skin glistening with a thick layer of oil.\n";
        std::cout << "The Oily Troll snarls: 'Hehehe... you think you can catch me?!'\n";

        int trollHealth = 40;
        int playerDamage = 15;
        int trollDamage = 10;
        int turnCounter = 0;
        srand(time(0)); // Seed for randomness

        while (trollHealth > 0 && player.isAlive()) {
            turnCounter++;
            std::cout << "You swing your weapon at the Oily Troll!\n";
            
            // 50% chance for the troll to dodge
            if (rand() % 2 == 0) {
                std::cout << "The Oily Troll SLIPS out of the way! Your attack misses!\n";
            } else {
                trollHealth -= playerDamage;
                std::cout << "Your attack lands! Oily Troll takes " << playerDamage << " damage.\n";
            }

            if (trollHealth <= 0) {
                std::cout << "The Oily Troll screeches as it collapses into a pool of grease.\n";
                std::cout << "You have defeated the Oily Troll!\n";
                std::cout << "You find an Anti-Oil Rag among the remains. This may be useful later...\n";
                player.addItem("Anti-Oil Rag");
                return;
            }

            std::cout << "The Oily Troll lunges at you!\n";
            player.takeDamage(trollDamage);

            if (!player.isAlive()) {
                std::cout << "You have been defeated by the Oily Troll!\n";
                std::cout << "Game Over.\n";
                return;
            }

            // Every third turn, the troll regenerates
            if (turnCounter % 3 == 0) {
                trollHealth += 10;
                std::cout << "The Oily Troll rubs more oil on itself and regenerates 10 HP!\n";
            }
        }
    }
};

class Room4 {
public:
    bool enter(Player& player) {
        std::cout << "You have entered Room 4.\n";
        std::cout << "The air is damp, and cobwebs stretch across the walls.\n";
        std::cout << "A MASSIVE SPIDER DESCENDS FROM THE CEILING!\n";
        if (!player.hasItem("Rusty Sword")) {
            std::cout << "You have no weapon! The spider lunges at you!\n";
            player.takeDamage(100);
            return false;
        }
        std::cout << "Prepare for battle!\n";
        int spiderHealth = 100;
        int spiderDamage = 20;
        int playerDamage = 15;
        while (spiderHealth > 0 && player.isAlive()) {
            std::cout << "You strike the Giant Spider!\n";
            spiderHealth -= playerDamage;
            if (spiderHealth <= 0) {
                std::cout << "You have slain the Giant Spider!\n";
                return true;
            }
            std::cout << "The Giant Spider attacks!\n";
            player.takeDamage(spiderDamage);
            if (!player.isAlive()) {
                std::cout << "You have been slain by the Giant Spider.\n";
                return false;
            }
        }
        return false;
    }
};

