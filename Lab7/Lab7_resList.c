#include "Lab7_resList.h"

void addResList(USERCALL *call)
{
    RESPONSELISTNODE *newnode;
    newnode = malloc(sizeof(RESPONSELISTNODE));
    newnode->user_call = call;

    if(resListHead.head == NULL)
    {
        resListHead.head = newnode;
        resListHead.tail = resListHead.head;
        newnode->next_node = NULL;
    }
    else
    {
        resListHead.tail->next_node = newnode;
        resListHead.tail = newnode;
        resListHead.tail->next_node = NULL;
    }
}

/*删除头节点 */
void delResList(USERCALL *call)
{
    if(resListHead.head == resListHead.tail)
    {
        resListHead.head = NULL;
        resListHead.tail = NULL;
    }
    else
    {
        RESPONSELISTNODE *temNode;
        
        temNode = resListHead.head->next_node;
        free(resListHead.head);
        resListHead.head = temNode;
    }
}