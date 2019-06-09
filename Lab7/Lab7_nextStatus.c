#include "Lab7_nextStatus.h"

void nextStatus()
{
    //读取电梯当前运行状态及当前楼层m(elevatorstate.current_floor)
    int m = eleState.current_floor, flag = 0, f, t;
    SERVELISTNODE *pNode;

    if (eleState.run_state == 'U') //电梯处于上行状态((elevatorstate.run_state == "U")
    {
        //for (pNode = serListHead.head; pNode != NULL || pNode->next_node != NULL; pNode = pNode->next_node) //遍历电梯的服务指令队列
        pNode = serListHead.head;
        while (1)
        {
            if (pNode == NULL)
            {
                break;
            }

            if (pNode == serListHead.head)
            {
                f = pNode->user_call->user_floor;
                t = pNode->user_call->user_target;

                if (serListHead.head->serve_state == 'P')
                {
                    if (f == m + 1)
                    {
                        eleState.run_state = 'S';
                        serListHead.head->serve_state = 'E';
                    }
                    else
                    {
                        if(serListHead.head->next_node == NULL)
                        {
                            break;
                        }
                        flag++;
                    }
                }
                else if (serListHead.head->serve_state == 'E')
                {
                    if (t == m + 1)
                    {
                        eleState.run_state = 'S'; //电梯运行状态改为停止状态
                        pNode = pNode->next_node;
                        free(serListHead.head);
                        serListHead.head = pNode; //删除头节点
                        continue;
                    }
                    else
                    {
                        if(serListHead.head->next_node == NULL)
                        {
                            break;
                        }
                        flag++;
                    }
                }
            }
            else
            {
                flag++;
            }

            if (flag != 0)
            {
                f = pNode->next_node->user_call->user_floor;
                t = pNode->next_node->user_call->user_target;

                if (serListHead.head->serve_state == 'P')
                {
                    if (f == m + 1)
                    {
                        eleState.run_state = 'S';
                        serListHead.head->serve_state = 'E';
                    }
                }
                else if (serListHead.head->serve_state == 'E')
                {
                    if (t == m + 1)
                    {
                        eleState.run_state = 'S'; //电梯运行状态改为停止状态
                        free(pNode->next_node);
                        pNode->next_node = pNode->next_node->next_node; //删除该节点
                    }
                }
            }

            if (pNode->next_node == NULL)
            {
                break;
            }
        }
        eleState.current_floor++; //将当前楼层改为(m + 1)
    }

    else if (eleState.run_state == 'D') //电梯处于下行状态(elevatorstate.run_state == "D")
    {
        //for (pNode = serListHead.head; pNode != NULL || pNode->next_node != NULL; pNode = pNode->next_node) //遍历电梯的服务指令队列
        pNode = serListHead.head;

        while (1)
        {
            if (pNode == NULL)
            {
                break;
            }

            if (pNode == serListHead.head)
            {
                f = pNode->user_call->user_floor;
                t = pNode->user_call->user_target;

                if (serListHead.head->serve_state == 'P')
                {
                    if (f == m - 1)
                    {
                        eleState.run_state = 'S';
                        serListHead.head->serve_state = 'E';
                    }
                    else
                    {
                        if(serListHead.head->next_node == NULL)
                        {
                            break;
                        }
                        flag++;
                    }
                }
                else if (serListHead.head->serve_state == 'E')
                {
                    if (t == m - 1)
                    {
                        eleState.run_state = 'S'; //电梯运行状态改为停止状态
                        pNode = pNode->next_node;
                        free(serListHead.head);
                        serListHead.head = pNode; //删除头节点
                        continue;
                    }
                    else
                    {
                        if(serListHead.head->next_node == NULL)
                        {
                            break;
                        }
                        flag++;
                    }
                }
            }
            else
            {
                flag++;
            }

            if (flag != 0)
            {
                f = pNode->next_node->user_call->user_floor;
                t = pNode->next_node->user_call->user_target;

                if (serListHead.head->serve_state == 'P')
                {
                    if (f == m + 1)
                    {
                        eleState.run_state = 'S';
                        serListHead.head->serve_state = 'E';
                    }
                }
                else if (serListHead.head->serve_state == 'E')
                {
                    if (t == m + 1)
                    {
                        eleState.run_state = 'S'; //电梯运行状态改为停止状态
                        free(pNode->next_node);
                        pNode->next_node = pNode->next_node->next_node; //删除该节点
                    }
                }
            }

            if (pNode->next_node == NULL)
            {
                break;
            }
        }
        eleState.current_floor--; //将当前楼层改为(m - 1)
        //将当前楼层改为(m - 1) elevatorstate.current_floor--;
    }

    else if (eleState.run_state == 'S') //电梯处于静止状态
    {
        if (serListHead.head == NULL)
        {
            return;
        }

        if (serListHead.head->serve_state == 'P')
        {
            if (serListHead.head->user_call->user_floor > m)
            {
                eleState.run_state = 'U';
            }
            else
            {
                eleState.run_state = 'D';
            }
        }

        else if (serListHead.head->serve_state == 'E')
        {
            if (serListHead.head->user_call->user_target > m)
            {
                eleState.run_state = 'U';
            }
            else
            {
                eleState.run_state = 'D';
            }
        }
        //楼层不做改变
    }
}

void showNextStatus()
{
    printf("%5d%5d%5c\n", time, eleState.current_floor, eleState.run_state);
}