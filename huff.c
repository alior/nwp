#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct W {
	int key,symbol;
	struct W *left, *right;
	//int left, right;
} wezel;

void show(wezel *z, int pom){
	int i;
	printf("sym: %d wart: %d -> ", z->symbol,z->key);
	for(i=0;i<2*pom-1;i++){
		printf("sym: %d wart: %d -> ", z->left->symbol,z->left->key);
	}

}
wezel *findmin(wezel *TAB[], int pom){
	int i,x=2147483647;
	wezel *szukany;
	for(i=0;i<pom*2-1;i++){
		//printf("\nSUPER 2\n;");
		if(TAB[i]->key < x && TAB[i]->key > 0)
			x=i;
	}
	szukany=TAB[x];
	return szukany;
}

void huffman(wezel *TAB[], int pom){
	int i;
	wezel *z, *x, *y;
	for(i=1;i<pom-1;i++){
		//printf("\nSUPER 1\n;");
		z=malloc(sizeof(wezel));
		x=findmin(TAB,pom);
		//printf("\nSUPER 3\n;");
		z->left=x;
		y=findmin(TAB,pom);
		z->right=y;
		z->key=x->key+y->key;
		z->symbol=-2;
		TAB[i+pom]=z;
	}
	for(i=0;i<pom*2-1;i++){
			printf("sym:%c, key:%d || ",TAB[i]->symbol, TAB[i]->key);
		}
	//show(z,pom);
}

int main(int argc, char **argv){
	int A[256],i,dlugosc,pom=0,j=0;
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
	printf ("Rozmiar pliku: %d\n", dlugosc);
	fseek(fp,0,0);
	for(i=0;i<dlugosc;i++){
		fscanf(fp, "%c", &x);
		A[x]++;
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
			TAB[j]=z;
			j++;
		}
	}
	/*for(i=0;i<pom*2-1;i++){
		printf("sym:%c, key:%d || ",TAB[i]->symbol, TAB[i]->key);
	}*/
	huffman(TAB,pom);
	fclose (fp);
	return 0;
}
