#include "Lab4_run.h"
#include "Lab4_fun.h"


void run (int argc , char* argv[])
{
	char input[1000], tem[1000];
    int i = 0,flag = 0;
    srand((int)time(0));

    CONF info;
    iniconf(&info);//为结构体变量各个分量初始化默认值

    if(isRelPath(info.filesavepath))//判断路径是否为相对路径。若是，将其转换为相对路径
    {
        char path[100];
        strcpy(path, info.filesavepath);

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
        strcpy(info.filesavepath, cwd);//将相对路径转换为绝对路径，重新储存在path中，供后续使用  
    }    

    switch (argc)
    {
        case 1:
            printf("是否随机生成记录条数?(y/n)\n");//询问是否随机生成记录条数
            while(1)
            {
                scanf("%s",tem);
                fflush(stdin);
                if((tem[0] == 'y') || (tem[0] == 'n'))
                {
                    break;
                }
                printf("输入错误！请重试。\n");
                printf("是否随机生成记录条数?(y/n)\n");
            }

            if(tem[0] == 'y')//是
            {
                info.number = random(info.recordcount2,info.recordcount1);//随机生成记录条数数写入配置信息变量
            }
            else //否
            {
                printf("请输入记录条数:\n");//提示用户输入记录条数
                while(1)
                {
                    scanf("%s",input);
                    fflush(stdin);
                    if(isNum(input, strlen(input)))
                    {
                        break;
                    }
                    printf("输入错误!请输入一个数字。\n");//提示错误信息
                }   
                info.number = atoi(input);//将用户输入的记录数信息写入配置信息变量
            }                                      
            flag++;
            break;
        case 2:
            if(isNum(argv[1], strlen(argv[1])))//命令行参数是数值？
            {
                info.number = atoi(argv[1]);//从命令行参数中取出记录条数信息写入配置信息变量
                flag++;                
                break;
            }

            if(isPath(argv[1])) //命令行参数是否合法？
            {
                DivPath(argv[1], &info);//从命令行参数中取出文件路径拆分成文件名和文件存储目录写入配置信息变量

                printf("Input the number of the data\n");//提示用户输入记录条数
        
                while(1)
                {
                    scanf("%s",input);
                    fflush(stdin);
                    if(isNum(input, strlen(input)))
                    {
                        break;
                    }
                    printf("INPUT ERROR! PLEASE RETRY.\n");//提示错误信息
                }
                
                printf("Randomly generate the number of data?(Y/N)\n");//询问是否随机生成记录条数

                while(1)
                {
                    scanf("%s", tem);
                    fflush(stdin);
                    if((tem[0] == 'Y') || (tem[0] == 'N'))
                    {
                        break;
                    }
                    printf("INPUT ERROR! PLEASE RETRY.\n");
                    printf("Randomly generate the number of data?(Y/N)\n");
                }

                if(tem[0] == 'Y')//是
                {
                    info.number = random(info.recordcount2,info.recordcount1);//随机生成记录条数数写入配置信息变量
                }
                else //否
                {
                    info.number = atoi(input);//将用户输入的记录数信息写入配置信息变量
                }
            }
            break;
        case 3:
            if(isNum(argv[1], strlen(argv[1])))//第一个参数是数值
            {
                info.number = atoi(argv[1]);//从命令行参数中取出第一个参数作为记录条数存入配置信息变量
                if(isPath(argv[2])) //第二个参数是否合法？
                {
                    DivPath(argv[2], &info);//从第二个参数中取出文件路径拆分成文件名和文件存储目录写入配置信息变量
                    break;
                }
                else
                {
                    printf("Command-line Argument ERROR!\n");//提示命令行参数不合法
                    return;
                }               
            }
            else
            {
                if(isNum(argv[2], strlen(argv[2])))//第二个参数是数值？
                {
                    info.number = atoi(argv[2]);//从命令行参数中取出第二个参数作为记录条数存入配置信息变量
                    if(isPath(argv[1])) //第一个参数是否合法？
                    {
                        DivPath(argv[1], &info);//从命令行参数中取出第一个参数——文件路径拆分成文件名和文件存储目录写入配置信息变量
                        break;
                    }
                    else
                    {
                        printf("Command-line Argument ERROR!\n");//提示命令行参数不合法
                        return;
                    }               
                }
                else
                {
                    printf("Can't find any parameter which records the number of data!\n");//提示用户输入的两个命令行参数中找不到记录条数参数
                    return;
                }                
            }
        case 4:
            {
                info.number = random(info.recordcount2, info.recordcount1);
                if(strcmp(argv[3],"dat") == 0)
                {
                    info.type = 1;
                    break;
                }
                if(strcmp(argv[3],"txt") == 0)
                {
                    info.type = 2;
                    break;
                }
                if(strcmp(argv[3],"both") == 0)
                {
                    info.type = 0;
                    break;
                }
            }
        case 5:
            {
                printf("是否随机生成记录条数?(y/n)\n");//询问是否随机生成记录条数
                while(1)
                {
                    scanf("%s",tem);
                    fflush(stdin);
                    if((tem[0] == 'y') || (tem[0] == 'n'))
                    {
                        break;
                    }   
                    printf("输入错误！请重试。\n");
                    printf("是否随机生成记录条数?(y/n)\n");
                }

                if(tem[0] == 'y')//是
                {
                    info.number = random(info.recordcount2,info.recordcount1);//随机生成记录条数数写入配置信息变量
                }
                else //否
                {
                    printf("请输入记录条数:\n");//提示用户输入记录条数
                    while(1)
                    {
                        scanf("%s",input);
                        fflush(stdin);
                        if(isNum(input, strlen(input)))
                        {
                            break;
                        }
                        printf("输入错误!请输入一个数字。\n");//提示错误信息
                    }      
                    info.number = atoi(input);//将用户输入的记录数信息写入配置信息变量
                }                                      
                flag++;

                if(strcmp(argv[4],"dat") == 0)
                {
                    info.type = 1;
                    break;
                }
                if(strcmp(argv[4],"txt") == 0)
                {
                    info.type = 2;
                    break;
                }
                if(strcmp(argv[4],"both") == 0)
                {
                    info.type = 0;
                    break;
                }
            }
        default:
            printf("Too many parameter!\n");
            break;
    }

    if(flag == 1)
    {
        printf("请输入文件存储路径:\n");//提示用户输入文件存储路径
        while(1)
        {
            scanf("%s",input);
            fflush(stdin);
            if(isPath(input))
            {
                break;
            }
            printf("输入错误!请输入正确路径。\n");//提示错误信息
        }
        transRel(input, &info);

        printf("请输入文件名:\n");//提示用户输入文件名
        scanf("%s",input);
        fflush(stdin);
        strcpy(info.filename, input);
    }

    if(argc != 4 && argc != 5)
    {
        printf("请选择输出数据文件类型(txt/dat/both)\n");
        while(1)
        {
            scanf("%s",input);
            fflush(stdin);
            if(strcmp(input,"dat") == 0)
            {
                info.type = 1;
                break;
            }
            if(strcmp(input,"txt") == 0)
            {
                info.type = 2;
                break;
            }
            if(strcmp(input,"both") == 0)
            {
                info.type = 0;
                break;
            }
            printf("INPUT ERROR! PLEASE RETRY.\n");//提示错误信息
        }
    }
    
    
    BuildDataFile(&info);//调用生成数据文件函数，根据配置信息生成数据文件(流程见图3-2)
}
