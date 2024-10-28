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
        cout << "������� ����� ��������: ";

        // �������� �� ���������� ����
        while (true) {
            cin >> playerChoice;

            // ���������, ������� �� ����� ���������
            if (cin.fail() || playerChoice < 1 || playerChoice > 3) {
                cin.clear(); // ���������� ��������� ������
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ���������� ������������ ����
                cout << "������������ ����� ��������! ���������� �����: ";
            }
            else {
                break; // ���� ���������, ������� �� �����
            }
        }

        gameOver = processMove(playerChoice);

    }

    if (lives == 0) {
        cout << "�� ���������! � ��� ����������� �����.\n";
    }

    return 0;
}