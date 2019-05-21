#include "Lab6_view.h"

void show_array(int (*arr)[3], int i)
{
    printf("\n/************************************/\n");

    if(i)
    {
        printf("当前使用二维数组储存数据（排序前）\n\n");
    }
    else
    {
        printf("当前使用二维数组储存数据（排序后）\n\n"); 
    }
    
    printf("数据条数为：%d\n", arr[0][0]);
    printf("各数据如下：\n");
    for(int i = 1; i <= arr[0][0]; i++)
    {
        printf("%d %d %d\n", arr[i][0], arr[i][1], arr[i][2]);
    }
    printf("/************************************/\n");
}

void show_struct(DATASTRUCT data[], int i)
{
    printf("\n/************************************/\n");

    if(i)
    {
        printf("当前使用结构体数组储存数据（排序前）\n\n");
    }
    else
    {
        printf("当前使用结构体数组储存数据（排序后）\n\n"); 
    }
    
    printf("数据条数为：%d\n", data[0].x);
    printf("各数据如下：\n");
    for(int i = 1; i <= data[0].x; i++)
    {
        printf("%d %d %d\n", data[i].x, data[i].y, data[i].z);
    }
    printf("/************************************/\n");
}

void show_PointerStruct(DATASTRUCT *a[], int i)
{
    printf("\n/************************************/\n");

    if(i)
    {
        printf("当前使用结构体指针数组储存数据（排序前）\n\n");
    }
    else
    {
       printf("当前使用结构体指针数组储存数据（排序后）\n\n");
    }
    
    printf("数据条数为：%d\n", a[0]->x);
    printf("各数据如下：\n");
    for(int i = 1; i <= a[0]->x; i++)
    {
        printf("%d %d %d\n", a[i]->x, a[i]->y, a[i]->z);
    }
    printf("/************************************/\n");
}

void ShowLinkData(DATASTRUCT *pHead, int i)
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
            printf("\n/************************************/\n");
            if(i)
            {
                printf("当前使用链表储存数据（排序前）\n\n");
            }
            else
            {
                printf("当前使用链表储存数据（排序后）\n\n");
            }
            
            printf("数据条数为：%d\n", pNode->x);
            printf("各数据如下：\n");
        }
        else
        {
            printf("%d %d %d\n", pNode->x, pNode->y, pNode->z);
        }         
    }
    printf("/************************************/\n");
    return;
}