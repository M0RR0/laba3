#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include<iostream>

using namespace std;


struct list {
	char a;
	struct list* b;
};


void init(char ar, struct list* ls) {
	ls->a = ar;
	ls->b = NULL;

}




struct list* add(char ar, struct list* ls) {
	struct list* lst = (struct list*)malloc(sizeof(struct list));
	if (lst == NULL) {
		printf("No memory added");
		return(0);
	}
	ls->b = lst;
	lst->a = ar;
	lst->b = NULL;


	return lst;
}

void added(char ar, struct list* ls, char f) {
	struct list* u = ls;
	while (u != NULL) {
		struct list* t = (struct list*)malloc(sizeof(struct list));
		/*if (t == NULL) {
			printf("No memory added");
			return 0;
		}*/
		if (u->a == f) {
			t->b = u->b;
			u->b = t;
			t->a = ar;
			if (u->a == ar) {
				u = u->b;
			}
		}
		u = u->b;
	}
}


void added1(char ar, struct list* ls, int f) {
	struct list* u = ls;
	int count = 1;
	char q = ls->a;
	while (u != NULL) {
		struct list* t = (struct list*)malloc(sizeof(struct list));
		/*if (t == NULL) {
			printf("No memory added");
			return(0);
		}*/
		if (count == f && (f != 1)) {
			t->b = u->b;
			u->b = t;
			t->a = ar;
			break;
		}
		if (f == 1) {
			ls->a = ar;
			t->b = ls->b;
			t->a = q;
			ls->b = t;
			break;
		}
		u = u->b;
		count++;
	}
}


void print(struct list* p) {
	struct list* i = p;
	while (i != NULL) {
		printf("%c", i->a);
		i = i->b;

	}
	printf("\n");

}

int find(char ar, struct list* ls)
{
	struct list* kl = ls;
	int count = 0;

	while (kl != NULL) {
		if (kl->a == ar) {
			count++;
			if (count == 5) {
				break;
			}
		}
		else {
			count = 0;
		}
		kl = kl->b;

	}
	return count;
}


struct list* del(char ar, struct list* ls) {
	struct list* t, * u, * i = ls;
	if (ls->a = ar) {
		ls = ls->b;
		free(i);
	}
	u = ls;
	t = ls;
	while (t != NULL) {
		if (t->a == ar)
		{
			while (u->b != t) {
				u = u->b;
			}
			u->b = t->b;
			i = t;
			free(i);
			u = ls;
			t = u;

		}
		else
		{
			t = t->b;
		}


	}
	print(ls);
	return ls;
}

struct list* del1(int ar, struct list* ls) {
	struct list* t, * u = ls;
	/*if (t == NULL) {
		printf("No memory added");
		return(0);
	}*/
	t = ls;
	int count = 1;
	while (t != NULL) {
		if (count == ar && (ar != 1))
		{
			while (u->b != t) {
				u = u->b;
			}
			u->b = t->b;
			free(t);
			break;

		}
		else if (ar == 1) {
			ls = ls->b;
			free(u);
			return ls;
		}
		else
		{
			u = t;
			t = t->b;

		}
		count++;

	}
	return ls;
}

struct list* removeall(struct list* head)
{
	while (head != NULL)
	{
		struct list* p = head;
		head = head->b;
		free(p);
	}
	return NULL;
}


