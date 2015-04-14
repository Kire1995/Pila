#include "Node.h"
typedef struct list{
    Node * head;
    Node * tail;
    int length;
}List;

List * newList(void);
void addLeft(List * l, int val);
void addRight(List * l, int val);
Node * search(Node * l, int val);
void removeNode(List * l, int val);
int getMin(List * l);
int getMax(List * l);
void push(List * l, int val);
int pop(List * l);


