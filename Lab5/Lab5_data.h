#define MAX_STR_LEN 100
#define MAX_ARR_LEN 10000

typedef struct configinfo{
char filesavepath[MAX_STR_LEN] ; //用于存放数据记录文件的存储目录
char filename[MAX_STR_LEN]; //用于存储数据记录文件的文件名信息
char realPath[MAX_STR_LEN];//用于储存数据记录文件的完整路径
int number; //用于存放生成的记录条数
}CONF;

typedef struct DataItem
{
    int x, y, z;
}DATASTRUCT;