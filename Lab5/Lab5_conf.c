#include "Lab5_conf.h"

void changeConf(CONF *info)
{
    
    char tem[100];
    int temp;

    printf("\n原 文件储存路径 为:\n%s\n",info->filesavepath);
    printf("请输入新的 文件存储目录（若不修改，请输入\"N\"）\n");
    scanf("%s",tem);
    if(strcmp(tem, "N"))
    {
        strcpy(info->filesavepath, tem);
    }
    
    printf("\n原 文件名 为:\n%s\n",info->filename);
    printf("请输入新的 文件名（若不修改，请输入\"N\"）\n");
    scanf("%s",tem);
    if(strcmp(tem, "N"))
    {
        strcpy(info->filename, tem);
    }

    printf("\n原 生成的数据记录三元组中第1、2个元素取值的上限 为:\n%d\n",info->maxvalue1);
    printf("请输入新的 上限（若不修改，请输入\"N\"）\n");
    scanf("%d",&temp);
    if(temp != 'N')
    {
        info->maxvalue1 = temp;
    }

    printf("\n原 生成的数据记录三元组中第1、2个元素取值的下限 为:\n%d\n",info->minvalue1);
    printf("请输入新的 下限（若不修改，请输入\"N\"）\n");
    scanf("%d",&temp);
    if(temp != 'N')
    {
        info->minvalue1 = temp;
    }

    printf("\n原 生成的数据记录三元组中第3个元素取值的上限 为:\n%d\n",info->maxvalue2);
    printf("请输入新的 上限（若不修改，请输入\"N\"）\n");
    scanf("%d",&temp);
    if(temp != 'N')
    {
        info->maxvalue2 = temp;
    }

    printf("\n原 生成的数据记录三元组中第3个元素取值的下限 为:\n%d\n",info->minvalue2);
    printf("请输入新的 下限（若不修改，请输入\"N\"）\n");
    scanf("%d",&temp);
    if(temp != 'N')
    {
        info->minvalue2 = temp;
    }

    printf("\n原 随机生成记录条数时条数值的上限 为:\n%d\n",info->recordcount1);
    printf("请输入新的 上限（若不修改，请输入\"N\"）\n");
    scanf("%d",&temp);
    if(temp != 'N')
    {
        info->recordcount1 = temp;
    }

    printf("\n原 随机生成记录条数时条数值的上限 为:\n%d\n",info->recordcount2);
    printf("请输入新的 下限（若不修改，请输入\"N\"）\n");
    scanf("%d",&temp);
    if(temp != 'N')
    {
        info->recordcount2 = temp;
    }

    if(info->mode == 1)
    {
        strcpy(tem, "自动模式");
    }
    else if(info->mode == 2)
    {
        strcpy(tem, "交互模式");
    }

    printf("\n原 模式 为:%s\n",tem);
    printf("请输入新的 工作模式(1:自动模式 2:手动模式（若不修改，请输入\"N\"）\n");
    scanf("%d",&temp);
    if(temp != 'N')
    {
        info->mode = temp;
    }

    FILE *op;
    op = fopen("conf.ini","w+");

    fprintf(op, "%s\n", info->filesavepath);
    fprintf(op, "%s\n", info->filename);
    fprintf(op, "%d\n", info->maxvalue1);
    fprintf(op, "%d\n", info->minvalue1);
    fprintf(op, "%d\n", info->maxvalue2);
    fprintf(op, "%d\n", info->minvalue2);
    fprintf(op, "%d\n", info->recordcount1);
    fprintf(op, "%d\n", info->recordcount2);

    fclose(op);

    op = fopen("MODE.ini","w");
    fprintf(op, "%d", info->mode);

    fclose(op);
}