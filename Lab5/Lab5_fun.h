#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include "Lab5_data.h"

int count(char* path);
int GetOffset(char *);

void iniconf(CONF *);
void initLink(CONF *,DATASTRUCT **, DATASTRUCT **, int);

void getinfo(CONF *,DATASTRUCT *, DATASTRUCT *);
void realPath(CONF *);
void getNum(CONF *);
void getMode(CONF *);
void transRel(CONF *);

void read_array(CONF *, int (*)[3]);
void Manual_read_array(CONF *, int (*)[3]);
void show_array(int (*)[3]);

void read_struct(CONF *, DATASTRUCT data[]);
void show_struct(DATASTRUCT data[]);

void read_PointerStruct(CONF *, DATASTRUCT *[]);
void show_PointerStruct(CONF *, DATASTRUCT *[]);

void read_linklist(CONF *info);
void ShowLinkData(DATASTRUCT *);
