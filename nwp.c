#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LCSLENGTH(char X[], char Y[]){

}
int main(){

	char X[20], Y[20];
	int i=0;
	for(i=0; i<20;i++){
		X[i]=0;
		Y[i]=0;
	}
	printf("Dawaj ciagi \n");
	scanf("%s", X);
	scanf("%s", Y);
	printf("%d",strlen(X));
	printf("%d",strlen(Y));
//	for(i=0;X[i]!=0;i++){
//		printf("%c",X[i]);
//	}
//	printf("\n");
//	for(i=0;Y[i]!=0;i++){
//			printf("%c",Y[i]);
//		}
	return 0;

}
