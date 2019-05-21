#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <io.h>
#include "Lab6_data.h"

int count(char* path);
int GetOffset(char *);

void iniconf(CONF *);

void realPath(CONF *);
void getNum(CONF *);
void getMode(CONF *);
void transRel(CONF *);
int isFileExist(char []);