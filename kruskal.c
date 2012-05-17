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
	/*printf("   x length = %d  y length=%d \n", x->head->length, y->head->length);*/
	if(y->head->length > x->head->length){
		pom=x;
		x=y;
		y=pom;

	}
	x->head->length = x->head->length + y->head->length;
	y->head->length=x->length;
	x->head->last->next=y->head;
	x->head->last=y->head->last;
	y=y->head;
	while(y!=NIL){
		y->head=x->head;
		y=y->next;
	}
}

int compare (const void * a, const void * b){
	return ( ((krawedz*)a)->waga - ((krawedz*)b)->waga );
}

krawedz *kruskal(krawedz *x, int lk, int lw){
	int i;
	wezel *W[lw+1];
	for(i=1;i<=lw;i++){
		W[i]=MakeSet(i);
	}
	for(i=0;i<lk;i++){
		if(FindSet(W[x[i].w1]) != FindSet(W[x[i].w2]) ){
			/*printf("\n%d.) KRAWEDZ %d-%d o wadze %d \n", i+1, x[i].w1, x[i].w2, x[i].waga);
			printf("    ");
			for(j=1;j<=lw;j++){
				printf("%d ", FindSet(W[j])->head->key);
			}
			printf(" w1:");
			pom=FindSet(W[x[i].w1]);
			for(j=1;pom!=NIL;j++){
				printf("%d->",pom->key);
				pom=pom->next;
			}
			printf(" w2:");
			pom=FindSet(W[x[i].w2]);
			for(j=1;pom!=NIL;j++){
				printf("%d->",pom->key);
				pom=pom->next;
			}
			printf("\n");*/
			x[i].roz=1;
			Union((W[x[i].w1]), (W[x[i].w2]));
			/*printf("    ");
			for(j=1;j<=lw;j++){
				printf("%d ", FindSet(W[j])->head->key);
			}
			printf(" w1:");
			pom=FindSet(W[x[i].w1]);
			for(j=1;pom!=NIL;j++){
				printf("%d->",pom->key);
				pom=pom->next;
			}
			printf(" w2:");
			pom=FindSet(W[x[i].w2]);
			for(j=1;pom!=NIL;j++){
				printf("%d->",pom->key);
				pom=pom->next;
			}
			printf("\n");*/
		}
	}
	return x;
}

void wyswietl(krawedz *x, int lk, int lw){
	int i;
	printf("graph G {\n");
	for(i=1;i<lw+1;i++){
		printf("%c \n", i+96);
	}
	for(i=0;i<lk;i++){
		if(x[i].roz==1)
			printf("%c -- %c [label=%d]\n", x[i].w1+96, x[i].w2+96, x[i].waga);
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
	x=kruskal(x,lk,lw);
	wyswietl(x,lk,lw);
	return 0;
}
