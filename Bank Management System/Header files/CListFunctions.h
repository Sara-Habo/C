#ifndef CLISTFUNCTIONS_H_INCLUDED
#define CLISTFUNCTIONS_H_INCLUDED



#include"StructHeader.h"


void CreateCList(CList_t* Pl);
uint8_t CListIsFull(const CList_t* Pl_full);
uint8_t CListIsEmpty(const CList_t* Pl_empty);
int32_t CListSize(const CList_t* Pl_size);
void CListInsert(CList_t* Pl_insert,uint32_t pos);
void CListTraverse(const CList_t * Pl_traverse);
uint8_t SearchNode(const CList_t* Pl_search,uint32_t CustID,int32_t *position);
void CListDelete(CListNode_t** Pe_delete,CList_t * Pl_delete,int32_t pos);
void CClearList(CList_t *Pl_clear);
void SwapNodes(CList_t* Pl_swap,int32_t pos1,int32_t pos2);


#endif // CLISTFUNCTIONS_H_INCLUDED
