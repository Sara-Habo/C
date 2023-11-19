#ifndef BM1HEADER_H_INCLUDED
#define BM1HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "StructHeader.h"

uint8_t MainMenue(CList_t* Pl_menue);
void InitSystem(void);
void NewAccount(CList_t* Pl);
void DeleteAccount(CList_t* Pl_delete);
void CustomerEdit(CList_t* Pl_edit);
void CustomerList(CList_t* Pl_sort);
void Transact(CList_t* Pl_transact);
void TransactList(CList_t* Pl_TransactList);

#endif // BM1HEADER_H_INCLUDED
