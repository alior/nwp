#include<stdio.h>
#include<stdlib.h>

typedef struct W {
		int key, length;
		struct W *head, *next, *last;
		int kolor;
	} wezel;

int main(){
	return 0;
}

wezel* MakeSet(int k){
	wezel *x;
	x = malloc(sizeof(wezel));
	x->key=k;
	x->head=x;
	x->last=x;
	x->next=x;
	x->length=1;
	return x;
}

wezel* FindSet(wezel *x){
	return x->head;
}

void Union(wezel *x, wezel *y){
	if(y->length > x->length){

	}
}
