#include "player.h"
#include "goober.h"
#include <iostream>
#include <unordered_set> // For tracking visited rooms

// Rules: Path to success = path player needs to take in order to complete the game.

class Room1 {
public:
    bool enter(Player& player) 
    {
        std::cout << "------------------------------------------\n\n";
        std::cout << "You entered Room 1.\n";
        std::cout << "You have encountered an enemy! It is the 'Goblin'.\n\n";
        std::cout << "-------- Choose: 1 - Fight || 2 - Flee --------\n";
        int choice;
        std::cin >> choice;
        if (choice == 2) // (1) Run away!!!
        {
            std::cout << "\nYou fled to another room! The Goblin curses at you in it native language.\n";
            return true;
        } 
        else // (2) Nah, I'd win.
        {
            std::cout << "\nYou choose to fight the Goblin.\n";
            srand(time(0));  // Seed for randomness

            //Goblin stats:
            int goblinHealth = 20;
            int goblinDamage = 5;

            while (goblinHealth > 0 && player.isAlive()) 
            {
                std::cout << "\n-------- Choose: 1 - Attack || 2 - Retreat --------\n";
                int battleChoice;
                std::cin >> battleChoice;

                if (battleChoice == 2) // Dishonor and coward moves
                {
                    std::cout << "You chose to retreat from battle!\n";
                    return true;  
                }

                // Player's attack (random between 1-6) (Also assuming the player only have it fist to punch)
                int playerDamage = (rand() % 6) + 1;
                goblinHealth -= playerDamage;
                std::cout << "You punch the Goblin! It takes " << playerDamage << " damage.\n";
                std::cout << "The Goblin's health: " << goblinHealth << ".\n";

                // Check if goblin is defeated
                if (goblinHealth <= 0) 
                {
                    std::cout << "You defeated the Goblin!\n";
                    std::cout << "You received a rusty sword. (Description: It ain't much but it's honest work.)\n";
                    player.addItem("Rusty Sword"); 
                    break;
                }

                // Goblin attacks back
                std::cout << "The Goblin strikes back!\n";
                player.takeDamage(goblinDamage);
                
                // Check if player is still alive
                if (!player.isAlive()) 
                {
                    std::cout << "You Died (Queue the Darksoul death theme)\n";
                    return false;
                }
            }
        }

        // Transition after defeating the goblin
        std::cout << "\nYou take a moment to catch your breath after the battle.\n\n";
        std::cout << "Do you want to explore further? (Choose: 1 - Yes, the adventure waits nobody. || 2 - No, you need to take a break.)\n";
        std::cin >> choice;
        player.restoreHealth();

        if (choice == 1)
        {
            std::cout << "You move deeper into the dungeon...\n";
            return true;  
        }
        else //Note: This will be expand more in the future. Ideas such as resting to recover HP, looting, exploring subrooms, etc...
        {
            std::cout << "You decide to rest here for a while before moving on.\n";
            return false;  
        }
    }
};

