#include<stdio.h>
#include<stdlib.h>

#define NIL NULL

typedef struct kr {
	int w1, w2, waga, roz;
} krawedz ;

typedef struct W {
	int key, length;
	struct W *head, *next, *last;
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

int compare (const void * a, const void * b){
  return ( ((krawedz*)a)->waga - ((krawedz*)b)->waga );
}

krawedz *kruskal(krawedz *x, int lk, int lw){
	int i;
	wezel *W[lw+1], *pom;
	for(i=1;i<=lw;i++){
		W[i]=MakeSet(i);
	}
	printf("lk= %d \n", lk);
	for(i=0;i<lk;i++){
		if(FindSet(W[x[i].w1]) != FindSet(W[x[i].w2]) ){
			printf("warunek wszedl przy krawedzi %d-%d \n", x[i].w1, x[i].w2);
			x[i].roz=1;
			Union((W[x[i].w1]), (W[x[i].w2]));
		}
	}
	for(i=0;i<lk;i++){
		printf("krawedz o wadze %d jest %d \n", x[i].waga, x[i].roz);
	}
	return x;
}
void wyswietl(krawedz *x, int lk, int lw){
	int i;
	printf("graph G {\n");
	for(i=1;i<lw+1;i++){
		printf("%d [style=filled, fillcolor=gray]\n", i);
	}
	for(i=0;i<lk;i++){
		if(x[i].roz==1)
			printf("%d -- %d [label=%d]\n", x[i].w1, x[i].w2, x[i].waga);
		}
	printf("}\n");
}
int main(){
	int i, lw, lk, w1, w2, waga;
	krawedz *x;
	scanf("%d %d", &lw, &lk);
	x = malloc(sizeof(krawedz)*lk);
	for(i=0;i<lk;i++){
		scanf("%d %d %d", &w1, &w2, &waga);
		x[i].w1=w1;
		x[i].w2=w2;
		x[i].waga=waga;
		x[i].roz=0;
	}
	qsort(x, lk , sizeof(krawedz), compare);
	/*for(i=0;i<lk;i++){
		printf("w1=%d, w2=%d, waga=%d \n", x[i].w1, x[i].w2, x[i].waga);
	}*/
	x=kruskal(x,lk,lw);
	wyswietl(x,lk,lw);
	return 0;
}
