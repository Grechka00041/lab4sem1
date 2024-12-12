#pragma once

#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include <string.h>
#define numberOfUniqueSymbols 256
using namespace std;

int checkInputString(int floor = (numeric_limits<int>::min)(), int ceiling = (numeric_limits<int>::max)());
unsigned int my_StrLen(char* String);
void del(char* arr, int length, int index);
void deleteExtraSpaces(char* txt);
void deleteExtraPunctuation(char* txt);
void correctLetterCase(char* txt);
void mainMenuString();
int linearSearch(char* txt, char word[], int textLength, int wordLength);
int BoyerMoore(char* txt, char* subsequence, int lenTxt, int lenSub);
int print(int i);
void prefix(char* pattern, int* patternIndex, int length);
void KMP(char* txt, char* pattern, int* patternIndex, int length, int f(int));