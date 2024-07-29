#ifndef LINKED_LIST_C
#define LINKED_LIST_C

#include <stdlib.h>
#include <stdio.h>

typedef struct LinkedList
{
    int *data;
    int size;
    int pos;
    LinkedList *next;
} LinkedList;

LinkedList
LinkedListInit(int size)
{
    LinkedList linked_list;
    linked_list.data = malloc(size * sizeof(*(linked_list.data)));
    if (linked_list.data == NULL)
    {
        printf("Error data allocation for a linked list\n");
    }
    linked_list.size = size;
    linked_list.pos  = 0;
    linked_list.next = NULL;
}

void
LinkedListFree(LinkedList *linked_list)
{
    for (;;)
    {
        if (linked_list -> data)
        {
            free(linked_list -> data);
        }
        linked_list -> pos = 0;

        if (linked_list -> next == NULL)
        {
            break;
        }
        else
        {
            linked_list = linked_list -> next;
        }
    }
}

void
LinkedListAppend(LinkedList *linked_list, int value)
{
    while (linked_list -> pos == (linked_list -> size) - 1)
    {
        if (linked_list -> next)
        {
            linked_list = linked_list -> next;
        }
        else
        {
            // allocate new sublist and make linked_list point to this sublist
        }
    }

    // here I expect linked list to be correctly initialized

    *((linked_list -> data) + (linked_list -> pos)) = value;
    (linked_list -> pos)++;
}

#endif // LINKED_LIST_C