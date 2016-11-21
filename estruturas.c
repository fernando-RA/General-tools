
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
   Info* unusedInfo;
   int totalQuantity;

 };

 struct unusedInfo{

   int EPAO; //Entidade Prestadora De Assistencia Odontologica
   int TPD; //Quantide de Técnicos em Prótese Dentária
   int LB;   //Quantidade de Laboratorio De Protese Dentaria
   int TSB;  //Quantide de Técnicos em Saúde Bucal
   int ASB;  //Quantide de Auxiliares em Saúde Bucal
   int APD;  //Quantide de Auxiliares de Próteses Dentárias
   int EPO;  //Quantide de Empresa De Produtos Odontologicos

 };

 /****
 * Structure creators
 * here whe initialize each structure with zero and null pointers;
 * Or whe create a new structure using input data
 ****/

City* initializeCity(){
  City* toReturn = (City*) malloc(sizeof(City));
  toReturn->unusedInfo = (Info*) malloc(sizeof(Info)); //initialize newUnusedInfo structure
  return toReturn;
}

City* constructorCity(char* inputUF, char* inputCityName, int inputSurgeonAmount, int inputTotal, Info* otherInfosCreatedBefore){
  City* newCity = initializeCity();
  strcpy(newCity->stateUF, inputUF);
  strcpy(newCity->cityName, inputCityName);
  newCity->surgeonAmount = inputSurgeonAmount;
  newCity->unusedInfo = otherInfosCreatedBefore;
  newCity->totalQuantity = inputTotal;
  return newCity;
}

Info* constructorOtherInfos(City* relatedInfoFrom, int in_value01, int in_value02, int in_value03, int in_value04, int in_value05, int in_value06, int in_value07){
  Info* toReturn = relatedInfoFrom->unusedInfo;

  toReturn->EPAO = in_value01;
  toReturn->TPD = in_value02;
  toReturn->LB = in_value03;
  toReturn->TSB = in_value04;
  toReturn->ASB = in_value05;
  toReturn->APD = in_value06;
  toReturn->EPO = in_value07;

  return toReturn;
}
