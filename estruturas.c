typedef struct no{
  struct no* left;  //Node a esquerda da arvore
  struct no* right; //Node a direita da arvore
  void* info;       //Informacao armazenada no no, tipo void permite quaisquer outros tipos
  int lineNumber;
} No;


typedef struct city{

  char* stateUF;
  char* cityName;
  int surgeonAmount;
  
  int EPAO;     //Entidade Prestadora De Assistencia Odontologica
  int TPD;      //Quantide de Técnicos em Prótese Dentária
  int LB;       //Quantidade de Laboratorio De Protese Dentaria
  int TSB;      //Quantide de Técnicos em Saúde Bucal
  int ASB;      //Quantide de Auxiliares em Saúde Bucal
  int APD;      //Quantide de Auxiliares de Próteses Dentárias
  int EPO;      //Quantide de Empresa De Produtos Odontologicos
    
  int totalQuantity; 
  
}cityInfo;

