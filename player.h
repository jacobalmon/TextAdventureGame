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
        void takeDamage(int amount) {
            health -= amount;
            if (health < 0) { health = 0; }
            std::cout << "You took " << amount << " damage.\n";
            std::cout << "Your Health: " << health << ".\n";
        }
         //Allows player to heal if a specific item is found (Eddie)
        void addHealth(int amount){
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
        
        // Determines if player has an item or not.
        bool hasItem(const std::string& item){
            for (int i; i < inventory.size(); ++i) {
                if (item == inventory[i]) {
                    return true;
                }
            }
            return false;
        }

        // Returns Current Inventory.
        std::vector<std::string>& getInventory() { return inventory; }

        // Returns Health.
        int getHealth() const { return health; }

        void reset() {
            health = 100;
            inventory.clear();
        }
};
