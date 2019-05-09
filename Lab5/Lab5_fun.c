#include "Lab5_fun.h"

void iniconf(CONF *info)
{
    FILE *op = NULL;
    op = fopen("conf.ini","r");

    fscanf(op, "%s", info->filesavepath);
    fscanf(op, "%s", info->filename);

    transRel(info);
    realPath(info);

    getMode(info);
    
    fclose(op);
}

void initLink(CONF *info,DATASTRUCT **h, DATASTRUCT **t, int n)
{
    FILE *op = NULL;
    op = fopen(info->realPath,"r");

    for(int i = 0; i <= n; i++)
    {
        DATASTRUCT *newnode;
        newnode = malloc(sizeof(DATASTRUCT));
        
        if(*h == NULL)
        {
            *h = newnode;
            *t = *h;
            newnode->pNextItem = NULL;
            //getinfo
            if (strstr(info->realPath, "txt") == info->realPath + strlen(info->realPath) - 3)
            {
                if(newnode == *h)
                {
                    fscanf(op, "%d", &newnode->x);
                }
                else
                {
                    fscanf(op, "%d %d %d", &newnode->x, &newnode->y, &newnode->z);
                }               
            }
            else
            {
                if(newnode == *h)
                {
                    fread(&newnode->x, sizeof(int), 1, op);
                }
                else
                {
                    fread(&newnode->x, sizeof(int), 1, op);
                    fread(&newnode->y, sizeof(int), 1, op);
                    fread(&newnode->z, sizeof(int), 1, op);
                }
            }     
        }
        else
        {
            (*t)->pNextItem = newnode;
            (*t) = (*t)->pNextItem;
            (*t)->pNextItem = NULL;
            //getinfo
            if (strstr(info->realPath, "txt") == info->realPath + strlen(info->realPath) - 3)
            {
                if(newnode == *h)
                {
                    fscanf(op, "%d", &newnode->x);
                }
                else
                {
                    fscanf(op, "%d %d %d", &newnode->x, &newnode->y, &newnode->z);
                }               
            }
            else
            {
                if(newnode == *h)
                {
                    fread(&newnode->x, sizeof(int), 1, op);
                }
                else
                {
                    fread(&newnode->x, sizeof(int), 1, op);
                    fread(&newnode->y, sizeof(int), 1, op);
                    fread(&newnode->z, sizeof(int), 1, op);
                }
            }    
        }        
    }
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

    if (strstr(info->realPath, "txt") == info->realPath + strlen(info->realPath) - 3)
    {
        fscanf(op, "%d", &arr[0][0]);
        for(int i = 1; i <= info->number; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                fscanf(op, "%d", &arr[i][j]);
            }
        }
    }
    else
    {
        fread(&arr[0][0], sizeof(int), 1, op);
        for(int i = 1; i <= info->number; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                fread(&arr[i][j], sizeof(int), 1, op);
            }            
        }
    }      

    fclose(op);
}

void Manual_read(CONF *info)
{
    char input[100];

    printf("请输入文件的存储位置\n");
    scanf("%s", input);
    strcpy(info->filesavepath, input);

    printf("请输入文件文件名\n");
    scanf("%s", input);
    strcpy(info->filename, input);

    transRel(info);
    realPath(info);
    getNum(info);
}

void show_array(int (*arr)[3])
{
    printf("\n数据条数为：\n%d\n", arr[0][0]);
    printf("各数据如下：\n");
    for(int i = 1; i <= arr[0][0]; i++)
    {
        printf("%d %d %d\n", arr[i][0], arr[i][1], arr[i][2]);
    }
}

void read_struct(CONF *info, DATASTRUCT structArr[])
{
    FILE *op = NULL;
    op = fopen(info->realPath,"r");

    if (strstr(info->realPath, "txt") == info->realPath + strlen(info->realPath) - 3)
    {
        fscanf(op, "%d", &structArr[0].x);
        for(int i = 1; i <= info->number; i++)
        {
            fscanf(op, "%d %d %d", &structArr[i].x, &structArr[i].y, &structArr[i].z);
        }
    }
    else
    {
        fread(&structArr[0].x, sizeof(int), 1, op);
        for(int i = 1; i <= info->number; i++)
        {            
            fread(&structArr[i].x, sizeof(int), 1, op);
            fread(&structArr[i].y, sizeof(int), 1, op);
            fread(&structArr[i].z, sizeof(int), 1, op);
        }
    }      

    fclose(op);
    return;
}

void read_PointerStruct(CONF *info, DATASTRUCT *a[])
{
    FILE *op = NULL;
    op = fopen(info->realPath,"r");

    if (strstr(info->realPath, "txt") == info->realPath + strlen(info->realPath) - 3)
    {
        fscanf(op, "%d", &(a[0]->x));
        for(int i = 1; i <= info->number; i++)
        {
            fscanf(op, "%d %d %d", &(a[i]->x), &(a[i]->y), &(a[i]->z));
        }
    }
    else
    {
        fread(&(a[0]->x), sizeof(int), 1, op);
        for(int i = 1; i <= info->number; i++)
        {            
            fread(&(a[i]->x), sizeof(int), 1, op);
            fread(&(a[i]->y), sizeof(int), 1, op);
            fread(&(a[i]->z), sizeof(int), 1, op);
        }
    }      

    fclose(op);
    return;    
}

void getinfo(CONF *info, DATASTRUCT *node, DATASTRUCT *head)
{
    FILE *op = NULL;
    op = fopen(info->realPath,"r");

    if (strstr(info->realPath, "txt") == info->realPath + strlen(info->realPath) - 3)
    {
        if(node == head)
        {
            fscanf(op, "%d", &node->x);
        }
        else
        {
            fscanf(op, "%d %d %d", &node->x, &node->y, &node->z);
        }               
    }
    else
    {
        //fread();
    }      


    fclose(op);
    return;
}

void ShowLinkData(DATASTRUCT *pHead)
{
    DATASTRUCT *pNode;
    if(pHead == NULL)
    {
        return;
    }
    for(pNode = pHead; pNode != NULL; pNode = pNode->pNextItem)
    {
        if(pNode == pHead)
        {
            printf("\n数据条数为：\n%d\n", pNode->x);
            printf("各数据如下：\n");
        }
        else
        {
            printf("%d %d %d\n", pNode->x, pNode->y, pNode->z);
        }                
    }
    return;
}

void show_struct(DATASTRUCT data[])
{
    printf("\n数据条数为：\n%d\n", data[0].x);
    printf("各数据如下：\n");
    for(int i = 1; i <= data[0].x; i++)
    {
        printf("%d %d %d\n", data[i].x, data[i].y, data[i].z);
    }
}

void show_PointerStruct(DATASTRUCT *a[])
{
    
    printf("\n数据条数为：\n%d\n", a[0]->x);
    printf("各数据如下：\n");
    for(int i = 1; i <= a[0]->x; i++)
    {
        printf("%d %d %d\n", a[i]->x, a[i]->y, a[i]->z);
    }
}