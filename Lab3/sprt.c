#include <stdio.h>
#include <string.h>

int main()
{
    char path[1000],filename[100],filepath[100];
    int i;
    gets(path);
    for(i = strlen(path) - 1; (path[i] != '\\') && (path[i] != '/'); i--);//从命令行参数中取出文件路径拆分成文件名和文件存储目录写入配置信息变量
    strncpy(filename, path , i);
    strncpy(filepath, path + i + 1, strlen(path) - i);
    puts(filepath);
    puts(filename);
    return 0;
}
