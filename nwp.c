#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char znak, X[20], Y[20];
	int i=0,k;
	printf("Dawaj ciagi \n");
	scanf("%s", X);
	scanf("%s", Y);
	k=i;
//	while(i<20){
//			scanf("%c", &znak);
//			Y[i]=znak;
//			i++;
//		}
	for(i=0;i<5;i++){
		printf("%c",X[i]);
	}
	for(i=0;i<5;i++){
			printf("%c",Y[i]);
		}
	return 0;

}
