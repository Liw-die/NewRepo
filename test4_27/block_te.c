#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM  10000

//创建10000个长度为1~4个字节的字符串
char **create_str()
{
	//申请 NUM 个元素的指针数组
	char **str = calloc(NUM,sizeof(char*));
	if(str == NULL)
	{
		printf("crate_str failed");
	}
	
	//循环，每次创建一个 1~4字节的字符串
	int i,j;
	for(i=0;i<NUM;i++)
	{
		str[i] = calloc(5,sizeof(char));
		
		//随机数确定字符串长度  1~4
		int len = rand()%4+1;
		
		for(j=0;j<len;j++)
			str[i][j] = rand()%26 + 'a';//字符 'a'~'z'
		str[i][j]='\0';//字符串以'\0'结尾
	}
	return str;
}

//创建索引表
int **create_index(char **str)
{
	int **index = calloc(26,sizeof(int*));
	if(index ==NULL)
	{
		printf("create_index failed\n");
		return NULL;
	}
	
	//它用来记录各个首字符出现的次数，初值为0
	// cnt[0]表示a出现的次数
	// cnt[1]表示b出现的次数
	// ......
	// cnt[25]表示z出现的次数
	unsigned int cnt[26]={0};
	
	
	//遍历一遍字符串，每次判断首字符是哪一个，然后做记录
	int i;
	int key;
	for(i=0;i<NUM;i++)
	{
		//str[i][0] 是字符串首字符
		key = str[i][0] - 'a';
		cnt[key]++;
	}
	
	//printf("字符b 出现 %d 次\n",cnt[1]);
	
	//创建索引表指针指向的堆空间。
	//该堆空间下标0的位置记录存入的个数
	//下标1~ cnt[i] 下标位置用来存放该字符串的行数
	for(i=0;i<26;i++)
	{
		index[i] = calloc( 1+cnt[i], sizeof(int));
	}
	
	//遍历字符串，存入某个字符串的行数
	int line;
	for(i=0;i<NUM;i++)
	{
		key = str[i][0] - 'a';
		
		index[key][0]++; //个数+1
		
		line = index[key][0];//要存入的下标位置
		
		index[key][line] = i;
	}
	
	return index;
}

int find_str(int **index,char **str,char *buf)
{
	//先根据索引表找到对应的块
	int key = buf[0]-'a';
	
	//对应块的元素个数
	int n = index[key][0];
	
	//遍历块--- 块的大小是 n+1,下标取值 0~n
	// 下标0记录总数  下标1~n记录行数
	int i;
	for(i=1;i<n+1;i++)
	{
		if(strcmp(buf,  str[ index[key][i] ]) == 0)
			return i;
	}
	
	return 0;
}



int main()
{
	//以当前时间重新设计随机数
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