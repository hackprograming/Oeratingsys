#include<stdio.h>
//#include<conio.h>
struct process
{    int id,burstt,arrivalt,finisht,tat,wt;
}s[10],temp;

void main()
{
int n,i,pass,sumtat=0,sumwt=0,tem;
float avgtat,avgwt;
//clrscr();
printf("Enter no. processes:");
scanf("%d",&n);
printf("\nEnter snapshot of system:");
printf("\nProcess\tBurst Time\tArrival Time");
for(i=0;i<n;i++)
{
 printf("\nP%d",i+1);
 s[i].id=i+1;
 scanf("%d",&s[i].burstt);
 scanf("%d",&s[i].arrivalt);
}
for(pass=1;pass<n;pass++)
{
 for(i=0;i<n-1;i++)
 {
  if(s[i].arrivalt>s[i+1].arrivalt)
  {   temp=s[i];
      s[i]=s[i+1];
      s[i+1]=temp;
  }
  else
  {
   if(s[i].arrivalt==s[i+1].arrivalt)
   {
	if(s[i].id>s[i+1].id)
	{
	temp=s[i];
	s[i]=s[i+1];
	s[i+1]=temp;
	}
   }
  }
 }
 }
for(i=0;i<n;i++)
{
 if(i==0)
 { s[i].finisht=s[i].burstt;
 }
 s[i].finisht=s[i-1].finisht+s[i].burstt;
 s[i].tat=s[i].finisht-s[i].arrivalt;
 s[i].wt=s[i].tat-s[i].burstt;
}
for(i=0;i<n;i++)
{
 sumtat+=s[i].tat;
 sumwt+=s[i].wt;
}
printf("\nProc\tBurstTime\tArrivalTime\tWaitTime\tFinishTime\tTATime");
for(i=0;i<n;i++)
{
 printf("\nP%d",s[i].id);
 printf("   \t%d",s[i].burstt);
 printf("   \t\t%d",s[i].arrivalt);
 printf("   \t\t%d",s[i].wt);
 printf("   \t\t%d",s[i].finisht);
 printf("   \t\t%d",s[i].tat);
}
 avgtat=(float)sumtat/n;
 avgwt=(float)sumwt/n;
printf("\n\nGantt Chart\n ");
for(i=0;i<n;i++)
{
 tem=s[i].burstt;
 while(tem!=0)
 {
  printf("__");
  tem--;
 }
 printf(".");
}
printf("\n ");
 printf("|");
for(i=0;i<n;i++)
{
 tem=s[i].burstt;
 while(tem>=0)
 {
  if(tem==(s[i].burstt/2))
   {
   printf("P%d",s[i].id);
   tem=tem-2;
   }
  else
	printf("  ");
  tem--;
 }
 printf("|");
}
printf("\n ");
for(i=0;i<n;i++)
{
 tem=s[i].burstt;
 while(tem!=0)
 {  printf("--");
     tem--;
 }
 printf(".");
}
printf("\n\nAverage Turn arround time:%f",avgtat);
printf("\n\nAverage Wait time:%f",avgwt);
//getch();
}