class Room2 {
public:
    bool enter(Player& player) 
    {
        std::cout << "------------------------------------------\n\n";
        std::cout << "You entered Room 2.\n";
        std::cout << "You hear strange noises... The 'Goober' appear!\n\n";
        std::cout << "-------- Choose: 1 - Fight || 2 - Flee --------\n";
        int choice;
        std::cin >> choice;

        if (choice == 2) // Run away!!!
        {
            std::cout << "\nYou barely escape, running to another room!\n";
            return true;
        } 

        else // (2) Nah, I'd win.
        {
            std::cout << "\nYou choose to fight the Goober.\n";
            srand(time(0));  // Seed for randomness  

            // Goober stats:  
            Goober goober;  
            int gooberDamage = 12;  

            while (goober.isAlive() && player.isAlive())  
            {
                std::cout << "\n-------- Choose: 1 - Attack || 2 - Retreat --------\n";
                int battleChoice;
                std::cin >> battleChoice;

                if (battleChoice == 2) 
                {
                    std::cout << "\nYou choose to retreat! You feel the goober is laughing at you.\n";
                    return true;
                }

                // Player attacks  
                int playerDamage;
                if (player.hasItem("Rusty Sword"))  
                {
                    playerDamage = (rand() % 6) + 7;  // 7-12 damage with sword  
                    std::cout << "You swing your Rusty Sword at the Goober!\n";
                }  
                else  
                {
                    playerDamage = (rand() % 6) + 1;  // 1-6 damage with fists  
                    std::cout << "You punch the Goober with your bare hands!\n";
                }

                goober.takeDamage(playerDamage);

                // Check if Goober is defeated  
                if (!goober.isAlive())  
                {
                    std::cout << "You defeated the Goober!\n";
                    break;
                }

                // Goober attacks back  
                std::cout << "The Goober lunges at you!\n";
                player.takeDamage(gooberDamage);

                // Check if player is alive  
                if (!player.isAlive())  
                {
                    std::cout << "You Died. (Queue the Dark Souls death theme)\n";
                    return false;
                }
            }
        }

        // Transition after defeating the Goobers  
        std::cout << "\nYou take a deep breath after the battle.\n\n";
        std::cout << "Do you want to explore further? (Choose: 1 - Yes, lets keep going, you are getting a hand of this. || 2 - No, lets call it for a night.)\n";
        std::cin >> choice;
        player.restoreHealth();

        if (choice == 1)
        {
            std::cout << "You move deeper into the dungeon...\n";
            return true;  
        }
        else 
        {
            std::cout << "You decide to rest here for a while before moving on.\n";
            return false;  
        }
    }
};

class Room3 {
public: 
    bool enter(Player& player) 
    {
        std::cout << "------------------------------------------\n\n";
        std::cout << "You step into a dimly lit room. The air is thick with an odd, greasy smell.\n";
        std::cout << "A grotesque creature stands in the center, its skin glistening with a thick layer of oil.\n";
        std::cout << "The Oily Troll snarls: 'Hehehe... you think you can catch me?!'\n";

        srand(time(0)); // Seed for randomness  

        // Oily Troll stats   
        int trollHealth = 40;
        int trollDamage = 5;  // 
        int regenCounter = 0;  // *Only regenerates once*  
        int dodgeChance = 25;  // 

        while (trollHealth > 0 && player.isAlive()) 
        {
            std::cout << "\n-------- Choose: 1 - Attack || 2 - Retreat --------\n";
            int battleChoice;
            std::cin >> battleChoice;

            if (battleChoice == 2)  
            {
                std::cout << "You decide to retreat! The Oily Troll cackles as you run...\n";
                return true;
            }

            // Player attacks  
            int playerDamage;
            if (player.hasItem("Rusty Sword"))  
            {
                playerDamage = (rand() % 6) + 7;  // 7-12 damage with sword  
                std::cout << "You swing your Rusty Sword at the Oily Troll!\n";
            }  
            else  
            {
                playerDamage = (rand() % 6) + 1;  // 1-6 damage with fists  
                std::cout << "You punch the Oily Troll with your bare hands!\n";
            }

            // 25% chance for the troll to dodge  
            if (rand() % 100 < dodgeChance) 
            {
                std::cout << "The Oily Troll SLIPS out of the way! Your attack misses!\n";
            } 
            else 
            {
                trollHealth -= playerDamage;
                std::cout << "Your attack lands! The Oily Troll takes " << playerDamage << " damage.\n";
            }

            // Check if Troll is defeated  
            if (trollHealth <= 0) 
            {
                std::cout << "The Oily Troll screeches as it collapses into a pool of grease.\n";
                std::cout << "You have defeated the Oily Troll!\n";
                std::cout << "You find an **Anti-Oil Rag** among the remains. This may be useful later...\n";
                player.addItem("Anti-Oil Rag");
                break;
            }

            // Troll attacks back  
            std::cout << "The Oily Troll lunges at you!\n";
            player.takeDamage(trollDamage);

            // Check if player is alive  
            if (!player.isAlive()) 
            {
                std::cout << "You have been defeated by the Oily Troll!\n";
                std::cout << "Game Over.\n";
                return false;
            }

            // Troll regenerates **ONLY ONCE**  
            if (trollHealth > 0 && regenCounter == 0)  
            {
                trollHealth += 10;
                regenCounter++;  // 
                std::cout << "The Oily Troll rubs more oil on itself and regenerates **10 HP!**\n";
            }

            // Always show troll health after attack  
            std::cout << "The Oily Troll's health: " << trollHealth << ".\n";
        }

        // Transition after defeating the Oily Troll  
        std::cout << "\nYou take a deep breath after the battle.\n\n";
        std::cout << "Do you want to explore further? (Choose: 1 - Yes, you do not want to end your excitement. || 2 - No, you are done for today and want to clean yourself up.)\n";
        int choice;
        std::cin >> choice;
        player.restoreHealth();

        if (choice == 1)
        {
            std::cout << "You move deeper into the dungeon...\n";
            return true;  
        }
        else 
        {
            std::cout << "You decide to rest here for a while before moving on.\n";
            return false;  
        }
    }
};

