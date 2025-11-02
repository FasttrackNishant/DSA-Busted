#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node * next;
} node_t ;

void printLinkedList(node_t * head)
{
    node_t * temp = head;
    while(temp)
    {
        printf("%d",temp->data);
        temp = temp ->next;
    }
}

int main()
{
    node_t * head = NULL;

    head = (node_t *) malloc(sizeof(node_t));

    head -> data = 123;
    head ->next = NULL;

    node_t * first = (node_t*)malloc(sizeof(node_t));
    first->data = 201;
    first->next = NULL;
    head->next = first;
 

    printLinkedList(head);
    return 0;

}