#include <stdio.h>
#include <string.h>
#include <direct.h>
int count(char* path)
{
    int counter = 0;
    while(strstr(path, "../") == path)
    {
        path += 3;
        counter++;
    }

    while(strstr(path, "./") == path)
    {
        path += 2;
        counter++;
    }
    return counter;
}
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

int isRelPath(char *path)
{
    int i, j;
    char ban[]={'*','?','<','>','|',':'};
    i = j = 0;

    while(strstr(path, "../") == path)
    {
        path += 3;
        i++;
    }

    while(strstr(path, "./") == path)
    {
        path += 2;
        j++;
    }

    if(i != 0 && j != 0)//"./"与"../"不能同时出现
    {
        return 0;
    }

    for(int i = 0; i < 5; i++)//不能出现非法字符
    {
        for(int j = 0; j < strlen(path); j++)
        {
            if(ban[i] == path[j])
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    char path[100];
    char cwd[100],real[100];
    char *index1, *index2, *name;
    gets(path);
    _getcwd(cwd,sizeof(cwd));
    for(int i = 1; i <= count(path); i++)
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
    //strcpy(real, cwd);
    name = GetOffset(path) + path - 1;
    strcat(cwd, name);
    printf("%s\n", cwd);
}