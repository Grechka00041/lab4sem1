#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include "Module1.4Func.h"
#define numberOfUniqueSymbols 256
using namespace std;

int strings() {
    setlocale(LC_ALL, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int N = 550;
    char Str[N] = { ' ' };
    int choice;
    do {
        mainMenuString();
        choice = checkInputString(1, 11);
        switch (choice) {
        case 1: {
            system("cls");
            cout << "Введите последовательность с клавиатуры: ";
            cin.getline(Str, N, '.');
            del(Str, my_StrLen(Str), 0);
            cin.sync();
            int StrLength = my_StrLen(Str);
            break;
        }
        case 2: {
            system("cls");
            cout << "Введенная вами из файла строка: ";
            const char* filePath = "C:/test/hmm.txt";
            ifstream file(filePath, ios::in);
            if (!file.is_open()) {
                cout << "Открыть файл не удалось! \n";
                return -1;
            }
            file.read((char*)Str, sizeof(Str));
            file.close();

            for (int i = 0; i < my_StrLen(Str); ++i)
                cout << Str[i];
            cout << endl;
            break;
        }
        case 3: {
            system("cls");
            deleteExtraSpaces(Str);
            int StrLength = my_StrLen(Str);
            cout << "Отредактированная строка: ";
            for (int i = 0; i <= StrLength; i++) {
                cout << Str[i];
            }
            cout << endl;
            break;
        }
        case 4: {
            system("cls");
            int StrLength = my_StrLen(Str);
            deleteExtraPunctuation(Str);
            cout << "Отредактированная строка: ";
            for (int i = 0; i <= StrLength; i++) {
                cout << Str[i];
            }
            cout << endl;
            break;
        }
        case 5: {
            system("cls");
            int StrLength = my_StrLen(Str);
            correctLetterCase(Str);
            cout << "Отредактированная строка: ";
            for (int i = 0; i <= StrLength; i++) {
                cout << Str[i];
            }
            cout << endl;
            break;
        }
        case 6: {
            system("cls");
            int a = 0;
            int length = my_StrLen(Str);
            for (int i = length; i >= 0; i--) {
                if (Str[i] == ' ') {
                    for (int k = i + 1; k <= (i + a); k++) {
                        cout << Str[k];
                    }
                    a = 0;
                    cout << " ";
                }
                a++;
            }
            for (int i = 0; i < length; i++) {
                if (Str[i] == ' ') break;
                cout << Str[i];
            }
            break;
        }
        case 7: {
            system("cls");
            for (int i = 0; i <= my_StrLen(Str); i++) {
                if (Str[i] == ' ')
                    cout << '\n';
                else
                    cout << Str[i];
            }
            break;
        }
        case 8: {
            system("cls");
            const int size = 50;
            char word[N];
            cout << "Введите подпоследовательность, которую хотите найти: ";
            cin.clear();
            cin.getline(word, size, '.');
            del(word, my_StrLen(word), 0);
            cin.sync();
            int textLength = my_StrLen(Str);
            int wordLength = my_StrLen(word);
            int result = linearSearch(Str, word, textLength, wordLength);
            if (result == -1)
                cout << "Подпоследовательность не найдена" << endl;
            else
                cout << "Подпоследовательность найдена на позиции " << result << endl;
            cout << endl;
            break;
        }
        case 9: {
            system("cls");
            const int size = 50;
            char word[N];
            int patternIndex[N];
            cout << "Введите подпоследовательность, которую хотите найти: ";
            cin.clear();
            cin.getline(word, size, '.');
            del(word, my_StrLen(word), 0);
            cin.sync();
            int result = BoyerMoore(Str, word, my_StrLen(Str), my_StrLen(word));
            if (result == -1)
                cout << "Подпоследовательность не найдена" << endl;
            else
                cout << "Подпоследовательность найдена на позиции " << result << endl;
            cout << endl;
            break;
        }
        case 10: {
            system("cls");
            const int size = 50;
            char word[N];
            int patternIndex[N];
            cout << "Введите подпоследовательность, которую хотите найти: ";
            cin.clear();
            cin.getline(word, size, '.');
            del(word, my_StrLen(word), 0);
            cin.sync();
            cout << "Подпоследовательность найдена на позиции: ";
            KMP(Str, word, patternIndex, my_StrLen(word), print);
            cout << endl;
            break;
        }
        }
        if (choice != 11)
            system("pause");
    } while (choice != 11);
}