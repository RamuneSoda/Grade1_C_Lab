#include "Lab6_conf.h"

void changeConf(CONF *info)
{
    
    char tem[100];
    int temp, input;

    while (1)
        {
            while(1)
                {
                    printf("\n实验五修改配置菜单：\n"
                    "   1. 修改文件存储目录\n"
                    "   2. 修改文件名称\n"
                    "   3. 修改第一、二个元素最大值\n"
                    "   4. 修改第一、二个元素最小值\n"
                    "   5. 修改第三个元素最大值\n"
                    "   6. 修改第三个元素最小值\n"
                    "   7. 修改记录条数最大值\n"
                    "   8. 修改记录条数最小值\n"
                    "   9. 修改实验5工作模式参数\n"
                    "   0. 退出\n"
                    "请输入您要执行的功能序号：");  /**/

                    scanf("%d",&input);
                    fflush(stdin);
                    if(input >= 0 && input <= 9)
                    {
                        break;
                    }
                    printf("\n请输入功能序号（0-9）\n");//提示错误信息
                }

            switch (input)
            {
            case 1:
                printf("\n原\"文件储存路径\"为:%s\n",info->filesavepath);
                printf("请输入新的\"文件存储目录\"（若不修改，请输入\"N\"）\n");
                scanf("%s",tem);
                if(strcmp(tem, "N"))
                {
                    strcpy(info->filesavepath, tem);
                }
                break;
            case 2:
                printf("\n原\"文件名\"为:%s\n",info->filename);
                printf("请输入新的\"文件名\"（若不修改，请输入\"N\"）\n");
                scanf("%s",tem);
                if(strcmp(tem, "N"))
                {
                    strcpy(info->filename, tem);
                }
                break;
            case 3:
                printf("\n原\"生成的数据记录三元组中第1、2个元素取值的上限\"为:%d\n",info->maxvalue1);
                printf("请输入新的\"上限\"（若不修改，请输入\"N\"）\n");
                scanf("%d",&temp);
                if(temp != 'N')
                {
                    info->maxvalue1 = temp;
                }
                break;
            case 4:
                printf("\n原\"生成的数据记录三元组中第1、2个元素取值的下限\"为:%d\n",info->minvalue1);
                printf("请输入新的\"下限\"（若不修改，请输入\"N\"）\n");
                scanf("%d",&temp);
                if(temp != 'N')
                {
                    info->minvalue1 = temp;
                }
                break;
            case 5:
                 printf("\n原\"生成的数据记录三元组中第3个元素取值的上限\"为:%d\n",info->maxvalue2);
                printf("请输入新的\"上限\"（若不修改，请输入\"N\"）\n");
                scanf("%d",&temp);
                if(temp != 'N')
                {
                    info->maxvalue2 = temp;
                }
                break;
            case 6:
                printf("\n原\"生成的数据记录三元组中第3个元素取值的下限\"为:%d\n",info->minvalue2);
                printf("请输入新的\"下限\"（若不修改，请输入\"N\"）\n");
                scanf("%d",&temp);
                if(temp != 'N')
                {
                    info->minvalue2 = temp;
                }
                break;
            case 7:
                printf("\n原\"随机生成记录条数时条数值的上限\"为:%d\n",info->recordcount1);
                printf("请输入新的\"上限\"（若不修改，请输入\"N\"）\n");
                scanf("%d",&temp);
                if(temp != 'N')
                {
                    info->recordcount1 = temp;
                }
                break;
            case 8:
                printf("\n原\"随机生成记录条数时条数值的上限\"为:%d\n",info->recordcount2);
                printf("请输入新的\"下限\"（若不修改，请输入\"N\"）\n");
                scanf("%d",&temp);
                if(temp != 'N')
                {
                    info->recordcount2 = temp;
                }
                break;
            case 9:
                if(info->mode == 1)
                {
                    strcpy(tem, "自动模式");
                }
                else if(info->mode == 2)
                {
                    strcpy(tem, "交互模式");
                }

                printf("\n原\"工作模式\"为:%s\n",tem);
                printf("请输入新的\"工作模式\"(1:自动模式 2:手动模式（若不修改，请输入\"N\"）\n");
                scanf("%d",&temp);
                if(temp != 'N')
                {
                    info->mode = temp;
                }
                break;
            case 0:
                return;
            default:
                break;
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
}