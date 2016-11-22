#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"

#ifndef FOO_H_INCLUDED
#define FOO_H_INCLUDED

void printNavbar(char* navbarTitle);
void clearScreen();

void printInitialMenu();
void printImportDataMenu();
void printReportOrdenedMenu();

City* initializeCity();
City* constructorCity(char* inputUF, char* inputCityName, int inputSurgeonAmount, int inputTotal, int* otherInfosCreatedBefore);
Info* constructorOtherInfos(City* relatedInfoFrom, int in_value01, int in_value02, int in_value03, int in_value04, int in_value05, int in_value06, int in_value07);
int importDataFromFile(char* fileName);

#endif
