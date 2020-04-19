#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


HLLIST CreateLList(void)
{
	HLLIST hLList;

	if ((hLList = (HLLIST)malloc(sizeof(LLIST))) == NULL)
		return NULL;

	hLList->pHead = hLList->pTail = NULL;
	hLList->count = 0;

	return hLList;
}

NODE *AddItemTail(HLLIST hLList, DATATYPE val)
{
	NODE *pNewNode;

	if ((pNewNode = (NODE *)malloc(sizeof(NODE))) == NULL)
		return NULL;
	pNewNode->val = val;

	if (hLList->pHead != NULL)			//Listede eleman varsa
		hLList->pTail->pNext = pNewNode;
	else								//Listede eleman yoksa
		hLList->pHead = pNewNode;

	//bunlar her iki durum için de ortak
	pNewNode->pPrev = hLList->pTail;	//listede eleman yoksa da iþlemesinin sebebi, listede eleman yoksa zaten hLList->pTail NULL o yüzden; pNewNode->pPrev = NULL; ile ayný þey
	pNewNode->pNext = NULL;
	hLList->pTail = pNewNode;

	++hLList->count;

	return pNewNode;
}

NODE *AddItemHead(HLLIST hLList, DATATYPE val)
{
	NODE *pNewNode;

	if ((pNewNode = (NODE *)malloc(sizeof(NODE))) == NULL)
		return NULL;
	pNewNode->val = val;

	if (hLList->pHead != NULL)			//Listede eleman varsa
		hLList->pHead->pPrev = pNewNode;
	else	
		hLList->pTail = pNewNode;		//Listede eleman yoksa
	
	//bunlar her iki durum için de ortak
	pNewNode->pNext = hLList->pHead;	
	pNewNode->pPrev = NULL;
	hLList->pHead = pNewNode;

	++hLList->count;

	return pNewNode;
}

NODE *InsertItemPrev(HLLIST hLList, NODE *pNode, DATATYPE val)
{
	NODE *pNewNode;

	if ((pNewNode = (NODE *)malloc(sizeof(NODE))) == NULL)
		return NULL;
	pNewNode->val = val;

	if (pNode == hLList->pHead)   //Listede tek eleman varsa yani eklenecek olan eleman listenin ilk elemaný olacaksa
		hLList->pHead = pNewNode; 
	else 
		pNode->pPrev->pNext = pNewNode;

	pNewNode->pPrev = pNode->pPrev;
	pNewNode->pNext = pNode;
	pNode->pPrev = pNewNode;

	++hLList->count;

	return pNewNode;
}

NODE *InsertItemNext(HLLIST hLList, NODE *pNode, DATATYPE val)
{
	NODE *pNewNode;

	if ((pNewNode = (NODE *)malloc(sizeof(NODE))) == NULL)
		return NULL;
	pNewNode->val = val;

	if (pNode == hLList->pHead)	  //Listede tek eleman varsa, eklenecek eleman listenin son elemaný olmuþ olur
		hLList->pTail = pNewNode;
	else 
		pNode->pNext->pPrev = pNewNode;
	
	pNewNode->pNext = pNode->pNext;
	pNewNode->pPrev = pNode;
	pNode->pNext = pNewNode;


	++hLList->count;

	return pNewNode;
}

NODE *InsertItemIndex(HLLIST hLList, size_t index, DATATYPE val)
{
	size_t i;
	NODE *pNode;

	if(index > hLList->count)
		return NULL;

	if (index == hLList->count)		//index olarak listenin sonu verilmiþse
		return AddItemTail(hLList, val);

	pNode = hLList->pHead;
	for (i = 0; i < index; ++i)
		pNode = pNode->pNext;

	return InsertItemPrev(hLList, pNode, val);
}

void DeleteItem(HLLIST hLList, NODE *pNode)
{
	if (pNode == hLList->pHead)
		hLList->pHead = pNode->pNext;
	else
		pNode->pPrev->pNext = pNode->pNext;

	if (pNode == hLList->pTail)
		hLList->pTail = pNode->pPrev;
	else	
		pNode->pNext->pPrev = pNode->pPrev;
	
	--hLList->count;

	free(pNode);
}

BOOL DeleteItemIndex(HLLIST hLList, size_t index)
{
	size_t i;
	NODE *pNode;

	if (index >= hLList->count)
		return FALSE;

	pNode = hLList->pHead;
	for (i = 0; i < index; ++i)
		pNode = pNode->pNext;

	DeleteItem(hLList, pNode);
	
	return TRUE;
}

DATATYPE *FindItem(HLLIST hLList, BOOL(*Compare)(const DATATYPE *))
{
	NODE *pNode;

	for (pNode = hLList->pHead; pNode != NULL; pNode = pNode->pNext)
		if (Compare(&pNode->val))
			return &pNode->val;
	
	return NULL;
}

NODE *FindItemNode(HLLIST hLList, BOOL(*Compare)(const DATATYPE *))
{
	NODE *pNode;

	for (pNode = hLList->pHead; pNode != NULL; pNode = pNode->pNext)
		if (Compare(&pNode->val))
			return pNode->val;

	return NULL;
}

BOOL WalkList(HLLIST hLList, BOOL(*Proc)(const DATATYPE *))
{
	NODE *pNode;

	for (pNode = hLList->pHead; pNode != NULL; pNode = pNode->pNext)
		if (!Proc(&pNode->val))
			return FALSE;

	return TRUE;
}

BOOL WalkListRev(HLLIST hLList, BOOL(*Proc)(DATATYPE *))
{
	NODE *pNode;

	for (pNode = hLList->pTail; pNode != NULL; pNode = pNode->pPrev)
		if (!Proc(&pNode->val))
			return FALSE;

	return TRUE;
}

void Clear(HLLIST hLList)
{
	NODE *pNode, *pTemp;

	pNode = hLList->pHead;
	while (pNode != NULL) {
		pTemp = pNode;
		pNode = pNode->pNext;
		free(pTemp);
	}

	hLList->pHead = hLList->pTail = NULL;
	hLList->count = 0;
}

void CloseList(HLLIST hLList)
{
	NODE *pNode, *pTemp;

	pNode = hLList->pHead;
	while (pNode != NULL) {
		pTemp = pNode;
		pNode = pNode->pNext;
		free(pTemp);
	}

	free(hLList);
}