class Room4 
{
    public:
        bool enter(Player& player) 
        {
            std::cout << "------------------------------------------\n\n";
            std::cout << "You have entered Room 4.\n";
            std::cout << "The air is damp, and cobwebs stretch across the walls.\n";
            std::cout << "A MASSIVE SPIDER DESCENDS FROM THE CEILING!\n";
            std::cout << "The Giant Enemy Spider!!! \n";
            std::cout << "Open this link: https://youtu.be/rcKFUp4YioU?\n\n";
    
            srand(time(0));  // Seed randomness  
    
            // Spider stats:  
            int spiderHealth = 100;
            int spiderDamage = 20;
            int dodgeChance = 25;  // 25% chance to dodge attacks  
            
            // If player has Anti-Oil Rag, spider starts **weakened**  
            if (player.hasItem("Anti-Oil Rag"))  
            {
                std::cout << "You wipe the Anti-Oil Rag on your weapon. The spider shrieks and weakens!\n";
                spiderHealth -= 20;  // Spider starts with 80 HP instead  
                spiderDamage -= 5;    // Spider deals 15 damage instead of 20  
            }
    
            while (spiderHealth > 0 && player.isAlive()) 
            {
                std::cout << "\n-------- Choose: 1 - Attack || 2 - Retreat --------\n";
                int battleChoice;
                std::cin >> battleChoice;
    
                if (battleChoice == 2) // Retreat option  
                {
                    std::cout << "You choose to retreat! The spider watches as you escape...\n";
                    return true;
                }
    
                // Player attacks  
                int playerDamage;
                if (player.hasItem("Rusty Sword"))  
                {
                    playerDamage = (rand() % 6) + 10;  // 10-15 damage with sword  
                    std::cout << "You slash the Giant Spider with your Rusty Sword!\n";
                }  
                else  
                {
                    playerDamage = (rand() % 6) + 3;  // 3-8 damage with fists  
                    std::cout << "You punch the Giant Enemy Spider! (Brave, but not smart...)\n";
                }
    
                spiderHealth -= playerDamage;
                std::cout << "The Giant Enemy Spider screeches! It takes " << playerDamage << " damage.\n";
    
                if (spiderHealth <= 0)  
                {
                    std::cout << "The Giant Enemy Spider collapses, its legs curling inward.\n";
                    std::cout << "You have slain the Giant Enemy Spider!\n";
                    std::cout << "You find a **Spider Fang** on the ground. It might be useful...\n";
                    player.addItem("Spider Fang");
                    break;
                }
    
                std::cout << "The Giant Enemy Spider lunges at you!\n";
    
                // 25% chance to dodge  
                if (rand() % 100 < dodgeChance)  
                {
                    std::cout << "You dodge just in time! The spider misses!\n";
                }  
                else  
                {
                    player.takeDamage(spiderDamage);
                }
    
                // Check if player is alive  
                if (!player.isAlive())  
                {
                    std::cout << "You have been slain by the Giant Enemy Spider.\n";
                    return false;
                }
    
                std::cout << "The Giant Spider's health: " << spiderHealth << ".\n";
            }
    
            std::cout << "\nYou take a deep breath after the battle.\n\n";
            std::cout << "Do you want to explore further? (Choose: 1 - Yes, you're doing great! || 2 - No, let's rest for now.)\n";
            int choice;
            std::cin >> choice;
            player.restoreHealth();
    
            if (choice == 1)
            {
                std::cout << "You move deeper into the dungeon...\n";
                return false; //Return false for now since there should more room in the future. 
            }
            else 
            {
                std::cout << "You decide to rest here before continuing your adventure.\n";
                return false;  
            }
        }
    };
