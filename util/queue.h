#ifndef _QUEUE_H
#define _QUEUE_H

#include "item.h"
typedef struct qnode qnode;

struct qnode{
	ITEM item;
	qnode *prev, *next;
};

typedef struct {
	qnode *head, *tail;
	int size;
}Queue;

Queue* qInit();
qnode* qNew(ITEM);
void   add(Queue*, ITEM);
ITEM   poll(Queue*);
ITEM   qElementAt(Queue*, int);

#endif
