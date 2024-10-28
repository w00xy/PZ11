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
        cin >> playerChoice;

        gameOver = processMove(playerChoice);

        /*if (!gameOver) {
            lives--;
            cout << "�������� ������: " << lives << "\n";
        }*/
    }

    if (lives == 0) {
        cout << "�� ���������! � ��� ����������� �����.\n";
    }

    return 0;
}
