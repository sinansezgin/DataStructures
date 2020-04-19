#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_

#include <stddef.h>

/* Symbolic Constants */

#define FALSE	0
#define TRUE	1

/* Type Definitons */

typedef int BOOL;
typedef int DATATYPE;

typedef struct tagNODE {
	DATATYPE val;
	struct tagNode *pNext;
}NODE;

typedef struct tagSTACK {
	NODE *pHead;
	size_t count;
}STACK, *HSTACK;

/* Function Prototypes */

HSTACK CreateStack(void);
BOOL Push(HSTACK hStack, DATATYPE val);
BOOL PopSecure(HSTACK hStack, DATATYPE *val);
DATATYPE Pop(HSTACK hStack);
void ClearStack(HSTACK hStack);
void CloseStack(HSTACK hStack);

/* Macro Definitions */

#define GetItemCount(hStack) ((hStack)->count)
#define IsEmptyStack(hStack) ((hStack)->count == 0)

#endif