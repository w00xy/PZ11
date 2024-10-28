#include <iostream>
#include <clocale>
#include <unordered_map>
#include <functional>
#include <limits> // ��� ������� ������ �����
#include "calc.h"

using namespace std;

static void quit(bool* key) {
    *key = false;
    cout << "����� �� ���������..." << endl;
}

int main() {
    // ��������� hashmap � ������� ���� - �������� (+, -, *, /, ^) - �������� ������� ��� ���������� ����� �����
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
        "�� ����������� ���������� �����������\n\n"
        "�������� �������� ������� ������ ���������:\n"
        "1. �������� (+)\n"
        "2. ��������� (-)\n"
        "3. ��������� (*)\n"
        "4. ������� (/)\n"
        "5. ��������� ����� (!)\n"
        "6. ���������� � ������� (^)\n"
        "����� ������� ��������� ������� q ��� ������� CTRL + C\n\n"
        "������� ���� ��������� ��������: "
    };

    char operation;

    while (key) {
        int a = 0;
        int b = 0;

        cout << start_text;

        // �������� ����� ����� ����������� operation
        if (cin.peek() == 'q' || cin.peek() == 'Q') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ������
            quit(&key);
            continue;
        }

        cin >> operation;

        if (operation == '!' || (operations.find(operation) != operations.end())) {
            try {
                if (operation == '!') {
                    cout << "������� �����: ";
                    cin >> a;
                    if (cin.fail()) {
                        cerr << "������������ ����. ���������� �����." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue; // ������� � ��������� �������� �����
                    }

                    cout << "���������: " << factorial(a) << endl;
                }
                else {
                    cout << "������� ������ �����: ";
                    cin >> a;
                    if (cin.fail()) {
                        cerr << "������������ ����. ���������� �����." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue; // ������� � ��������� �������� �����
                    }

                    cout << "������� ������ �����: ";
                    cin >> b;
                    if (cin.fail()) {
                        cerr << "������������ ����. ���������� �����." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue; // ������� � ��������� �������� �����
                    }

                    // ����� ������� �� map �� �����:
                    double result = operations[operation](a, b);
                    cout << "���������: " << result << endl;
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
            cout << "�������� ���� ��������." << endl;
        }
    }

    return 0;
}