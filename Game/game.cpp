#include <iostream>
#include <cstring>
#include <cstdlib>  // ��� ������� rand()
#include "game.h"
using namespace std;

int currentLocation = 0;
int lives = MAX_LIVES;
char inventory[MAX_INVENTORY_ITEMS][20] = {};
int inventoryCount = 0;

void displayIntro() {
    cout << "����� ���������� � ��������� ����� '����������� � ������'!\n";
    cout << "���� ���� - ����������� ������ � ����� ������� ��������.\n";
    cout << "� ��� ���� " << MAX_LIVES << " �����. �����!\n\n";
}

void displayCurrentLocation(int locationIndex) {
    if (locationIndex == 0) {
        cout << "�� ���������� � ����� � ������. ����� ����� � �������.\n";
        cout << "��������� ��������:\n";
        cout << "1) �����\n";
        cout << "2) �����������\n";
        cout << "3) ����� �����\n";
    }
    else if (locationIndex == 1) {
        cout << "�� ���������� ������ � ������. ����� ������� �������� ���������.\n";
        cout << "��������� ��������:\n";
        cout << "1) ��������� ������\n";
        cout << "2) ��������� �����\n";
        cout << "3) ����� ������\n";
    }
    else if (locationIndex == 2) {
        cout << "�� ���������� � ������� ������. ����� ���� ������� ��������.\n";
        cout << "��������� ��������:\n";
        cout << "1) ��������� �����\n";
        cout << "2) ����� ��������\n";
    }
    cout << "������� ����� ��������: ";
}

void takeItem(const char* item) {
    if (inventoryCount < MAX_INVENTORY_ITEMS) {
        strcpy_s(inventory[inventoryCount++], item);
        cout << "�� �������� " << item << " � ���������.\n";
    }
    else {
        cout << "��������� ����������!\n\n";
    }
}

void displayInventory() {
    cout << "��� ���������: ";
    if (inventoryCount == 0) {
        cout << "����\n";
    }
    else {
        for (int i = 0; i < inventoryCount; ++i) {
            cout << inventory[i];
            if (i < inventoryCount - 1) cout << ", ";
        }
        cout << ".\n";
    }
}

// ������� ��� �������� ������� �������� � ���������
bool hasItem(const char* item) {
    for (int i = 0; i < inventoryCount; ++i) {
        if (strcmp(inventory[i], item) == 0) {
            return true;
        }
    }
    return false;
}

// ��������� �������� �� ������ ������ ������������
bool processMove(int choice) {
    if (currentLocation == 0) {
        if (choice == 1) {
            currentLocation = 1;
            cout << "�� ����� � ������.\n";

            // �������� ������� ������ � ���������
            if (!hasItem("�����")) {
                lives--;
                cout << "��� ������� ���-�� � �������, ������ ��� � ��� ��� ������! -1 �����.\n\n";
                cout << "�������� ������: " << lives << "\n\n";
                if (lives <= 0) return true;
            }
        }
        else if (choice == 2) {
            // �����������, ��� ����� ������������� � �������� �����
            if (rand() % 100 < 33) { // 0-32 ���� 33% �����������
                lives--;
                cout << "�� �������������� � ���������! -1 �����.\n\n";
                cout << "�������� ������: " << lives << "\n\n";
                if (lives <= 0) return true; // �������� �� ����� ����
            }
            else {
                cout << "�� ��������� �����������, �� �� ����� ������ ������.\n\n";
            }
        }
        else if (choice == 3) {
            takeItem("�����");
            displayInventory();
        }
        else {
            cout << "������������ ����� ��������! ���������� �����.\n\n";
            return false;
        }
    }
    else if (currentLocation == 1) {
        if (choice == 1) {
            // �������� �� ������� ������ ����� ���, ��� ��������� ������
            if (!hasItem("�����")) {
                lives -= 2; // ������ ���� ������
                cout << "�� ������������� ������ � ������� � ��� ������� ����! -2 �����.\n\n";
                cout << "�������� ������: " << lives << "\n\n";
                if (lives <= 0) return true; // ���� ���������
            }
            else {
                currentLocation = 2;
                cout << "�� ������������� ������ � ������� ������.\n\n";
            }
        }
        else if (choice == 2) {
            currentLocation = 0;
            cout << "�� ��������� ����� � �����.\n\n";
        }
        else if (choice == 3) {
            takeItem("������");
            displayInventory();
        }
        else {
            cout << "������������ ����� ��������! ���������� �����.\n\n";
            return false;
        }
    }
    else if (currentLocation == 2) {
        if (choice == 1) {
            currentLocation = 1;
            cout << "�� ��������� �����.\n\n";
        }
        else if (choice == 2) {
            takeItem("��������");
            cout << "�����������! �� ����� ������� �������� � ������� ��������� �����!\n\n";
            return true; // ���� ���������
        }
        else {
            cout << "������������ ����� ��������! ���������� �����.\n\n";
            return false;
        }
    }
    return false;
}
