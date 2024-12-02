#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;
int checkInput(int floor = (numeric_limits<int>::min)(), int ceiling = (numeric_limits<int>::max)()) {
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
unsigned int my_StrLen(char* String){
    unsigned int Length = 0;
    while (String[Length])
        ++Length;
    return Length;
}
void del(char* arr, int length, int index){
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
void mainMenu() {
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
    cout << "9. Поиск подстроки, алгоритм КМП" << endl;
    cout << "10. Поиск подстроки, алгоритм Бойера-Мура" << endl;
    cout << "11. Выход" << endl;
    cout << "Введите число, соответствующее нужному вам действию: ";
}
int linearSearch(char* txt, char* word) {
    int textLength = my_StrLen(txt);
    int wordLength = my_StrLen(word);
    for (int i = 0; i <= textLength - wordLength; i++) {
        int j;
        for (j = 0; j < wordLength; j++) {
            if (txt[i + j] != word[j])
                break;
        }
        if (j == wordLength)
            return i;
    }
    return -1;
    }
int main(){
    setlocale(LC_ALL, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int N = 550;
    char Str[N];
    int choice;
    do {
        mainMenu();
        choice = checkInput(1, 11);
        switch (choice) {
        case 1: {
            system("cls");
            cout << "Введите последовательность с клавиатуры: ";
            cin.getline(Str, N, '.');
            cin.sync();
            int StrLength = my_StrLen(Str);
            break;
        }
        case 2: {
            system("cls");
            cout << "Введите последовательность из файла: ";
            ifstream i_File;  
            i_File.open("C:\\sentense.txt", ios::binary);  
            if (!i_File.is_open()) 
            {
                cout << "Открыть файл не удалось! \n";
                return -1;
            }
            i_File.read((char*)Str, sizeof(Str)); 
            i_File.close(); 

            for (int i = 0; i < my_StrLen(Str); ++i) // временно выводим для проверки работы кода
                cout << Str[i];
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
            cin.sync();
            int result = linearSearch(Str, word);
            if (result == -1)
                cout << "Подстрока не найдена" << endl;
            else
                cout << "Подстрока найдена в позиции: " << result << endl;
            break;
        }
        case 9: {
            system("cls");
            break;
        }
        case 10: {}
            system("cls");
            break;
        }
        if (choice != 11)
            system("pause");
    } while (choice != 11);
}



