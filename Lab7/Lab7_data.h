#ifndef __Data__
#define __Data__
/*用户请求信息结构体*/
typedef struct UserCall{
    int user_floor;     //用户所在楼层
    int user_target;    //用户目标楼层
    int call_time;      //用户请求时间
    char call_type;     //用户请求类型，´U´表示上行指令，´D´表示下行指令
}USERCALL;

/*当前服务指令队列链表结点结构体*/
typedef struct ServeListNode{
    char serve_state ; //电梯服务状态  （服务前‘P’  服务中‘E'）
    USERCALL *user_call ;//电梯当前响应用户指令时，指向指令数组的某一个元素
    struct ServeListNode *next_node ;//存储下一个结点的地址
}SERVELISTNODE;

/*当前服务指令队列链表结点头节点*/
typedef struct ServeListHeadNode{
    int list_num ; //待响应用户指令链表中数据结点的个数
    SERVELISTNODE *head ;//链表中第一个数据结点的指针
    SERVELISTNODE *tail ;//链表中最后一个数据结点的指针
}SERVELISTHEADNODE; 

/*电梯状态结构体*/
typedef struct elevatorstate{
    int current_floor ; //电梯当前所处楼层
    char run_state ; //电梯运行状态
    SERVELISTNODE *serve_list; //电梯当前服务指令队列指针
}ELEVATORSTATE;

/*待响应指令队列链表结点结构体*/
typedef struct ResponseListNode{
    USERCALL *user_call ; //用户指令在指令数组中对应的序号
    struct ResponseListNode *next_node;//存储下一个结点的地址
}RESPONSELISTNODE;

/*链表头结点数据结构体*/
typedef struct ResponseListHeadNode{
    int list_num ; //待响应用户指令链表中数据结点的个数
    RESPONSELISTNODE *head ;//链表中第一个数据结点的指针
    RESPONSELISTNODE *tail ;//链表中最后一个数据结点的指针
}RESPONSELISTHEADNODE; 


/*init EVERYTHING
    1. 计时器置零
    2.
        2.1 声明 用户请求信息结构体
        2.2 读取 用户请求信息 至结构体数组中
        2.3 按照 发出指令时间 排序
    3. 初始化 待响应指令队列
    4. 初始化 当前服务指令队列
*/
extern int time, num;
extern USERCALL *usercall;
extern RESPONSELISTHEADNODE resListHead;
extern SERVELISTHEADNODE serListHead;
extern ELEVATORSTATE eleState;
#endif