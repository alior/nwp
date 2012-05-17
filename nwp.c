#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PRINTLCS(int b[][100], char X[], int i, int j) {
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == 1) {
		PRINTLCS(b, X, i - 1, j - 1);
		printf("%c", X[i-1]);
	} else if (b[i][j] == 2)
		PRINTLCS(b, X, i - 1, j);
	else
		PRINTLCS(b, X, i, j - 1);
}

void LCSLENGTH(char X[], char Y[]) {
	int m = strlen(X), n = strlen(Y), i, j, c[100][100], b[100][100];
	for (i = 1; i <= m; i++)
		c[i][0] = 0;
	for (j = 0; j <= n; j++)
		c[0][j] = 0;
	for (i = 0; i <= m; i++) {
		for (j = 0; j <= n; j++) {
			if (X[i] == Y[j]) {
				c[i + 1][j + 1] = c[i][j] + 1;
				b[i + 1][j + 1] = 1;
			} else if (c[i][j + 1] >= c[i + 1][j]) {
				c[i + 1][j + 1] = c[i][j + 1];
				b[i + 1][j + 1] = 2;
			} else {
				c[i + 1][j + 1] = c[i + 1][j];
				b[i + 1][j + 1] = 3;
			}
		}
	}
	printf("dlugosc nwp: %d \n", c[m][n]);
	printf("\n");
	//showstr(c, b, m, n, X, Y);
	printf("Najdluzszy wspolny podciag to:" );
	PRINTLCS(b, X, m, n);
	printf("\n");
}
/*
void showstr(int c[][100], int b[][100], int leni, int lenj, char X[], char Y[]) {
	int i, j;
	char strzalka;

	printf("|       |       |");
	for (j = 0; j < lenj; j++) {
		printf("   %c   |", Y[j]);
	}
	printf("\n");
	for (i = 0; i <= leni; i++) {
		if (i != 0) {
			printf("|   %c   |", X[i - 1]);
		} else {
			printf("|       |");
		}
		for (j = 0; j <= lenj; j++) {
			if (b[i][j] == 1) {
				strzalka = 's';
			}
			else if (b[i][j] == 2) {
				strzalka = 'g';
			}
			else if (b[i][j] == 3) {
				strzalka = 'l';
			}
			else strzalka = ' ';
			printf(" %3d %c |", c[i][j],strzalka);
		}
		printf("\n");
	}
}
*/
int main() {

	char X[100], Y[100];
	int i = 0;
	for (i = 0; i < 100; i++) {
		X[i] = -1;
		Y[i] = -1;
	}
	printf("Dawaj ciagi \n");
	scanf("%s", X);
	scanf("%s", Y);
	LCSLENGTH(X, Y);
	getchar();
	getchar();
	return 0;

}
