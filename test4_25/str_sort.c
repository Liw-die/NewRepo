#include <stdio.h>
#include <string.h>

void show_select(char *arr,int len)
{
	for(int i=0;i<len;i++)
		printf("-%c-",arr[i]);
	printf("\n");
}

//插入排序
void inse_sort(char *str,int len)
{
	int i,j,temp;
	for(i=0;i<len-1;i++)
	{
		for(j=i;j<len;j++)
		{
			if(str[j+1]<str[i] && (j+1)<len)
			{
				temp=str[i];
				str[i]=str[j+1];
				str[j+1]=temp;
			}
		}
		//show_select(str,len);
	}
}

//冒泡排序
void bulling_sort(char *str,int len)
{
	int i,j,temp;
	for(i=0;i<len-1;i++)
	{
		for(j=0;j<len-i;j++)
		{
			if(str[j]>str[j+1] && j+1<len)
			{
				temp=str[j+1];
				str[j+1]=str[j];
				str[j]=temp;
			}
		}
	}
}
//选择排序
void selection_sort(char *str,int len)
{
	int i,j,temp;
	for(i=0;i<len;i++)
	{
		int min=i;
		for(j=i;j<len;j++)
		{
			if(str[j+1]<str[min] && j+1<len)
			{
				min=j+1;
			}
		}
		temp=str[i];
		str[i]=str[min];
		str[min]=temp;
	}
}

void quick_sort(char *str,int left,int right)//快排
{
	if(left>=right)
		return ;
	int i=left;
	int j=right;
	char key=str[left];
	
	while(i<j)
	{
		while(str[j]>key && i<j)
			j--;
		str[i]=str[j];
		
		while(str[i]<key && i<j)
			i++;
		str[j]=str[i];
	}
	str[i]=key;
	//show_select(str,11);
	quick_sort(str,left,i-1);
	quick_sort(str,j+1,right);
}

int main(void)
{
	char str[20]="fwergGdACOhbunm";
	int len=strlen(str);
	printf("原排->");
	show_select(str,len);
	
	printf("快排->");
	quick_sort(str,0,len-1);
	show_select(str,len);
	
	printf("插排->");
	strcpy(str,"fwergGdACOhbunm");	
	inse_sort(str,len);
	show_select(str,len);
	
	printf("冒排->");
	strcpy(str,"fwergGdACOhbunm");	
	bulling_sort(str,len);
	show_select(str,len);
	
	printf("选排->");
	strcpy(str,"fwergGdACOhbunm");	
	selection_sort(str,len);
	show_select(str,len);
	return 0;
}
	