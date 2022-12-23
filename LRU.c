//#include<conio.h>
#include<stdio.h>
void main()
{
int tp,succ=0,flag=0,tf,page[20],frame[10],temp,pgptr,fmptr,fault=0,i,j,k,l;
//clrscr();
printf("\n LRU");
printf("\n\n Enter total no of frame:");
scanf("%d",&tf);
printf("\n Enter total no of page:");
scanf("%d",&tp);
printf("\n Enter %d no of page:",tp);for(i=0;i<tp;i++)
scanf("%d",&page[i]);

fmptr=0;
printf("\n Page \t Page Fault \t Page Sequence:");
for(pgptr=0;pgptr<tp;pgptr++)
{
  printf("\n  %d",page[pgptr]);
   if(fmptr!=tf)
	{

	   for(i=0;i<=fmptr;i++)
	   {
	  //printf("\n %d",frame[i] );
		 if(frame[i]==page[pgptr])
		  {
		   flag=1;
		   printf("\t NO\t ");
		   succ++;
		 }
	   }
		if(flag==0)
	   {
		 frame[fmptr]=page[pgptr];
		 printf("\t YES\t ");
		 fault++;
		 fmptr++;
		}

	}
  /* else if(flag==0)
	   {
		 frame[fmptr]=page[pgptr];
		 printf("\t YES");
		 fault++;
		 fmptr++;
		}
				*/

   else
   {
	  flag=0;
	  for(i=0;i<fmptr;i++)
	  {
	   if(frame[i]==page[pgptr])
	   {
		flag=1;
		printf("\t NO\t ");
		succ++;
	   }
	  }
	 if(flag==0)
	 {
	 temp=page[pgptr-tf];
	 for(i=0;i<tf;i++)
	 {
	 if(frame[i]==temp)
	  {
	   frame[i]=page[pgptr];
	   printf("\t YES\t ");
	   fault++;
	  }
	 }
   }
  }
	for(j=0;j<fmptr;j++)
   {
   printf("\t %d",frame[j]);
   }
}
printf("\n Total page fault:%d",fault);
printf("\n Total page success:%d",succ);
//getch();

}

