#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t x=fork();
	if(x>0)
	{	
		int status=0;
		pid_t ret=wait(&status);
		printf("x=%d\n",x);
		printf("res=%d\n",ret);
		printf("status=%d\n",status);
		
	}
	if(x==0)
	{
		printf("chilb=%d\n",getpid());
		exit(15);
	}
	
	return 0;
}