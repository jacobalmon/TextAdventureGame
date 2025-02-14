#include "player.h"
#include "goober.h"
#include <iostream>
#include <unordered_set> // For tracking visited rooms

//Rules: Path to success = path player neeeds to take in order to complete the game.
class Room1 {
  public:

    bool fled(Player& player) {
        int choice_dos; // Player can only choose between 1.4, 1.8,and 4
        std::cout << "You fled\n";
        std::cout << "You have enterd room 1.5\n";
        std::cout << "-------- Choose a room: 1 - Room 1.4 | 2 - Room 1.8 | 3 - Room 4 --------\n";
        std::cin >> choice_dos;

        if(choice_dos == 1)//Path to success
        {
            std::cout << "You have enterd room 1.4\n";
            player.addItem("Rusty Sword");
            std::cout << "Congratulations, now have a weapon in your inventory.[Rusty Sword:15+ damage]\n";
            std::cout << "You have encountered an enemy!\n";
            std::cout << "Its a goober!\n";

            // Player is forced to fight
            Goober goober;
            std::cout << "You have no choice but to fight!\n";
            std::cout << "You attacked Goober with your Rusty Sword!\n";
              
            goober.takeDamage(15);

            while (goober.isAlive() && player.isAlive()) {
                std::cout << "Goober attacks you with * *.\n";
                player.takeDamage(15);

                if (!player.isAlive()) {
                    std::cout << "You have been defeated.\n";
                    std::cout << "Game Over.\n";
                    return false;
                }

                std::cout << "You attacked Goober with your Rusty Sword!.\n";
                goober.takeDamage(15);

                if (!goober.isAlive()) {
                    std::cout << "Goober has been defeated!\n";
                    std::cout << "You survived and can now proceed.\n";
                    std::cout << "Congratulations! You obtained a key\n";
                    player.addItem("Key");
                    return true;
                }
            }
          } 
          else if(choice_dos == 2)//Player will be able to enter room2 without obtaining a weapon but will immedietly get killed by an enemy and will be forced to start over.
          {
           std::cout << "You have enterd room 1.8\n";
           std::cout << "Congratulations! You obtained a key\n";
           player.addItem("Key");
           return true;
          
          }
          
          else if(choice_dos == 3) //DO NOT ENTER PLEASE PLEASE PLEEEEEAAAAAAAAAAASSSSSSSSSSSniueinieuneiu 
          {
              std::cout << "Player - W..wh..what.....ar.......no....no no no NOOOOO NOOOOO DONT DO THI AAAAAAAAAAAAAAAAAAONOUNI)N)(J()NI\n";
              std::cout << "...\n";
              std::cout << "KS - ...\n";
              std::cout << "Game Over.\n";
              return false;
          } else {
            std::cout << "Invalid Input, Try Again.\n";
            return fled(player);
          }
          return false;
    }
    
    void unprepared(Player& player) {
        std::cout << "You chose to attack with no weapon equiped\n";
        player.takeDamage(100);
        std::cout << "You have lost 100 hp\n";
        std::cout << "Game Over\n";
    }

    bool enter(Player& player) {
       int choice; // Player can only choose between 1 and 2
       std::cout << "You entered Room 1.\n"; 
       std::cout << "You have encountered an enemy!\n";
       std::cout << "-------- Choose: 1 - To flee or 2 - To attack --------\n";
       std::cin >> choice;
       if(choice == 1)  // Path to success 
       { 
            bool flag = fled(player);
            if (!flag) {
                return false;
            }
            return true;
       }
       else if(choice == 2) // Path will lead the player to start again because they decided to fight the final boss with nothing other than their bare hands.
       {
            unprepared(player);
            return false;
       } else {
            std::cout << "Invalid Input, Try Again.\n";
            return enter(player);
       }
       return false;
    }
};

