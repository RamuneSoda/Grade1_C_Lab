#include <stdio.h>
#include <windows.h>
#include "Lab7_data.h"
#include "Lab7_main.h"
#include "Lab7_getStatus.h"
#include "Lab7_nextStatus.h"
#include "Lab7_input.h"

int time, num;
USERCALL *usercall;
RESPONSELISTHEADNODE resListHead;
SERVELISTHEADNODE serListHead;
ELEVATORSTATE eleState;


void run()
{
    time = 1;
    /*init EVERYTHING
    1. 计时器置零
    2.
        2.1 声明 用户请求信息结构体
        2.2 读取 用户请求信息 至结构体数组中
        2.3 按照 发出指令时间 排序
    3. 初始化 待响应指令队列
    4. 初始化 当前服务指令队列
    */
    /*电梯状态初始化*/
    eleState.current_floor = 1;
    eleState.run_state = 'S';
    eleState.serve_list = serListHead.head;
    
    /*外部数据输入与整理*/
    read_struct();
    sort_struct(num);
    callType();

    while(1)  //服务未完毕
    {
        getStatus();//获取当前状态及用户指令相应情况();
        nextStatus();//根据当前状态计算下一时刻状态();
        //计时器++
        Sleep(1000);
        time++;
    }
}