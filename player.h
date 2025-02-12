#include <vector>
#include <iostream>

class Player {
    private:
        int health;
        std::vector<std::string> inventory;
    public:
        // Initialize Health at 100.
        Player() : health(100) {}

        // Determine whether player is alive.
        bool isAlive() const {return health > 0;}  

        // Allows player to take damage.
        void takeDamage(unsigned int amount) {
            health -= amount;
            std::cout << "You took " << amount << " damage.\n";
            std::cout << "Health: " << health << ".\n";
        }
         //Allows player to heal if a specific item is found (Eddie)
        void addHealth(unsigned int amount){
            if(health == 100)
            {
                std::cout << "Health is full";
            }
            else
            {
                health += amount;
                std::cout << "You gained " << amount << " Health.\n";
                std::cout << "Health: " << health << ".\n";
            }
        }

        // Allows player to add items to inventory.
        void addItem(const std::string& item) {
            inventory.push_back(item);
            std::cout << item << " added to inventory.\n";
        }
        
        // Allows player to view inventory.
        void showInventory() const {
            // Empty Inventory.
            if (inventory.empty()) {
                std::cout << "Your inventory is empty.\n";
                return;
            }
            // Display Non-Empty Inventory.
            std::cout << "Inventory:\n";
            for (const auto& item : inventory) {
                std::cout << "- " << item << "\n";
            }
        }

        // Returns Current Inventory.
        std::vector<std::string>& getInventory() { return inventory; }

        // Returns Health.
        int getHealth() const { return health; }
};
