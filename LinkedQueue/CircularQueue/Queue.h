#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdlib.h>

/* Symbolic Constants */
#define FALSE	0
#define TRUE	1

/* Type Declarations */

typedef int DATATYPE;
typedef int BOOL;

typedef struct tagNODE {
	DATATYPE val;
	struct tagNode *pNext;
}NODE;

typedef struct tagQUEUE {
	NODE *pHead;
	NODE *pTail;
	size_t count;
}QUEUE, *HQUEUE;

/* Function Prototypes*/

HQUEUE CreateQueue(void);
BOOL PutItem(HQUEUE hQueue, DATATYPE val);
BOOL GetItem(HQUEUE hQueue, DATATYPE *pVal);
void ClearQueue(HQUEUE hQueue);
void CloseQueue(HQUEUE hQueue);

/* Macros */

#define IsEmpty(hQueue)	((hQueue)->count == 0)
#define GetCount(hQueue) ((hQueue)->count)


#endif