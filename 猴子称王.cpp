#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#define n sizeof(struct monkey)
int main()
{
	int i,m,j,z;
	i=0; 
	struct monkey
	{
		int num;
	struct monkey *next;
    struct monkey *former;
	};
	struct monkey *p1,*p2,*head[30],*p3;
	p1=p2=(struct monkey *)malloc(n);
	srand((int)time(0));
	while(i<=29)
	{
		(*p1).num=rand()%10+1;	
		head[i]=p1;
		if(i==29)
		{
			(*p1).next=head[0];
			(*p1).former=head[i-1];
		}
		else{
			if(i!=0)
			(*p1).former=head[i-1];
	    p1=(struct monkey *)malloc(n);
		(*p2).next=p1;
		p2=p1;}
		i++;
	}
	(*head[0]).former=head[29];
	
	
	m=(*head[0]).num;
	p1=p2=p3=head[0];
    while(1)
	{
		for(j=1;j<=m;j++)
		{
			p1=(*p2).next;
			p2=p1;
		}


        for(i=1;i<=30;i++)
		{
			if(head[i-1]==p1)
			{
				p3=(*head[i-1]).former;
				(*p3).next=(*p1).next;
				p3=(*head[i-1]).next;
				(*p3).former=(*p1).former;
				m=(*p1).num;
				head[i-1]=NULL;
				break;
			}
		}
		z=0;
		for(j=0;j<=29;j++)
		{
		    if(head[j]==NULL)
		    z++;
		}
		if(z==30)
			break;
		
		printf("第%d只猴子已被移除\n",i);
		Sleep(1000);
	}
	
	printf("第%d只猴子为猴王",i);
	getch();




return 0;
}








