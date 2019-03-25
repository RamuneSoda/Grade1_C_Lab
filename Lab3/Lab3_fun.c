#include "Lab3_fun.h"

/***********************************************
函数名称:
    判断数字；
功能描述:
    判断传入字符串是否为纯数字；
函数参数:
    指向字符数组的指针 char *str，字符串长度 int n;
返回值:
    若字符串为纯数字，返回1；
    否则，返回0；
模块历史:
    蔡晞阳于20190312创建本模块，email：18281031@bjtu.edu.cn
**********************************************/
int isNum(char *str, int n)
{
    int k = 1;
    for (int i = 0; i <= n-1; i++)
    {
        if(isdigit(str[i]) == 0)
        {
            k--;
            break;
        }
    }
    return k;
}

void BuildDataFile(char *str)
{
    //从配置信息变量中获取数据文件存放目录
    if(//目录不存在(取了反))
    {
        //创建存放数据文件的目录
        if(//创建不成功)
        {
            //输出错误信息
            return;
        }
    }

    //从配置信息变量中获取数据文件存放目录与文件名，将其拼装为完整的文件路径
    //打开文件
    if(//文件打开成功？)
    {
        //清空文件中的已有内容
        //从配置信息中取出记录条数并写入文件
        for(//执行数据条数次)
        {
            //调用随机函数获取一个指定范围内的整数，作为第一个元素
            //调用随机函数获取一个指定范围内的整数，作为第二个元素
            while(//第一、第二个元素相等)
            {
                //调用随机函数获取一个指定范围内的整数，作为第二个元素
            }
            //调用随机函数获取一个指定范围内的整数，作为第三个元素
            //将三个元素形成一条记录数据，暂存入数据容器
        }
        //将暂存在数据容器中的数据写入数据记录文件保存并关闭文件，输出文件生成成功提示信息
    }
    else
    {
        //输出错误提示
        return;
    }    
}

int isPath(char *pPath)
{
    int len = strlen(pPath);
    if(strstr(pPath, "\\") - pPath == 0) //不能以\\开头
    {
        return 0;
    }
    if(pPath[0] >= 'A' && pPath[0] <= 'Z') //是绝对路径吗？
    {
        if(strstr(pPath, ":/") == (pPath + 1) || strstr(pPath, ":\\") == (pPath + 1) )
        {
            for(int i = 0; i <= len -1; i++)
            {
                switch (pPath[i])
                {
                    case ':':
                        if(i != 1)
                        {
                            return 0;
                        }
                        break;
                    case '*':
                        return 0;
                    case '?':
                        return 0;                    
                    case '<':
                        return 0;
                    case '>':
                        return 0;
                    case '|':
                        return 0;
                    case '\\':
                        if(pPath[i+1] == '\\')
                        {
                            break;
                        }
                        else
                            return 0;
                    default:
                        break;
                }
            }
            return 1;
        }
        else
        {
            return 0;
        }
        

        if(strstr(pPath, "\\") == (pPath + len -1) ||(strchr(pPath, '/') == (pPath + len )))
        {
            return 0;
        }
    }
//    else if()//是相对路径吗？
    else 
        return 0;
}