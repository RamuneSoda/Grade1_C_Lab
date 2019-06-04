#include "Lab7_nextStatus.h"

void nextStatus()
{
    //读取电梯当前运行状态及当前楼层m(elevatorstate.current_floor)
    if(0)//电梯处于上行状态((elevatorstate.run_state == "U")
    {
        //遍历电梯的服务指令队列
        {
            //检查电梯对当前用户指令的服务状态(servelist.serve_state)
            if(0)//"服务前" servelist.serve_state == 'P'
            {
                if(0)//servelist.user_call.user_floor == m + 1
                {
                    //elevatorstate.run_state == "S"
                    //servelist.servestate = "E"
                }
            }

            if(0)//"服务中 servelist.serve_state == 'E'
            {
                if(0)//servelist.user_call.user_target == m + 1
                {
                    //elevatorstate.run_state == "S"
                    //将该指令从当前服务指令队列删除
                }
            }
        }
        //将当前楼层改为(m + 1) elevatorstate.current_floor++;
    }
    
    if(0)//电梯处于下行状态(elevatorstate.run_state == "D")
    {
        //遍历电梯的服务指令队列
        {
            //检查电梯对当前用户指令的服务状态(servelist.serve_state)
            if(0)//"服务前" servelist.serve_state == 'P'
            {
                if(0)//servelist.user_call.user_floor == m - 1
                {
                    //elevatorstate.run_state == "S"
                    //servelist.servestate = "E"
                }
            }

            if(0)//"服务中 servelist.serve_state == 'E'
            {
                if(0)//servelist.user_call.user_target == m - 1
                {
                    //elevatorstate.run_state == "S"
                    //将该指令从当前服务指令队列删除
                }
            }
        }
        //将当前楼层改为(m - 1) elevatorstate.current_floor--;
    }

    if(0)//电梯处于静止状态(elevatorstate.run_state == "S")
    {
        //取出电梯服务指令队列(servelist)
        //检查电梯对该用户指令的服务状态(servelist.serve_state)
        if(0)//"服务前" servelist.serve_state == "P"
        {
            if(0)//servelist.user_call.user_floor > m
            {
                //elevatorstate.run_state = "U"
            }
            else
            {
                //elevatorstate.run_state = "D"
            } 
        }

        if(0)//"服务前" servelist.serve_state == "E"
        {
            if(0)//servelist.user_call.user_target > m
            {
                //elevatorstate.run_state = "U"
            }
            else
            {
                //elevatorstate.run_state = "D"
            }
        }
        //楼层不做改变
    }
}