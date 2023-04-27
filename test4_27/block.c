#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM 10000

//创建10000个长度为1~4个字节长度的字符串
char **create_str()
{
	char **str=calloc(NUM,sizeof(char*));
	if(str==NULL)
	{
		printf("crate_str failed");
		//return NULL;
	}
	
	int i,j;
	for(i=0;i<NUM;i++)
	{
		str[i]=calloc(5,sizeof(char));
		int len=rand()%4+1;//首先取余4随机数的长度在0-3之间,+1后在1-4之间
		
		for(j=0;j<len;j++)
			str[i][j]=rand()%26 + 'a';
		str[i][j]='\0';//在循环完后j=4,正好是字符数组最后一个元素的下标
	}
	return str;
}

//创建索引表
int **create_index(char **str)
{
	int **index=calloc(26,sizeof(int*));
	if(index==NULL)
	{
		printf("create_index failed\n");
		return NULL;
	}
	unsigned int cnt[26]={0};
	int i;
	int key;
	//计算每个字母出现的次数
	for(i=0;i<NUM;i++)
	{
		key = str[i][0] - 'a';
		cnt[key]++;//str[i][0]-'a'刚好等于所在字母元素的下标
	}
	//为索引创建指向的堆空间，该下标0，存次数以及行数
	for(i=0;i<26;i++)
	{
		index[i]=calloc(1+cnt[i],sizeof(int));//cnt[i]是存放的每个字母出现的次数，+1是用来存放出现的次数的
	}
	//遍历字符串,将行号存入索引
	int line;
	for(i=0;i<NUM;i++)
	{
		key=str[i][0] - 'a';
		index[key][0]++;//该元素的首字母所在索引的计数++
		line=index[key][0];
		index[key][line]=i;
	}
	return index;
}
int find_str(int **index,char **str,char *buf)
{
	int key = buf[0]-'a';
	int n=index[key][0];//索引的0位置存储的是该字母记录的个数
	//在遍历时应该从1的位置开始到n+1
	for(int i=1;i<n+1;i++)
	{
		if(strcmp(buf, str[index[key][i]]) == 0)
			return i;
	}
	return 0;
}
	
		
int main()
{
	srand(time(NULL));
	char **str = create_str();
	
	int **index = create_index(str);
	
	
	char buf[5];
	int  ret;
	while(1)
	{
		ret = scanf("%s",buf);
		if(ret!=1)
		{
			while(getchar()!='\n');
			continue;
		}
		
		ret = find_str(index,str,buf);
		if(ret == 0)
			printf("%s 字符串没有出现过\n",buf);
		else
			printf("%s 字符串在第%d行出现过\n",buf,ret);

	}
	return 0;
}
	
	