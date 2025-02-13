#include <iostream>
#include "rooms.h"

class Game {
    private:
        bool quit;
    protected:
        Player player;
        Room1 room1;
        Room2 room2;
        // Room3 room3;
        // Room4 room4;
    public:
        // Game set to not quit out, unless specified in game.
        Game() : quit(false) {}

        void run() {
            std::cout << "Welcome to the Text Adventure!\n";
            while (player.isAlive() && !quit) {
                // Write Game Logic & Story.
                bool complete1 = room1.enter(player);
                if (!complete1) {
                    return;
                }

                bool complete2 = room2.enter(player);
            }
        };
};

int main() {
    Game game;
    game.run();
    return 0;
}