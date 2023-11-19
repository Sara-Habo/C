#ifndef STRUCTHEADER_H_INCLUDED
#define STRUCTHEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include<string.h>


typedef char char_t;
typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef signed long int64_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long uint64_t;

typedef struct
{
    uint32_t day;
    uint32_t month;
    uint32_t year;
}Date_t;

typedef struct{
    Date_t TDate;
    uint64_t TAmount;
    uint32_t WithdrawFlage:1;
}Transact_t;

typedef struct TListNode
{
    Transact_t TEntry;
    struct TListNode* Tnext;
}TListNode_t;

typedef struct
{
    TListNode_t* top;
    int32_t TSize;
}TList_t;


typedef struct
{
    TList_t THistory;
    int64_t TotDeposit;
    uint32_t ID;
    uint32_t phone;
    Date_t DOB;
    char_t FName[10];
    char_t LName[10];
    char_t address[20];

}Customer_t;



typedef struct CListNode
{
    Customer_t entry;
    struct  CListNode* next;
}CListNode_t;

typedef struct
{
    CListNode_t* top;
    int32_t size;
}CList_t;


#endif // STRUCTHEADER_H_INCLUDED
