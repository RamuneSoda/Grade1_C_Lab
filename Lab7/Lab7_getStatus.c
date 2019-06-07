#include "Lab7_getStatus.h"

void getStatus()
{
    for (int i = 0; i < num; i++)
    {
        if (usercall[i].call_time == time)
        {
            addResList(&usercall[i]); //将指令加入待响应指令队列
        }
    }

    if (serListHead.head == NULL) //电梯不在提供服务
    {
        /*检查待响应指令队列responselist*/
        if (resListHead.head != NULL) //队列不为空
        {
            addSerList(resListHead.head->user_call); //从 待响应指令队列取出第一条指令,加入到 电梯的服务指令队列
            delResList(resListHead.head->user_call); //将该指令从待响应序列中删除

            int f;

            f = serListHead.head->user_call->user_floor; //取出该指令的用户所在楼层f

            if (f == eleState.current_floor) //f == 电梯所在楼层(elevatorstate.current_floor)
            {
                serListHead.head->serve_state = 'E'; //服务状态(servelistnode.serve_state)设置为服务中(E)
            }
            else
            {
                serListHead.head->serve_state = 'P'; //服务状态(servelistnode.serve_state)设置为服务前(P)
            }
            anotherUser(); //遍历待响应指令队列，判断能否响应其他用户的指令，若可以，将其状态设置为“服务前”
        }
    }
}

