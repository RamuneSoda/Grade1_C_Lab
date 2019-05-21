#include "Lab6_sort.h"


int cmp_arr(const void *a, const void *b) 
{ 
    int *aa = (int*)a;
    int *bb = (int*)b;
    return aa[2] - bb[2];  //升序 
}

void sort_array(int (*arr)[3], int n)
{
    qsort(arr[1], n, sizeof(int[3]), cmp_arr);
}


int cmp_struct(const void *a, const void *b)
{
    DATASTRUCT *aa = (DATASTRUCT *)a;
    DATASTRUCT *bb = (DATASTRUCT *)b;
    return aa->z - bb->z;
}

void sort_struct(DATASTRUCT data[], int n)
{
    qsort(&data[1], n, sizeof(data[1]), cmp_struct);
}


int cmp_PointerStruct(const void *a, const void *b)
{
    DATASTRUCT *aa = *(DATASTRUCT **)a;
    DATASTRUCT *bb = *(DATASTRUCT **)b;
    return (aa->z - bb->z);
}

void sort_PointerStruct(DATASTRUCT *a[], int n)
{
    qsort(&a[1], n, sizeof(a[1]), cmp_PointerStruct);
}

void LinkSortQ(LINKINFO *L)  
{  
	if(L->listlen <= 1)  
	    return;
	DATASTRUCT **all = (DATASTRUCT**)malloc(sizeof(DATASTRUCT*) * (L->listlen));
	all[0]=L->head->pNextItem;  
	for(int i = 1;i < L->listlen; i++)
	    all[i] = (all[i-1])->pNextItem;

	qsort(&all[0], L->listlen - 1, sizeof(all[0]), cmp_PointerStruct);
	DATASTRUCT *start = L->head;  

	for(int i=0;i<L->listlen;i++)  
	{  
	    start->pNextItem = all[i];  
	    start = start->pNextItem;  
	}  
	L->tail = all[L->listlen-1];  
	free(all);  
} 
