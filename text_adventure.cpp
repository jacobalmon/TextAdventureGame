#include <iostream>
#include "rooms.h"

class Game {
    protected:
        Player player;
        Room1 room1;
        Room2 room2;
        Room3 room3;
        Room4 room4;
    public:
        // Game set to not quit out, unless specified in game.
        Game() {}

        void run() 
        {
            std::cout << "Welcome to the Text Adventure!\n";
            std::cout << "You are in a world where you must explore, fight, and survive in a dungeon filled with random rooms.\n";
            std::cout << "Rooms may contain battles against enemies, puzzles, and more.\n";
            std::cout << "Disclaimer: This is the alpha version. We currently have simple mechanics. The beta version will be released next month.\n";

            while (player.isAlive()) 
            {
                // Write Game Logic & Story.
                bool complete1 = room1.enter(player); // Fighting the "Goblin"
                if (!complete1) 
                {
                    break;
                }
                
                bool complete2 = room2.enter(player); // Fighting the "Goober" (What the heck is the Goober?)
                if (!complete2) 
                {
                    break;
                }

                bool complete3 = room3.enter(player); // Fighting the "Oily Troll" 
                if (!complete3) 
                {
                    break;
                }

                bool complete4 = room4.enter(player); // Fighting the "Giant Enemy Spider"
                if (!complete4) 
                {
                    break;
                }
            }

            std::cout << "Do you want to play again? (Y/N)?\n";
            char input;
            std::cin >> input;
            if (input == 'Y' || input == 'y') {
                player.reset();
                return run();
            }
        }
};

int main() {
    Game game;
    game.run();
    return 0;
}
