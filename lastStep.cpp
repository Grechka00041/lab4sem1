#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
using namespace std;
unsigned my_StrLen(char* S) {
    unsigned L = 0;
    while (S[L])
        ++L;
    return L;
}
void myStrCat(char* S1, char* S2)

{
    unsigned j = my_StrLen(S1);
    for (unsigned i = 0; S2[i]; ++i, ++j)
        S1[j] = S2[i];
    S1[++j] = '\0';

}
void findSymbol(char symbol, char* arr, int* index, int length) {
    for (char* start = arr; arr + length - 2; start++) {
            if (*start == symbol)
                *(index + *start) = 1;           
    }
}
int main() {
    const int N = 550;
    char Str[N];
    char output[N];
    cin.getline(Str, N, '.');
    cin.sync();
    
    int place = 0;
    char c;
    for (char c : Str)
        bool flag = false;
        if (c == ' ' && !flag) {
            output[place] = c;
            flag = True;
        }
        else if (c == ' ' && flag)




    return 0;
}

