#include <stdio.h>
#include <stdlib.h>
#include "b_tree.h"

char* storeFile(Node* no, Node* n1, Node*n2);


int main(){
	char caractere, inserir;
	Node b1, b2, b3;
	b1.leaf = 0;
	b1.n_keys = 1;
	b1.keys[0].chave = 'd';
	b1.children[0] = 1;
	b1.children[1] = 2;
	b1.children[2] = 0;
	b1.children[3] = 0;
	b1.father = 0;

	b2.leaf = 1;
	b2.n_keys = 3;
	b2.keys[0].chave = 'a';
	b2.keys[1].chave = 'b';
	b2.keys[2].chave = 'c';
	b2.children[0] = 0;
	b2.children[1] = 0;
	b2.children[2] = 0;
	b2.children[3] = 0;
	b2.father = 1;

	b3.leaf = 1;
	b3.n_keys = 3;
	b3.keys[0].chave = 'e';
	b3.keys[1].chave = 'f';
	b3.keys[2].chave = 'g';
	b3.children[0] = 0;
	b3.children[1] = 0;
	b3.children[2] = 0;
	b3.children[3] = 0;
	b3.father = 1;

	storeFile(&b1,&b2,&b3);

	printf("Digite o que deseja buscar: ");
	scanf("%c",&caractere);
	FILE* fp = fopen("arq1.dat","rb");
	if(search(caractere,fp))
		printf("Achou!\n");
	else printf("Nao Achou!\n");
	printf("Digite o que deseja inserir: ");
	scanf("%c",&inserir);
	fclose(fp);
	fp = fopen("arq1.dat","rb");
	if(inserir == insert(inserir,fp) == 1)printf("Inserido com sucesso!\n");
	else printf("Erro na insercao!\n");
	return 0;
}

char* storeFile(Node* no1, Node* no2, Node* no3){
	static char name[] = "arq1.dat";
	long gravado;
	FILE* fp = fopen(name,"wb");
	// Node *no[3];
	// no[0] = no1;
	// no[1] = no2;
	// no[2] = no3;
	fseek(fp,sizeof(Node),SEEK_SET);
	gravado  = fwrite(no1,sizeof(Node),1,fp);
	gravado += fwrite(no2,sizeof(Node),1,fp);
	gravado += fwrite(no3,sizeof(Node),1,fp);
	//long gravado = fwrite(no[0],3*sizeof(Node),3,fp);
	printf("Elementos gravados: %li elementos\n",gravado);
	fclose(fp);
	return name;
}
