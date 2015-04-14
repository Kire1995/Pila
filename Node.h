#include <stdlib.h>
typedef struct _node {
    int value;
    struct _node * next;
    struct _node * prev;
}Node;
/*Constructor de Nodos*/
Node * newNode(int val);
Node * newNode(int val){
    Node * new = (Node*) malloc(sizeof(Node));
    new->value = val;
    new->next = NULL;
    new->prev = NULL;
    return new;
}
