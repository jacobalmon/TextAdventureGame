#ifndef ROOMS_H
#define ROOMS_H

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

       bool hasWeapon = false;
       for (const auto& item : player.getInventory()) {
           if (item == "Rusty Sword") {
               hasWeapon = true;
               break;
           }
       }

       if (!hasWeapon) {
           std::cout << "You have no weapon to defend yourself!\n";
           std::cout << "The enemy strikes and you take 100 damage!\n";
           player.takeDamage(100);

           if (!player.isAlive()) {
               std::cout << "You died! Restarting from Room 1...\n";
               player = Player(); // Reset player
               Room1 room1;
               room1.enter(player);
           }
       } else {
           std::cout << "You use your Rusty Sword to fight off the enemy!\n";
           std::cout << "You barely make it out alive but continue forward.\n";
       }
    }

};

class Room3 {};

class Room4 {};


#endif
