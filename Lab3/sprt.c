#include <stdio.h>
#include <string.h>

int main()
{
    char path[1000],filename[100],filepath[100];
    int i;
    gets(path);
    for(i = strlen(path) - 1; (path[i] != '\\') && (path[i] != '/'); i--);//从命令行参数中取出文件路径拆分成文件名和文件存储目录写入配置信息变量
    printf("%d\n",i);
    if(path[i] == '\\')
    {
        strncpy(filepath, path, i - 1);
        filepath[i-1] = '\0';
    }
    else
    {
        strncpy(filepath, path, i);
        filepath[i + 1] = '\0';
    }
    strncpy(filename, path + i + 1, strlen(path) - i -1);
    char RealPath[1000];
    strcpy(RealPath, filepath);
    strcat(strcat(RealPath,"/"),filename);
    puts(filepath);
    puts(filename);
    puts(RealPath);
    return 0;
}
