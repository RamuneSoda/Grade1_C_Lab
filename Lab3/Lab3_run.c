#include <Lab3_run.h>
#include <Lab3_fun.h>
#include <Lab3_data.h>


void run (int argc , char* argv[])
{
    char input[100000];
    int flag = 0;

    CONF info;
    info.maxvalue1 = 50;
    info.minvalue1 = 0;
    info.maxvalue2 = 20;
    info.minvalue2 = 0;
    info.recordcount1 = 50;
    info.recordcount2 = 1;//为结构体变量各个分量初始化默认值

    switch (argc)
    {
        case 1:
            //提示用户输入记录条数
            while(isNum(input, strlen(input)))
            {
                //提示错误信息
            }
            //询问是否随机记录条数  
            if(//是)
            {
                //随机生成记录条数数写入配置信息变量
            }
            else//否
            {
                //将用户输入的记录数信息写入配置信息变量
            }
            flag++;
            break;
        case 2:
            if(isNum(argv[1], strlen(argv[1])))//命令行参数是数值？
            {
                //从命令行参数中取出记录条数信息写入配置信息变量
                flag++;
                break;
            }

            if(isPath(argv[1], strlen(argv[1]))) //命令行参数是否合法？
            {
                //从命令行参数中取出文件路径拆分成文件名和文件存储目录写入配置信息变量
                //提示用户输入记录条数
                while(isNum(input, strlen(input)))
                {
                    //提示错误信息
                }
                //询问是否随机记录条数  
                if(//是)
                {
                    //随机生成记录条数数写入配置信息变量
                }
                else//否
                {
                //将用户输入的记录数信息写入配置信息变量
                }
            }
            else
            {
                //提示命令行参数不合法
                return;
            }
            break;
        case 3:
            if(//第一个参数是数值)
            {
                //从命令行参数中取出第一个参数作为记录条数存入配置信息变量
                if(isPath(argv[2],strlen(argv[2]))) //第二个参数是否合法？
                {
                    //从命令行参数中取出第二个参数作为文件存储路径，拆分后存入配置信息变量
                    break;
                }
                else
                {
                    //提示命令行参数不合法
                    return;
                }               
            }
            else
            {
                if(//第二个参数是数值？)
                {
                    //从命令行参数中取出第二个参数作为记录条数存入配置信息变量
                     if(isPath(argv[1],strlen(argv[1]))) //第一个参数是否合法？
                    {
                        //从命令行参数中取出第二个参数作为文件存储路径，拆分后存入配置信息变量
                        break;
                    }
                    else
                    {
                        //提示命令行参数不合法
                        return;
                    }               
                }
                else
                {
                    //提示用户输入的两个命令行参数中找不到记录条数参数
                    return;
                }                
            }
        default:
            break;
    }

    if(flag == 0)
    {
        //提示用户输入文件存储路径
        while(isPath(input,strlen(input)))
        {
            //提示错误信息
        }
        //将用户输入的文件路径拆分成文件名和文件存储目录写入配置信息变量
    }

    //调用生成数据文件函数，根据配置信息生成数据文件(流程见图3-2)
}
