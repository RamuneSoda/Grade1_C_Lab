#include "Lab5_run.h"
#include "Lab5_fun.h"
#include "Lab5_data.h"



void run(void)
{
    system("chcp 65001");
    //自检
    /*if(自检错误)
    {
        Error!
        return;
    }*/
    //加载系统参数
    CONF info;
    iniconf(&info);

    /*动态申请二维数组内存空间*/
    int (*dataArray)[3] = (int (*)[3])malloc(sizeof(int (*)[3]) * info.number);
    
    /*动态申请结构体数组内存空间*/
    DATASTRUCT *dataStructs = (DATASTRUCT*)malloc(sizeof(DATASTRUCT) * info.number);

    /*动态申请指针数组内存空间*/
    DATASTRUCT **pStruct = (DATASTRUCT**)malloc(sizeof(DATASTRUCT*) * info.number);

    //等待用户输入
    int input;
    while(1)
    {
            //printf("使用交互模式请输入：1 自动模式请输入：2\n");
            scanf("%d",&input);
            fflush(stdin);
            if(input == 1 || input == 2)
            {
                break;
            }      
    }
    if(input == 1)
    {
        system("Lab4");//交互模式
    }
    else
    {
        while (1)
        {
            while(1)
                {
                    //显示系统菜单
                    /*printf("XXX 的实验 5 程序：\n"
                    "1. 调用实验 4 程序生成记录文件（文本方式）\n"
                    "2. 调用实验 4 程序生成记录文件（二进制方式）\n"
                    "3.读取指定数据记录文件（二维数组存储方式）\n"
                    "4.读取指定数据记录文件（结构体数组存储方式）\n"
                    "5.读取指定数据记录文件（指针数组存储方式）\n"
                    "6.读取指定数据记录文件（链表存储方式）\n"
                    "7. 调用实验 4 生成数据记录文件，同时读取数据记录文件（文本方式输出，二维数组方式存储）\n"
                    "8. 调用实验 4 生成数据记录文件，同时读取数据记录文件（文本方式输出，结构体数组方式存储）\n"
                    "9. 调用实验 4 生成数据记录文件，同时读取数据记录文件（文本方式输出，指针数组方式存储）\n"
                    "10. 调用实验 4 生成数据记录文件，同时读取数据记录文件（文本方式输出，链表方式存储）\n"
                    "11. 调用实验 4 生成数据记录文件，同时读取数据记录文件（二进制方式输出，二维数组方式存储）\n"
                    "12. 调用实验 4 生成数据记录文件，同时读取数据记录文件（二进制方式输出，结构体数组方式存储）\n"
                    "13. 调用实验 4 生成数据记录文件，同时读取数据记录文件（二进制方式输出，指针数组方式存储）\n"
                    "14. 调用实验 4 生成数据记录文件，同时读取数据记录文件（二进制方式输出，链表方式存储）\n"
                    "15. 重新设置配置参数值\n"
                    "0. 退出\n"
                    "请输入您要执行的程序序号：");  */

                    scanf("%d",&input);
                    fflush(stdin);
                    if(input >= 0 && input <= 15)
                    {
                        break;
                    }
                    //printf("\n请输入功能序号（0-15）\n");//提示错误信息
                }

            if(input == 0)
            {
                return;
            }

            switch (input)
            {
            case 1:
                /*调用实验 4 程序生成记录文件（文本方式）*/
                system("Lab4 0 0 txt");
                break;
            case 2:
                /*调用实验 4 程序生成记录文件（二进制方式）*/
                system("Lab4 0 0 dat");
                break;
            case 3:
                /*读取指定数据记录文件（二维数组存储方式）*/
                iniconf(&info);
                read_array(&info, dataArray);
                break;
            case 4:
                /*读取指定数据记录文件（结构体数组存储方式）*/
                iniconf(&info);
                break;
            case 5:
                /*读取指定数据记录文件（指针数组存储方式）*/
                iniconf(&info);
                break;
            case 6:
                /*读取指定数据记录文件（链表存储方式）*/
                break;
            case 7:
                /*调用实验 4 生成数据记录文件，同时读取数据记录文件（文本方式输出，二维数组方式存储）*/
                system("Lab4 0 0 txt");

                iniconf(&info);
                read_array(&info, dataArray);
                break;
            case 8:
                /*调用实验 4 生成数据记录文件，同时读取数据记录文件（文本方式输出，结构体数组方式存储）*/
                system("Lab4 0 0 txt");

                iniconf(&info);
                break;
            case 9:
                /*调用实验 4 生成数据记录文件，同时读取数据记录文件（文本方式输出，指针数组方式存储）*/
                system("Lab4 0 0 txt");

                iniconf(&info);
                break;
            case 10:
                /*调用实验 4 生成数据记录文件，同时读取数据记录文件（文本方式输出，链表方式存储）*/
                system("Lab4 0 0 txt");
                break;
            case 11:
                /*调用实验 4 生成数据记录文件，同时读取数据记录文件（二进制方式输出，二维数组方式存储）*/
                system("Lab4 0 0 dat");
                break;
            case 12:
                /*调用实验 4 生成数据记录文件，同时读取数据记录文件（二进制方式输出，结构体数组方式存储）*/
                system("Lab4 0 0 dat");
                break;
            case 13:
                /*调用实验 4 生成数据记录文件，同时读取数据记录文件（二进制方式输出，指针数组方式存储）*/
                system("Lab4 0 0 dat");
                break;
            case 14:
                /*调用实验 4 生成数据记录文件，同时读取数据记录文件（二进制方式输出，链表方式存储）*/
                system("Lab4 0 0 dat");

                break;
            case 15:
                /*重新设置配置参数值*/
                system("notepad conf.ini");
                break;
            default:
                break;
            }
        }
    }
    
}

