#include <stdio.h>
#include <sys/types.h>
#include<unistd.h>
void ChildProcess(); /* child process prototype */
void ParentProcess(); /* parent process prototype */
int priority=0;
int main()
{ pid_t pid;

pid = fork();
if (pid == 0)
ChildProcess();
else
ParentProcess();
return 0;
}
void ChildProcess()
{ 
	sleep(1);
  printf("\nI am child process..\n");
  int pid=getpid();
  
  printf("\n Child Process %d Exit\n",pid);
}
void ParentProcess()
{ 
	int pid=getpid();
  printf("\nI am parent process %d Exit..\n",pid);
}
