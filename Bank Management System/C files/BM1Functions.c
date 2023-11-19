#include"BM1Header.h"
#include "CListFunctions.h"
#include "TransactHeader.h"
uint8_t MainMenue(CList_t* Pl_menue)
{
    uint8_t a,flage;
    uint32_t len; //remove
    printf("To add new Account press 1\n");
    printf("To Delete account press 2\n");
    printf("To edit customer data press 3\n");
    printf("To view customer List sorted Alphabetically press 4\n");
    printf("To perform a transact process press 5\n");
    printf("To view transact list press 6 \n");
    printf("To view customer list press 7\n");
    printf("To get customer list size press 8\n");
    printf("To clear customer list press 9\n");//remove


    printf("To exit press 0 \n");
    scanf("%u",&a);
    switch (a)
    {
        case 1:
            NewAccount(Pl_menue);
            flage=1;
            break;
        case 2:
            DeleteAccount(Pl_menue);
            flage=1;
            break;
        case 3:
            CustomerEdit(Pl_menue);
            flage=1;
            break;
        case 4:
            CustomerList(Pl_menue);
            flage=1;
            break;
        case 5:
            Transact(Pl_menue);
            flage=1;
            break;
        case 6:
            TransactList(Pl_menue);
            flage=1;
            break;
        case 7:
            CListTraverse(Pl_menue);
            flage=1;
            break;
        case 8:
            len=CListSize(Pl_menue);
            printf("You currently have %d customers.\n",len);
            flage=1;
            break;
        case 9:
            CClearList(Pl_menue);
            flage=1;
            break;

        case 0:
            flage=0;
            break;

        default:
            printf("Please enter a valid number\n");
    }
    return flage;
}


void NewAccount(CList_t* Pl_new)
{
    CListInsert(Pl_new,0);
}



void DeleteAccount(CList_t* Pl_delete)
{
    uint32_t CustID_delete;
    int32_t position_del;
    uint8_t found_del;
    CListNode_t*Pn_delete=NULL;

    printf("Please Enter the ID of the customer to be deleted:");
    scanf("%u",&CustID_delete);

    found_del=SearchNode(Pl_delete,CustID_delete,&position_del);
    if(0==found_del)
    {
        printf("Customer not found.Invalid ID\n");
    }
    else
    {
       CListDelete(&Pn_delete,Pl_delete,position_del);
       printf("Customer with Name: %s %s and",Pn_delete->entry.FName,Pn_delete->entry.LName);
       printf(" ID: %u is deleted\n",CustID_delete);

    }
}





void CustomerEdit(CList_t* Pl_edit)
{
    uint32_t CustID_edit;
    int32_t position_edit;
    uint32_t flage_edit;
    uint8_t while_flage=1;
    printf("Please Enter the ID of customed to be edited:");
    scanf("%u",&CustID_edit);

    flage_edit=SearchNode(Pl_edit,CustID_edit,&position_edit);
    if(0==flage_edit)
    {
        printf("Customer not found.Invalid ID\n");
    }
    else
    {
        CListNode_t* Pn_edit=Pl_edit->top;
        int i;
        for(i=0;i<position_edit;i++)
        {
            Pn_edit=Pn_edit->next;
        }
        while(while_flage)
        {
            uint8_t c;
            printf("-----------------Edit Customer Meneu---------------\n");
            printf("\nTo edit customer name,Please Press 1\n");
            printf("To edit customer address,Please Press 2\n");
            printf("To edit customer phone,Please Press 3\n");
            printf("To edit customer DOB,Please Press 4\n");
            printf("To return to main menue press 0\n");

            scanf("%u",&c);

            switch(c)
            {
                case 1:
                    printf("Please Enter New First Name:");
                    fflush(stdin);
                    scanf("%[^\n]%*c",Pn_edit->entry.FName);
                    printf("\n");
                    printf("Please Enter New Last Name:");
                    scanf("%[^\n]%*c",Pn_edit->entry.LName);
                    fflush(stdin);
                    printf("\n");
                    while_flage=1;
                    break;
                case 2:
                    printf("Please Enter new Address:");
                    fflush(stdin);
                    scanf("%[^\n]%*c",Pn_edit->entry.address);
                    printf("\n");
                    while_flage=1;
                    break;
                case 3:
                    printf("Please enter a new phone number:");
                    fflush(stdin);
                    scanf("%u",&(Pn_edit->entry.phone));
                    printf("\n");
                    while_flage=1;
                    break;
                case 4:
                    printf("Please enter new Date of birth(Day,Month,Year):");
                    fflush(stdin);
                    scanf("%u %u %u",&(Pn_edit->entry.DOB.day),&(Pn_edit->entry.DOB.month),&(Pn_edit->entry.DOB.year));
                    printf("\n");
                    while_flage=1;
                    break;
                case 0:
                    while_flage=0;
                    break;
                default:
                    printf("please enter a valid number\n");
                    while_flage=1;
                    break;
            }

        }
    }
}




