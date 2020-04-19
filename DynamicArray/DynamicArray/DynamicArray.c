#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DynamicArray.h"

HDARRAY CreateDArray(void)
{
	return CreateDArrayWithCapacity(DEF_CAPACITY);
}

HDARRAY CreateDArrayWithCapacity(size_t capacity)
{
	HDARRAY hDArray;

	if ((hDArray = (HDARRAY)malloc(sizeof(DARRAY))) == NULL)
		return NULL;

	if ((hDArray->pArray = (DATATYPE *)malloc(sizeof(DATATYPE) * capacity)) == NULL) {
		free(hDArray);
		return NULL;
	}

	hDArray->size = 0;
	hDArray->capacity = capacity;

	return hDArray;
}

HDARRAY CreateDArrayWithArray(const DATATYPE *pArray, size_t size)
{
	HDARRAY hDArray;

	if ((hDArray = (HDARRAY)malloc(sizeof(DARRAY))) == NULL)
		return NULL;

	if ((hDArray->pArray = (DATATYPE *)malloc(sizeof(DATATYPE) * size)) == NULL) {
		free(hDArray);
		return NULL;
	}

	memmove(hDArray->pArray, pArray, size * sizeof(DATATYPE));

	hDArray->size = size;
	hDArray->capacity = size;

	return hDArray;
}

BOOL SetCapacity(HDARRAY hDArray, size_t newCapacity)
{
	DATATYPE *newArray;

	if (newCapacity < hDArray->size)
		return FALSE;

	if ((newArray = (DATATYPE *)realloc(hDArray->pArray, sizeof(DATATYPE) * newCapacity)) == NULL)
		return FALSE;

	hDArray->pArray = newArray;
	hDArray->capacity = newCapacity;	

	return TRUE;
}

size_t AddItem(HDARRAY hDArray, DATATYPE val)
{
	if (hDArray->size == hDArray->capacity && !SetCapacity(hDArray, hDArray->capacity * 2))
			return DARRAY_FAILED;
	
	hDArray->pArray[hDArray->size++] = val;

	return hDArray->size - 1;
}

BOOL GetItemRef(HDARRAY hDArray, size_t index, DATATYPE *pVal)
{
	if (index >= hDArray->size)
		return FALSE;

	*pVal = hDArray->pArray[index];

	return TRUE;
}

size_t FindItem(HDARRAY hDArray, DATATYPE val)
{
	size_t i;

	for (i = 0; i < hDArray->size; ++i)
		if (val == hDArray->pArray[i])
			return i;

	return DARRAY_FAILED;
}

BOOL InsertItem(HDARRAY hDArray, size_t index, DATATYPE val)
{
	if (index > hDArray->size)
		return FALSE;

	if (hDArray->size == hDArray->capacity && !SetCapacity(hDArray, hDArray->capacity * 2))
		return FALSE;

	memmove(&hDArray->pArray[index + 1], &hDArray->pArray[index], (hDArray->size - index) * sizeof(DATATYPE));
	hDArray->pArray[index] = val;
	++hDArray->size;

	return TRUE;
}

BOOL DeleteItem(HDARRAY hDArray, size_t index)
{
	if (index >= hDArray->size)
		return FALSE;

	memmove(&hDArray->pArray[index], &hDArray->pArray[index + 1], (hDArray->size - index - 1) * sizeof(DATATYPE));
	--hDArray->size;
	
	return TRUE;
}

BOOL Remove(HDARRAY hDArray, DATATYPE val)
{
	size_t index;

	if ((index = FindItem(hDArray, val)) == DARRAY_FAILED)
		return FALSE;

	return DeleteItem(hDArray, index);
}

void TrimToSize(HDARRAY hDArray)
{
	hDArray->pArray = (DATATYPE *)realloc(hDArray->pArray, sizeof(DATATYPE) * hDArray->size);
	hDArray->capacity = hDArray->size;
}

void CloseDArray(HDARRAY hDArray)
{
	free(hDArray->pArray);
	free(hDArray);
}