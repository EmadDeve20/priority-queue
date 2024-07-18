#ifndef PQUEUE_H_
#define PQUEUE_H_
#include <stdlib.h>

// check if queue is empty or not
#define QEMPTY(X) (X==NULL)

extern int QUEUE_LENGTH, MINIMUM_PRORITY, MAXIMUM_PRORITY;

typedef struct pqueue {
	int value;
	long priority;
	void* data;
	struct pqueue *next;

} p_queue;

typedef p_queue *pp_queue;

pp_queue create_queue(int value, long priority, void* data);

pp_queue add_queue(pp_queue *p, int value, long priority,void* data);

int pop(pp_queue p, int* value, void* data);

#endif
