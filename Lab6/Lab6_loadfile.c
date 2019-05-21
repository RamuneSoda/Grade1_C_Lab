#include "Lab6_loadfile.h"
#include "Lab6_init.h"

void initLink(CONF *info,DATASTRUCT **h, DATASTRUCT **t, int n)
{
    FILE *op = NULL;
    transRel(info);
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