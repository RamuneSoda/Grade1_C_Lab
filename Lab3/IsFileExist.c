#include<stdio.h>
#include<io.h>

int main()
{
    char path[100];
    gets(path);
    printf("%d\n",access(path, 0));
}
