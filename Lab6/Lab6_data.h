#define MAX_STR_LEN 100
#define MAX_ARR_LEN 10000

#ifndef __CONF__
#define __CONF__
typedef struct configinfo{
char filesavepath[MAX_STR_LEN] ; //用于存放数据记录文件的存储目录
char filename[MAX_STR_LEN]; //用于存储数据记录文件的文件名信息
char realPath[MAX_STR_LEN];//用于储存数据记录文件的绝对路径

int number; //用于存放生成的记录条数
int maxvalue1; //用于存放实验2中生成的数据记录三元组中第1、2个元素取值的上限
int minvalue1; //用于存放实验2中生成的数据记录三元组中第1、2个元素取值的下限
int maxvalue2 ; //用于存放实验2中生成的数据记录三元组中第3个元素取值的上限
int minvalue2; //用于存放实验2中生成的数据记录三元组中第3个元素取值的下限
int recordcount1; //用于存放数据记录文件需要随机生成记录条数时条数值的上限
int recordcount2; //用于存放数据记录文件需要随机生成记录条数时条数值的下限
int mode;//储存工作模式
}CONF;
#endif

#ifndef __DataItem__
#define __DataItem__
typedef struct DataItem
{
    int x, y, z;
    struct DataItem *pNextItem;
}DATASTRUCT;

typedef struct Link //用来记录链表头结点、最后一个节点、元素个数  
{  
	int listlen;  
	DATASTRUCT *head,*tail;  
}LINKINFO;
#endif