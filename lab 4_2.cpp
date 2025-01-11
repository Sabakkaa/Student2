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

    ~Weapon() {
        std::cout << "Удаление оружия: " << name
            << ", Урон: " << damage
            << ", Вес: " << weight << " кг" << std::endl;
    }

    void display() const {
        std::cout << "Название: " << name
            << ", Урон: " << damage
            << ", Вес: " << weight << " кг" << std::endl;
    }

    bool canLift(float maxWeight) const {
        return weight > maxWeight;
    }

    float totalWeight(const Weapon& other) const {
        return weight + other.weight;
    }

    float totalWeight(float otherWeight) const {
        return weight + otherWeight;
    }
};

int main() {

    setlocale(LC_ALL, "Russian");
    
    Weapon sword("Меч", 50, 3.0f);
    sword.display();

    Weapon* dynamicSword = new Weapon("Динамический Меч", 60, 4.0f);
    dynamicSword->display();

    float maxWeight = 3.5f;
    std::cout << "Может ли поднять меч (макс. вес " << maxWeight << " кг): "
        << (sword.canLift(maxWeight) ? "Нет" : "Да") << std::endl;

    float totalWeightWithObject = sword.totalWeight(*dynamicSword);
    std::cout << "Суммарный вес меча и динамического меча: " << totalWeightWithObject << " кг" << std::endl;

    float additionalWeight = 2.0f;
    float totalWeightWithValue = sword.totalWeight(additionalWeight);
    std::cout << "Суммарный вес меча и дополнительного веса (" << additionalWeight << " кг): "
        << totalWeightWithValue << " кг" << std::endl;

    delete dynamicSword;
    
}