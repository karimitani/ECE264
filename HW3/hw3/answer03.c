
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "answer03.h"


char * strcat_ex(char * * dest, int * n, const char * src)
{
int src_len = strlen(src);
int dst_len = 0;



if(*dest == NULL){
    *n =  1 + 2 * (strlen(src));
    *dest = malloc(sizeof(char)*(*n));
    strcpy (*dest, src);
    return *dest;
}


if( (src_len + dst_len + 1 <= *n) ) {
strcat (*dest, src);
}


if((src_len + dst_len + 1 > *n) ) {
    *n = 1 + 2 * (strlen(*dest) + strlen(src));
    char * temp = *dest;
    *dest = malloc(sizeof(char)*(*n));
    strcpy(*dest, temp);
    strcat(*dest, src);
    free(temp);
}
return *dest;
free(dest);
}




char * * explode(const char * str, const char * delims, int * arrLen)
{
int  count = 0;
int delim_count = 0;
int x = 0;
char * temp = malloc(sizeof(char*) * strlen(str));
int delimPosn = 0;
char * temp2;
int ansCount = 0;

while (count < strlen(str)){
    if(strchr(delims, str[count]) != NULL){
    delim_count++;
    }
count++;
}

char * * strArr = malloc((delim_count+1) * sizeof(char *));
strcpy(temp, str);

while(temp[x] != '\0'){

    if(strchr(delims, temp[x]) != NULL){

    temp2 = malloc(sizeof(char*) * (x - (delimPosn) ));
    memcpy(temp2, str, (x - (delimPosn)));

    strArr[ansCount] = temp2;

    ansCount++;
    str += x - delimPosn;
    delimPosn = x;
    }

x++;
}

temp2 = malloc(sizeof(char*) * (x - delimPosn + 1));
memcpy(temp2, str, x - delimPosn + 1);

strArr[ansCount] = temp2;

*arrLen = delim_count + 1;
free(temp);
free(temp2);
return strArr;
}


char * implode(char * * strArr, int len, const char * glue)
{
char * answer = NULL;
int n = 0;
int count;

for(count = 0; count< len; ++count){
    if(count > 0)
    strcat_ex(&answer, &n, glue);
    strcat_ex(&answer, &n, strArr[count]);
}
return answer;
}


void sortStringArray(char * * arrString, int len)
{
    int i;
    char *temp = malloc(sizeof(arrString)/len);
    for(i = 0; i < len-1; i++)
    {
        if(strcmp(arrString[i],arrString[i+1]) > 0)
        {
            strcpy(temp,arrString[i]);
            strcpy(arrString[i], arrString[i+1]);
            strcpy(arrString[i+1], temp);
            i = -1;
        }
    }
    free(temp);
}


void sortStringCharacters(char * str)
{
int len = strlen(str);
int i;
char temp;

    for(i = 0; i < len-1; i++)
    {
        if(str[i] - str[i+1] > 0)
        {
            temp = str[i];
            str[i] = str[i+1];
            str[i+1] = temp;
            i = -1;
        }
    }
}


void destroyStringArray(char * * strArr, int len)
{
int count = 0;

while(count < len-1 )
{
free(strArr[count]);
count++;
}
free(strArr);
}
