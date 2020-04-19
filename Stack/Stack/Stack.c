#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


HSTACK CreateStack(size_t size)
{
	HSTACK hStack;

	if ((hStack = (HSTACK)malloc(sizeof(STACK))) == NULL)
		return NULL;

	if ((hStack->pStack = (DATATYPE *)malloc(size * sizeof(DATATYPE))) == NULL) {
		free(hStack);
		return NULL;
	}

	hStack->size = size;
	hStack->count = 0;
	hStack->sp = hStack->pStack + size;

	return hStack;
}

BOOL Push(HSTACK hStack, DATATYPE val)
{
	if (hStack->count == hStack->size) /*hStack->sp == hStack->pStack*/
		return FALSE;

	*--hStack->sp = val;
	++hStack->count;

	return TRUE;
}

DATATYPE Pop(HSTACK hStack)
{
	--hStack->count;

	return *hStack->sp++;
}

BOOL PopSecure(HSTACK hStack, DATATYPE *pVal)
{
	if (!hStack->count) /*hStack->sp == hStack->pStack + size*/
		return FALSE;

	*pVal = *hStack->sp++;
	--hStack->count;

	return TRUE;
}

BOOL Walk(HSTACK hStack, BOOL(*Proc)(DATATYPE *))
{
	size_t i;

	for (i = 0; i < hStack->count; ++i)
		if (!Proc(&hStack->sp[i]))
			return FALSE;

	return TRUE;
}

void ClearStack(HSTACK hStack)
{
	hStack->sp = hStack->pStack + hStack->size;
	hStack->count = 0;
}

void CloseStack(HSTACK hStack)
{
	free(hStack->pStack);
	free(hStack);
}