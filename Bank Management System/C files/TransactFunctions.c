#include "TransactHeader.h"
#include "CListFunctions.h"
void CreateTList(TList_t* Pt_create)
{
    Pt_create->top=NULL;
    Pt_create->TSize=0;
}

void TListInsert(CList_t* Pl_TInsert,int32_t position_transact)
{
    CListNode_t* temp_customer=Pl_TInsert->top;
    uint32_t h;
    int32_t temp_bit;
    int64_t temp_amount;
    for(h=0;h<position_transact;h++)
    {
        temp_customer=temp_customer->next; /*make it point to needed customer*/
    }

    printf("Please, Enter 0 for deposit\n");
    printf("Please, Enter 1 for withdraw\n");
    scanf("%u",&temp_bit);
    printf("\n");

    printf("Please, Enter Money Amount:");
    scanf("%ld",&temp_amount);
    printf("\n");

    if(temp_bit==1) /*if withdraw make sure there is enough balance*/
    {
        if(temp_amount< temp_customer->entry.TotDeposit)
        {
            TList_t* PTList=&(temp_customer->entry.THistory);
            TListNode_t* Ptn=(TListNode_t*)malloc(sizeof(TListNode_t));
            Ptn->TEntry.WithdrawFlage=temp_bit;
            Ptn->TEntry.TAmount=temp_amount;

            printf("Please Enter Date of today (Day,Month,Year)\n");
            scanf("%u %u %u",&(Ptn->TEntry.TDate.day),&(Ptn->TEntry.TDate.month),&(Ptn->TEntry.TDate.year));
            printf("\n");


            /*insert at top*/
            Ptn->Tnext=PTList->top;
            PTList->top=Ptn;
            PTList->TSize++;
           temp_customer->entry.TotDeposit-=temp_amount;

        }
        else
        {
            printf("No sufficient balance.Current Total Balance:%ld\n",temp_customer->entry.TotDeposit);
        }

    }
    else /*Deposite*/
    {
        TList_t* PTList=&(temp_customer->entry.THistory);
        TListNode_t* Ptn=(TListNode_t*)malloc(sizeof(TListNode_t));
        Ptn->TEntry.WithdrawFlage=temp_bit;
        Ptn->TEntry.TAmount=temp_amount;
        printf("Please Enter Date of today (Day,Month,Year)\n");
        scanf("%u %u %u",&(Ptn->TEntry.TDate.day),&(Ptn->TEntry.TDate.month),&(Ptn->TEntry.TDate.year));
        printf("\n");




        /*insert at top*/
        Ptn->Tnext=PTList->top;
        PTList->top=Ptn;
        PTList->TSize++;
        temp_customer->entry.TotDeposit+=temp_amount;
    }
}

void TListTraverse (const CList_t* Pl_TInsert,int32_t position_transact)
{
    CListNode_t* temp_customer=Pl_TInsert->top;
    int32_t k;
    for(k=0;k<position_transact;k++)
    {
        temp_customer=temp_customer->next; /*make it point to needed customer*/
    }
    TList_t* PTList=&(temp_customer->entry.THistory);
    TListNode_t* temp_Tlist=PTList->top;


    char_t sign;
    if(!PTList->top)
    {
        printf("No Transactions exist to view\n");
    }
    else
    {
        //printf("|--------------------|-----------------------\n");
        //printf("|Date                |Amount                 \n");
        //printf("|--------------------|-----------------------\n");


        while(temp_Tlist)
        {
            if(1==temp_Tlist->TEntry.WithdrawFlage)
            {
                sign='-';
            }
            else
            {
                sign='+';
            }
            //printf("|%u-%u-%u            |(%c)%ld                \n",temp_Tlist->TEntry.TDate.day,temp_Tlist->TEntry.TDate.month,temp_Tlist->TEntry.TDate.year,sign,temp_Tlist->TEntry.TAmount);

            //printf("|%s|(%c)%ld                \n",temp_Tlist->TEntry.TDate,sign,temp_Tlist->TEntry.TAmount);
            printf("Date:%u-%u-%u \n",temp_Tlist->TEntry.TDate.day,temp_Tlist->TEntry.TDate.month,temp_Tlist->TEntry.TDate.year);
            printf("Deposit amount:(%c)%ld \n",sign,temp_Tlist->TEntry.TAmount);
            printf("---------------------------------------------------\n");
            temp_Tlist=temp_Tlist->Tnext;
        }
    }
}

void SwapTNodes(TList_t* Pl_TSwap, int32_t pos1,int32_t pos2)
{
    TListNode_t* temp_swap;
    if(0==pos1)/*we want to swap first node(0) with second node(1)*/
    {
        temp_swap=Pl_TSwap->top; /*make temp points to node 0*/
        Pl_TSwap->top=temp_swap->Tnext; /*make top points to node 1*/
        temp_swap->Tnext=temp_swap->Tnext->Tnext; /*make node 0 point to node 2 */
        Pl_TSwap->top->Tnext=temp_swap;
    }
    else
    {
        int k;
        TListNode_t* temp=Pl_TSwap->top;
        for(k=0;k<pos1-1;k++)/* make temp points to node previous to pos1*/
        {
            temp=temp->Tnext;
        }
         temp_swap=temp->Tnext; /*make temp_swap points to pos1*/
         temp->Tnext=temp_swap->Tnext; /*make previous to pos1 point to pos2*/
         temp_swap->Tnext=temp_swap->Tnext->Tnext; /*make pos1 points to next of pos2*/
         temp->Tnext->Tnext=temp_swap; /*make pos2 points to pos1*/
    }
}

