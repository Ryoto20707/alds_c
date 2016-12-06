#include <stdio.h>
#include <stdlib.h>

#define LEN 1025

typedef char ITEM;
typedef struct lnode lnode;

struct lnode{
	ITEM item;
	lnode *prev, *next;
};

typedef struct {
	lnode *head, *tail;
	int size;
}LinkedList;

LinkedList *lInit() {
	LinkedList *l = NULL;
	l = malloc(sizeof(LinkedList));
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
	return l;
}

lnode *lNew(ITEM item) {
	lnode *node = NULL;
	node = malloc(sizeof(lnode));
	node->item = item;
	node->prev = NULL;
	node->next = NULL;
	return node;
}

void insert(LinkedList *l, ITEM item) {
	lnode *node = lNew(item);
	if (l->size == 0) {
		l->head = node;
		l->tail = node;
		node->next = node;
		node->prev = node;
	}
	else {
		l->tail->next = node;
		node->prev = l->tail;
		l->tail = node;
		node->next = l->head;
		l->head->prev = node;
	}
	l->size++;
}

ITEM nthItem(LinkedList *l, int n) {
	lnode *node = l->head;
	int i;
	for (i = 0; i < n; i++) {
		node = node->next;
	}
	return node->item;
}


int main(void) {
	int i, j, n, count;
	char inputs[LEN], state;
	LinkedList *buttons[9];
	for (i = 0; i < 9; i++) {
		buttons[i] = lInit();
	}
	insert(buttons[0], '.');
	insert(buttons[0], ',');
	insert(buttons[0], '!');
	insert(buttons[0], '?');
	insert(buttons[0], ' ');
	insert(buttons[1], 'a');
	insert(buttons[1], 'b');
	insert(buttons[1], 'c');
	insert(buttons[2], 'd');
	insert(buttons[2], 'e');
	insert(buttons[2], 'f');
	insert(buttons[3], 'g');
	insert(buttons[3], 'h');
	insert(buttons[3], 'i');
	insert(buttons[4], 'j');
	insert(buttons[4], 'k');
	insert(buttons[4], 'l');
	insert(buttons[5], 'm');
	insert(buttons[5], 'n');
	insert(buttons[5], 'o');
	insert(buttons[6], 'p');
	insert(buttons[6], 'q');
	insert(buttons[6], 'r');
	insert(buttons[6], 's');
	insert(buttons[7], 't');
	insert(buttons[7], 'u');
	insert(buttons[7], 'v');
	insert(buttons[8], 'w');
	insert(buttons[8], 'x');
	insert(buttons[8], 'y');
	insert(buttons[8], 'z');
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", inputs);
		count = 0;
		state = '0';
		for (j = 0; j < LEN; j++) {
			if(inputs[j] == '\0') break;
			if(inputs[j] == '0') {
				if (state != '0') printf("%c", nthItem(buttons[state-'1'], count));
				state = '0';
				count = 0;
			}
			else if (inputs[j] == state) {
				count++;
			}
			else {
				state = inputs[j];
				count = 0;
			}
		}
		printf("\n");
	}
	return 0;
}