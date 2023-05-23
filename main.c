#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include "HelperFuncs.h"

int main()
{
    bool isLogged = false;
    int menuChoice, tempChoice, x, x2;
    struct Node *temp = NULL, *temp2 = NULL;


    DblLinkedList *list = createDblLinkedList();
    printf("The list is created automatically at the start\n");
    system("pause");

    while (1)
    {
        system("cls");
        printf("Menu\n"
               "1. Append a node to the list\n"
               "2. Delete a node from the list\n"
               "3. Swap two nodes in the list\n"
               "4. Print the list\n"
               "0. Exit\n");
        menuChoice = range_scan(0, 4);
        switch (menuChoice)
        {
            case 1:
                system("cls");
                printf("Adding a node to the list\n"
                       "1. Adding node to the end list\n"
                       "2. Adding node to the beginning list\n");
                tempChoice = range_scan(1, 2);

                printf("Enter the value: ");
                x = scan_safe_func_int();

                if (tempChoice == 1)
                    append(list, x);
                else
                    push(list, x);
                break;
            case 2:
                if (list->size == 0)
                {
                    printf("There are no elements in the list\n");
                    break;
                }

                system("cls");
                printf("Deleting a node from the list\n"
                       "1. Deleting node after a given node\n"
                       "2. Deleting node before a given node\n");
                tempChoice = range_scan(1, 2);

                isLogged = false;
                do{
                    if (isLogged++)
                        printf("Node not found, try again\n");
                    printf("Enter the value: ");
                    x = scan_safe_func_int();
                    temp = searchNode(list, x);
                } while (temp == NULL);

                if (tempChoice == 1)
                    deleteNodeAfter(list, searchNode(list, x));
                else
                    deleteNodeBefore(list, searchNode(list, x));
                break;
            case 3:
                system("cls");
                printf("Swapping two nodes in the list\n");

                if (list->size < 2)
                {
                    printf("There are too few elements for swap in the list\n");
                    break;
                }

                isLogged = false;
                temp = NULL;
                temp2 = NULL;

                do
                {
                    if (isLogged++)
                        printf("Incorrect input, try again\n");
                    printf("Enter the value 1: ");
                    x = scan_safe_func_int();
                    temp = searchNode(list, x);
                } while (temp == NULL);

                isLogged = false;
                do
                {
                    if (isLogged++)
                        printf("Node not found, try again\n");
                    printf("Enter the value 2: ");
                    x2 = scan_safe_func_int();
                    temp2 = searchNode(list, x2);
                } while (temp2 == NULL);

                swapNodes(list, temp, temp2);
                break;
            case 4:
                if (list->size == 0)
                {
                    printf("The list is empty\n");
                    break;
                }
                system("cls");
                printf("Printing the list\n"
                       "1. Printing the list from head\n"
                       "2. Printing the list from tail\n");
                tempChoice = range_scan(1, 2);

                system("cls");
                if (tempChoice == 1)
                    printListFromHead(list);
                else
                    printListFromTail(list);
                break;
            case 0:
                deleteDblLinkedList(&list);
                return 0;
            default: // сюда мы не зайдём, так как у нас menuChoice проверяется функцией range_scan
                printf("Incorrect input, try again\n");
        }
        system("pause");
    }
}