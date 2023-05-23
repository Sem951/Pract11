#include <stdlib.h>
#include "list.h"


/**
 * Create a new node
 *
 * @param value The value of the node
 *
 * @return A pointer to the new node
 */
struct Node *createNode(int value)
{
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    if (node == NULL)
        return NULL;
    node->value = value;
    node->next = NULL;
    node->prev = NULL;

    return node;
}


/**
 * @brief Delete a node (free the memory)
 *
 * @param node The node to delete
 */
void deleteNode(struct Node *node)
{
    free(node);
}
