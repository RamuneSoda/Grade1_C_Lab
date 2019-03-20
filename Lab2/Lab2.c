#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#define random(x) (rand () % x)

//结构体声明
typedef struct tuple
{
    int x, y, z;
}anstype;

//变量声明
int (*TriTuple)[3] = NULL;
anstype ans[1000];

//函数声明
int isNum(char*, int);
int judge(int argc, char *argv[]);
void Generate(int n);
void WriteArray(int (*tem)[3], int n);
void WriteStruct(int (*tem)[3], int n);

/***********************************************
函数名称:
    判断参数类型；
功能描述:
    判断命令行输入的参数的类型；
函数参数:
    命令行参数argc, *argv[]；
返回值:
    无命令行参数：返回1；
    有一个命令行参数：若为纯数字，返回2；否则，返回3；
    有两个命令行参数：返回4；
    其他情况：返回0；
模块历史:
    蔡晞阳于20190312创建本模块，email：18281031@bjtu.edu.cn
**********************************************/
int judge(int argc, char *argv[])
{
    if (argc == 1)
    {
        return 1;
    }
    else if(argc == 2)
    {
        if(isNum(argv[1], strlen(argv[1])) == 1)
        {
            return 2;
        }
        else
        {
            return 3;
        }
    }
    else if(argc == 3)
    {
        return 4;
    }
    return 0;
}

/***********************************************
函数名称: main
功能描述: 根据命令行参数生成若干个随机数三元组并储存
函数参数: 命令行参数 int argc, char *argv[]
返回值: 0
模块历史: 蔡晞阳于20190312创建本模块，email：18281031@bjtu.edu.cn
**********************************************/
int main (int argc, char *argv[]) 
{ 
    srand((int)time(0));

    FILE *op;
    int amount;

    switch (judge(argc, argv))
    {
        case 1:
            op = fopen ("output.txt", "w");
            amount = random(20);
            break;
        case 2:
            op = fopen ("output.txt", "w");
            amount = atoi(argv[1]);
            break;
        case 3:
            op = fopen (argv[1], "w");
            amount = random(20);
            break;
        case 4:
            if(isNum(argv[2], strlen(argv[2])) == 1)
            {
                char tem[100];
                strcpy(tem,argv[2]);
                strcpy(argv[2],argv[1]);
                strcpy(argv[1],tem);
            }
            amount = atoi(argv[1]);
            op = fopen (argv[2], "w");
            break;
        default:
            printf("Input Error!");
            return 0;
            break;
    }

    TriTuple = (int (*)[3])malloc(amount * sizeof(int [3]));
	
    Generate(amount);

    for (int i = 0; i < amount; i++)
    {
        fprintf(op ,"%d, %d, %d\n", TriTuple[i][0], TriTuple[i][1], TriTuple[i][2]);
    }

    fclose(op);

    return 0; 
} 

/***********************************************
函数名称:
    判断参数类型；
功能描述:
    判断命令行输入的参数的类型；
函数参数:
    命令行参数argc, *argv[]；
返回值:
    无命令行参数：返回1；
    有一个命令行参数：若为纯数字，返回2；否则，返回3；
    有两个命令行参数：返回4；
    其他情况：返回0；
模块历史:
    蔡晞阳于20190312创建本模块，email：18281031@bjtu.edu.cn
**********************************************/
int judge(int argc, char *argv[])
{
    if (argc == 1)
    {
        return 1;
    }
    else if(argc == 2)
    {
        if(isNum(argv[1], strlen(argv[1])) == 1)
        {
            return 2;
        }
        else
        {
            return 3;
        }
    }
    else if(argc == 3)
    {
        return 4;
    }
    return 0;
}

/***********************************************
函数名称:
    判断数字；
功能描述:
    判断传入的字符串是否为纯数字；
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

/***********************************************
函数名称:
    生成随机数并储存；
功能描述:
    随机生成指定个随机数三元组，并将其储存到二维数组与储存数据的结构体数组中；
函数参数:
    三元组的个数 int n；
返回值:
    无返回值
模块历史:
    蔡晞阳于20190312创建本模块，email：18281031@bjtu.edu.cn
**********************************************/
void Generate(int n)
{
    int tem[1000][3]={ 0 };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tem[i][j] = random(50);
        }
    }
    WriteArray(tem, n);
    WriteStruct(tem, n);
}

/***********************************************
函数名称:
    数组储存三元组；
功能描述:
    将传入的参数存储到指定的二维数组中；
函数参数:
    指向临时储存随机数三元组的二维数组的指针 int (*tem)[3]；
    三元组的个数n；
返回值:
    无返回值
模块历史:
    蔡晞阳于20190312创建本模块，email：18281031@bjtu.edu.cn
**********************************************/
void WriteArray(int (*tem)[3],  int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
           TriTuple[i][j] = tem[i][j];
        }
    }
}

/***********************************************
函数名称:
    结构体储存三元组；
功能描述:
    将传入的参数存储到指定的结构体数组中；
函数参数:
    指向临时储存随机数三元组的二维数组的指针 int (*tem)[3]；
    三元组的个数n；
返回值:
    无返回值
模块历史:
    蔡晞阳于20190312创建本模块，email：18281031@bjtu.edu.cn
**********************************************/
void WriteStruct(int (*tem)[3], int n)
{
    for (int i = 0; i < n; i++)
    {
        ans[i].x = tem[i][0];
        ans[i].y = tem[i][1];
        ans[i].z = tem[i][2];
    }
}