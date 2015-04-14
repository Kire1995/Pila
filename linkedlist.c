#include "linkedlist.h"
#include <stdlib.h>

List *
newList(void)
{
    List * l = (List*) malloc(sizeof(List));
    l->head = NULL;
    l->tail = NULL;
    l->length = 0;
    return l;
}

void 
addLeft(List * l, int val)
{
    Node * new = newNode(val);
    l->length++;
    if(l->length == 0)
        l->head = l->tail = new;
    l->head->prev = new;
    new->next = l->head;
    l->head = new;    
}

void 
addRight(List * l, int val)
{
    Node * new = newNode(val);
    l->length++;
    if(l->length == 0)
        l->head = l->tail = new;
    l->tail->next = new;
    new->prev = l->tail;
    l->tail = new;
}

Node *
search(Node * n, int val)
{
    if(n == NULL)
        return NULL;
    if(n->value == val)
        return n;
    return search(n->next, val);
}

void
removeNode(List * l, Node * n)
{
    if(l->length == 0)
        return;
    Node * aux = search(l->head,n->value);
    if(l->head->value == aux->value)
    {
        l->head->next->prev = NULL;
        l->head = l->head->next;
    }
    else if(l->tail->value == aux->value)
    {
        l->tail->prev->next = NULL;
        l->tail = l->tail->prev;
    }
    else
    {
        aux->prev->next = aux->next;
        aux->next->prev = aux->prev;
    }
    free(aux);
}

int
getMin(List * l)
{
    int min = 1000000;
    if(l->length == 0)
        return -1;
    while(l)
    {   
        Node * aux = l->head;
        if(aux->value < min)
            min = aux->value;
        aux = aux->next;
    }
    return min;
}

int
getMax(List * l)
{
    int max = 0;
    if(l->length == 0)
        return -1;
    while(l)
    {
        Node * aux = l->head;
        if(aux->value > max)
            max = aux->value;
        aux = aux->next;
    }
    return max;
}

void
push(List * l, int val)
{
    addleft(l,val);
}

int 
pop(List * l)
{
    if(l->length == 0)
        return -1;
    int x = l->head->value;
    Node*aux = l->head;
    l->head = l->head->next;
    l->length-=1;
    free(aux);
    return x;
}
