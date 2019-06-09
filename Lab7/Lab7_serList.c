#include "Lab7_serList.h"

/*将指令添加到服务队列末端 */
void addSerList(USERCALL *call)
{
    SERVELISTNODE *newnode;
    newnode = (SERVELISTNODE *)malloc(sizeof(SERVELISTNODE));
    newnode->user_call = call;

    if(serListHead.head == NULL)
    {
        serListHead.head = newnode;
        serListHead.tail = serListHead.head;
        newnode->next_node = NULL;
    }
    else
    {
        serListHead.tail->next_node = newnode;
        serListHead.tail = newnode;
        serListHead.tail->next_node = NULL;
    }
}

/*用于修改 末 节点的服务状态*/
void setSerState(char c)
{
    serListHead.tail->serve_state = c;
}