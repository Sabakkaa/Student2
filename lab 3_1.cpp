#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");

    int variable = 10;
    int* pointer = &variable;
    std::cout << "Адрес указателя: " << pointer << std::endl;
    std::cout << "Значение по адресу указателя: " << *pointer << std::endl;

    *pointer = 20;
    std::cout << "Новое значение переменной: " << variable << std::endl;

    int array[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(array) / sizeof(array[0]);
    std::cout << "Элементы массива: ";
    for (int i = 0; i < size; ++i) {
        std::cout << *(array + i) << " ";
    }
    std::cout << std::endl;

    int fixedValue = 5;
    int* const constPointer = &fixedValue;

    //constPointer = nullptr; // Эта строка вызовет ошибку компилятора

    *constPointer = 10;
    std::cout << "Новое значение переменной fixedValue: " << fixedValue << std::endl;
}
