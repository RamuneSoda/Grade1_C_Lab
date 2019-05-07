#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include "Lab5_data.h"

int count(char* path);
int GetOffset(char *);

void iniconf(CONF *);
void initLink(DATASTRUCT **, DATASTRUCT **, int);

void realPath(CONF *);
void getNum(CONF *);
void getMode(CONF *);
void transRel(CONF *);

void read_array(CONF *, int (*)[3]);
void Manual_read_array(CONF *, int (*)[3]);
void show_array(int (*)[3]);

void read_struct(CONF *, DATASTRUCT data[]);
void read_PointerStruct(CONF *, DATASTRUCT *a[]);
void read_linklist(CONF *info);
