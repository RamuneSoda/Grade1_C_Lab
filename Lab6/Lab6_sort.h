#include <stdlib.h>
#include "Lab6_data.h"

int cmp_arr(const void *, const void *);
void sort_array(int (*)[3], int);

int cmp_struct(const void *, const void *);
void sort_struct(DATASTRUCT [], int);

int cmp_PointerStruct(const void *, const void *);
void sort_PointerStruct(DATASTRUCT *[], int);

void LinkSortQ(LINKINFO *L);