#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int i;
    for (i = 0; i < 3; i++) {
        pid_t pid = fork(); // fork出子进程
        if (pid < 0) { // 如果fork失败
            printf("Error: fork error.\n");
            exit(1);
        } else if (pid == 0) { // 如果是子进程
            printf("I am child process. My PID is %d and my parent PID is %d.\n", getpid(), getppid());
            exit(0); // 子进程退出
        } else { // 如果是父进程
            printf("I am parent process. My PID is %d and my child PID is %d.\n", getpid(), pid);
        }
    }
    for (i = 0; i < 3; i++) {
        wait(NULL); // 父进程等待子进程结束
    }
    printf("All child processes are done.\n");
    return 0;
}
