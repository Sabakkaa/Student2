#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

enum class ErrorCode {
    INVALID_INPUT,
    YEAR_TOO_EARLY,
    YEAR_TOO_LATE,
    NEGATIVE_NUMBER
};

class CustomException : public std::exception {
private:
    ErrorCode code;
    string message;

public:
    CustomException(ErrorCode code, const string& message) : code(code), message(message) {}

    const char* what() const noexcept override {
        return message.c_str();
    }

    ErrorCode getCode() const {
        return code;
    }
};

void processNumberInput(int number) {
    switch (number) {
    case 1:
        cout << "Один" << endl;
        break;
    case 2:
        cout << "Два" << endl;
        break;
    case 3:
        cout << "Три" << endl;
        break;
    default:
        throw CustomException(ErrorCode::INVALID_INPUT, "Некорректное значение");
    }
}

void processYearOfBirth(int year) {
    const int currentYear = 2023;

    if (year < 1850) {
        throw CustomException(ErrorCode::YEAR_TOO_EARLY, "Что-то не верится...");
    }
    else if (year > currentYear) {
        throw CustomException(ErrorCode::YEAR_TOO_LATE, "Вы ещё не родились");
    }
    else if (year < 0) {
        throw CustomException(ErrorCode::NEGATIVE_NUMBER, "Вы ввели отрицательное число!");
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    try {
        int number;
        cout << "Введите число 1, 2 или 3: ";
        cin >> number;
        processNumberInput(number);
    }
    catch (const CustomException& e) {
        cout << e.what() << endl;
    }

    try {
        int year;
        cout << "Введите год своего рождения: ";
        cin >> year;
        processYearOfBirth(year);
        cout << "Спасибо!" << endl;
    }
    catch (const CustomException& e) {
        cout << e.what() << endl;
    }

}