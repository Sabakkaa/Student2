#include <iostream>
#include "Header.h"

int main() {

    setlocale(LC_ALL, "Russian");
    // Создание объекта оружия
    Weapon sword("Меч", 50, 3.0f);
    sword.display(); // Вывод информации об оружии

    // Создание динамического объекта оружия
    Weapon* dynamicSword = new Weapon("Динамический Меч", 60, 4.0f);
    dynamicSword->display(); // Вывод информации о динамическом объекте

    // Проверка работы метода canLift
    float maxWeight = 3.5f;
    std::cout << "Может ли поднять меч (макс. вес " << maxWeight << " кг): "
        << (sword.canLift(maxWeight) ? "Нет" : "Да") << std::endl;

    // Проверка работы метода totalWeight с другим объектом
    float totalWeightWithObject = sword.totalWeight(*dynamicSword);
    std::cout << "Суммарный вес меча и динамического меча: " << totalWeightWithObject << " кг" << std::endl;

    // Проверка работы перегруженного метода totalWeight с весом
    float additionalWeight = 2.0f;
    float totalWeightWithValue = sword.totalWeight(additionalWeight);
    std::cout << "Суммарный вес меча и дополнительного веса (" << additionalWeight << " кг): "
        << totalWeightWithValue << " кг" << std::endl;

    // Освобождение памяти для динамического объекта
    delete dynamicSword;

    return 0;
}
