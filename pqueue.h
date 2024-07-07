#include <stdio.h>

typedef struct pqueue {
	int value;
	long priority;
	void* data;
	pqueue* next;

} p_queue;


