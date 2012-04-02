#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LCSLENGTH(char X[], char Y[]){
	int m=strlen(X), n=strlen(Y), i, j, c[m][n], b[m][n];
	printf("m=%d n=%d", m, n);
	for (i=1;i<m;i++)
		c[i][0]=0;
	for (j=0;j<n;j++)
		c[0][j]=0;
	for (i=1;i<m;i++){
		for(j=1;j<n;j++){
			if(X[i]==Y[j]){
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=0;
			}
			else
				if(c[i-1][j]>=c[i][j-1]){
					c[i][j]=c[i-1][j];
					b[i][j]=1;
				}
				else{
					c[i][j]=c[i][j-1];
					b[i][j]=2;
				}
		}
	}
	printf("dlugosc nwp: %d ", c[m][n]);
	for(j=1;j<m;j++){
		for(i=1;i<n;i++){
			printf("%d",b[j][i]);
		}
		printf("\n");
	}
}

int main(){

	char X[10], Y[10];
	int i=0;
	for(i=0; i<20;i++){
		X[i]=-1;
		Y[i]=-1;
	}
	printf("Dawaj ciagi \n");
	scanf("%s", X);
	scanf("%s", Y);
	LCSLENGTH(X,Y);
//	for(i=0;X[i]!=0;i++){
//		printf("%c",X[i]);
//	}
//	printf("\n");
//	for(i=0;Y[i]!=0;i++){
//			printf("%c",Y[i]);
//		}
	return 0;

}
