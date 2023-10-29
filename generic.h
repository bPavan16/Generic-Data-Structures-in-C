#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    void *data;
    struct Node *next;
} Node;

typedef struct Generic_LinkedList
{
    Node *head;
    Node *tail;
    int size;
} Generic_LinkedList;

typedef struct Generic_Stack
{
    Node *top;
    int size;
} Generic_Stack;

typedef struct Generic_Queue
{
    Node *front;
    Node *rear;
    int size;
} Generic_Queue;

void copyData(void *Source, void *Destination, int DataSize)
{
    char *p = (char *)Source;
    char *q = (char *)Destination;

    for (int i = 0; i < DataSize; i++)
    {
        *q = *p;
        p++;
        q++;
    }
}

Node *Create_GNode(void *data, int DataSize)
{
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    // if (newNode == NULL)
    // {
    //     perror("Memory Full\n");
    //     return NULL;
    // }

    newNode->data = malloc(DataSize);
    copyData(data, newNode->data, DataSize);
    newNode->next = NULL;
    return newNode;
}

void GLL_init(Generic_LinkedList *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void GLL_AddatHead(Generic_LinkedList *list, void *data, int DataSize)
{
    Node *newNode = Create_GNode(data, DataSize);
    list->size++;
    newNode->next = list->head;
    if (list->tail == NULL)
        list->tail = newNode;
    list->head = newNode;
}

void GLL_AddatTail(Generic_LinkedList *List, void *data, int DataSize)
{
    Node *newNode = Create_GNode(data, DataSize);
    List->size++;
    newNode->next = NULL;
    if (List->head == NULL)
    {
        List->head = newNode;
        List->tail = newNode;
        return;
    }

    List->tail->next = newNode;
    List->tail = newNode;
}

void GLL_Display(Generic_LinkedList *List, void (*DisplayDatatype)(void *))
{

    if (List->head == NULL)
    {
        printf("The Generic_LinkedList is Empty\n");
        return;
    }

    Node *curr = List->head;
    while (curr)
    {
        DisplayDatatype(curr->data);
        printf(" --> ");
        curr = curr->next;
    }
    printf("\n");
}

void DisplayINT(void *data)
{
    int *a = (int *)data;
    printf("%d", *a);
}

void *GLL_DeleteAtHead(Generic_LinkedList *List)
{
    if (List->head == NULL)
    {
        printf("The Generic_LinkedList is already Empty and NULL is returned\n");
        return NULL;
    }
    else
    {
        Node *curr = List->head;
        List->head = List->head->next;
        if (List->head == NULL)
        {
            List->tail = NULL;
        }

        void *ele = curr->data;
        free(curr);
        List->size--;

        return ele;
    }
}

void *GLL_DeleteAtTail(Generic_LinkedList *List)
{
    if (List->head == NULL)
    {
        printf("The Generic_LinkedList is already Empty and NULL is returned \n");
        return NULL;
    }
    else
    {
        Node *curr = List->head;
        Node *prev = NULL;

        if (List->head == List->tail)
        {
            void *ele = curr->data;
            free(curr);
            List->head = NULL;
            List->tail = NULL;
            List->size--;
            return ele;
        }

        while (curr->next)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = NULL;
        List->tail = prev;

        void *ele = curr->data;
        free(curr);
        List->size--;
        return ele;
    }
}

void GLL_DeleteList(Generic_LinkedList *List)
{
    Node *curr = List->head;
    Node *temp;
    while (curr)
    {
        temp = curr;
        curr = curr->next;
        free(temp->data);
        free(temp);
    }

    List->head = NULL;
    List->tail = NULL;
    List->size = 0;
    printf("The Generic_LinkedList is Deleted\n");
}

int GLL_Length(Generic_LinkedList *List)
{
    return List->size;
}

void Gstack_init(Generic_Stack *stack)
{
    stack->top = NULL;
    stack->size = 0;
}

int isEmpty_Gstack(Generic_Stack *S)
{
    if (S->top == NULL && S->size == 0)
        return 1;
    else
        return 0;
}

void push_Gstack(Generic_Stack *stack, void *data, int DataSize)
{
    Node *temp = Create_GNode(data, DataSize);
    temp->next = stack->top;
    stack->top = temp;
    stack->size++;
}

void *pop_Gstack(Generic_Stack *stack)
{
    if (isEmpty_Gstack(stack))
    {
        printf("Generic Stack is Empty, NULL is returned \n");
        return NULL;
    }

    Node *curr = stack->top;
    void *D = curr->data;
    stack->top = stack->top->next;
    free(curr);
    stack->size--;
    return D;
}


void *peek_Gstack(Generic_Stack *stack)
{
    return stack->top->data;
}

void Display_Gstack(Generic_Stack *stack, void (*DisplayDatatype)(void *))
{
    if (isEmpty_Gstack(stack))
    {
        printf("Generic Stack is Empty\n");
        return;
    }

    Node *curr = stack->top;
    while (curr)
    {
        DisplayDatatype(curr->data);
        printf("\n");
        curr = curr->next;
    }
    printf("\n");
}

int Size_Gstack(Generic_Stack *S)
{
    return S->size;
}

void Delete_Gstack(Generic_Stack *S)
{
    Node *curr = S->top;
    Node *temp;
    while (curr)
    {
        temp = curr;
        curr = curr->next;
        free(temp->data);
        free(temp);
    }

    S->top = NULL;
    S->size = 0;

    printf("The Generic_Stack is Deleted\n");
}

void GQueue_init(Generic_Queue *queue)
{
    queue->rear = NULL;
    queue->front = NULL;
    queue->size = 0;
}

void Enqueue_Gqueue(Generic_Queue *queue, void *data, int DataSize)
{
    Node *newNode = Create_GNode(data, DataSize);
    if (queue->rear == NULL && queue->front == NULL)
    {
        queue->rear = queue->front = newNode;
    }
    else
    {
        newNode->next = NULL;
        queue->rear->next = newNode;
        queue->rear =newNode;
    }
    queue->size++;
}

void *Dequeue_Gqueue(Generic_Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("The Generic Queue is Empty and NULL is returned\n ");
        return NULL;
    }

    void *D;
    Node *curr = queue->front;
    D = curr->data;

    if (queue->front == queue->rear)
    {

        queue->front = queue->rear = NULL;
        free(curr);
        queue->size--;
        return D;
    }

    queue->front = queue->front->next;
    free(curr);
    queue->size--;
    return D;
}

void *GetFront_Gqueue(Generic_Queue *queue)
{
    return queue->front->data;
}

void *GetRear_Gqueue(Generic_Queue *queue)
{
    return queue->rear->data;
}

int Size_Gqueue(Generic_Queue *queue)
{
    return queue->size;
}

void Display_Gqueue(Generic_Queue *queue, void (*DisplayDatatype)(void *))
{
    if (queue->front == NULL)
    {
        printf("The Generic Queue is Empty\n");
        return;
    }

    Node *curr = queue->front;
    while (curr)
    {
        DisplayDatatype(curr->data);
        printf("\n");
        curr = curr->next;
    }
    printf("\n");
}

int IsEmpty_GQueue(Generic_Queue *queue)
{
    if (queue->front == NULL && queue->rear == NULL)
        return 1;
    else
        return 0;
}

void Delete_GQueue(Generic_Queue *queue)
{
    Node *curr = queue->front;
    Node *temp;
    while (curr)
    {
        temp = curr;
        curr = curr->next;
        free(temp->data);
        free(temp);
    }

    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;

    printf("The Generic_Queue is Deleted\n");
}

