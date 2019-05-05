#include "Lab5_fun.h"

void iniconf(CONF *info)
{
    FILE *op = NULL;
    op = fopen("conf.ini","r");

    fscanf(op, "%s", info->filesavepath);
    fscanf(op, "%s", info->filename);

    transRel(info);
    char realPath[1000];
    strcpy(realPath, info->filesavepath);
    strcat(strcat(realPath,"/"), info->filename);
    strcpy(info->realPath,realPath); //从配置信息变量中获取数据文件存放目录与文件名，将其拼装为完整的文件路径，并储存到配置文件中

    fclose(op);

//读取数据记录文件中的数据条数，并储存到配置文件中
    op = fopen(info->realPath,"r");

    fscanf(op, "%d", &info->number);

    fclose(op);
}

void transRel(CONF *info)
{
    char path[100];
    strcpy(path, info->filesavepath);
    char cwd[100];
    char *index1, *index2, *name;
    int cut = count(path);

    _getcwd(cwd,sizeof(cwd));//将工作区目录储存在字符数组cwd中

    for(int i = 1; i <= cut ; i++)//从后往前找若干个分隔符，并就将其前面的所有字符组成新的字符串
    {
        index1 = strrchr(cwd,'/');
        index2 = strrchr(cwd,'\\');
        if(index1 > index2)
        {
            *index1 = '\0';
        }
        else
        {
            *index2 = '\0';
        }
    }
    name = GetOffset(path) + path - 1;//将“../”与“./”后的路径储存在name中
    strcat(cwd, name);
    strcpy(path, cwd);//将相对路径转换为绝对路径，重新储存在path中，供后续使用
    
    strcpy(info->filesavepath, path);
}

/*
*函数名称：count；
*函数功能：获取相对路径中的 “../” 的个数，即向上多少级目录；
*输入参数：储存路径的字符串;
*返回值：“../” 的个数；
*版本信息：create by CaiXiyang, 2019-03-28, email:18281031@bjtu.edu.cn
*/
int count(char* path)
{
    int counter = 0;
    while(strstr(path, "../") == path)
    {
        path += 3;
        counter++;
    }
    return counter;
}

/*
*函数名称：GetOffset；
*函数功能：获取相对路径中的 “../” 与 “./” 所占的字符数；
*输入参数：储存路径的字符串;
*返回值：“../” 与 “./” 所占的字符数；
*版本信息：create by CaiXiyang, 2019-03-28, email:18281031@bjtu.edu.cn
*/
int GetOffset(char *path)
{
    int offset = 0;
    while(strstr(path, "../") == path)
    {
        path += 3;
        offset += 3;
    }

    while(strstr(path, "./") == path)
    {
        path += 2;
        offset += 2;
    }
    return offset;
}

void read_array(CONF *info, int (*arr)[3])
{
  
    FILE *op = NULL;
    op = fopen(info->realPath,"r");

    fscanf(op, "%d", &arr[0][0]);
    for(int i = 1; i <= info->number; i++)
    {
        for(int j = 0; j <= 2; j++)
        {
            fscanf(op, "%d", &arr[i][j]);
        }
    }

    fclose(op);
}

