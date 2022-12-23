#include <stdio.h>
#include <sys/types.h>
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
  priority=nice(-5);
printf("\nI am child process..%d \n",priority);
}
void ParentProcess()
{ printf("\nI am parent process..\n");
}
