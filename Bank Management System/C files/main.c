#include"BM1Header.h"
#include "CListFunctions.h"
/*------------------------------------------Main--------------------------------*/
int main()
{
    int8_t state=1;

    printf("\t\t\tWelcome to Bank Management System\n");

    CList_t Customers;
    CreateCList(&Customers);

    printf("\t\t\tSystem Initialized Successfully\n");


    while(state)
    {
        printf("\n");
        printf("\t\t\t\t\tMain Meneu\n");
        state=MainMenue(&Customers);
    }


    return 0;
}
