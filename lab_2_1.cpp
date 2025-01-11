#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    double num1, num2;
    std::cout << "Введите первое число: ";
    std::cin >> num1;
    std::cout << "Введите второе число: ";
    std::cin >> num2;
    std::cout << "Среднее арифметическое: " << (num1 + num2) / 2 << std::endl;

    char operation;
    std::cout << "Введите знак операции (+, -, *, /): ";
    std::cin >> operation;
    double result;
    switch (operation) {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 != 0) {
            result = num1 / num2;
        }
        else {
            std::cout << "Ошибка: деление на ноль!" << std::endl;
            return 1;
        }
        break;
    default:
        std::cout << "Ошибка: неверный знак операции!" << std::endl;
        return 1;
    }
    std::cout << "Результат: " << result << std::endl;
}
