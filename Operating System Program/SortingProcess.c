#include <stdio.h>
#include <sys/types.h>
void ChildProcess(); /* child process prototype */
void ParentProcess(); /* parent process prototype */

int main()
{ 

int array[100],n,k;
printf("Enter number of elements\n");
scanf("%d",&n);
printf("Enter %d integers\n",n);
for(k=0;k<n;k++)
scanf("%d",&array[k]);

pid_t pid;
pid = fork();
if (pid == 0)
ChildProcess(array,n);
else
ParentProcess(array,n);
return 0;
}



void ChildProcess(int arr[],int n)
{ 
 printf("\nIn Child process..\n"); 
 int temp=0;
printf("\nBubble Sort\n");
for(int i=0;i<n-1;i++)
{
  for(int j=0;j<n-i-1;j++)
{
   if(arr[j]>arr[j+1])
  {
     temp =arr[j];
     arr[j] =arr[j+1];
     arr[j+1]=temp;
   }
  }
 }
 printf("sorted list in ascending order:\n");
 for(int i=0;i<n;i++)
 printf("%d  ",arr[i]);
 
}






void ParentProcess(int arr[],int n)
{ 
wait(NULL);
printf("\nIn parent process..\n");
  int i,j,key;
   for(i=1;i<n;i++)
   {
     key=arr[i];
     for(j=i-1;(j>=0)&&(key<arr[j]);j--)
     arr[j+1]=arr[j];
     arr[j+1]=key;
   }
 
 printf("\n Insertion Sort \n sorted list in ascending order:\n");
 for(i=0;i<n;i++)
 printf("%d  ",arr[i]);

}
