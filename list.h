#ifndef PRACT11_LIST_H
#define PRACT11_LIST_H

#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
} ;


typedef struct DblLinkedList
{
    size_t size;
    struct Node *head;
    struct Node *tail;
} DblLinkedList;


struct Node *createNode(int value);
void deleteNode(struct Node *node);

DblLinkedList *createDblLinkedList();
void deleteDblLinkedList(DblLinkedList **list);
void append(DblLinkedList *list, int value);
void push(DblLinkedList *list, int value);
void swapNodes(DblLinkedList *list, struct Node *node1, struct Node *node2);
void deleteNodeAfter(DblLinkedList *list, struct Node *node);
void deleteNodeBefore(DblLinkedList *list, struct Node *node);
void printListFromHead(DblLinkedList *list);
void printListFromTail(const DblLinkedList *list);
struct Node *searchNode(DblLinkedList *list, int value);

#endif //PRACT11_LIST_H
