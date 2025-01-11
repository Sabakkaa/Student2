#include <iostream>
#include <string>

class Weapon {
private:
    std::string name;
    int damage;
    float weight;

public:
    
    Weapon(const std::string& weaponName, int weaponDamage, float weaponWeight)
        : name(weaponName), damage(weaponDamage), weight(weaponWeight) {}

    Weapon() : Weapon("Default Weapon", 10, 1.5f) {}

    void display() const {
        std::cout << "Название: " << name << ", Урон: " << damage << ", Вес: " << weight << " кг" << std::endl;
    }
};

int main() {

    setlocale(LC_ALL, "Russian");

    Weapon sword("Sword", 50, 3.0f);

    Weapon defaultWeapon;

    std::cout << "Информация о первом оружии:" << std::endl;
    sword.display();

    std::cout << "Информация о втором оружии:" << std::endl;
    defaultWeapon.display();

}
