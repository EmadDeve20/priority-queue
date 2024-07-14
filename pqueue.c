#include "pqueue.h"


int QUEUE_LENGTH = 0;
int MINIMUM_PRORITY = 0;
int MAXIMUM_PRORITY = 0;

pp_queue create_queue(int value, long priority, void* data)
{
	pp_queue new_p = NULL;
	new_p = (pp_queue) malloc(sizeof(p_queue));
	if (new_p != NULL)
	{
		new_p->data = data;
		new_p->value = value;
		new_p->priority = priority;
		
		QUEUE_LENGTH++;
		MINIMUM_PRORITY = MINIMUM_PRORITY > priority ? priority : MINIMUM_PRORITY;
		MAXIMUM_PRORITY = MAXIMUM_PRORITY < priority ? priority : MAXIMUM_PRORITY;	
		return new_p;
	}
	return NULL;

}


// TODO: update this function to set queue correctly
pp_queue add_queue(pp_queue p, int value, long priority, void* data)
{
	pp_queue new_p = NULL;
	new_p = (pp_queue) malloc(sizeof(p_queue));
	if (new_p != NULL)
	{
		new_p->data = data;
		new_p->value = value;
		new_p->priority = priority;
		p->next = new_p;
		return new_p;
	}
	return NULL;
}


// return 1 if queue is not empty otherwise 0
int pop(pp_queue p, int* value, void* data)
{
	if (p != NULL)
	{
		*value = p->value;
		data = p->data;
		pp_queue delete_p = p;
		p = p->next;
		free(delete_p);
		return 1;
	}
	
	return 0;
}
