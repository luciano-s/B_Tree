#ifndef B_TREE_H
#define B_TREE_H
#define T 3
#define pula_linha printf("\n")
#include <stdlib.h>
#include <stdio.h>
typedef struct key{
	char chave;
}Key;

typedef struct node{
	Key keys[2*T-1];
	int children[2*T];
	int n_keys;
	short leaf;
	int father;
}Node;

typedef struct{
	int root;
}BTree;

short search(char key, FILE *f);
Node* remover(char key, FILE *f);
short insert(char key, FILE *f);

#endif