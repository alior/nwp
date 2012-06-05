#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct W {
	int key,symbol, bracpoduwage;
	struct W *left, *right;
} wezel;

void wyswietl(wezel* root) {
	if (root!=NULL) {
		//printf("%d ",root->key);
		if(root->symbol>0)   // jaki kolor
			printf("%c [label=\"%c:%d\", shape=rect, style=filled]\n",root->symbol,  root->symbol, root->key);
		else
			printf("%d [style=filled]\n", root->key);
		if (root->left!=NULL || root->right!=NULL) {
			if (root->left!=NULL && root->left->symbol>0) {
				printf("%d->%c [label=0];",root->key, root->left->symbol);
			}
			if (root->left!=NULL && root->left->symbol<0) {
				printf("%d->%d [label=0];",root->key, root->left->key);
			}

			if (root->right!=NULL && root->right->symbol>0) {
				printf("%d->%c [label=1];",root->key, root->right->symbol);
			}
			if (root->right!=NULL && root->right->symbol<0) {
				printf("%d->%d [label=1];",root->key,root->right->key);
			}

			printf("\n");
			if (root->left!=NULL ) {
				wyswietl(root->left);
			}
			if (root->right!=NULL ) {
				wyswietl(root->right);
			}
		}
	}
}

void show(wezel *z, int pom){
	int i;
	printf("sym: %d wart: %d -> ", z->symbol,z->key);
	for(i=0;i<2*pom-1;i++){
		printf("sym: %d wart: %d -> ", z->left->symbol,z->left->key);
	}

}
wezel *findmin(wezel *TAB[], int pom){
	int i,x=2147483647,y;
	for(i=0;i<pom*2-1;i++){
		if(TAB[i]->key<x &&  TAB[i]->bracpoduwage == 1){
			x=TAB[i]->key;
			y=i;
		}
	}
	TAB[y]->bracpoduwage=0;
	return TAB[y];
}

void huffman(wezel *TAB[], int pom){
	int i;
	wezel *z, *x, *y;
	for(i=0;i<pom-1;i++){
		z=malloc(sizeof(wezel));
		x=findmin(TAB,pom);
		z->left=x;
		y=findmin(TAB,pom);
		z->right=y;
		z->key=x->key+y->key;
		z->bracpoduwage=1;
		z->symbol=-2;
		TAB[i+pom]=z;
	}

	printf("digraph G {\n");
	wyswietl(z);
	printf("}\n");
}

int main(int argc, char **argv){
	int A[256],i,pom=0,j=0,dlugosc;
	char x;
	wezel *wypelniacz;
	FILE *fp;
	for(i=0;i<256;i++){
		A[i]=0;
	}
	fp = fopen(argv[1], "rb");
	if( fp == NULL ){
		perror("Blad otwarcia pliku");
		exit(-10);
	}
	fseek (fp, 0, SEEK_END);
	fgetpos (fp, &dlugosc);
	fseek(fp,0,0);
	for(i=0;i<dlugosc;i++){
		fscanf(fp, "%c", &x);
		A[(int)x]++;
	}
	for(i=0;i<256;i++){
		if(A[i]!=0)
			pom++;
	}
	wezel *TAB[pom*2-1];
	wypelniacz=malloc(sizeof(wezel));
	wypelniacz->symbol=0;
	wypelniacz->key=0;
	wypelniacz->left=NULL;
	wypelniacz->right=NULL;
	wypelniacz->bracpoduwage=0;
	for(i=0;i<pom*2;i++){
		TAB[i]=wypelniacz;
	}
	for(i=0;i<256;i++){
		if(A[i]!=0){
			wezel *z=malloc(sizeof(wezel));
			z->key=A[i];
			z->symbol=i;
			z->left=NULL;
			z->right=NULL;
			z->bracpoduwage=1;
			TAB[j]=z;
			j++;
		}
	}
	huffman(TAB,pom);
	fclose (fp);
	return 0;
}
