#include <stdlib.h>
#include <stdio.h>
#include "list.h"


/**
 * @brief Create a new doubly linked linear list
 *
 * @return A pointer to the new list
 */
DblLinkedList *createDblLinkedList()
{
    DblLinkedList *list = (DblLinkedList *) malloc(sizeof(DblLinkedList));
    if (list == NULL)
    {
        printf("Error in createDblLinkedList\n");
        return NULL;
    }
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}


/**
 * @brief Delete a doubly linked linear list
 *
 * @param list The list to delete
 */
void deleteDblLinkedList(DblLinkedList **list)
{
    struct Node *tmp = (*list)->head;
    struct Node *next = NULL;
    while (tmp)
    {
        next = tmp->next;
        deleteNode(tmp);
        tmp = next;
    }
    free(*list);
    (*list) = NULL;
}


/**
 * @brief Adding to the end of a node to a doubly linked linear list
 *
 * @param list The list
 * @param value The value to append
 */
void append(DblLinkedList *list, int value)
{
    struct Node *node = createNode(value);

    if (list->size == 0)
    {
        list->head = node;
        list->tail = node;
    } else
    {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }
    list->size++;
}


/**
 * @brief Adding to the beginning of a node to a doubly linked linear list
 *
 * @param list The list
 * @param value The value to append
 */
void push(DblLinkedList *list, int value)
{
    struct Node *node = createNode(value);

    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
    } else
    {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }
    list->size++;
}


/**
 * @brief Swapping two nodes in a doubly linked linear list
 *
 * @param list The list
 * @param node1 The first node
 * @param node2 The second node
 */
void swapNodes(DblLinkedList *list, struct Node *node1, struct Node *node2)
{
    int tmp = node1->value;
    node1->value = node2->value;
    node2->value = tmp;
}


/**
 * @brief Delete all nodes after a given node
 *
 * @param list The list
 * @param node The node
 */
void deleteNodeAfter(DblLinkedList *list, struct Node *node)
{
    if (node->prev)
    {
        node->prev->next = NULL;
        list->tail = node->prev;
    } else
    {
        list->head = NULL;
        list->tail = NULL;
    }

    struct Node *currentNode = node;
    struct Node *nextNode;

    while (currentNode != NULL)
    {
        nextNode = currentNode->next;
        deleteNode(currentNode);
        list->size--;
        currentNode = nextNode;
    }
}


void deleteNodeBefore(DblLinkedList *list, struct Node *node)
{
    if (node->next)
    {
        node->next->prev = NULL;
        list->head = node->next;
    } else
    {
        list->head = NULL;
        list->tail = NULL;
    }

    struct Node *currentNode = node;
    struct Node *prevNode;

    while (currentNode != NULL)
    {
        prevNode = currentNode->prev;
        deleteNode(currentNode);
        list->size--;
        currentNode = prevNode;
    }
}


/**
 * @brief Print a doubly linked linear list from the head
 *
 * @param list The list
 */
void printListFromHead(DblLinkedList *list)
{
    printf("Printing list from head\n");
    struct Node *tmp = list->head;
    do
    {
        printf("%d  ", tmp->value);
        tmp = tmp->next;
    } while (tmp != NULL);
    printf("\n");
}


/**
 * @brief Print a doubly linked linear list from the tail
 *
 * @param list The list
 */
void printListFromTail(const DblLinkedList *list)
{
    printf("Printing list from tail\n");
    struct Node *tmp = list->tail;
    do
    {
        printf("%d  ", tmp->value);
        tmp = tmp->prev;
    } while (tmp != NULL);
    printf("\n");
}


/**
 * @brief Search a node in a doubly linked linear list
 *
 * @param list The list
 * @param value The value
 *
 * @return Found node or NULL if not found
 */
struct Node *searchNode(DblLinkedList *list, int value)
{
    struct Node *tmp = list->head;
    do
    {
        if (tmp->value == value)
            return tmp;
        tmp = tmp->next;
    } while (tmp != NULL);
    return NULL;
}