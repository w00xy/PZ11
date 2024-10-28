#include <iostream>
#include <clocale>
#include <unordered_map>
#include <functional>
#include <limits> // Для очистки буфера ввода
#include "calc.h"

using namespace std;

static void quit(bool* key) {
    *key = false;
    cout << "Выход из программы..." << endl;
}

int main() {
    // Определяю hashmap в котором ключ - операция (+, -, *, /, ^) - значение функция для вычисления этого числа
    std::unordered_map<char, std::function<double(int, int)>> operations;
    operations['+'] = add;
    operations['-'] = subtract;
    operations['*'] = multiply;
    operations['/'] = divide;
    operations['^'] = [](int base, int exp) -> double {
        return power(base, static_cast<int>(exp));
        };

    setlocale(LC_ALL, "ru");

    bool key = true;

    char start_text[] = {
        "Вы используете консольный калькулятор\n\n"
        "Выберите действие которое хотите совершить:\n"
        "1. Сложение (+)\n"
        "2. Вычитание (-)\n"
        "3. Умножение (*)\n"
        "4. Деление (/)\n"
        "5. Факториал числа (!)\n"
        "6. Возведение в степень (^)\n"
        "Чтобы закрыть программу введите q или нажмите CTRL + C\n\n"
        "Введите знак желаемого действия: "
    };

    char operation;

    while (key) {
        int a = 0;
        int b = 0;

        cout << start_text;

        // Проверка ввода перед считыванием operation
        if (cin.peek() == 'q' || cin.peek() == 'Q') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
            quit(&key);
            continue;
        }

        cin >> operation;

        if (operation == '!' || (operations.find(operation) != operations.end())) {
            try {
                if (operation == '!') {
                    cout << "Введите число: ";
                    cin >> a;
                    if (cin.fail()) {
                        cerr << "Некорректный ввод. Попробуйте снова." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue; // Переход к следующей итерации цикла
                    }

                    cout << "Результат: " << factorial(a) << endl;
                }
                else {
                    cout << "Введите первое число: ";
                    cin >> a;
                    if (cin.fail()) {
                        cerr << "Некорректный ввод. Попробуйте снова." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue; // Переход к следующей итерации цикла
                    }

                    cout << "Введите второе число: ";
                    cin >> b;
                    if (cin.fail()) {
                        cerr << "Некорректный ввод. Попробуйте снова." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue; // Переход к следующей итерации цикла
                    }

                    // Вызов функции из map по ключу:
                    double result = operations[operation](a, b);
                    cout << "Результат: " << result << endl;
                }
            }
            catch (const std::exception& error) {
                cerr << error.what() << endl;
            }
        }
        else if (operation == 'q' || operation == 'Q') {
            quit(&key);
        }
        else {
            cout << "Неверный знак операции." << endl;
        }
    }

    return 0;
}