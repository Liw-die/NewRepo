#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#if 0
int main(void)
{
	printf("%d========\n",(int)getpid());
	pid_t p=fork();
	printf("pid->%d p->%d\n",(int)getpid(),p);
	
	return 0;
}
#endif


int main(void)
{
	
	printf("%d========\n",(int)getppid());
	pid_t p=fork();
	if(p>0)
	{	
		printf("pid->%d p->%d\n",(int)getpid(),p);
		while(1);
	}
	if(p==0)
	{
		printf("ppid->%d p->%d\n",(int)getpid(),p);
		printf("ppid->%d p->%d\n",(int)getppid(),p);
	}
	return 0;
}
