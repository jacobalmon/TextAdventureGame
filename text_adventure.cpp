#include <iostream>

class Game {
    public:
        void gameloop(); // Run indefinately.
};

int main() {
    Game game;
    game.gameloop();
    return 0;
}