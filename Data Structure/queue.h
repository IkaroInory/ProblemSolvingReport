#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode* next;
} node;
typedef struct queue
{
    node* head;
    node* raer;
    int size;
} queue;

void init(queue* q);
void push(queue* q, int val);
void pop(queue* q);
int empty(queue q);
int front(queue q);
int same(queue q);
node* differ(queue q);
void erase(queue* q, node* from, node* to);
void print(queue q);
void clear(queue* q);

void init(queue* q)
{
    q->head = NULL;
    q->raer = NULL;
    q->size = 0;
}
void push(queue* q, int val)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->next = NULL;
    newNode->val = val;
    if (q->size == 0)
    {
        q->head = newNode;
        q->raer = newNode;
    }
    else
    {
        q->raer->next = newNode;
        q->raer = q->raer->next;
    }
    q->size++;
}
void pop(queue* q)
{
    if (q->size != 0)
    {
        node* delNode = q->head;
        q->head = q->head->next;
        free(delNode);
        q->size--;
    }
}
int empty(queue q)
{
    return q.size == 0;
}
int front(queue q)
{
    return q.head->val;
}
int same(queue q)
{
    if (q.size == 0 || q.size == 1)
        return 1;

    int temp = q.head->val;
    node* cur = q.head;
    while (cur != NULL)
    {
        if (cur->val != temp)
            return 0;
        cur = cur->next;
    }
    return 1;
}
node* differ(queue q)
{
    if (q.size == 0 || q.size == 1)
        return NULL;

    int temp = q.head->val;
    node* cur = q.head;
    while (cur != NULL)
    {
        if (cur->val != temp)
            return cur;
        cur = cur->next;
    }
    return NULL;
}
void erase(queue* q, node* from, node* to)
{
    if (to == NULL)
    {
        clear(q);
        return;
    }

    if (from != q->head)
    {
        node* cur = q->head;
        while (cur->next != from)
            cur = cur->next;
        node* del = cur->next;
        while (del != to)
        {
            node* delNode = del;
            cur->next = del->next;
            del = del->next;
            free(delNode);
            q->size--;
        }
    }
    else
    {
        while (q->head != to)
            pop(q);
    }
}
void print(queue q)
{
    node* cur = q.head;
    while (cur != NULL)
    {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
}
void clear(queue* q)
{
    while (q->size != 0)
        pop(q);
}