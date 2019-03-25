#include <stdio.h>
#include <direct.h>
#define MAX_PATH 1000

void main()
{
    char strDirPath[100];
    gets(strDirPath);
    if (strlen(strDirPath)> MAX_PATH )
    {
        return;
    }
    int ipathLength=strlen(strDirPath);
    int ileaveLength=0;
    int iCreatedLength=0;
    char szPathTemp[MAX_PATH]={0};
    for (int i=0;(NULL!=strchr(strDirPath+iCreatedLength,'\\'));i++)
    {
        ileaveLength=strlen(strchr(strDirPath+iCreatedLength,'\\'))-1;
        iCreatedLength=ipathLength-ileaveLength;
        strncpy(szPathTemp,strDirPath,iCreatedLength);
        mkdir(szPathTemp);
    }
    if (iCreatedLength<ipathLength)
    {
        mkdir(strDirPath);
    }
    //printf("%d\n",mkdir(path));
    
}