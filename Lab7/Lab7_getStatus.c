#include "Lab7_getStatus.h"

void getStatus()
{
    while(0)//该时刻是否有新指令到来
    {
        //将指令加入待响应指令队列
    }
    
    if(0)//电梯不在提供服务
    {
        /*检查待响应指令队列responselist*/
        if(0)//队列不为空
        {
            //从 待响应指令队列responselist 取出第一条指令
            //将该指令加入到 电梯的服务指令队列  servelistnode
            //取出该指令的用户所在楼层f
            if(0)//f == 电梯所在楼层(elevatorstate.current_floor)
            {
                //服务状态(servelistnode.serve_state)设置为服务中(E)
            }
            else
            {
                //服务状态(servelistnode.serve_state)设置为服务前(P)
            }
            anotherUser();//遍历待响应指令队列，判断能否响应其他用户的指令，若可以，将其状态设置为“服务前”
        }
    }
}

void anotherUser()
{
    //读取电梯当前运行状态(elevatorstate.run_state)以及当前楼层m
    if(0)//电梯运行状态为上行(U)
    {
        //遍历待响应指令序列(responselist)
        {
            //取出当前指令用户所在楼层(responselist.user_call.user_floor)f与目标楼层t(responselist.user_call.user_target)
            if(0)//f > m && t > f
            {
                //从待响应指令序列(responselist)中取出并删除
                
                //将其加入当前服务指令序列(servelist)
                //将其服务状态(servelist.serve_state)设置为"服务前"(P)
            }
        }
    }

    //读取电梯当前运行状态(elevatorstate.run_state)以及当前楼层m
    if(0)//电梯运行状态为下行(D)
    {
        //遍历待响应指令序列(responselist)
        {
            //取出当前指令用户所在楼层(responselist.user_call.user_floor)f与目标楼层t(responselist.user_call.user_target)
            if(0)//f < m && t < f
            {
                //从待响应指令序列(responselist)中取出并删除
                
                //将其加入当前服务指令序列(servelist)
                //将其服务状态(servelist.serve_state)设置为"服务前"(P)
            }
        }
    }

    if(0)//电梯处于停止状态
    {
        int flag = 0;

        //取出电梯当前服务指令队列中(servelist)第一条指令
        //检查电梯对该用户指令的服务状态(servelist.serve_state)
        if(0)//服务前(servelist.serve_state == "P")
        {
            if(0)//servelist.user_call.user_floor > m
            {
                //flag++;
            }
        }

        if(0)//服务中(servelist.serve_state == "E")
        {
            if(0)//servelist.user_call.user_target > m
            {
                //flag++;
            }
        }

        if(0)//flag == 0
        {
            /*遍历待响应指令序列(responselist)*/
            {
                //取出当前指令用户所在楼层(responselist.user_call.user_floor)f与目标楼层t(responselist.user_call.user_target)
                if(0)//f <= m && t < f
                {
                    //从待响应指令序列(responselist)中取出并删除
                
                    //将其加入当前服务指令序列(servelist)
                    
                    if(0)//f == m
                    {
                        //将该指令的服务状态(servelist.serve_state)设置为“服务中”(E)
                    }
                    else
                    {
                        //将该指令的服务状态(servelist.serve_state)设置为“服务前”(P)
                    }
                    
                }
            }
        }
        else
        {
            /*遍历待响应指令序列(responselist)*/
            {
                //取出当前指令用户所在楼层(responselist.user_call.user_floor)f与目标楼层t(responselist.user_call.user_target)
                if(0)//f >= m && t > f
                {
                    //从待响应指令序列(responselist)中取出并删除
                
                    //将其加入当前服务指令序列(servelist)
                    
                    if(0)//f == m
                    {
                        //将该指令的服务状态(servelist.serve_state)设置为“服务中”(E)
                    }
                    else
                    {
                        //将该指令的服务状态(servelist.serve_state)设置为“服务前”(P)
                    }
                    
                }
            }
        }    
    }
}