void CustomerList(CList_t* Pl_sort)
{
    CListNode_t* Pi;
    CListNode_t*Pj;
    uint32_t itr;
    int32_t pos1_sort;
    int32_t pos2_sort;

    for(itr=0; itr < Pl_sort->size;itr++) /*iterate on the list size times at the end of each iteration the last element is positioned at its right place*/
    {


        pos1_sort=0;
        for(pos2_sort=1; pos2_sort < Pl_sort->size-itr ;pos2_sort++)
        {

            Pi=Pl_sort->top;
            int k;
            for(k=0;k<pos2_sort-1;k++) /*make pi point to pos1*/
            {
                Pi=Pi->next;
            }
            Pj=Pi->next;
          if(strcmp(Pi->entry.FName,Pj->entry.FName)>0)
          {

              SwapNodes(Pl_sort,pos1_sort,pos2_sort);
          }
          else if(0==strcmp(Pi->entry.FName,Pj->entry.FName)) /*same first name*/
          {
                if(strcmp(Pi->entry.LName,Pj->entry.LName)>0)
                {

                    SwapNodes(Pl_sort,pos1_sort,pos2_sort);
                }
                else if(0==strcmp(Pi->entry.LName,Pj->entry.LName))/*same last name*/
                {
                    if(Pi->entry.ID > Pj->entry.ID) /*arrange depending on id*/
                    {
                        SwapNodes(Pl_sort,pos1_sort,pos2_sort);
                    }
                    else
                    {
                        /*Already arranged according to id,
                            Do nothing
                        */
                    }
                }
                else
                {
                    /*Already arranged according to LName,
                        Do Nothing
                    */
                }
          }
          else
          {
            /*Already arranged according to FName,
                Do Nothing
            */
          }
          pos1_sort++;
        }
    }
    printf("\t\t\t\t\tSorted Customer List\n");
    CListTraverse(Pl_sort);
}



void Transact(CList_t* Pl_transact)
{
    uint32_t CustID_transact;
    int32_t position_transact;
    uint8_t flage_transact;
    printf("Please Enter the ID of customer:");
    scanf("%u",&CustID_transact);

    flage_transact=SearchNode(Pl_transact,CustID_transact,&position_transact);
    if(0==flage_transact)
    {
        printf("Customer not found.Invalid ID\n");
    }
    else
    {
        TListInsert(Pl_transact,position_transact);
    }
}



void TransactList(CList_t* Pl_TransactList)
{
    uint32_t CustID_TransactList;
    int32_t position_TransactList;
    uint8_t flage_TransactList;
    printf("Please Enter the ID of customer:");
    scanf("%u",&CustID_TransactList);

    flage_TransactList=SearchNode(Pl_TransactList,CustID_TransactList,&position_TransactList);
    if(0==flage_TransactList)
    {
        printf("Customer not found.Invalid ID\n");
    }
    else
    {
        TListTraverse(Pl_TransactList,position_TransactList);
    }
}
