#include "Lab7_input.h"


void read_struct()
{
    FILE *op = NULL;
    
    op = fopen("DataFile.txt","r");

    fscanf(op, "%d", &num);
    usercall = (USERCALL*)malloc(sizeof(USERCALL) * (num + 1));

    for(int i = 0; i < num; i++)
    {
        fscanf(op, "%d %d %d", &usercall[i].user_floor, &usercall[i].user_target, &usercall[i].call_time);
    }    
    
    fclose(op);
    return;
}

int cmp_struct(const void *a, const void *b)
{
    USERCALL *aa = (USERCALL *)a;
    USERCALL *bb = (USERCALL *)b;
    return aa->call_time - bb->call_time;
}

void sort_struct(int n)
{
    qsort(&usercall[0], n, sizeof(usercall[0]), cmp_struct);
}

void callType()
{
    for(int i = 0; i < num; i++)
    {
        if(usercall[i].user_floor > usercall[i].user_target)
        {
            usercall[i].call_type = 'D';
        }
        else
        {
            usercall[i].call_type = 'U';
        }
    }
}