#include "b_tree.h"
#incldude <stdio.h>
short search(char key, FILE *f){
	Node no;
	FILE *log;
	log = fopen("logbusca.txt","w");

	fseek(f,sizeof(Node),SEEK_SET);
	fread(&no,sizeof(Node),1,f);
	
		
	for(int i = 1; i < no.n_keys+3; i++){
		for(int j = 0; j < no.n_keys && key >= no.keys[j].chave; j++){
			if(key == no.keys[j].chave){
				printf("Chave %c encontrada!\n",no.keys[j].chave);
				fclose(log);
				return 1;
			}
			fprintf(log,"LOG: chave verificada %c\n",no.keys[j].chave);
			fprintf(log,"LOG: raiz: %c\n",no.keys[0].chave);
			fprintf(log,"LOG: filho 1: %d\n",no.children[0]);
			fprintf(log,"LOG: filho 2: %d\n",no.children[1]);
			fprintf(log,"LOG: filho 3: %d\n",no.children[2]);
			fprintf(log,"LOG: filho 4: %d\n",no.children[3]);
			fprintf(log,"LOG: numero de chaves: %d\n",no.n_keys);
			fprintf(log,"LOG: verifica folha: %d\n",no.leaf);
			fprintf(log,"LOG: verifica pai: %d\n\n",no.father);
		}
		fseek(f,(i+1)*sizeof(Node),SEEK_SET);
		fread(&no,sizeof(Node),1,f);
	}
	fclose(log);
	return 0;
}

Node* remover(char key, FILE *f){
return key;
}
/*

short insert(char key, FILE *f){
	Node* no = getRoot(f);
	if(no->n_keys != 2*T-1){
		return insert_non_full(no,key);
	}else{
		Node* nodo = (Node *)malloc(sizeof(Node));
		setRoot(nodo);
		nodo->leaf = 0;
		nodo->n_keys = 0;
		nodo->children[0] = no;
		split_child(nodo,1,no);
		insert_non_full(nodo,key);
	}
}


short insert(char key, FILE *f){
	Node no;
	int aux, cont = 1;

	FILE* log = fopen("loginsercao.txt","w");
	fseek(f,sizeof(Node),SEEK_SET);
	fread(&no,sizeof(Node),1,f);
	fprintf(log,"LOG: chave verificada %c\n",no.keys[0].chave);
	fprintf(log,"LOG: raiz: %c\n",no.keys[0].chave);
	fprintf(log,"LOG: filho 1: %d\n",no.children[0]);
	fprintf(log,"LOG: filho 2: %d\n",no.children[1]);
	fprintf(log,"LOG: filho 3: %d\n",no.children[2]);
	fprintf(log,"LOG: filho 4: %d\n",no.children[3]);
	fprintf(log,"LOG: numero de chaves: %d\n",no.n_keys);
	fprintf(log,"LOG: verifica folha: %d\n",no.leaf);
	fprintf(log,"LOG: verifica pai: %d\n\n",no.father);
	while(no.leaf == 1){
		printf("entrou while\n");
		for(int j = 0; j < no.n_keys && key > no.keys[j].chave;j++){
			aux = j;
			printf("aux:%d\n",aux);
			printf("chave: %c\n",no.keys[aux].chave);
		}

		cont++;
		getchar();
		//printf("cont= %d\n",cont);
		fseek(f,(cont)*sizeof(Node),SEEK_SET);
		fread(&no,sizeof(Node),1,f);
	}
	if(no.n_keys <= 2*T-1){
		no.keys[aux].chave = key;
		return no.keys[aux].chave;
	}
	return -1;	
}
*/


Node* getRoot(FILE* f){
	Node* no = (Node *)malloc(sizeof(Node));
	fseek(f,sizeof(Node),SEEK_SET);
	fread(no,sizeof(Node),1,f);
	if(no->father == 0)return no;
	else return NULL;
}
