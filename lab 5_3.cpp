#include <iostream>
#include <string>

using namespace std;

class Weapon {
public:
    virtual void Attack() = 0;
    virtual ~Weapon() {}
};

class MagicWeapon : public Weapon {
public:
    void Attack() override {
        cout << "Атакуем магическим оружием" << endl;
    }
};

class DisposableWeapon : public Weapon {
private:
    bool used;

public:
    DisposableWeapon() : used(false) {}

    void Attack() override {
        if (used) {
            cout << "Оружие уже было использовано" << endl;
        }
        else {
            cout << "Атакуем одноразовым оружием" << endl;
            used = true;
        }
    }
};

template <typename LeftWeaponType, typename RightWeaponType>
class WeaponHolder {
private:
    LeftWeaponType leftWeapon;
    RightWeaponType rightWeapon;

public:
    WeaponHolder(LeftWeaponType left, RightWeaponType right)
        : leftWeapon(left), rightWeapon(right) {}

    LeftWeaponType GetLeftWeapon() const {
        return leftWeapon;
    }

    RightWeaponType GetRightWeapon() const {
        return rightWeapon;
    }

    void SetLeftWeapon(LeftWeaponType weapon) {
        leftWeapon = weapon;
    }

    void SetRightWeapon(RightWeaponType weapon) {
        rightWeapon = weapon;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    MagicWeapon magicSword;
    magicSword.Attack();

    DisposableWeapon disposableSword;
    disposableSword.Attack();
    disposableSword.Attack();

    WeaponHolder<MagicWeapon, DisposableWeapon> weaponHolder(magicSword, disposableSword);

    cout << "Левое оружие: ";
    weaponHolder.GetLeftWeapon().Attack();
    cout << "Правое оружие: ";
    weaponHolder.GetRightWeapon().Attack();

}