void anotherUser()
{
    //读取电梯当前运行状态(elevatorstate.run_state)以及当前楼层m
    int m, f, t, flag = 0;
    RESPONSELISTNODE *pNode;
    m = eleState.current_floor;

    if (eleState.run_state == 'U') //电梯运行状态为上行(U)
    {
        for (pNode = resListHead.head; pNode != NULL && pNode->next_node != NULL; pNode = pNode->next_node) //遍历待响应指令序列(responselist)
        {
            //取出当前指令用户所在楼层(responselist.user_call.user_floor)f与目标楼层t(responselist.user_call.user_target)
            if (pNode == resListHead.head)
            {
                f = pNode->user_call->user_floor;
                t = pNode->user_call->user_target;

                if (f > m && t > f) //f > m && t > f
                {
                    /*从待响应指令序列(responselist)中取出并删除*/
                    addSerList(pNode->user_call);        //将其加入当前服务指令序列(servelist)
                    setSerState('P');                    //setState//将其服务状态(servelist.serve_state)设置为"服务前"(P)
                    free(resListHead.head);
                    resListHead.head = pNode->next_node; //删除头节点
                }
                else
                {
                    flag++;
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

                if (f > m && t > f) //f > m && t > f
                {
                    /*从待响应指令序列(responselist)中取出并删除*/
                    addSerList(pNode->next_node->user_call);        //将其加入当前服务指令序列(servelist)
                    setSerState('P');                               //setState//将其服务状态(servelist.serve_state)设置为"服务前"(P)
                    free(pNode->next_node);
                    pNode->next_node = pNode->next_node->next_node; //删除该节点
                }
            }
        }
    }
    else if (eleState.run_state == 'D') //电梯运行状态为下行(D)
    {
        for (pNode = resListHead.head; pNode != NULL && pNode->next_node != NULL; pNode = pNode->next_node) //遍历待响应指令序列(responselist)
        {
            flag = 0;
            //取出当前指令用户所在楼层(responselist.user_call.user_floor)f与目标楼层t(responselist.user_call.user_target)
            if (pNode == resListHead.head)
            {
                f = pNode->user_call->user_floor;
                t = pNode->user_call->user_target;

                if (f < m && t < f) //f > m && t > f
                {
                    /*从待响应指令序列(responselist)中取出并删除*/
                    addSerList(pNode->user_call);        //将其加入当前服务指令序列(servelist)
                    setSerState('P');                    //setState//将其服务状态(servelist.serve_state)设置为"服务前"(P)
                    free(resListHead.head);
                    resListHead.head = pNode->next_node; //删除头节点
                }
                else
                {
                    flag++;
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

                if (f < m && t < f) //f > m && t > f
                {
                    /*从待响应指令序列(responselist)中取出并删除*/
                    addSerList(pNode->next_node->user_call);        //将其加入当前服务指令序列(servelist)
                    setSerState('P');                               //setState//将其服务状态(servelist.serve_state)设置为"服务前"(P)
                    free(pNode->next_node);
                    pNode->next_node = pNode->next_node->next_node; //删除该节点
                }
            }
        }
    }

    else if (eleState.run_state == 'S') //电梯处于停止状态
    {
        int flg = 0;
        char state;
        state = serListHead.head->serve_state;
        //取出电梯当前服务指令队列中(servelist)第一条指令
        //检查电梯对该用户指令的服务状态(servelist.serve_state)
        if (state == 'P') //服务前(servelist.serve_state == "P")
        {
            if (serListHead.head->user_call->user_floor > m) //servelist.user_call.user_floor > m
            {
                flg++; //flg++;
            }
        }
        else if (state == 'E') //服务中(servelist.serve_state == "E")
        {
            if (serListHead.head->user_call->user_target > m) //servelist.user_call.user_target > m
            {
                flg++; //flg++;
            }
        }

        if (flg == 0) //flg == 0
        {
            for (pNode = resListHead.head; pNode != NULL && pNode->next_node != NULL; pNode = pNode->next_node) //遍历待响应指令序列(responselist)
            {
                flag = 0;
                //取出当前指令用户所在楼层(responselist.user_call.user_floor)f与目标楼层t(responselist.user_call.user_target)
                if (pNode == resListHead.head)
                {
                    f = pNode->user_call->user_floor;
                    t = pNode->user_call->user_target;

                    if (f <= m && t < f)
                    {
                        /*从待响应指令序列(responselist)中取出并删除*/
                        addSerList(pNode->user_call);        //将其加入当前服务指令序列(servelist)
                        if (f == m)
                        {
                            setSerState('E');
                        }
                        else
                        {
                            setSerState('P');
                        }
                        free(resListHead.head);
                        resListHead.head = pNode->next_node; //删除头节点
                    }
                    else
                    {
                        flag++;
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

                    if (f <= m && t < f)
                    {
                        /*从待响应指令序列(responselist)中取出并删除*/
                        addSerList(pNode->next_node->user_call);        //将其加入当前服务指令序列(servelist)
                        if (f == m)
                        {
                            setSerState('E');
                        }
                        else
                        {
                            setSerState('P');
                        }
                        free(pNode->next_node);
                        pNode->next_node = pNode->next_node->next_node; //删除该节点
                    }
                }
            }
        }
        else
        {
            for (pNode = resListHead.head; pNode != NULL && pNode->next_node != NULL; pNode = pNode->next_node) //遍历待响应指令序列(responselist)
            {
                flag = 0;
                //取出当前指令用户所在楼层(responselist.user_call.user_floor)f与目标楼层t(responselist.user_call.user_target)
                if (pNode == resListHead.head)
                {
                    f = pNode->user_call->user_floor;
                    t = pNode->user_call->user_target;

                    if (f >= m && t > f)
                    {
                        /*从待响应指令序列(responselist)中取出并删除*/
                        addSerList(pNode->user_call);        //将其加入当前服务指令序列(servelist)
                        if (f == m)
                        {
                            setSerState('E');
                        }
                        else
                        {
                            setSerState('P');
                        }
                        free(resListHead.head);
                        resListHead.head = pNode->next_node; //删除头节点
                    }
                    else
                    {
                        flag++;
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

                    if (f >= m && t > f)
                    {
                        /*从待响应指令序列(responselist)中取出并删除*/
                        addSerList(pNode->next_node->user_call);        //将其加入当前服务指令序列(servelist)
                        if (f == m)
                        {
                            setSerState('P');
                        }
                        else
                        {
                            setSerState('E');
                        }
                        free(pNode->next_node);
                        pNode->next_node = pNode->next_node->next_node; //删除该节点
                    }
                }
            }
        }
    }
}