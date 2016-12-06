#include "queue.h"
#include <stdlib.h>

Queue *qInit() {
	Queue *q = NULL;
	q = malloc(sizeof(Queue));
	q->head = NULL;
	q->tail = NULL;
	q->size = 0;
	return q;
}

qnode *qNew(ITEM item) {
	qnode *node = NULL;
	node = malloc(sizeof(qnode));
	node->item = item;
	node->prev = NULL;
	node->next = NULL;
	return node;
}

void add(Queue *q, ITEM item) {
	qnode *node = qNew(item);
	if (q->size == 0) {
		q->head = node;
		q->tail = node;
	}
	else {
		q->tail->next = node;
		node->prev = q->tail;
		q->tail = node;
	}
	q->size++;
}

ITEM poll(Queue *q) {
	qnode *node = q->head;
	if (q->size == 1) {
		q->head = NULL;
		q->tail = NULL;
	}
	else {
		q->head = node->next;
		q->head->prev = NULL;
	}
	q->size--;
	return node->item;
}

ITEM qElementAt(Queue *q, int n) {
	if (n > q->size || n < 0) exit(-1);
	int i;
	qnode *crawl = q->head;
	for(i = 0; i < n; i++) crawl = crawl->next;
	return crawl->item;
}