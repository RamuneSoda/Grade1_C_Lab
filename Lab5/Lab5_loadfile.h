#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Lab5_data.h"


void initLink(CONF *,DATASTRUCT **, DATASTRUCT **, int);

void Manual_read(CONF *);

void read_array(CONF *, int (*)[3]);
void read_struct(CONF *, DATASTRUCT data[]);
void read_PointerStruct(CONF *, DATASTRUCT *[]);
void read_linklist(CONF *info);