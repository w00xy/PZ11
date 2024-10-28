#ifndef GAME_H
#define GAME_H

// ���������
const int MAX_LIVES = 3;
const int MAX_INVENTORY_ITEMS = 5;
const int LOCATION_COUNT = 3;

// �������
void displayIntro();
void displayCurrentLocation(int locationIndex);
bool processMove(int choice); // �������� �������� �� int
void displayInventory();
void takeItem(const char* item); // �������� �������� �� const char*

// ����������
extern int currentLocation;
extern int lives;
extern char inventory[MAX_INVENTORY_ITEMS][20];
extern int inventoryCount;

#endif
