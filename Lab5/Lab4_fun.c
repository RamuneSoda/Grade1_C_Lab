#include "Lab4_fun.h"

/*
*函数名称：isNum；
*函数功能：判断传入字符串是否为纯数字；
*输入参数：指向字符数组的指针 char *str，字符串长度 int n;
*返回值：若字符串为纯数字，返回1；
        否则，返回0；
*版本信息：create by CaiXiyang, 2019-03-28, email:18281031@bjtu.edu.cn
*/
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

/*
*函数名称：isPath；
*函数功能：判断字符串是否为合法路径；
*输入参数：储存路径字符串的首地址;
*返回值：若合法，返回1；否则，返回0；
*版本信息：create by CaiXiyang, 2019-03-28, email:18281031@bjtu.edu.cn
*/
int isPath(char *path)
{
    int len = strlen(path);
    if(strstr(path, "\\") - path == 0) //不能以\\开头
    {
        return 0;
    }

    if((isAbsPath(path) == 0) && (isRelPath(path) == 0))
    {
        return 0;
    }

    return 1;

}

/*
*函数名称：isAbsPath；
*函数功能：判断指定的路径是否为绝对路径；
*输入参数：储存路径的字符串;
*返回值：若是，返回1；若不是，返回0；
*版本信息：create by CaiXiyang, 2019-03-28, email:18281031@bjtu.edu.cn
*/
int isAbsPath(char *path)
{
    char ban[]={'*','?','<','>','|',':'};

    if((path[0] < 'A') || (path[0] > 'Z'))//盘符要正确
    {
        return 0;
    }

    if(strstr(path, ":/") != (path + 1) && strstr(path, ":\\") != (path + 1) )/* 盘符后要跟:/或:\ */
    {
        return 0;
    }

    for(int i = 0; i < 5; i++)//不能出现非法字符
    {
        for(int j = 3; j < strlen(path); j++)
        {
            if(ban[i] == path[j])
            {
                return 0;
            }
        }
    }
    return 1;
}

