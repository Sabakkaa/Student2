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

    string GetName() const {
        return name;
    }

    int GetDamage() const {
        return damage;
    }

    WeaponType GetType() const {
        return type;
    }

    void SetDamage(int damage) {
        this->damage = damage;
    }
};

struct Player {
    int id;
    string login;
    string password;

    void DisplayInfo() const {
        cout << "ID: " << id << ", Логин: " << login << ", Пароль: " << password << endl;
    }
};

class MagicWeapon : public Weapon {
private:
    int additionalDamage;

public:
    MagicWeapon(string name, int damage, WeaponType type, int additionalDamage)
        : Weapon(name, damage, type), additionalDamage(additionalDamage) {}

    MagicWeapon() : Weapon("Магическое оружие", 5, WeaponType::ONEHANDED), additionalDamage(0) {}

    int GetAdditionalDamage() const {
        return additionalDamage;
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

    PrintWeaponType(sword.GetType());

    Player player = { 1, "Player1", "Password123" };
    player.DisplayInfo();

    MagicWeapon magicSword("Магический меч", 10, WeaponType::ONEHANDED, 5);
    cout << "Оружие: " << magicSword.GetName() << ", Урон: " << magicSword.GetDamage()
        << ", Дополнительный урон: " << magicSword.GetAdditionalDamage() << endl;

    MagicWeapon defaultMagicSword;
    cout << "Оружие: " << defaultMagicSword.GetName() << ", Урон: " << defaultMagicSword.GetDamage()
        << ", Дополнительный урон: " << defaultMagicSword.GetAdditionalDamage() << endl;
    
}
