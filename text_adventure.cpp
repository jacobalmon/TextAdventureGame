#include <iostream>
#include "rooms.h"

class Game {
    protected:
        Player player;
        Room1 room1;
        Room2 room2;
        // Room3 room3;
        // Room4 room4;
    public:
        // Game set to not quit out, unless specified in game.
        Game() {}

        void run() {
            std::cout << "Welcome to the Text Adventure!\n";
            while (player.isAlive()) {
                // Write Game Logic & Story.
                bool complete1 = room1.enter(player);
                if (!complete1) {
                    break;
                }
                
                bool complete2 = room2.enter(player);

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
