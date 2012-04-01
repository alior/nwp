#include <stdio.h>
#include <stdlib.h>

int main(){

	char znak, X[20], Y[20];
	int i=0,k;
	printf("Dawaj ciagi \n");
	while(znak!=' '){
		scanf("%c", &znak);
		X[i]=znak;
		i++;
	}
	k=i;
	i=0;
	while(znak!=' '){
			scanf("%c", &znak);
			Y[i]=znak;
			i++;
		}
	for(i=0;i<k;i++){
		printf("%c",X[i]);
	}
	for(i=0;i<k;i++){
			printf("%c",Y[i]);
		}

	//scanf("%d", &i);
	//return 0;

}
