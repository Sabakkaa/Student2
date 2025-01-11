
#include <iostream>
#include <vector>

int main() {

    setlocale(LC_ALL, "Russian");

    int number;
    while (true) {
        std::cout << "Введите целое положительное число: ";
        std::cin >> number;
        if (number > 0) {
            break;
        }
        else {
            std::cout << "Число должно быть положительным." << std::endl;
        }
    }

    int sum_numbers = 0;
    std::cout << "Сумма: ";
    for (int i = 1; i <= number; ++i) {
        sum_numbers += i;
        std::cout << i;
        if (i < number) {
            std::cout << " + ";
        }
    }
    std::cout << " = " << sum_numbers << std::endl;

    std::vector<int> array = { 5, 12, 7, 3, 19, 8, 14, 21, 2, 10 };

    std::cout << "Массив: ";
    for (size_t i = 0; i < array.size(); ++i) {
        std::cout << array[i];
        if (i < array.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    std::cout << "Числа на четных позициях: ";
    for (size_t i = 0; i < array.size(); ++i) {
        if (i % 2 == 0) {
            std::cout << array[i] << " ";
        }
    }
    std::cout << std::endl;

    int sum_odd_indexed = 0;
    for (size_t i = 0; i < array.size(); ++i) {
        if (i % 2 != 0) {
            sum_odd_indexed += array[i];
        }
    }
    std::cout << "Сумма элементов на нечётных позициях: " << sum_odd_indexed << std::endl;
}

