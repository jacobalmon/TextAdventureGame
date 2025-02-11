#ifndef ROOMS_H
#define ROOMS_H

#include "player.h"

class Room1 {
  public:
    void enter(Player& player){
       int choice;
       int choice_dos
       std::cout << "You entered Room 1.\n";
       std::cout << "You have encountered an enemy!\n";
       std::cout << "-------- Choose: 1 - To flee or 2 - To attack --------\n";
       std::cin >> choice;
       if(choice == 1)  //Path to success 
       { 
          std::cout << "You fled\n";
          std::cout << "You have enterd room 1.5";
          std::cout << "-------- Choose: 1 - Enter room 1.7 | Enter room 1.8 | Enter room4 --------\n";
          
          
          player.addItem("Key");
          std::cout << "Congratulations! You obtained a key\n";
          Room2 room2
          room2.enter(player);
        
       }
       else if(choice == 2) //Path will lead the player to start again
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
   std::cout << "Welcome to room 2\n";

};

class Room3 {
   std::cout << "Welcome to room 3\n";

};

class Room4 {
   std::cout << "Welcome to room 4\n";

};


#endif
