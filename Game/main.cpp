#include <iostream>
#include <clocale>
#include "game.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    displayIntro();
    bool gameOver = false;
    while (!gameOver && lives > 0) {
        displayCurrentLocation(currentLocation);

        int playerChoice;
        cout << "Введите номер действия: ";

        // Проверка на корректный ввод
        while (true) {
            cin >> playerChoice;

            // Проверяем, введено ли число корректно
            if (cin.fail() || playerChoice < 1 || playerChoice > 3) {
                cin.clear(); // Сбрасываем состояние потока
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем некорректный ввод
                cout << "Некорректный номер действия! Попробуйте снова: ";
            }
            else {
                break; // Ввод корректен, выходим из цикла
            }
        }

        gameOver = processMove(playerChoice);

    }

    if (lives == 0) {
        cout << "Вы проиграли! У вас закончились жизни.\n";
    }

    return 0;
}