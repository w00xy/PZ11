#include <iostream>
#include <cstring>
#include "game.h"
using namespace std;

// Глобальные переменные, доступные для использования в разных файлах
int currentLocation = 0;
int lives = MAX_LIVES;
char inventory[MAX_INVENTORY_ITEMS][20] = {};
int inventoryCount = 0;

// Функция для отображения вступительной информации
void displayIntro() {
    cout << "Добро пожаловать в текстовый квест 'Путешествие в Пещеру'!\n";
    cout << "Ваша цель - исследовать пещеру и найти древний артефакт.\n";
    cout << "У вас есть " << MAX_LIVES << " жизни. Удачи!\n\n";
}

// Функция отображения текущей локации и доступных действий
void displayCurrentLocation(int locationIndex) {
    if (locationIndex == 0) {
        cout << "Вы находитесь у входа в пещеру. Здесь темно и холодно.\n";
        cout << "Доступные действия:\n";
        cout << "1) войти\n";
        cout << "2) исследовать\n";
        cout << "3) взять факел\n";
    }
    else if (locationIndex == 1) {
        cout << "Вы находитесь глубже в пещере. Стены покрыты древними надписями.\n";
        cout << "Доступные действия:\n";
        cout << "1) двигаться дальше\n";
        cout << "2) вернуться назад\n";
        cout << "3) взять камень\n";
    }
    else if (locationIndex == 2) {
        cout << "Вы находитесь в глубине пещеры. Перед вами древний артефакт.\n";
        cout << "Доступные действия:\n";
        cout << "1) вернуться назад\n";
        cout << "2) взять артефакт\n";
    }
    cout << "Введите номер действия: ";
}

// Функция добавления предмета в инвентарь
void takeItem(const char* item) {
    if (inventoryCount < MAX_INVENTORY_ITEMS) {
        strcpy_s(inventory[inventoryCount++], item);
        cout << "Вы добавили " << item << " в инвентарь.\n";
    }
    else {
        cout << "Инвентарь переполнен!\n";
    }
}

// Функция отображения инвентаря
void displayInventory() {
    cout << "Ваш инвентарь: ";
    if (inventoryCount == 0) {
        cout << "пуст\n";
    }
    else {
        for (int i = 0; i < inventoryCount; ++i) {
            cout << inventory[i];
            if (i < inventoryCount - 1) cout << ", ";
        }
        cout << ".\n";
    }
}

// Обработка действия на основе выбора пользователя
bool processMove(int choice) {
    if (currentLocation == 0) {
        if (choice == 1) {
            currentLocation = 1;
            cout << "Вы вошли в пещеру.\n";
        }
        else if (choice == 2) {
            cout << "Вы осмотрели окрестности, но не нашли ничего нового.\n";
        }
        else if (choice == 3) {
            takeItem("факел");
            displayInventory();
        }
        else {
            cout << "Некорректный номер действия! Попробуйте снова.\n";
            return false;
        }
    }
    else if (currentLocation == 1) {
        if (choice == 1) {
            currentLocation = 2;
            cout << "Вы продвигаетесь дальше в глубину пещеры.\n";
        }
        else if (choice == 2) {
            currentLocation = 0;
            cout << "Вы вернулись назад к входу.\n";
        }
        else if (choice == 3) {
            takeItem("камень");
            displayInventory();
        }
        else {
            cout << "Некорректный номер действия! Попробуйте снова.\n";
            return false;
        }
    }
    else if (currentLocation == 2) {
        if (choice == 1) {
            currentLocation = 1;
            cout << "Вы вернулись назад.\n";
        }
        else if (choice == 2) {
            takeItem("артефакт");
            cout << "Поздравляем! Вы нашли древний артефакт и успешно завершили квест!\n";
            return true; // Игра завершена
        }
        else {
            cout << "Некорректный номер действия! Попробуйте снова.\n";
            return false;
        }
    }
    return false;
}
