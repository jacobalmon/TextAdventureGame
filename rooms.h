#include "player.h"
#include "goober.h"
#include <iostream>
//Rules: Path to success = path player neeeds to take in order to complete the game.
class Room1 {
  public:
    void enter(Player& player){
       int choice; // Player can only choose between 1 and 2
       float choice_dos; // Player can only choose between 1.4, 1.8,and 4
       std::cout << "You entered Room 1.\n"; 
       std::cout << "You have encountered an enemy!\n";
       std::cout << "-------- Choose: 1 - To flee or 2 - To attack --------\n";
       std::cin >> choice;
       if(choice == 1)  //Path to success 
       { 
          std::cout << "You fled\n";
          std::cout << "You have enterd room 1.5\n";
          std::cout << "-------- Choose a room: 1 - Enter 1.4 | Enter 1.8 | Enter 4 --------\n";
          std::cin >> choice_dos;
         
          if(choice_dos == 1.7)//Path to success
          {
            std::cout << "You have enterd room 1.7\n";
            player.addItem("Rusty Sword");
            std::cout << "Congratulations, now have a weapon in your inventory.[Rusty Sword:15+ damage]\n";
            std::cout << "You have encountered an enemy!\n";
            std::cout << "Its a goober!\n";

              // Player is forced to fight
              Goober goober;
              std::cout << "You have no choice but to fight!\n";
              std::cout << "You attacked Goober with your Rusty Sword!\n";
              
              goober.takeDamage(15);

              if (!goober.isAlive()) {
                  std::cout << "Goober has been defeated!\n";
                  player.takeDamage(15);
                  std::cout << "You lost 15 HP in the battle.\n";
                  std::cout << "You survived and can now proceed.\n";
                  player.addItem("Key");
                  std::cout << "Congratulations! You obtained a key\n";
                  Room2 room2;
                  room2.enter(player);
              }

          }

           else if(choice_dos == 1.8)//Player will be able to enter room2 without obtaining a weapon but will immedietly get killed by an enemy and will be forced to start over.
           {
            std::cout << "You have enterd room 1.8\n";
            player.addItem("Key");
            std::cout << "Congratulations! You obtained a key\n";
            Room2 room2;
            room2.enter(player);
           
           }
           
           else if(choice_dos == 4) //DO NOT ENTER PLEASE PLEASE PLEEEEEAAAAAAAAAAASSSSSSSSSSSniueinieuneiu 
           {
            std::cout << "Player - W..wh..what.....ar.......no....no no no NOOOOO NOOOOO DONT DO THI AAAAAAAAAAAAAAAAAAONOUNI)N)(J()NI\n";
            std::cout << "...\n";
            std::cout << "KS - ...\n";
            std::cout << "Game Over.\n";


             
           }

 
       }
       else if(choice == 2) //Path will lead the player to start again because they decided to fight the final boss with nothing other than their bare hands.
       {
         std::cout << "You chose to attack with no weapon equiped\n";
         player.takeDamage(100);
         std::cout << "You have lost 100 hp";
         if(!player.isAlive()){
            std::cout << "You died! Would you like to try again? (1 - Yes, 2 - No): ";
              int retry;
              std::cin >> retry;              
              if (retry == 1) 
              {
                  std::cout << "Restarting...\n";
                  player = Player(); // Reset the player
                  enter(player);     // Restart Room1
              } 
                else 
              {
                  std::cout << "Game Over!\n";
              }

         }
         
       }
      
    }
     
   
};

class Room2 {
   public:
    void enter(Player& player) {
       std::cout << "Welcome to Room 2\n";
       std::cout << "Suddenly, an enemy appears!\n";

       if (!player.hasItem("Rusty Sword")) { 
           std::cout << "You have no weapon to defend yourself!\n";
           std::cout << "The enemy strikes and you take 100 damage!\n";
           player.takeDamage(100);

           if (!player.isAlive()) {
               std::cout << "You died! Restarting from Room 1...\n";
               player = Player(); // Reset player
               Room1 room1;
               room1.enter(player);
               return; // Exit to prevent further execution
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
               return;
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
                           std::cout << "Restarting from Room 1...\n";
                           player = Player(); // Reset player
                           Room1 room1;
                           room1.enter(player);
                           return;
                       }
                   }
               }
               float choice_dos;
               std::cout << "You have successfully defeated both Goobers!\n";
               std::cout << "The goobers dropped something.\n";
               std::cout << "Its obsidion!\n";
               std::cout << "Keep exploring to find more peices of obsidion to craft the obsidion sword or key.\n"; //A piece of obsidion was discovered here.
               std::cout << "You have enterd room 2.5\n";
               std::cout << "-------- Choose a room: 1 - Enter 2.7 | Enter 2.1 | Enter 2.8 | Enter 4(DO NOT ENTER) --------\n";
               std::cin >> choice_dos;
               //2.7  - You get a new sword but it is a dead end so they go back(Needed if user wants to survive through room 2.1 and beyond)
               //2.1 - 2.3 - Room3(Success)
               //2.8 - 2.2 - 2.4 ----- 2.6 ---- 2.5 ---- Room3 (Success)
               //    (Fight monsters)   |-------1.1(Obsidion piece 2/3) ------- 1.3 ---------- room3 (Sucesss)
               //4 STOP STOP DOOOOOONNNNNT AHHHHHHHHH INUNUNUINIUNUNWONDW

               
           }
       }
    }
};

class Room3 {};

class Room4 {};
