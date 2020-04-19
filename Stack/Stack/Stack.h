#ifndef STACK_H_
#define STACK_H_

#include <stddef.h>

#define FALSE	0
#define TRUE	1

/* Type Declarations */

typedef int BOOL;
typedef int DATATYPE;

typedef struct tagStack {
	DATATYPE *pStack;
	DATATYPE *sp;
	size_t count;
	size_t size;
}STACK, *HSTACK;

/* Function Prototypes */

HSTACK CreateStack(size_t size);
BOOL Push(HSTACK hStack, DATATYPE val);
DATATYPE Pop(HSTACK hStack);
BOOL PopSecure(HSTACK hStack, DATATYPE *pVal);
BOOL Walk(HSTACK hStack, BOOL(*Proc)(DATATYPE *));
void ClearStack(HSTACK hStack);
void CloseStack(HSTACK hStack);

/* Macros */
#define IsEmpty(hStack)		((hStack)->count == 0)
#define GetCount(hStack)	((hStack)->count)
#define GetSize(hStack)		((hStack)->size)

#endif