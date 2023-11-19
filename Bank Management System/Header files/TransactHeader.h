#ifndef TRANSACTHEADER_H_INCLUDED
#define TRANSACTHEADER_H_INCLUDED

#include"StructHeader.h"

void CreateTList(TList_t* Pt_create);
void TListInsert(CList_t* Pl_TInsert,int32_t position_transact);
void TListTraverse (const CList_t* Pl_TInsert,int32_t position_transact);
#endif // TRANSACTHEADER_H_INCLUDED
