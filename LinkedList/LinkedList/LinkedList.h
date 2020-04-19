#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

/* Symbolic Constants */

#define FALSE	0
#define	TRUE	1

/* Type Definitions */

typedef int DATATYPE;
typedef int BOOL;

typedef struct tagNODE {
	DATATYPE val;
	struct tagNODE *pNext;
	struct tagNODE *pPrev;
}NODE;

typedef struct tagLLIST{
	NODE *pHead;
	NODE *pTail;
	size_t count;

}LLIST, *HLLIST;

/* Function Prototypes */

HLLIST CreateLList(void);
NODE *AddItemTail(HLLIST hLList, DATATYPE val);
NODE *AddItemHead(HLLIST hLList, DATATYPE val);
NODE *InsertItemPrev(HLLIST hLList, NODE *pNode, DATATYPE val);	 //Insert etme Node'un önüne yapýlýyor
NODE *InsertItemNext(HLLIST hLList, NODE *pNode, DATATYPE val);	 //Insert etme Node'un sonrasýna yapýlýyor
NODE *InsertItemIndex(HLLIST hLList, size_t index, DATATYPE val); //Belirli bir indekse insert eder, insert edilen node o indexe gelir
void DeleteItem(HLLIST hLList, NODE *pNode);
BOOL DeleteItemIndex(HLLIST hLList, size_t index);
DATATYPE *FindItem(HLLIST hLList, BOOL (*Compare)(const DATATYPE *));
NODE *FindItemNode(HLLIST hLList, BOOL(*Compare)(const DATATYPE *));
BOOL WalkList(HLLIST hLList, BOOL (*Proc)(DATATYPE *));
BOOL WalkListRev(HLLIST hLList, BOOL(*Proc)(DATATYPE *));
void Clear(HLLIST hLList);
void CloseList(HLLIST hLList);

/* Macros */

#define GetCount(hLList) ((hLList)->count)
#define IsEmpty(hLList)  ((hLList)->count == 0)

#endif