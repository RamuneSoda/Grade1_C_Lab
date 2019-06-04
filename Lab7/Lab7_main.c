#include "Lab7_main.h"
#include "Lab7_getStatus.h"
#include "Lab7_nextStatus.h"
#include "Lab7_data.h"

void run()
{
    /*init EVERYTHING
    1. 计时器置零
    2.
        2.1 声明 用户请求信息结构体
        2.2 读取 用户请求信息 至结构体数组中
        2.3 按照 发出指令时间 排序
    3. 初始化 待响应指令队列
    4. 初始化 当前服务指令队列
    */
   int time = 0;
   //USERCALL usercall[];
   
    //while()  //服务未完毕
    {
        getStatus();//获取当前状态及用户指令相应情况();
        nextStatus();//根据当前状态计算下一时刻状态();
        //输出下一时刻状态();
        //计时器++
        //sleep(1000);
    }
}