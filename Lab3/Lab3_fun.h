#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <direct.h>
#include <io.h>
#include "Lab3_data.h"

#define random(x,y) (rand () % y + x) //x:min y:max

int isNum(char*, int);
int isPath(char *);
int isAbsPath(char *);
int isRelPath(char *);
int isFileExist(char *);
void DivPath(char *, CONF*);
void BuildDataFile(CONF *);
void mkdir_m(char *);
int GetOffset(char *);
int count(char *);