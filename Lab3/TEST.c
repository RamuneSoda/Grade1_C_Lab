#include <stdio.h>
#include <string.h>

int isPath(char *pPath)
{
    int len = strlen(pPath);
    if(strstr(pPath, "\\") - pPath == 0) //不能以\\开头
    {
        return 0;
    }
    if(pPath[0] >= 'A' && pPath[0] <= 'Z') //是绝对路径吗？
    {
        if(strstr(pPath, ":/") == (pPath + 1) || strstr(pPath, ":\\") == (pPath + 1) )
        {
            for(int i = 0; i <= len -1; i++)
            {
                switch (pPath[i])
                {
                    case ':':
                        if(i != 1)
                        {
                            return 0;
                        }
                        break;
                    case '*':
                        return 0;
                    case '?':
                        return 0;                    
                    case '<':
                        return 0;
                    case '>':
                        return 0;
                    case '|':
                        return 0;
                    case '\\':
                        return 0;
                    default:
                        break;
                }
            }
        }
        else
        {
            return 0;
        }
        

        if(strstr(pPath, "\\") == (pPath + len -1) ||(strchr(pPath, '/') == (pPath + len )))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char path[100];
    gets(path);
    printf("%d",isPath(path));

}