#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "generic.h"

void LinkedListMenu()
{
    int ch;
    int d;
    void *dt;
    Generic_LinkedList L;
    GLL_init(&L);

    while (1)
    {
        printf("\n\nMENU\n\n");
        printf("(0) Create a Test List \n");
        printf("(1) Add At Head\n");
        printf("(2) Add At End\n");
        printf("(3) Delete At Head\n");
        printf("(4) Delete At End\n");
        printf("(5) Display the List\n");
        printf("(6) Size of the List\n");
        printf("(7) Delete List\n");
        printf("( PRESS 8 TO EXIT SUB MENU ) ");

        printf("\n\n");
        printf("Enter The choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 0:
            for (int i = 1; i <= 10; i++)
            {
                d = i;
                GLL_AddatTail(&L, &d, sizeof(int));
            }
            break;

        case 1:
            printf("Enter the data to be added : ");
            scanf("%d", &d);
            GLL_AddatHead(&L, &d, sizeof(int));
            break;

        case 2:
            printf("Enter the data to be added : ");
            scanf("%d", &d);
            GLL_AddatTail(&L, &d, sizeof(int));
            break;

        case 3:
            dt = GLL_DeleteAtHead(&L);
            printf("The element is : ");
            DisplayINT(dt);
            printf("\n");
            free(dt);
            break;

        case 4:
            dt = GLL_DeleteAtTail(&L);
            printf("The element is : ");
            DisplayINT(dt);
            printf("\n");
            free(dt);
            break;

        case 5:
            GLL_Display(&L, DisplayINT);
            break;

        case 6:
            d = GLL_Length(&L);
            printf("The size of the stack is : %d", d);
            break;

        case 7:
            GLL_DeleteList(&L);
            break;

        case 8:
            GLL_DeleteList(&L);
            return;
            break;

        default:
            break;
        }
    }
}

void DisplayDOUBLE(void *a)
{
    double *f = (double *)a;
    double b = *f;
    printf("%lf", b);
}

void StackMenu()
{
    int ch;
    Generic_Stack st;
    Gstack_init(&st);
    int d;
    void *dt;

    while (1)
    {
        printf("\n\nMENU\n\n");
        printf("(0) Create a Test Stack \n");
        printf("(1) Push an element\n");
        printf("(2) Pop an element\n");
        printf("(3) Peek the Stack\n");
        printf("(4) Size of Stack\n");
        printf("(5) Display Stack\n");
        printf("(6) Is Stack Empty\n");
        printf("(7) Delete Stack\n");
        printf("( PRESS 8 TO EXIT SUB MENU ) ");

        printf("\n\n");
        printf("Enter The choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 0:
            for (int i = 0; i < 10; i++)
            {
                d = i;
                push_Gstack(&st, &d, sizeof(int));
            }
            break;

        case 1:
            printf("Enter the data to be added : ");
            scanf("%d", &d);
            push_Gstack(&st, &d, sizeof(int));
            break;

        case 2:
            dt = pop_Gstack(&st);
            printf("The element is : ");
            DisplayINT(dt);
            printf("\n");
            free(dt);
            break;

        case 3:
            dt = peek_Gstack(&st);
            printf("The element is : ");
            DisplayINT(dt);
            printf("\n");
            free(dt);
            break;

        case 4:
            d = Size_Gstack(&st);
            printf("The size of the stack is : %d", d);
            break;

        case 5:
            Display_Gstack(&st, DisplayINT);
            break;

        case 6:
            d = isEmpty_Gstack(&st);
            if (d)
                printf("YES\n");
            else
                printf("NO\n");
            break;

        case 7:
            Delete_Gstack(&st);
            break;

        case 8:
            Delete_Gstack(&st);
            return;
            break;

        default:
            break;
        }
    };
}

void QueueMenu()
{
    int ch;
    Generic_Queue Qu;
    int d;
    GQueue_init(&Qu);
    void *dt;

    while (1)
    {
        printf("\n\nMENU\n\n");
        printf("(0) Create a Test Queue \n");
        printf("(1) Enqueue an element\n");
        printf("(2) Dequeue an element\n");
        printf("(3) GetFront the Queue\n");
        printf("(3) GetRear the Queue\n");
        printf("(5) Display Queue\n");
        printf("(6) Is Queue Empty\n");
        printf("(7) Delete Queue\n");
        printf("(8) Size of Queue\n");
        printf("( PRESS 9 TO EXIT SUB MENU ) ");

        printf("\n\n");
        printf("Enter The choice : ");
        scanf("%d", &ch);

        switch (ch)
        {

        case 0:
            for (int i = 0; i < 10; i++)
            {
                d = i;
                Enqueue_Gqueue(&Qu, &d, sizeof(int));
            }
            break;

        case 1:
            printf("Enter the data to be added : ");
            scanf("%d", &d);
            Enqueue_Gqueue(&Qu, &d, sizeof(int));
            break;

        case 2:
            dt = Dequeue_Gqueue(&Qu);
            printf("The element is : ");
            DisplayINT(dt);
            printf("\n");
            free(dt);
            break;

        case 3:
            dt = GetFront_Gqueue(&Qu);
            printf("The element is : ");
            DisplayINT(dt);
            printf("\n");
            free(dt);
            break;

        case 4:
            dt = GetRear_Gqueue(&Qu);
            printf("The element is : ");
            DisplayINT(dt);
            printf("\n");
            free(dt);
            break;

        case 5:
            Display_Gqueue(&Qu, DisplayINT);
            break;

        case 6:
            d = IsEmpty_GQueue(&Qu);
            if (d)
                printf("YES\n");
            else
                printf("NO\n");
            break;

        case 7:
            Delete_GQueue(&Qu);
            break;

        case 8:
            d = Size_Gqueue(&Qu);
            printf("The size of the Queue is : %d", d);
            break;

        case 9:
            Delete_GQueue(&Qu);
            return;

        default:
            break;
        }
    }
};

int main()
{

    int ch;
    while (1)
    {
        printf("\n\n------Test Program menu ------\n\n");
        printf("Select The Data Structure you want to test\n");
        printf("(1) LinkedList\n");
        printf("(2) Stack\n");
        printf("(3) Queue\n");
        printf("\n\nPress 0 to Exit the program \n");

        printf("\nEnter Your Choice Here : ");
        scanf("%d", &ch);

        printf("\n\n---------------------\n\n");

        switch (ch)
        {
        case 0:
            exit(0);
            break;

        case 1:
            LinkedListMenu();
            break;

        case 2:
            StackMenu();
            break;

        case 3:
            QueueMenu();
            break;

        default:
            printf("INVALID SELECTION\nTRY AGAIN\n");
            break;
        }
    }

    getch();
    return 0;
}