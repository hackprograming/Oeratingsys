#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>

int list(char c, char *fn)
{
	int count=0;
	
	 struct dirent *pDirent;
        DIR *pDir;
  
        pDir = opendir (fn);
        if (pDir == NULL) {
            printf ("Cannot open directory '%s'\n", fn);
            return 1;
        }

    	switch(c)
	{
	case 'f':       while ((pDirent = readdir(pDir)) != NULL) {
            			printf (" %s \n", pDirent->d_name);
        	    	 }
        	    	 closedir (pDir);
			break;
	
	case 'n':	
			while ((pDirent = readdir(pDir)) != NULL) {
               			count++;
        	    	 }
			printf("Total No.of files = %d\n",count);
			closedir (pDir);
			break;
	
	case 'i':   	while ((pDirent = readdir(pDir)) != NULL) {
	                    printf (" %s  %i \n", pDirent->d_name,pDirent->d_ino);
        			//printf("%i\n",(*pDirent).d_ino);
    			   }
			closedir (pDir);
			break;
	}
	return 0;
}

void main()
{
	char command[80],t1[20],t2[20],t3[20],t4[20];
	int n;
	system("clear");
	while(1)
	{
		printf("myShell$");
		fflush(stdin);
		fgets(command,80,stdin);
		n = sscanf(command,"%s %s %s %s",t1,t2,t3,t4);
		switch(n)
		{
		case 1:
			if(!fork())
			{
				execlp(t1,t1,NULL);
				perror(t1);
			}
			break;
		case 2:
			if(!fork())
			{
				execlp(t1,t1,t2,NULL);
				perror(t1);
			}
			break;
		case 3:
			if(strcmp(t1,"list")==0)
				list(t2[0],t3);
			else
			{
				if(!fork())
				{
					execlp(t1,t1,t2,t3,NULL);
					perror(t1);
				}
			}
			break;
		case 4:
			if(!fork())
			{
				execlp(t1,t1,t2,t3,t4,NULL);
				perror(t1);
			}
		}
	}
}
