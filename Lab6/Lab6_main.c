#include "Lab6_main.h"
#include "Lab6_init.h"
#include "Lab6_call.h"
#include "Lab6_loadfile.h"
#include "Lab6_view.h"
#include "Lab6_conf.h"
#include "Lab6_sort.h"

void run(void)
{
    system("chcp 65001");
    //自检
    if(isFileExist("./Lab4.exe") == 0)
    {
        printf("Lab4.exe不存在！\n");
        return;
    }

    if(isFileExist("./conf.ini") == 0)
    {
        printf("conf.ini不存在！\n");
        return;
    }

    if(isFileExist("./MODE.ini") == 0)
    {
        printf("MODE.ini不存在！\n");
        return;
    }
    //加载系统参数
    CONF info;
    iniconf(&info);
    getNum(&info);
    int input;

    /*动态申请二维数组内存空间*/
    int (*dataArray)[3] = NULL;
    dataArray = (int (*)[3])malloc(sizeof(int (*)[3]) * (info.number + 1));
    
    
    /*动态申请结构体数组内存空间*/
    DATASTRUCT *dataStructs = NULL;
    dataStructs = (DATASTRUCT*)malloc(sizeof(DATASTRUCT) * (info.number + 1));

    /*动态申请指针数组内存空间*/
    DATASTRUCT **pStruct = (DATASTRUCT**)malloc(sizeof(DATASTRUCT*) * (info.number + 1));
    for(int i = 0; i <= info.number; i++)
    {
        pStruct[i] = (DATASTRUCT*)malloc(sizeof(DATASTRUCT));
    }

    /*初始化单向链表*/
    LINKINFO likinfo;
    likinfo.head = NULL;
    likinfo.tail = NULL;
    likinfo.listlen = info.number + 1;

    while (1)
        {
            while(1)
                {
                    //显示系统菜单
                    printf("\n蔡晞阳 的实验 5 程序：\n"
                    "   1. 调用实验 4 程序生成记录文件（文本方式）\n"
                    "   2. 调用实验 4 程序生成记录文件（二进制方式）\n"
                    "   3. 读取指定数据记录文件（二维数组存储方式）\n"
                    "   4. 读取指定数据记录文件（结构体数组存储方式）\n"
                    "   5. 读取指定数据记录文件（指针数组存储方式）\n"
                    "   6. 读取指定数据记录文件（链表存储方式）\n"
                    "   7. 调用实验 4 生成数据记录文件，同时读取数据记录文件（文本方式输出，二维数组方式存储）\n"
                    "   8. 调用实验 4 生成数据记录文件，同时读取数据记录文件（文本方式输出，结构体数组方式存储）\n"
                    "   9. 调用实验 4 生成数据记录文件，同时读取数据记录文件（文本方式输出，指针数组方式存储）\n"
                    "   10. 调用实验 4 生成数据记录文件，同时读取数据记录文件（文本方式输出，链表方式存储）\n"
                    "   11. 调用实验 4 生成数据记录文件，同时读取数据记录文件（二进制方式输出，二维数组方式存储）\n"
                    "   12. 调用实验 4 生成数据记录文件，同时读取数据记录文件（二进制方式输出，结构体数组方式存储）\n"
                    "   13. 调用实验 4 生成数据记录文件，同时读取数据记录文件（二进制方式输出，指针数组方式存储）\n"
                    "   14. 调用实验 4 生成数据记录文件，同时读取数据记录文件（二进制方式输出，链表方式存储）\n"
                    "   15. 重新设置配置参数值\n"
                    "   0. 退出\n"
                    "请输入您要执行的功能序号：");  /**/

                    scanf("%d",&input);
                    fflush(stdin);
                    if(input >= 0 && input <= 15)
                    {
                        break;
                    }
                    printf("\n请输入功能序号（0-15）\n");//提示错误信息
                }

            if(input == 0)
            {
                return;
            }

            switch (input)
            {
            case 1:
            /*调用实验 4 程序生成记录文件（文本方式）*/
                lab4_write(1, info.mode, &info);
                break;
            case 2:
            /*调用实验 4 程序生成记录文件（二进制方式）*/
                lab4_write(2, info.mode, &info);
                break;
            case 3:
            /*读取指定数据记录文件（二维数组存储方式）*/
                switch (info.mode)
                {
                case 1://自动模式
                    transRel(&info);
                    getNum(&info);
                    read_array(&info, dataArray);
                    show_array(dataArray, 1);

                    sort_array(dataArray, info.number);
                    show_array(dataArray, 0);
                    break;
                case 2://交互模式
                    Manual_read(&info);
                    read_array(&info, dataArray);
                    show_array(dataArray, 1);

                    sort_array(dataArray, info.number);
                    show_array(dataArray, 0);
                    break;
                default:
                    printf("输入模式选择错误。使用自动模式请输1，交互模式请输2。");
                    break;
                }                 
                break;
            case 4:
            /*读取指定数据记录文件（结构体数组存储方式）*/
                switch (info.mode)
                {
                case 1://自动模式
                    transRel(&info);
                    getNum(&info);
                    read_struct(&info, dataStructs);
                    show_struct(dataStructs, 1);

                    sort_struct(dataStructs, info.number);
                    show_struct(dataStructs, 0);
                    break;
                case 2://交互模式
                    Manual_read(&info);
                    read_struct(&info, dataStructs);
                    show_struct(dataStructs, 1);

                    sort_struct(dataStructs, info.number);
                    show_struct(dataStructs, 0);
                    break;
                default:
                    printf("输入模式选择错误。使用自动模式请输1，交互模式请输2。");
                    break;
                }                 
                break;

            case 5:
            /*读取指定数据记录文件（指针数组存储方式）*/
                switch (info.mode)
                {
                case 1://自动模式
                    transRel(&info);
                    getNum(&info);
                    read_PointerStruct(&info, pStruct);
                    show_PointerStruct(pStruct, 1);

                    sort_PointerStruct(pStruct, info.number);
                    show_PointerStruct(pStruct, 0);
                    break;
                case 2://交互模式
                    Manual_read(&info);
                    read_PointerStruct(&info, pStruct);
                    show_PointerStruct(pStruct, 1);

                    sort_PointerStruct(pStruct, info.number);
                    show_PointerStruct(pStruct, 0);
                    break;
                default:
                    printf("输入模式选择错误。使用自动模式请输1，交互模式请输2。");
                    break;
                }
                break;
            case 6:
            /*读取指定数据记录文件（链表存储方式）*/
                likinfo.head = NULL;
                likinfo.tail = NULL;
                likinfo.listlen = info.number + 1;
                initLink(&info, &likinfo.head, &likinfo.tail, info.number);
                ShowLinkData(likinfo.head, 1);

                LinkSortQ(&likinfo);
                ShowLinkData(likinfo.head, 0);
                break;
            case 7:
            /*调用实验 4 生成数据记录文件，同时读取数据记录文件（文本方式输出，二维数组方式存储）*/

                /*调用实验 4 程序生成记录文件（文本方式）*/
                switch (info.mode)
                {
                case 1://自动模式
                    system("Lab4 0 0 txt");
                    break;
                case 2://交互模式
                    system("Lab4 0 0 0 txt");
                    break;
                default:
                    printf("输入模式选择错误。使用自动模式请输1，交互模式请输2。");
                    break;
                }                              

                /*读取指定数据记录文件（二维数组存储方式）*/
                switch (info.mode)
                {
                case 1://自动模式
                    transRel(&info);
                    getNum(&info);
                    read_array(&info, dataArray);
                    show_array(dataArray, 1);

                    sort_array(dataArray, info.number);
                    show_array(dataArray, 0);
                    break;
                case 2://交互模式
                    Manual_read(&info);
                    read_array(&info, dataArray);
                    show_array(dataArray, 1);

                    sort_array(dataArray, info.number);
                    show_array(dataArray, 0);
                    break;
                default:
                    printf("输入模式选择错误。使用自动模式请输1，交互模式请输2。");
                    break;
                }

                break;
            case 8:
            /*调用实验 4 生成数据记录文件，同时读取数据记录文件（文本方式输出，结构体数组方式存储）*/
                
                /*调用实验 4 程序生成记录文件（文本方式）*/
                lab4_write(1, info.mode, &info);         
                
                /*读取指定数据记录文件（结构体数组存储方式）*/
                switch (info.mode)
                {
                case 1://自动模式
                    transRel(&info);
                    getNum(&info);
                    read_struct(&info, dataStructs);
                    show_struct(dataStructs, 1);

                    sort_struct(dataStructs, info.number);
                    show_struct(dataStructs, 0);
                    break;
                case 2://交互模式
                    Manual_read(&info);
                    read_struct(&info, dataStructs);
                    show_struct(dataStructs, 1);

                    sort_struct(dataStructs, info.number);
                    show_struct(dataStructs, 0);
                    break;
                default:
                    printf("输入模式选择错误。使用自动模式请输1，交互模式请输2。");
                    break;
                }

                break;
            case 9:
            /*调用实验 4 生成数据记录文件，同时读取数据记录文件（文本方式输出，指针数组方式存储）*/

                /*调用实验 4 程序生成记录文件（文本方式）*/
                lab4_write(1, info.mode, &info);  
                
                /*读取指定数据记录文件（指针数组存储方式）*/
                switch (info.mode)
                {
                case 1://自动模式
                    transRel(&info);
                    getNum(&info);
                    read_PointerStruct(&info, pStruct);
                    show_PointerStruct(pStruct, 1);

                    sort_PointerStruct(pStruct, info.number);
                    show_PointerStruct(pStruct, 0);
                    break;
                case 2://交互模式
                    Manual_read(&info);
                    read_PointerStruct(&info, pStruct);
                    show_PointerStruct(pStruct, 1);

                    sort_PointerStruct(pStruct, info.number);
                    show_PointerStruct(pStruct, 0);
                    break;
                default:
                    printf("输入模式选择错误。使用自动模式请输1，交互模式请输2。");
                    break;
                }

                break;
            case 10:
            /*调用实验 4 生成数据记录文件，同时读取数据记录文件（文本方式输出，链表方式存储）*/

                /*调用实验 4 程序生成记录文件（文本方式）*/
                lab4_write(1, info.mode, &info);         

                /*读取指定数据记录文件（链表存储方式）*/
                likinfo.head = NULL;
                likinfo.tail = NULL;
                likinfo.listlen = info.number + 1;
                initLink(&info, &likinfo.head, &likinfo.tail, info.number);
                ShowLinkData(likinfo.head, 1);

                LinkSortQ(&likinfo);
                ShowLinkData(likinfo.head, 0);
                
                break;
            case 11:
            /*调用实验 4 生成数据记录文件，同时读取数据记录文件（二进制方式输出，二维数组方式存储）*/
                
                /*调用实验 4 程序生成记录文件（二进制方式）*/
                lab4_write(2, info.mode, &info);  

                /*读取指定数据记录文件（二维数组存储方式）*/
                switch (info.mode)
                {
                case 1://自动模式
                    transRel(&info);
                    getNum(&info);
                    read_array(&info, dataArray);
                    show_array(dataArray, 1);

                    sort_array(dataArray, info.number);
                    show_array(dataArray, 0);
                    break;
                case 2://交互模式
                    Manual_read(&info);
                    read_array(&info, dataArray);
                    show_array(dataArray, 1);

                    sort_array(dataArray, info.number);
                    show_array(dataArray, 0);
                    break;
                default:
                    printf("输入模式选择错误。使用自动模式请输1，交互模式请输2。");
                    break;
                }      
                
                break;
            case 12:
            /*调用实验 4 生成数据记录文件，同时读取数据记录文件（二进制方式输出，结构体数组方式存储）*/
                
                /*调用实验 4 程序生成记录文件（二进制方式）*/
                lab4_write(2, info.mode, &info);

                /*读取指定数据记录文件（结构体数组存储方式）*/
                switch (info.mode)
                {
                case 1://自动模式
                    transRel(&info);
                    getNum(&info);
                    read_struct(&info, dataStructs);
                    show_struct(dataStructs, 1);

                    sort_struct(dataStructs, info.number);
                    show_struct(dataStructs, 0);
                    break;
                case 2://交互模式
                    Manual_read(&info);
                    read_struct(&info, dataStructs);
                    show_struct(dataStructs, 1);

                    sort_struct(dataStructs, info.number);
                    show_struct(dataStructs, 0);
                    break;
                default:
                    printf("输入模式选择错误。使用自动模式请输1，交互模式请输2。");
                    break;
                }

                break;
            case 13:
            /*调用实验 4 生成数据记录文件，同时读取数据记录文件（二进制方式输出，指针数组方式存储）*/
                
                /*调用实验 4 程序生成记录文件（二进制方式）*/
                lab4_write(2, info.mode, &info);

                /*读取指定数据记录文件（指针数组存储方式）*/
                switch (info.mode)
                {
                case 1://自动模式
                    transRel(&info);
                    getNum(&info);
                    read_PointerStruct(&info, pStruct);
                    show_PointerStruct(pStruct, 1);

                    sort_PointerStruct(pStruct, info.number);
                    show_PointerStruct(pStruct, 0);
                    break;
                case 2://交互模式
                    Manual_read(&info);
                    read_PointerStruct(&info, pStruct);
                    show_PointerStruct(pStruct, 1);

                    sort_PointerStruct(pStruct, info.number);
                    show_PointerStruct(pStruct, 0);
                    break;
                default:
                    printf("输入模式选择错误。使用自动模式请输1，交互模式请输2。");
                    break;
                }

                break;
            case 14:
            /*调用实验 4 生成数据记录文件，同时读取数据记录文件（二进制方式输出，链表方式存储）*/
                
                /*调用实验 4 程序生成记录文件（二进制方式）*/
                lab4_write(2, info.mode, &info);

                /*读取指定数据记录文件（链表存储方式）*/
                likinfo.head = NULL;
                likinfo.tail = NULL;
                likinfo.listlen = info.number + 1;
                initLink(&info, &likinfo.head, &likinfo.tail, info.number);
                ShowLinkData(likinfo.head, 1);

                LinkSortQ(&likinfo);
                ShowLinkData(likinfo.head, 0);

                break;
            case 15:
                /*重新设置配置参数值*/
                changeConf(&info);
                iniconf(&info);
                break;
            default:
                break;
            }
        }
}