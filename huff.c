#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct W {
	int key;
	struct W *left, *right, *p;
} wezel;

void huffman(int A[]){


}

int main(int argc, char **argv){
	int A[256],i;
	char x;
	FILE *fp;
	int dlugosc;
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
		printf("%d ",x);
		A[x]++;
	}
	printf("\nliczba A: %d, B: %d, D: %d", A['A'],A['B'],A['D']);

	fclose (fp);
	return 0;
}
