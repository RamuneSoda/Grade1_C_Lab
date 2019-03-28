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

void BuildDataFile(CONF *info)
{
    mkdir_m(info->filesavepath);
    int tem[1000][3];
    FILE *op;
    char RealPath[1000];
    strcpy(RealPath, info->filesavepath);
    strcat(strcat(RealPath,"/"), info->filename); //从配置信息变量中获取数据文件存放目录与文件名，将其拼装为完整的文件路径
    op = fopen (RealPath, "w");//打开文件并清空文件中的已有内容
   

    if(op != NULL)//文件打开成功？
    {
        //从配置信息中取出记录条数并写入文件
        for(int i = 0; i < info->number; i++)//执行数据条数次
        {
            tem[i][0] = random(info->minvalue1,info->maxvalue1);//调用随机函数获取一个指定范围内的整数，作为第一个元素
            tem[i][1] = random(info->minvalue1,info->maxvalue1);//调用随机函数获取一个指定范围内的整数，作为第二个元素
            while(tem[i][0] == tem[i][1])//第一、第二个元素相等
            {
                tem[i][1] = random(info->minvalue1,info->maxvalue1);//调用随机函数获取一个指定范围内的整数，作为第二个元素
            }
            tem[i][2] = random(info->minvalue2,info->maxvalue2);//调用随机函数获取一个指定范围内的整数，作为第三个元素
            //将三个元素形成一条记录数据，暂存入数据容器
        }
        for(int i =0; i < info->number; i++)
        {
            fprintf(op, "%d %d %d\n", tem[i][0], tem[i][1], tem[i][2]);//将暂存在数据容器中的数据写入数据记录文件保存并关闭文件，输出文件生成成功提示信息
        }
        
    }
    else
    {
        printf("OPEN FILE ERROR!\n");//输出错误提示
        return;
    }    
}

int isPath(char *path)
{
    int len = strlen(path);
    if(strstr(path, "\\") - path == 0) //不能以\\开头
    {
        return 0;
    }

    if((isAbsPath(path) == 0)/* || (isRelPath(path) == 0)*/)
    {
        return 0;
    }
    return 1;

}

void DivPath(char *path,  CONF *info_1)
{
    int i;
    for(i = strlen(path) - 1; (path[i] != '\\') && (path[i] != '/'); i--);//从命令行参数中取出文件路径拆分成文件名和文件存储目录写入配置信息变量
     strncpy(info_1->filesavepath, path, i);
	 info_1->filesavepath[i] = '\0';
    
    strncpy(info_1->filename, path + i + 1, strlen(path) - i -1);
	info_1->filename[strlen(path) - i - 1] = '\0';
}

int isFileExist(char *path)
{
	if (access(path, 0) == 0)
		return 1;
	else
		return 0;
}

void mkdir_m(char *muldir)
{
	int i, len;
	char str[512];
	strcpy(str, muldir);
	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		if (str[i] == '/' || str[i] == '\\')
		{
			str[i] = '\0';
			if (isFileExist(str) == 0)
			{
				if (_mkdir(str) != 0)
				{
					printf("Directory creation failed!\n");
				}
			}
			str[i] = '\\';
		}
	}
	if (len > 0 && isFileExist(str) == 0)
	{
		if (_mkdir(str) != 0)
		{
			printf("Directory creation failed!\n");
		}
	}
	_chdir(str);
}

int isAbsPath(char *path)
{
    char ban[]={'*','?','<','>','|'};

    if((path[0] < 'A') || (path[0] > 'Z'))//盘符要正确
    {
        return 0;
    }

    if(strstr(path, ":/") != (path + 1) && strstr(path, ":\\") != (path + 1) )/* 盘符后要跟:/或:\ */
    {
        return 0;
    }
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < strlen(path); j++)
        {
            if(ban[i] == path[j])
            {
                return 0;
            }
        }
    }
    return 1;
}

int isRelPath(char *path)
{
    return 0;
}