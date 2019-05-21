#include <string.h>
#include "Lab6_call.h"
#include "Lab6_data.h"
/*type: 1->txt,  2->dat
  mode: 1->Auto, 2->Manual*/
void lab4_write(int type, int mode,CONF *info)
{
    switch (type)
    {
    case 1:

        if(strstr(info->filename, ".txt") == info->filename + strlen(info->filename) - 4)
        {
            info->filename[strlen(info->filename) - 3] = 'd';
            info->filename[strlen(info->filename) - 2] = 'a';
        }

        if(mode == 1)
        {
            system("Lab4 0 0 txt");
        }
        else if(mode == 2)
        {
            system("Lab4 0 0 0 txt");
        }
        else
        {
            printf("输入模式选择错误。使用自动模式请输1，交互模式请输2。");
        }
        break;
    
    case 2:

        if(strstr(info->filename, ".dat") == info->filename + strlen(info->filename) - 4)
        {
            info->filename[strlen(info->filename) - 3] = 't';
            info->filename[strlen(info->filename) - 2] = 'x';
        }

        if(mode == 1)
        {
            system("Lab4 0 0 dat");
        }
        else if(mode == 2)
        {
            system("Lab4 0 0 0 dat");
        }
        else
        {
            printf("输入模式选择错误。使用自动模式请输1，交互模式请输2。");
        }
        break;
    default:
        break;
    }
}