/*
*函数名称：isRelPath；
*函数功能：判断指定的路径是否为相对路径；
*输入参数：储存路径的字符串;
*返回值：若是，返回1；若不是，返回0；
*版本信息：create by CaiXiyang, 2019-03-28, email:18281031@bjtu.edu.cn
*/
int isRelPath(char *path)
{
    int i, j;
    char ban[]={'*','?','<','>','|',':'};
    i = j = 0;

    while(strstr(path, "../") == path)
    {
        path += 3;
        i++;
    }

    while(strstr(path, "./") == path)
    {
        path += 2;
        j++;
    }

    if(!(i ^ j))// "./" 与 "../" 不能同时出现，也不能同时不出现
    {
        return 0;
    }

    for(int i = 0; i < 5; i++)//不能出现非法字符
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

/*
*函数名称：isFileExist；
*函数功能：判断指定的路径是否存在指定的文件夹；
*输入参数：储存路径的字符串;
*返回值：若存在，返回1；若不存在，返回0；
*版本信息：create by CaiXiyang, 2019-03-28, email:18281031@bjtu.edu.cn
*/
int isFileExist(char *path)
{
	if (access(path, 0) == 0)
		return 1;
	else
		return 0;
}

/*
*函数名称：BuildDataFile；
*函数功能：生产数据文件；
*输入参数：指向结构体变量CONF的地址;
*返回值：无；
*版本信息：create by CaiXiyang, 2019-03-28, email:18281031@bjtu.edu.cn
*/
void BuildDataFile(CONF *info)
{
    
    
    mkdir_m(info->filesavepath);//若用户输入的路径不存在，则创建该路径

    DATAITEM *data = NULL;//动态内存申请
    data = (DATAITEM*)malloc(sizeof(DATAITEM) * info->number);
    

    char RealPath[1000];

    strcpy(RealPath, info->filesavepath);
    strcat(strcat(RealPath,"/"), info->filename); //从配置信息变量中获取数据文件存放目录与文件名，将其拼装为完整的文件路径
    
    //从配置信息中取出记录条数并写入文件
    for(int i = 0; i < info->number; i++)//执行数据条数次
    {
        data[i].x = random(info->minvalue1,info->maxvalue1);//调用随机函数获取一个指定范围内的整数，作为第一个元素
        data[i].y = random(info->minvalue1,info->maxvalue1);//调用随机函数获取一个指定范围内的整数，作为第二个元素
        while(data[i].x == data[i].y)//第一、第二个元素相等
        {
            data[i].y = random(info->minvalue1,info->maxvalue1);//调用随机函数获取一个指定范围内的整数，作为第二个元素
        }
        data[i].z = random(info->minvalue2,info->maxvalue2);//调用随机函数获取一个指定范围内的整数，作为第三个元素
        //将三个元素形成一条记录数据，暂存入数据容器
    }

	clock_t start,finish;
	double TheTimes; 

    switch (info->type)
    {

    case 1:
        start=clock();
        buildBin(info, data, RealPath);
        finish=clock();
        TheTimes=(double)(finish-start)/CLOCKS_PER_SEC;
        printf("Output binary file took %fs\n",TheTimes);
        break;

    case 2:
        start=clock();
        buildTxt(info, data, RealPath);
        finish=clock();
        TheTimes=(double)(finish-start)/CLOCKS_PER_SEC;
        printf("Output txt file took %fs\n",TheTimes);
        break; 

    default:
        start=clock();
        buildBin(info, data, RealPath);
        finish=clock();
        TheTimes=(double)(finish-start)/CLOCKS_PER_SEC;
        printf("Output binary file took %fs\n",TheTimes);

        start=clock();
        buildTxt(info, data, RealPath);
        finish=clock();
        TheTimes=(double)(finish-start)/CLOCKS_PER_SEC;
        printf("Output txt file took %fs\n",TheTimes);
    }
}

/*
*函数名称：DivPath；
*函数功能：将输入的路径划分为文件名及储存的路径，并将其存放到配置文件中；
*输入参数：储存需要划分的路径的字符串，配置文件的地址;
*返回值：无；
*版本信息：create by CaiXiyang, 2019-03-28, email:18281031@bjtu.edu.cn
*/
void DivPath(char *path,  CONF *info_1)
{
    int i;
    if(isRelPath(path))//判断是否为相对路径。若是，将其转换为绝对路径
    {
        
        char cwd[100];
        char *index1, *index2, *name;
        int cut = count(path);

        _getcwd(cwd,sizeof(cwd));//将工作区目录储存在字符数组cwd中

        for(i = 1; i <= cut ; i++)//从后往前找若干个分隔符，并就将其前面的所有字符组成新的字符串
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
    }

    //从path中取出文件路径拆分成文件名和文件存储目录写入配置信息变量
    for(i = strlen(path) - 1; (path[i] != '\\') && (path[i] != '/'); i--);//找到最后一个分隔符所在的位置引索i

    strncpy(info_1->filesavepath, path, i);//i之前的为文件路径
	info_1->filesavepath[i] = '\0';
    
    strncpy(info_1->filename, path + i + 1, strlen(path) - i -1);//i之后的作为文件名
	info_1->filename[strlen(path) - i - 1] = '\0';
}

/*
*函数名称：mkdir_m；
*函数功能：创建指定的路径；
*输入参数：储存路径的字符串;
*返回值：无；
*版本信息：create by CaiXiyang, 2019-03-28, email:18281031@bjtu.edu.cn
*/
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

void iniconf(CONF *info)
{
    FILE *op;
    op = fopen("conf.ini","r");
    fscanf(op, "%s", &info->filesavepath);
    fscanf(op, "%s", &info->filename);

    fscanf(op, "%d", &info->maxvalue1);
    fscanf(op, "%d", &info->minvalue1);
    fscanf(op, "%d", &info->maxvalue2);
    fscanf(op, "%d", &info->minvalue2);
    fscanf(op, "%d", &info->recordcount1);
    fscanf(op, "%d", &info->recordcount2);
    info->type = 0;

    fclose(op);
}

void buildBin(CONF *info, DATAITEM *data,char* RealPath)
{
    if(strstr(RealPath, ".txt") == RealPath + strlen(RealPath) - 4)
    {
        RealPath[strlen(RealPath) - 3] = 'd';
        RealPath[strlen(RealPath) - 2] = 'a';
    }

    FILE *op;
    op = fopen (RealPath, "w");//打开文件并清空文件中的已有内容

    if(op != NULL)//文件打开成功？
    {                
        fwrite(&info->number, sizeof(int), 1, op);
        for(int i = 0; i <=  info->number; i++)
        {
            fwrite(&data[i], sizeof(DATAITEM), 1, op); 
        }              
    }
    else
    {
        printf("OPEN FILE ERROR!\n");//输出错误提示
        return;
    }
}

void buildTxt(CONF *info, DATAITEM *data,char* RealPath)
{
    if(strstr(RealPath, ".dat") == RealPath + strlen(RealPath) - 4)
    {
        RealPath[strlen(RealPath) - 3] = 't';
        RealPath[strlen(RealPath) - 2] = 'x';
    }

    FILE *op;
    op = fopen (RealPath, "w");//打开文件并清空文件中的已有内容

    if(op != NULL)//文件打开成功？
    {                
        fprintf(op, "%d\n",info->number);
        for(int i =0; i < info->number; i++)
        {
            fprintf(op, "%d %d %d\n", data[i].x, data[i].y, data[i].z);//将暂存在数据容器中的数据写入数据记录文件保存并关闭文件，输出文件生成成功提示信息
        }       
    }
    else
    {
        printf("OPEN FILE ERROR!\n");//输出错误提示
        return;
    }
}

void transRel(char *path,  CONF *info)
{
    if(isRelPath(path))//判断是否为相对路径。若是，将其转换为绝对路径
    {
        
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
    }
    strcpy(info->filesavepath, path);
}