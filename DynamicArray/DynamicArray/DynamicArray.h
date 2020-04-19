#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

#include <stddef.h>

/* Symbolic Constants */

#define FALSE			0
#define TRUE			1

#define DEF_CAPACITY	5
#define DARRAY_FAILED	((size_t)-1)

/* Type Declarations */

typedef int DATATYPE;
typedef int BOOL;

typedef struct tagDARRAY {
	DATATYPE *pArray;
	size_t size;
	size_t capacity;
}DARRAY, *HDARRAY;

/* Function Prototypes */

HDARRAY CreateDArray(void);
HDARRAY CreateDArrayWithCapacity(size_t capacity);
HDARRAY CreateDArrayWithArray(const DATATYPE *pArray, size_t size);
BOOL SetCapacity(HDARRAY hDArray, size_t newCapacity);
size_t AddItem(HDARRAY hDArray, DATATYPE val);
BOOL GetItemRef(HDARRAY hDArray, size_t index, DATATYPE *pVal);
size_t FindItem(HDARRAY hDArray, DATATYPE val);
BOOL InsertItem(HDARRAY hDArray, size_t index, DATATYPE val);
BOOL DeleteItem(HDARRAY hDArray, size_t index);
BOOL Remove(HDARRAY hDArray, DATATYPE val); //val'in ilk bulunduðu yerde silme iþlemi yapar
void TrimToSize(HDARRAY hDArray);//Kapasiteyi size'a çeker
void CloseDArray(HDARRAY hDArray);



/* Macros */

#define GetSize(hDArray)		((hDArray)->size)
#define GetCapacity(hDArray)	((hDArray)->capacity)
#define GetItem(hDArray, index) ((hDArray)->pArray[index])
#define Clear(hDArray)			((hDArray)->size = 0)

#endif