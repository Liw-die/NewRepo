#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>


int *create_hash(char *str)
{
	int *h = calloc(26,sizeof(int));
	
	int len=strlen(str);
	int i,key;
	for(i=0;i<len;i++)
	{
		key=str[i]-'a';
		h[key]++;
	}
	
	return h;
}

bool h_empty(int *par1,int *par2)
{
	int i;
	for(i=0;i<26;i++)
	{
		if(par1[i]>par2[i])
			return false;
	}
	return true;
}

bool h2_empty(int *par1,int *par2)
{
	int i;
	for(i=0;i<26;i++)
	{
		if(par1[i]!=par2[i])
			return false;
	}
	return true;
}

int main(void)
{
	char arr1[32];
	char arr2[32];
	
	int *par1=NULL;
	int *par2=NULL;
	
	while(1)
	{
		scanf("%s",arr1);
		scanf("%s",arr2);
		par1=create_hash(arr1);
		par2=create_hash(arr2);
		if(h2_empty(par1,par2))
			printf("true!\n");
		else
			printf("false!\n");
	}
}
	
	
	
	
	
