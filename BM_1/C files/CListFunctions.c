#include"CListFunctions.h"
#include "TransactHeader.h"

void CreateCList(CList_t* Pl_creat)
{
    Pl_creat->top=NULL;
    Pl_creat->size=0;
}

uint8_t CListIsEmpty(const CList_t* Pl_empty)
{
    return (!Pl_empty->top);
}

uint8_t CListIsFull(const CList_t* Pl_full)
{
    return 0;
}

int32_t CListSize(const CList_t* Pl_size)
{
    return Pl_size->size;
}

void CListInsert(CList_t* Pl_insert,uint32_t pos)
{
    /*Treat pos as an index af array
      Insert at first >>Pos=0
      Insert at pos=i >> the node while be at i
      Insert at last >> pos= previeous size before insert
    */

    if(pos>Pl_insert->size-1 )
    {
        printf("Invalid index for insert\n");
    }
    else
    {
                /*create a new node*/
        CListNode_t* Pn=(CListNode_t*)malloc(sizeof(CListNode_t));
        /*Get customer Data*/
        printf("Please enter customer first name:");
        fflush(stdin);
        scanf("%[^\n]%*c",Pn->entry.FName);
        printf("\n");


        printf("Please enter customer Last name:");
        fflush(stdin);
        scanf("%[^\n]%*c",Pn->entry.LName);
        printf("\n");


        printf("Please enter customer phone number:");
        fflush(stdin);
        scanf("%u",&(Pn->entry.phone));
        printf("\n");

        uint32_t temp_id;
        printf("Please enter customer ID number:");
        fflush(stdin);
        scanf("%u",&temp_id);
        printf("\n");

        /*make sure the new id does not already exists*/
        int32_t position_new;
        uint8_t id_found=1;
        while(id_found)
        {
            id_found=SearchNode(Pl_insert,temp_id,&position_new);
            if(id_found)
            {
                printf("Entered ID already exists\n");
                printf("Please enter customer ID number:");
                fflush(stdin);
                scanf("%u",&temp_id);
                printf("\n");

            }
            else
            {
                Pn->entry.ID=temp_id;
            }
        }

        printf("Please enter customer address:");
        fflush(stdin);
        scanf("%[^\n]%*c",Pn->entry.address);
        printf("\n");

        printf("Please enter customer Date of birth(Day,Month,Year):\n");
        fflush(stdin);
        scanf("%u %u %u",&(Pn->entry.DOB.day),&(Pn->entry.DOB.month),&(Pn->entry.DOB.year));
        printf("\n");

            /*Initialize Deposit with zero*/
        Pn->entry.TotDeposit=0;

            /*Initialize Transact list */
        CreateTList(&(Pn->entry.THistory));

        if(0==pos)/*insert at first*/
        {
                    /*if the stack was empty*/
            Pn->next=Pl_insert->top;
            Pl_insert->top=Pn;
            Pl_insert->size++;
        }
        else /*insert at last or middle*/
        {

           CListNode_t* temp_insert=Pl_insert->top;
           int i;
           for(i=0;i<pos-1;i++) /*stop at the preveous node to pos*/
           {
               temp_insert=temp_insert->next;
           }
           Pn->next=temp_insert->next;
           temp_insert->next=Pn;
           Pl_insert->size++;
        }

    }
}

void CListDelete(CListNode_t** Pe_delete,CList_t * Pl_delete,int32_t pos)
{
    if(pos> Pl_delete->size-1)
    {
        printf("Invalid index for deleting\n");
        *Pe_delete=NULL;
    }
    if(!Pl_delete->size) /*empty list*/
    {
       printf("List is empty can not delete\n");
       *Pe_delete=NULL;
    }
    else if(0==pos)
    {
       *Pe_delete=Pl_delete->top;
       CListNode_t *temp_if=Pl_delete->top->next;
       free(Pl_delete->top);
       Pl_delete->top=temp_if;
       Pl_delete->size--;
    }
    else
    {
        CListNode_t* temp_else=Pl_delete->top;
        CListNode_t* q;
        int j;
        for(j=0;j<pos-1;j++) /*at the end temp points at preveous node*/
        {
            temp_else=temp_else->next;
        }
        *Pe_delete=temp_else->next;
        q=temp_else->next->next;
        free(temp_else->next);
        temp_else->next=q;
        Pl_delete->size--;
    }
}


uint8_t SearchNode(const CList_t* Pl_search,uint32_t CustID,int32_t *position)
{
    CListNode_t* temp_search=Pl_search->top;
    uint8_t found=0;
    *position=-1;
    while(!found && temp_search)
    {

        if(CustID == temp_search->entry.ID)
        {
           found=1;

        }
        else
        {
            found=0;

        }
        temp_search=temp_search->next;
        (*position)++;

    }
    return found;
}


void SwapNodes(CList_t* Pl_swap,int32_t pos1,int32_t pos2)
{
        CListNode_t* temp_swap;
        if(0==pos1)/*we wanto swap first node(0) with second node(1)*/
        {
           temp_swap=Pl_swap->top; /*make temp points to node 0*/
            Pl_swap->top=temp_swap->next; /*make top points to node 1*/
            temp_swap->next=temp_swap->next->next; /*make node 0 point to node 2 */
            Pl_swap->top->next=temp_swap;
        }
        else
        {
            int k;
            CListNode_t* temp=Pl_swap->top;
            for(k=0;k<pos1-1;k++)/* make temp points to node previous to pos1*/
            {
                temp=temp->next;
            }
             temp_swap=temp->next; /*make temp_swap points to pos1*/
             temp->next=temp_swap->next; /*make previous to pos1 point to pos2*/
             temp_swap->next=temp_swap->next->next; /*make pos1 points to next of pos2*/
             temp->next->next=temp_swap; /*make pos2 points to pos1*/
        }
}

void CListTraverse(const CList_t * Pl_traverse)
{
    if(!Pl_traverse->top)
    {
        printf("List is empty\n");
    }
    else
    {
        CListNode_t *temp=Pl_traverse->top;
        //printf("|--------------------|-----------------------|-------------------------|------------------------|---------------|\n");
        //printf("|ID                  |Name                   |Total Deposite           |Address                 |DOB            |\n");
        //printf("|--------------------|-----------------------|-------------------------|------------------------|---------------|\n");

        fflush(stdout);
        while(temp)
        {
        //printf("|%d                  |%s %s                  |%ld                      |%s                       |%d-%d-%d        |\n",temp->entry.ID,temp->entry.FName,temp->entry.LName,temp->entry.TotDeposit,temp->entry.address,temp->entry.DOB.day,temp->entry.DOB.month,temp->entry.DOB.year);
        printf("ID: %d\n",temp->entry.ID);
        printf("Name: %s %s\n",temp->entry.FName,temp->entry.LName);
        printf("Total Deposit:%ld \n",temp->entry.TotDeposit);
        printf("Address: %s \n",temp->entry.address);
        printf("Phone No.: %u \n",temp->entry.phone);
        printf("DOB: %d-%d-%d \n",temp->entry.DOB.day,temp->entry.DOB.month,temp->entry.DOB.year);
        printf("--------------------------------------------------------------------------------\n");
        temp=temp->next;
        }
        printf("\n");
    }
}

void CClearList(CList_t *Pl_clear)
{
    CListNode_t *temp=NULL;
    while(Pl_clear->top)
    {
        temp=Pl_clear->top->next;
        free(Pl_clear->top);
        Pl_clear->top=temp;
    }
    Pl_clear->size=0;
}
