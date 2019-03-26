#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define random(x,y) (rand () % y + x)

int isNum(char*, int);
int isPath(char *);
void BuildDataFile(char *);
