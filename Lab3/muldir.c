#include<stdio.h>
#include<direct.h>

void mkdir_m(char *muldir)
{
	int i, len;
	char str[512];
	strcpy(str, muldir);
	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		if (str[i] == '/' || str[i] == '\\')
		{
			str[i] = '\0';
			//if (IsFileExist(str) == 0)
			//{
				if (_mkdir(str) != 0)
				{
					printf("目录创建失败！\n");
				}
			//}
			str[i] = '\\';
		}
	}
	if (len > 0 /*&& IsFileExist(str) == 0*/)
	{
		if (_mkdir(str) != 0)
		{
			printf("目录创建失败！\n");
		}
	}
	_chdir(str);
}

int main()
{
    char path[100];
    gets(path);
    mkdir_m(path);

}