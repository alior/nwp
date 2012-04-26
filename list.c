#include<stdio.h>
#include<stdlib.h>

#define NIL NULL

typedef struct W {
		int key, length;
		struct W *head, *next, *last;
		int kolor;
	} wezel;

wezel* MakeSet(int k){
	wezel *x;
	x = malloc(sizeof(wezel));
	x->key=k;
	x->head=x;
	x->last=x;
	x->next=NIL;
	x->length=1;
	return x;
}

wezel* FindSet(wezel *x){
	return x->head;
}

void Union(wezel *x, wezel *y){
	wezel *pom;
	if(y->length > x->length){
		pom=x;
		x=y;
		y=pom;
	}
	x->length = x->length + y->length;
	x->last->next=y;
	x->last=y->last;
	while(y!=NIL){
		y->head=x;
		y=y->next;
	}
}

int main(){
	wezel *W[11], *pom;
	int i;
	for(i=0;i<11;i++){
		W[i]=MakeSet(i);
	}
	Union(FindSet(W[0]),FindSet(W[2]));
	Union(FindSet(W[1]),FindSet(W[2]));
	Union(FindSet(W[3]),FindSet(W[4]));
	Union(FindSet(W[5]),FindSet(W[6]));
	Union(FindSet(W[7]),FindSet(W[8]));
	Union(FindSet(W[9]),FindSet(W[10]));
	Union(FindSet(W[1]),FindSet(W[4]));
	Union(FindSet(W[9]),FindSet(W[3]));
	Union(FindSet(W[8]),FindSet(W[1]));
	pom=FindSet(W[2]);
	for(i=0;pom!=NULL;i++){
			printf("%d->",pom->key);
			pom=pom->next;
	}
	printf("\nreprezentantem zbioru jest: %d \n", FindSet(W[7])->key);
	printf("ostatnim elementem zbioru jest: %d \n", FindSet(W[5])->last->key);
	return 0;
}

