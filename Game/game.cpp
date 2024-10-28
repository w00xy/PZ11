#include <iostream>
#include <cstring>
#include <cstdlib>  // для функции rand()
#include "game.h"
using namespace std;

int currentLocation = 0;
int lives = MAX_LIVES;
char inventory[MAX_INVENTORY_ITEMS][20] = {};
int inventoryCount = 0;

void displayIntro() {
    cout << "Добро пожаловать в текстовый квест 'Путешествие в Пещеру'!\n";
    cout << "Ваша цель - исследовать пещеру и найти древний артефакт.\n";
    cout << "У вас есть " << MAX_LIVES << " жизни. Удачи!\n\n";
}

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

void takeItem(const char* item) {
    if (inventoryCount < MAX_INVENTORY_ITEMS) {
        strcpy_s(inventory[inventoryCount++], item);
        cout << "Вы добавили " << item << " в инвентарь.\n";
    }
    else {
        cout << "Инвентарь переполнен!\n\n";
    }
}

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

// Функция для проверки наличия предмета в инвентаре
bool hasItem(const char* item) {
    for (int i = 0; i < inventoryCount; ++i) {
        if (strcmp(inventory[i], item) == 0) {
            return true;
        }
    }
    return false;
}

// Обработка действия на основе выбора пользователя
bool processMove(int choice) {
    if (currentLocation == 0) {
        if (choice == 1) {
            currentLocation = 1;
            cout << "Вы вошли в пещеру.\n";

            // Проверка наличия факела в инвентаре
            if (!hasItem("факел")) {
                lives--;
                cout << "Вас укусило что-то в темноте, потому что у вас нет факела! -1 жизнь.\n\n";
                cout << "Осталось жизней: " << lives << "\n\n";
                if (lives <= 0) return true;
            }
        }
        else if (choice == 2) {
            // Вероятность, что игрок поскользнется и потеряет жизнь
            if (rand() % 100 < 33) { // 0-32 дает 33% вероятность
                lives--;
                cout << "Вы поскользнулись и ударились! -1 жизнь.\n\n";
                cout << "Осталось жизней: " << lives << "\n\n";
                if (lives <= 0) return true; // Проверка на конец игры
            }
            else {
                cout << "Вы осмотрели окрестности, но не нашли ничего нового.\n\n";
            }
        }
        else if (choice == 3) {
            takeItem("факел");
            displayInventory();
        }
        else {
            cout << "Некорректный номер действия! Попробуйте снова.\n\n";
            return false;
        }
    }
    else if (currentLocation == 1) {
        if (choice == 1) {
            // Проверка на наличие факела перед тем, как двигаться дальше
            if (!hasItem("факел")) {
                lives -= 2; // Потеря двух жизней
                cout << "Вы продвигаетесь дальше в темноте и вас съедает паук! -2 жизни.\n\n";
                cout << "Осталось жизней: " << lives << "\n\n";
                if (lives <= 0) return true; // Игра завершена
            }
            else {
                currentLocation = 2;
                cout << "Вы продвигаетесь дальше в глубину пещеры.\n\n";
            }
        }
        else if (choice == 2) {
            currentLocation = 0;
            cout << "Вы вернулись назад к входу.\n\n";
        }
        else if (choice == 3) {
            takeItem("камень");
            displayInventory();
        }
        else {
            cout << "Некорректный номер действия! Попробуйте снова.\n\n";
            return false;
        }
    }
    else if (currentLocation == 2) {
        if (choice == 1) {
            currentLocation = 1;
            cout << "Вы вернулись назад.\n\n";
        }
        else if (choice == 2) {
            takeItem("артефакт");
            cout << "Поздравляем! Вы нашли древний артефакт и успешно завершили квест!\n\n";
            return true; // Игра завершена
        }
        else {
            cout << "Некорректный номер действия! Попробуйте снова.\n\n";
            return false;
        }
    }
    return false;
}
