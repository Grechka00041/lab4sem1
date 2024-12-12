#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "Module1.4Func.h"
#define numberOfUniqueSymbols 256
using namespace std;
int checkInputString(int floor, int ceiling) {
    int num;
    cin >> num;
    while (cin.fail() || cin.peek() != '\n' || num > ceiling || num < floor) {
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        cout << "Введите корректное значение: ";
        cin >> num;
    }
    return num;
}
unsigned int my_StrLen(char* String) {
    unsigned int Length = 0;
    while (String[Length])
        ++Length;
    return Length;
}
void del(char* arr, int length, int index) {
    for (int i = index; i < length; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[length - 1] = '\0';
}
void deleteExtraSpaces(char* txt) {
    int length = my_StrLen(txt);
    for (int i = 0; i < length; i++) {
        if (txt[i] == ' ' && txt[i + 1] == ' ')
            while (txt[i + 1] == ' ')
                del(txt, length, (i + 1));
    }
}
void deleteExtraPunctuation(char* txt) {
    int length = my_StrLen(txt);
    for (int i = 0; i <= length; i++) {
        if (ispunct(txt[i]) && ispunct(txt[i + 1]))
            if (txt[i] == '.' && txt[i + 1] == '.' && txt[i + 2] == '.' && txt[i + 3] == ' ') {
                i += 3;
            }
            else {
                while (ispunct(txt[i + 1]))
                    del(txt, length, (i + 1));
            }
    }
}
void correctLetterCase(char* txt) {
    for (int i = 0; i < my_StrLen(txt); i++) {
        if (isalpha(txt[i]) && (i == 0 || txt[i - 1] == ' ')) {
            txt[i] = toupper(txt[i]);
        }
        else {
            txt[i] = tolower(txt[i]);
        }
    }
}
void mainMenuString() {
    system("cls");
    cout << "Выберите действие: " << endl;
    cout << "1. Ввести последовательность с клавиатруры" << endl;
    cout << "2. Ввести последовательность из файла" << endl;
    cout << "3. Удалить лишние пробелы" << endl;
    cout << "4. Удалить лишние знаки препинания" << endl;
    cout << "5. Исправить регистр букв" << endl;
    cout << "6. Вывести на экран слова последовательности в обратном порядке" << endl;
    cout << "7. Вывести все слова исходной последовательности на экран вертикально" << endl;
    cout << "8. Линейный поиск подстроки" << endl;
    cout << "9. Поиск подстроки, алгоритм Бойера-Мура" << endl;
    cout << "10. Поиск подстроки, алгоритм Кнутта-Морисса-Пратта" << endl;
    cout << "11. Выход" << endl;
    cout << "Введите число, соответствующее нужному вам действию: ";
}
int linearSearch(char* txt, char word[], int textLength, int wordLength) {
    for (int i = 0; i <= textLength - wordLength; ++i) {
        int j;
        for (j = 0; j <= wordLength; ++j)
            if (txt[i + j] != word[j])
                break;
        if (j == wordLength)
            return i;
    }
    return -1;
}
int BoyerMoore(char* txt, char* subsequence, int lenTxt, int lenSub) {
    int table[numberOfUniqueSymbols];
    int step = 0;
    for (int i = 0; i < numberOfUniqueSymbols; i++)
        table[i] = -1;
    for (int i = 0; i <= numberOfUniqueSymbols - 1; i++)
        table[subsequence[i]] = i;
    while (step <= (lenTxt - lenSub))
    {
        int j = lenSub - 1;
        while (j >= 0 && subsequence[j] == txt[step + j])
            j--;

        if (j < 0)
        {
            return step;
            step += (step + lenSub < lenTxt) ? lenSub - subsequence[txt[step + lenSub]] : -1;
        }
        else
        {
            step += max(1, j - table[txt[step + j]]);
        }
    }
}
int print(int i) {
    cout << i << " ";
    return 1;
}
void prefix(char* pattern, int* patternIndex, int length) {
    patternIndex[0] = 0;
    for (int i = 1; i < length; ++i)
    {
        int j = patternIndex[i - 1];
        while ((j > 0) && (pattern[i] != pattern[j]))
            j = patternIndex[j - 1];
        if (pattern[i] == pattern[j])
            ++j;
        patternIndex[i] = j;
    }
}
void KMP(char* txt, char* pattern, int* patternIndex, int length, int f(int)) {
    patternIndex[0] = 0;
    int l = 0;
    for (l = 1; l < length; ++l)
    {
        int j = patternIndex[l - 1];
        while ((j > 0) && (pattern[l] != pattern[j]))
            j = patternIndex[j - 1];
        if (pattern[l] == pattern[j])
            ++j;
        patternIndex[l] = j;
    }
    int j = 0;
    for (int i = 0; txt[i]; ++i)
    {
        while ((j > 0) && (txt[i] != pattern[j]))
            j = patternIndex[j - 1];

        if (txt[i] == pattern[j])
            ++j;
        if (j == l)
            if (!print(i - l + 1))
                return;
    }
}