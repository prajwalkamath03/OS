#include<stdio.h>
#include<sys/types.h>;
#include<unistd.h>;
#include<sys/wait.h>
int main()
{
    pid_t pid;
    pid=vfork();
    if(pid==-1)
    {
        perror("vfork");
        return 1;
    }else if(pid==0)
    {
        printf("child process:hello,I'm the child\n");
        printf("child process:my PID is %d\n",getpid());
        printf("child process:My parents PID is %d\n",getpid());
        exit(0);
    }else{
        printf("parent process:Hello Im the parent\n");
        printf("Parent process:My PID is %d\n",getpid());
        printf("Parent process:My childs PID is %d\n",pid);
        int status;
        waitpid(pid,&status,0);
        if(WIFEXITED(status))
        {
            printf("parent process:child porcess terminated normally.\n");
        }else{
            printf("parent process:child process terminated abnormally.\n");
    }
}