class Room2 {
   public:
    bool enter(Player& player) {
       std::cout << "Welcome to Room 2\n";
       std::cout << "Suddenly, an enemy appears!\n";

       if (!player.hasItem("Rusty Sword")) { 
           std::cout << "You have no weapon to defend yourself!\n";
           std::cout << "The enemy strikes and you take 100 damage!\n";
           player.takeDamage(100);

           if (!player.isAlive()) {
               std::cout << "You died!\n";
               return false; // Exit to prevent further execution
           }
       } 
       else 
       {  
           std::cout << "You use your Rusty Sword to fight off the enemy!\n";
           std::cout << "You barely make it out alive but continue forward.\n";
           std::cout << "--- You have encountered an enemy! ---\n";
           std::cout << "It's a pair of Goobers!\n";
           std::cout << "-------- Choose: 1 - To flee or 2 - To attack --------\n";

           int choice;
           std::cin >> choice;

           if (choice == 1) //Path to success 1 (Easy)
           {
               std::cout << "You fled successfully!\n";
               return false;
           } 
           else if (choice == 2) //Path to success 2 (Medieum)
           {
               std::cout << "You chose to fight!\n";
               int playerDamage = 15; // Rusty Sword deals 15 damage
               int gooberHealth = 20;
               int numGoobers = 2;
               int gooberDamage = 10; // Each Goober deals 10 damage

               while (numGoobers > 0 && player.isAlive()) 
               {
                   // Player's Turn
                   std::cout << "You strike a Goober with your Rusty Sword!\n";
                   gooberHealth -= playerDamage;

                   if (gooberHealth <= 0) {
                       std::cout << "You defeated a Goober!\n";
                       numGoobers--;
                       if (numGoobers > 0) {
                           std::cout << "One Goober remains!\n";
                           gooberHealth = 20; // Reset health for the second Goober
                       }
                   }

                   // Enemy's Turn (if still alive)
                   if (numGoobers > 0) 
                   {
                       std::cout << "The Goobers strike back!\n";
                       player.takeDamage(gooberDamage);
                       player.takeDamage(gooberDamage); // Both Goobers attack

                       if (!player.isAlive()) 
                       {
                           std::cout << "You have fallen in battle!\n";
                           std::cout << "Game Over.\n";
                           return false;
                       }
                   }
               }
             
               int choice_dos;
               std::unordered_set<float> visitedRooms; // Track visited rooms
               std::cout << "You have successfully defeated both Goobers!\n";
               std::cout << "The goobers dropped something.\n";
               std::cout << "Its obsidion!\n";
               std::cout << "Keep exploring to find more peices of obsidion to craft the obsidion sword or key.\n"; //A piece of obsidion was discovered here.
               std::cout << "You have enterd room 2.5\n";
               //2.7  - You get a new sword but it is a dead end so they go back(Needed if user wants to survive through room 2.1 and beyond)
               //2.1 - 2.3 - Room3(Success)
               //2.8 - 2.2 - 2.4 ----- 2.6 ---- 2.5 ---- Room3 (Success)
               //    (Fight monsters)   |-------1.1(Obsidion piece 2/3) ------- 1.3 ---------- room3 (Sucesss)
               //4 STOP STOP DOOOOOONNNNNT AHHHHHHHHH INUNUNUINIUNUNWONDW
               while (true) {
                    std::cout << "-------- Choose a room: 1 - Enter 2.7 | 2 - Enter 2.1 | 3 - Enter 2.8 | 4 - Enter 4 (DO NOT ENTER) --------\n";
                    std::cin >> choice_dos;

                    // Check if the player already visited the room
                    if (visitedRooms.find(choice_dos) != visitedRooms.end()) {
                        std::cout << "You have already visited this room! Choose another.\n";
                        continue;
                    }

                    switch (choice_dos) {
                        case 1: // Room 2.7 (Dead End)
                            std::cout << "You have entered Room 2.7, but it's a dead end!\n";
                            std::cout << "You must return and choose another room.\n";
                            visitedRooms.insert(2.7); // Mark 2.7 as visited
                            break; // Forces the player back to selection

                        case 2: // Room 2.1
                            std::cout << "You have entered Room 2.1.\n";
                            visitedRooms.insert(2.1); // Mark 2.1 as visited
                            // Proceed with Room 2.1 events
                            return true;

                        case 3: // Room 2.8
                            std::cout << "You have entered Room 2.8.\n";
                            visitedRooms.insert(2.8); // Mark 2.8 as visited
                            // Proceed with Room 2.8 events
                            return true;

                        case 4: // Room 4 (Dangerous)
                            std::cout << "You foolishly entered Room 4...\n";
                            std::cout << "An overwhelming enemy strikes! You stand no chance.\n";
                            player.takeDamage(100); // Instant death
                            if (!player.isAlive()) {
                                std::cout << "You died! Restarting from Room 1...\n";
                                player = Player(); // Reset player
                                Room1 room1;
                                room1.enter(player);
                            }
                            return false; // Exit the function

                        default:
                            std::cout << "Invalid choice. Try again.\n";
                            break;
                    }
                }    
           }
       }
    }
};

// class Room3 {};

// class Room4 {};
