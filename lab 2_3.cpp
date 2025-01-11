#include <iostream>

void calculate(int a, int b, int& sum, int& product) {
    sum = a + b;
    product = a * b;
}

int sumPositive(int number = 1) {
    if (number <= 0) {
        return 0;
    }

    int sum = 0;
    for (int i = 1; i <= number; ++i) {
        sum += i;
    }
    return sum;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int array2D[2][3] = { {1, 2, 3}, {4, 5, 6} };

    int totalSum = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            totalSum += array2D[i][j];
        }
    }
    std::cout << "Сумма всех чисел в двумерном массиве: " << totalSum << std::endl;

    int array1D[3];
    for (int j = 0; j < 3; ++j) {
        array1D[j] = array2D[0][j] + array2D[1][j];
    }

    std::cout << "Одномерный массив: { ";
    for (int i = 0; i < 3; ++i) {
        std::cout << array1D[i];
        if (i < 2) {
            std::cout << ", ";
        }
    }
    std::cout << " }" << std::endl;

    float value = 20.84;
    float& ref1 = value;
    float& ref2 = value;
    ref1 = 30.5;
    std::cout << "Значение переменной value: " << value << std::endl;
    std::cout << "Значение ссылки ref2: " << ref2 << std::endl;

    int num;
    std::cout << "Введите число: ";
    std::cin >> num;
    std::cout << "Сумма чисел от 1 до данного числа: " << sumPositive(num) << std::endl;

    std::cout << "Сумма чисел от 1 до 1 (по умолчанию): " << sumPositive() << std::endl;

    int sumRef, productRef;
    calculate(3, 4, sumRef, productRef);

    std::cout << "Сумма (по ссылке): " << sumRef << ", Произведение (по ссылке): " << productRef << std::endl;

    std::string exampleVar = "Пример переменной";
    std::cout << "Переменная: " << exampleVar << std::endl;

    for (int i = 0; i < 3; ++i) {
        std::cout << "Число из двумерного массива: " << array2D[0][0] << std::endl;
    }
    for (int i = 0; i < 3; ++i) {
        int newVariable = 10;
        std::cout << "Вывод новой переменной (раз " << (i + 1) << "): " << newVariable << std::endl;
    }
}