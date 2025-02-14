#include <vector>
#include <iostream>

class Goober {
    private:
        int health;
    public:
         Goober() : health(20) {}
         bool isAlive() const {return health > 0;}
         void takeDamage(int amount) 
         {
               health -= amount;
               if (health < 0) { health = 0; }
               std::cout << "Goober took " << amount << " damage.\n";
               std::cout << "Goober Health: " << health << ".\n";
         }

};
