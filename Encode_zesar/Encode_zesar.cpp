#include <iostream>
#include <string>
#include <clocale>

using namespace std;

// Функция для шифрования/дешифрования символа
char caesarCipher(char ch, int shift, bool encrypt) {
    // Проверка на алфавитный символ
    if (isalpha(ch)) {
        // Определение смещения
        int offset = encrypt ? shift : -shift;
        // Установка базового симвоала + определение зашифрованного символа
        char base = islower(ch) ? 'a' : 'A';
        return base + (ch - base + offset + 26) % 26;
    }
    else {
        return ch;
    }
}

int main() {
    char operation;
    int shift;
    int length;

    while (true) {
        // Запрос выбора операции
        cout << "E - Encrypt D - Decrypt Q - Quit: ";
        cin >> operation;

        // Выход из программы при вводе 'Q'
        if (operation == 'Q') {
            cout << "Ended" << endl;
            break;
        }

        // Проверка правильности ввода операции
        if (operation != 'E' && operation != 'D') {
            cout << "No such operation" << endl;
            continue; // Продолжить цикл
        }

        // Запрос смещения
        cout << "Enter shift (Integer number): ";
        cin >> shift;

        // Запрос длины строки
        cout << "Enter length of string: ";
        cin >> length;

        // Проверка ввода длины строки
        if (length <= 0) {
            cout << "Not available to have such string" << endl;
            continue; // Продолжить цикл
        }

        // Запрос строки
        cout << "Enter string: ";
        cin.ignore(); // Очистка буфера ввода
        string inputLine;
        getline(cin, inputLine);

        // Проверка длины строки
        if (inputLine.length() < length) {
            cout << "Input string is shorter than specified length" << endl;
            continue; // Продолжить цикл
        }

        // Приведение смещения к правильному диапазону
        shift %= 26;

        // Шифрование/дешифрование текста
        string result = "";
        for (int i = 0; i < length; i++) {
            result += caesarCipher(inputLine[i], shift, operation == 'E');
        }

        cout << "Result: " << result << endl;
    }

    return 0;
}

