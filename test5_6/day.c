#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>


void GetMemory(char** p,unsigned int size)
{
	*p=(char*)malloc(size);
	printf("no \n");
	return ;
}

void main (void)
{
	char*str=NULL;
	GetMemory(&str,100);
	printf("no \n");
	strcpy(str,"Anyka is a hi-tech company.");
	printf("no \n");
	printf("%s",str);
	return;
}