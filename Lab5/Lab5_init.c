#include "Lab5_init.h"

void iniconf(CONF *info)
{
    FILE *op = NULL;
    op = fopen("conf.ini","r");

    fscanf(op, "%s", info->filesavepath);
    fscanf(op, "%s", info->filename);
    fscanf(op, "%d", &info->maxvalue1);
    fscanf(op, "%d", &info->minvalue1);
    fscanf(op, "%d", &info->maxvalue2);
    fscanf(op, "%d", &info->minvalue2);
    fscanf(op, "%d", &info->recordcount1);
    fscanf(op, "%d", &info->recordcount2);

    transRel(info);
    realPath(info);

    getMode(info);
    
    fclose(op);
}

void realPath(CONF *info)
{
    char realPath[1000];
    strcpy(realPath, info->filesavepath);
    strcat(strcat(realPath,"/"), info->filename);
    strcpy(info->realPath,realPath); //从配置信息变量中获取数据文件存放目录与文件名，将其拼装为完整的文件路径，并储存到配置文件中
}

void getNum(CONF *info)
{
    //读取数据记录文件中的数据条数，并储存到配置文件中
    FILE *op;
    
    if(strstr(info->realPath, "txt") == info->realPath + strlen(info->realPath) - 3)
    {
        op = fopen(info->realPath, "rt+");
        fscanf(op, "%d", &info->number);
    }
    else
    {
        op = fopen(info->realPath, "rt+");
        fread(&info->number, sizeof(int), 1, op);
    }
    
    fclose(op);
}

void getMode(CONF *info)
{
    FILE *op;
    op = fopen("MODE.ini", "r");
    fscanf(op, "%d", &info->mode);
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
    
    strcpy(info->realPath, path);
    realPath(info);
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

int isFileExist(char *path)
{
	if (access(path, 0) == 0)
		return 1;
	else
		return 0;
}