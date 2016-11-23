#include "header.h"

typedef struct treeMun{
	struct treeMun *left;
	char municipio[45];
	int linha;
	struct treeMun *right;
}TreeMun;

typedef struct treeCD{
	struct treeCD *left;
	int cd;
	int linha;
	struct treeCD *right;
}TreeCD;

typedef struct treeTotal{
	struct treeTotal *left;
	int total;
	int linha;
	struct treeTotal *right;
}TreeTotal;

typedef struct treeUF{
	struct treeUF *left;
	int linha;
	int total;
	struct treeUF *right;
}TreeUF;
