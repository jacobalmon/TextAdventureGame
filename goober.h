#include <vector>
#include <iostream>

class Goober {
    private:
        int health;
    public:
         Goober() : health(20) {}
         bool isAlive() const {return health > 0;}
         void takeDamage(unsigned int amount) 
         {
               health -= amount;
               std::cout << "You took " << amount << " damage.\n";
               std::cout << "Health: " << health << ".\n";
         }

};
