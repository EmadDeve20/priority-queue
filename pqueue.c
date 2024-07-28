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
		// TODO: dont save minimum and maximum built-in! return it or get a pointer to save it!
		// because this is diffrent for any queue!
		MINIMUM_PRORITY = MAXIMUM_PRORITY = priority;
		return new_p;
	}
	return NULL;
}


// add new item to queue
pp_queue enqueue(pp_queue *p, int value, long priority, void* data)
{
	pp_queue new_p = NULL;
	new_p = (pp_queue) malloc(sizeof(p_queue));
	if (new_p != NULL)
	{
		new_p->data = data;
		new_p->value = value;
		new_p->priority = priority;
		if (QEMPTY(*p) || (*p)->priority >= priority)
		{
			new_p->next = *p;
			*p = new_p;
		}
		else
		{
			pp_queue p_next = *p;
		       	pp_queue p_prev = NULL;
			while (!QEMPTY(p_next))
			{	
				if (p_next->priority >= new_p->priority)
					break;

				p_prev = p_next;
				p_next = p_next->next;
			}
			p_prev->next = new_p;
			new_p->next = p_next;
		}
		MINIMUM_PRORITY = MINIMUM_PRORITY > priority || QUEUE_LENGTH == 0 ? priority : MINIMUM_PRORITY;
		MAXIMUM_PRORITY = MAXIMUM_PRORITY < priority || QUEUE_LENGTH == 0 ? priority : MAXIMUM_PRORITY;	
		QUEUE_LENGTH++;
		return new_p;
	}
	return NULL;
}


// return 1 if queue is not empty otherwise 0
// TODO: update queue length and minimum and maximum priority
int dequeue(pp_queue *p, int* value, void* data)
{
	if (!QEMPTY(*p))
	{
		*value = (*p)->value;
		data = (*p)->data;
		pp_queue delete_p = *p;
		*p = (*p)->next;
		free(delete_p);
		return 1;
	}
	
	return 0;
}

