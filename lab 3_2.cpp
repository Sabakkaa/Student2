#include <iostream>

int sumArray(int* start, int* end) {
    int sum = 0;
    for (int* ptr = start; ptr < end; ++ptr) {
        sum += *ptr;
    }
    return sum;
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

typedef int (*OperationFunc)(int, int);

OperationFunc getOperation(char op) {
    if (op == '+') {
        return add;
    }
    else if (op == '-') {
        return subtract;
    }
    return nullptr;
}

int main() {

    setlocale(LC_ALL, "Russian");
    
    int arr[] = { 1, 2, 3, 4, 5 };
    int sum = sumArray(arr, arr + 5);
    std::cout << "Сумма элементов массива: " << sum << std::endl;

    char operation = '+';
    OperationFunc func = getOperation(operation);
    if (func) {
        int result = func(10, 5);
        std::cout << "Результат операции " << operation << ": " << result << std::endl;
    }

    operation = '-';
    func = getOperation(operation);
    if (func) {
        int result = func(10, 5);
        std::cout << "Результат операции " << operation << ": " << result << std::endl;
    }

    float* dynamicFloat = new float(3.14f);
    std::cout << "Динамический указатель на float: " << *dynamicFloat << std::endl;

    delete dynamicFloat;

}