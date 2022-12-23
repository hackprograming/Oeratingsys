#include<stdio.h>
#include<stdlib.h>
int diskBlock[100];
int fileNo=0;

struct file
{
char fileName[20];
int address[10];
}files[10];

void diskFree()
{
int i;
for(i=0;i<100;i++)
diskBlock[i]=0;
}

void fileStatus()
{
int i;
for(i=0;i<fileNo;i++)
{
int no;
printf("\n File Name=%s",files[i].fileName);
printf("\n Block \n");
for(no=0;no<10;no++)
printf(" %d",files[i].address[no]) ;
}
}

void allocation()
{
int no,i;
printf("\n Enter the file Name");
scanf(" %s",&files[fileNo].fileName);
printf("\n Following block allocated");
for(i=0,no=0;i<100 & no<10;i++)
{
if(diskBlock[i]!=1)
{
files[fileNo].address[no]=i;
diskBlock[i]=1;
no++;
}
}
printf("\n File No=%d",fileNo++);
}

void deallocation()
{
int fno,no;
printf("\n Enter the file No");
scanf("%d",&fno);
for (no=0;no<10;no++)
{
diskBlock[files[fno].address[no]]=0;
files[fno].address[no]=0;
}
}
void diskStatus()
{
int i=0;
for(i=0;i<100;i++)
printf(" %d",diskBlock[i]);
}

int main()
{
int choice;

diskFree();
while(1)
{
printf("\n 1 File Allocation \n 2 File Deallocation \n 3 Show Disk Status \n 4 File Status \n 5 Exit \n") ;
scanf("%d",&choice);
switch(choice)
{
case 1: allocation(); break;
case 2: deallocation(); break;
case 3: diskStatus(); break;
case 4: fileStatus(); break;
case 5: exit(0);
}
}
}