int main() {

	setlocale(LC_ALL, "Russian");
	struct list* lst = (struct list*)malloc(sizeof(struct list)), * p = lst;

	if (lst == NULL) {
		printf("No memory added");
		return(0);
	}
	int j = 1, count, i, more, r1;
	char s, q1, q2;
	printf("Введиет текст: \n");
	scanf_s("%c", &s);
	init(s, lst);
	while (s != '\n') {
		scanf_s("%c", &s);
		if (s != '\n')
		{
			lst = add(s, lst);
		}
	}


	while (1) {
		printf("1.вывести список\n 2.добавить элемент в список\n 3.удалить элемент\n 4.найти элемент (и количество его вхождений\n5.завершить работу\n");
		scanf_s("%d", &i);
		if (i == 1) {
			print(p);
		}
		if (i == 2) {
			printf("весли вы хотите добавить элемент после конкретного элемента списка нажмите 1, если после всех одинаковых элементов списка нажмите 2, если в конец 3 \n: ");
			scanf_s("%d", &more);
			if (more == 1) {
				printf("введите элемент который хотите добавить: ");
				scanf_s("%s", &q1);
				printf("введите номер элемента после которого хотите добавлять: ");
				scanf_s("%d", &r1);
				added1(q1, p, r1);

			}
			if (more == 2) {
				char s, q1, q2;
				printf("введите элемент который хотите добавить: ");
				scanf_s("%s", &q1);
				printf("введите элемент после которых хотите добавлять: ");
				scanf_s("%s", &q2);
				added(q1, p, q2);
			}
			if (more == 3) {
				char q1;
				printf("введите элемент который хотите добавить: ");
				scanf_s("%s", &q1);

				lst = add(q1, lst);
			}
		}
		if (i == 3) {
			printf("весли вы хотите удалить по номеру этого элемента в списке нажмите 1, если вы хотите удалить по символу нажмите 2\n: ");
			scanf_s("%d", &more);
			if (more == 1) {
				printf("введите номер элемента  который хотите удалить: ");
				scanf_s("%d", &r1);
				p = del1(r1, p);

			}
			if (more == 2) {
				printf("введите элемент который хотите удалить: ");
				scanf_s("%s", &q1);
				p = del(q1, p);
			}
		}
		if (i == 4) {
			char jok;
			printf("введите элемент, который хотите найти: ");
			scanf_s("%s", &jok);

			count = find(jok, p);

			if (count == 5)
			{
				printf("ok\n");
			}
			else {
				printf("no\n");
			}

		}
		if (i == 5) {
			p = removeall(p);
			break;
		}
	}




	return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
struct list{
	char a;
	struct list *b;
	struct list *c;
};



void init(char ar, struct list * ls){
	ls->a=ar;
	ls->b=NULL;
	ls->c =NULL;

}




struct list* add(char ar, struct list *ls){
	struct list *lst= (struct list*)malloc(sizeof(struct list));
	ls->b = lst;
	lst->a = ar;
	lst ->b = NULL;
	lst->c = ls;


	return lst;
}

void added(char ar, struct list*ls, char f){
	struct list *u= ls;
	while(u->b != NULL){
		struct list *t = (struct list*)malloc(sizeof(struct list));
		if (u->a == f){
			t->b = u->b;
			u->b->c = t;
			t->c = u;
			u->b = t;
			t->a = ar;
			if( u->a == ar){
				u = u->b;
			}
		}
		u = u->b;
	}
}


void added1(char ar, struct list*ls, int f){
	struct list *u= ls;
	int count = 0;
	while(u->b != NULL){
		struct list *t = (struct list*)malloc(sizeof(struct list));
		if (count == f){
			t->b = u->b;
			u->b->c = t;
			t->c = u;
			u->b = t;
			t->a = ar;
			break;
		}
		u = u->b;
		count++;
	}
}


void print(struct list *p){
	struct list *i = p;
	while(i->b !=NULL){
		printf("%c", i->a);
		i = i->b;

	}
	printf("\n");

}

int find(char ar, struct list  *ls)
{
	struct list *kl = ls;
	int count = 0;

	while( kl->b !=NULL){
		if (kl->a == ar){
			count++;
			if (count == 5){
				break;
			}
		}
		else{
			count = 0;
		}
		kl = kl->b;

	}
	return count;
}


void del(char ar, struct list *ls){
	struct list *t = (struct list*)malloc(sizeof(struct list)), *u= ls, *i;
	t = ls;
	while(t->b != NULL){
		if (t->a == ar)
		{
			while (u->b != t){
				u = u->b;
			}
			u->b = t->b;
			t->b->c = u;
			i = t;
			free(i);
			u = ls;
			t = u;

		}
		else
		{
			t=t->b;
		}


	}
	print(ls);
}

void del1(int ar, struct list *ls){
	struct list *t = (struct list*)malloc(sizeof(struct list)), *u= ls, *i;
	t = ls;
	int count = 0;
	while(t->b != NULL){
		if (count == ar)
		{
			while (u->b != t){
				u = u->b;
			}
			u->b = t->b;
			t->b->c = u;
			i = t;
			free(i);
			u = ls;
			t = u;


		}
		else
		{
			u = t;
			t=t->b;

		}
		count++;

	}
}

struct list* removeall(struct list* head)
{
	while (head != NULL)
	{
		struct list* p = head;
		head = head->b;
		free(p);

	}
	head = NULL;
	return NULL;
}


int main(){
	struct list *lst = (struct list*)malloc(sizeof(struct list)), *p = lst;
	int j=1, count, i, more, r1;
	char s, q1, q2;
	printf("Введиет текст: \n");
	scanf_s("%c", &s);
	init(s, lst);
	while(s != '\n'){
		scanf_s("%c", &s);
		lst = add(s, lst);
		j++;
	}


while(1){
	printf("1.вывести список\n 2.добавить элемент в список\n 3.удалить элемент\n 4.найти элемент (и количество его вхождений\n5.завершить работу\n");
	scanf_s("%d", &i);
	if (i == 1){
		print(p);
	}
	if (i == 2){
		printf("весли вы хотите добавить элемент после конкретного элемента списка нажмите 1, если после всех одинаковых элементов списка нажмите 2\n: ");
		scanf_s("%d", &more);
		if (more == 1){
			printf("введите элемент который хотите добавить: ");
			scanf_s("%s", &q1);
			printf("введите номер элемента после которого хотите добавлять: ");
			scanf_s("%d", &r1);
			added1(q1, p , r1);

		}
		if(more == 2){
			char s, q1, q2;
			printf("введите элемент который хотите добавить: ");
			scanf_s("%s", &q1);
			printf("введите элемент после которых хотите добавлять: ");
			scanf_s("%s", &q2);
			added(q1, p , q2);
		}
	}
	if(i == 3){
		printf("весли вы хотите удалить по номеру этого элемента в списке нажмите 1, если вы хотите удалить по символу нажмите 2\n: ");
		scanf_s("%d", &more);
		if (more == 1){
			printf("введите номер элемента  который хотите удалить: ");
			scanf_s("%d", &r1);
			del1(r1, p);

		}
		if(more == 2){
			printf("введите элемент который хотите удалить: ");
			scanf_s("%s",&q1);
			del(q1, p);
		}
	}
	if( i ==4){
		char jok;
		printf("введите элемент, который хотите найти: ");
		scanf_s("%s", &jok);

		count = find(jok, p);

		if (count == 5)
			{
				printf("ok\n");
			}
			else{
				printf("no\n");
			}

	}
	if ( i ==5){
		p = removeall(p);
		break;
	}
}



	lst = NULL;
	return 0;
}
*/
