#include <iostream>
#include <string>

using namespace std;


enum class WeaponType {
    ONEHANDED,
    TWOHANDED,
    BOW,
    CROSSBOW
};

class Weapon {
private:
    string name;
    int damage;
    WeaponType type;

public:
    Weapon(string name, int damage, WeaponType type)
        : name(name), damage(damage), type(type) {}

    virtual int GetDamage() const {
        return damage;
    }

    string GetName() const {
        return name;
    }

    WeaponType GetType() const {
        return type;
    }

    bool operator>(const Weapon& other) const {
        return this->GetDamage() > other.GetDamage();
    }

    bool operator<(const Weapon& other) const {
        return this->GetDamage() < other.GetDamage();
    }
};

class MagicWeapon : public Weapon {
private:
    int additionalDamage;

public:
    MagicWeapon(string name, int damage, WeaponType type, int additionalDamage)
        : Weapon(name, damage, type), additionalDamage(additionalDamage) {}

    int GetDamage() const override {
        return Weapon::GetDamage() + additionalDamage;
    }
};

void PrintWeaponType(WeaponType type) {
    switch (type) {
    case WeaponType::ONEHANDED:
        cout << "Одноручное оружие" << endl;
        break;
    case WeaponType::TWOHANDED:
        cout << "Двуручное оружие" << endl;
        break;
    case WeaponType::BOW:
        cout << "Лук" << endl;
        break;
    case WeaponType::CROSSBOW:
        cout << "Арбалет" << endl;
        break;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    Weapon sword("Меч", 10, WeaponType::ONEHANDED);
    cout << "Оружие: " << sword.GetName() << ", Урон: " << sword.GetDamage() << endl;

    MagicWeapon magicSword("Магический меч", 10, WeaponType::ONEHANDED, 5);
    cout << "Оружие: " << magicSword.GetName() << ", Урон: " << magicSword.GetDamage() << endl;

    if (magicSword.GetDamage() == sword.GetDamage() + 5) {
        cout << "Магическое оружие возвращает правильный урон." << endl;
    }

    if (sword < magicSword) {
        cout << sword.GetName() << " имеет меньший урон, чем " << magicSword.GetName() << endl;
    }

    if (magicSword > sword) {
        cout << magicSword.GetName() << " имеет больший урон, чем " << sword.GetName() << endl;
    }

}