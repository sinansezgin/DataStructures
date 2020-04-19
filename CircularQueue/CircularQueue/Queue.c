#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


HQUEUE CreateQueue(size_t size)
{
	HQUEUE hQueue;

	if ((hQueue = (HQUEUE)malloc(sizeof(QUEUE))) == NULL)
		return NULL;

	if ((hQueue->pQUEUE = (DATATYPE *)malloc(sizeof(DATATYPE) * size)) == NULL) {
		free(hQueue);
		return NULL;
	} 

	hQueue->size = size;
	hQueue->count = 0;
	hQueue->head = hQueue->tail = 0;

	return hQueue;
}

BOOL PutItem(HQUEUE hQueue, DATATYPE val)
{
	if (hQueue->count == hQueue->size)
		return FALSE;

	hQueue->pQUEUE[hQueue->tail++] = val;
	
	hQueue->tail %= hQueue->size;
	++hQueue->count;

	return TRUE;
}

BOOL GetItem(HQUEUE hQueue, DATATYPE *pVal)
{
	if (hQueue->count == 0)
		return FALSE;

	*pVal = hQueue->pQUEUE[hQueue->head++];
	hQueue->head %= hQueue->size;
	--hQueue->count;

	return TRUE;
}

void ClearQueue(HQUEUE hQueue)
{
	hQueue->head = hQueue->tail = hQueue->count = 0;
}


void CloseQueue(HQUEUE hQueue)
{
	free(hQueue->pQUEUE);
	free(hQueue);
}
