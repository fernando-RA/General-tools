
#include "estruturas.h"
#include "headers.h"

/*
 * Structures Definitions
 *  Here whe define the structures that will be used
 *  */
 struct no{
   struct no* left;  //Node a esquerda da arvore
   struct no* right; //Node a direita da arvore
   void* info;       //Informacao armazenada no no, tipo void permite quaisquer outros tipos
   int lineNumber;
 };

 struct city{

   char* stateUF;
   char* cityName;
   int surgeonAmount;
   int totalQuantity;
   int* unusedInfo;
 };

 struct $${

   int EPAO; //Entidade Prestadora De Assistencia Odontologica
   int TPD; //Quantide de Técnicos em Prótese Dentária
   int LB;   //Quantidade de Laboratorio De Protese Dentaria
   int TSB;  //Quantide de Técnicos em Saúde Bucal
   int ASB;  //Quantide de Auxiliares em Saúde Bucal
   int APD;  //Quantide de Auxiliares de Próteses Dentárias
   int EPO;  //Quantide de Empresa De Produtos Odontologicos

 };
 //TODO Make unusedInfo an array , test stucts and go on on BInary tree
 
 /****
 * Structure creators
 * here whe initialize each structure with zero and null pointers;
 * Or whe create a new structure using input data
 ****/
City* initializeCity(){
  City* toReturn = (City*) malloc(sizeof(City));
  toReturn->unusedInfo = (int*) malloc(sizeof(int)*(7+1)); //initialize newUnusedInfo structure
  return toReturn;
}

City* constructorCity(char* inputUF, char* inputCityName, int inputSurgeonAmount, int inputTotal, int* arrayUnusedInfo){
  City* newCity = initializeCity();
  strcpy(newCity->stateUF, inputUF);
  strcpy(newCity->cityName, inputCityName);
  newCity->surgeonAmount = inputSurgeonAmount;
  newCity->unusedInfo = arrayUnusedInfo;
  newCity->totalQuantity = inputTotal;
  return newCity;
}

int* constructorUnusedInfo(City* relatedInfoFrom, int in_value01, int in_value02, int in_value03, int in_value04, int in_value05, int in_value06, int in_value07){
  int* toReturn = relatedInfoFrom->unusedInfo;

  toReturn[1] = in_value01;
  toReturn[2] = in_value02;
  toReturn[3] = in_value03;
  toReturn[4] = in_value04;
  toReturn[5] = in_value05;
  toReturn[6] = in_value06;
  toReturn[7] = in_value07;

  return toReturn;
}
