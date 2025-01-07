#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode* next;
}ListNode;

ListNode* newListNode(int val)
{
    ListNode* node;
    node = (ListNode*)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void insert(ListNode* n0, ListNode* p)
{
    ListNode* q = n0->next;
    p->next = q;
    n0->next = p;
}

void removeOneItem(ListNode* n0)
{
    if(!n0->next)
    {
        return;
    }
    //n0->q->n1
    ListNode* q = n0->next;
    n0->next = q->next;
    free(q);
}

ListNode* access(ListNode* head, int index)
{
    ListNode* p = head;
    for(int i = 0; i < index; i++)
    {
        if(head == NULL)
            return NULL;
        p = p->next;
    }
    return p;
}

int findListNode(ListNode* head, int val)
{
    ListNode* p = head;
    int index = 0;
    while(p)
    {
        if(p->val == val)
            return index;
        p = p->next;
        index++; 
    }
    return -1;
}

int main(void)
{
    ListNode* head = newListNode(1);

    return 0;
}