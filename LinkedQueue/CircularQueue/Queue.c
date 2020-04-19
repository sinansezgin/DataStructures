#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

HQUEUE CreateQueue(void)
{
	HQUEUE hQueue;

	if ((hQueue = (HQUEUE)malloc(sizeof(QUEUE))) == NULL)
		return NULL;

	hQueue->pHead = hQueue->pTail = NULL;
	hQueue->count = 0;

	return hQueue;
}

BOOL PutItem(HQUEUE hQueue, DATATYPE val)
{
	NODE *pNewNode;

	if((pNewNode = (NODE *)malloc(sizeof(NODE))) == NULL)
		return FALSE;
	pNewNode->val = val;
	pNewNode->pNext = NULL;
	
	if (hQueue->pTail == NULL) //Queue bo�sa, eklenecek eleman ilk eleman olacaksa
		hQueue->pHead = pNewNode;
	else
		hQueue->pTail->pNext = pNewNode;
	hQueue->pTail = pNewNode;

	++hQueue->count;

	return TRUE;
}

BOOL GetItem(HQUEUE hQueue, DATATYPE *pVal)
{
	NODE *pNode;

	if (hQueue->pHead == NULL) //hQueue bo�sa
		return FALSE;
	
	pNode = hQueue->pHead;
	hQueue->pHead = pNode->pNext;

	if (pNode->pNext == NULL) //1 tane node varsa art�k, tail'in de NULL olmas� gerekir
		hQueue->pTail = NULL;

	*pVal = pNode->val;
	free(pNode);

	--hQueue->count;

	return TRUE;
}

void ClearQueue(HQUEUE hQueue)
{
	NODE *pTempNode, *pNode;

	pNode = hQueue->pHead;

	while (pNode != NULL) {
		pTempNode = pNode;
		pNode = pNode->pNext;
		free(pTempNode);
	}

	hQueue->pHead = hQueue->pTail = NULL;
	hQueue->count = 0;

}

void CloseQueue(HQUEUE hQueue)
{
	NODE *pTempNode, *pNode;

	pNode = hQueue->pHead;
	while (pNode != NULL) {
		pTempNode = pNode;
		pNode = pNode->pNext;
		free(pTempNode);
	}

	free(hQueue);
}
