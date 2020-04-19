#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

HSTACK CreateStack(void)
{
	HSTACK hStack;

	if ((hStack = (HSTACK)malloc(sizeof(STACK))) == NULL)
		return NULL;

	hStack->pHead = NULL;
	hStack->count = 0;

	return hStack;
}

BOOL Push(HSTACK hStack, DATATYPE val)
{
	NODE *pNewNode;

	if ((pNewNode = (NODE *)malloc(sizeof(NODE))) == NULL)
		return FALSE;
	pNewNode->val = val;

	pNewNode->pNext = hStack->pHead;
	hStack->pHead = pNewNode;

	++hStack->count;

	return TRUE;
}

DATATYPE Pop(HSTACK hStack)
{
	NODE *pNode;
	DATATYPE val;

	pNode = hStack->pHead;
	hStack->pHead = pNode->pNext;
	val = pNode->val;
	--hStack->count;
	
	free(pNode);

	return val;
}

BOOL PopSecure(HSTACK hStack, DATATYPE *val)
{
	NODE *pNode;

	if (hStack->pHead == NULL)
		return FALSE;

	pNode = hStack->pHead;
	hStack->pHead = pNode->pNext;
	*val = pNode->val;
	--hStack->count;
	
	free(pNode);

	return TRUE;
}

void ClearStack(HSTACK hStack)
{
	NODE *pNode, *pTemp;

	pNode = hStack->pHead;

	while (pNode != NULL) {
		pTemp = pNode;
		pNode = pNode->pNext;
		free(pTemp);
	}

	hStack->pHead = NULL;
	hStack->count = 0;
}

void CloseStack(HSTACK hStack)
{
	NODE *pNode, *pTemp;

	pNode = hStack->pHead;

	while (pNode != NULL) {
		pTemp = pNode;
		pNode = pNode->pNext;
		free(pTemp);
	}

	free(hStack);
}