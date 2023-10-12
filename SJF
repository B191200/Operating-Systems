#include<stdio.h>
struct process
{
	int at,bt,ct,tat,wt,c;
};

int findprocess(struct process* p,int n,int t)
{
	int min=99999,index=-1;
	for(int i=0;i<n;i++)
	{
		if(p[i].at<=t && p[i].c==0)
		{
			if(p[i].bt<min)
			{
				min=p[i].bt;
				index=i;
			}
		}
	}
	return index;
}
	
main()
{
	int n,t=0,ct=0,k=0, index;
	printf("enter nuber of precosses");
	scanf("%d",&n);
	struct process *p;
	p=(struct process*)malloc(n*sizeof(struct process));
	printf("enter processes detailes ");
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&p[i].at,&p[i].bt);
		p[i].c=0;
	}
	
	while(k<n)
	{
		index=findprocess(p,n,t);
		if(index!=-1)
		{
			p[index].c=1;
			p[index].ct=ct+p[index].bt;
			p[index].tat=p[index].ct-p[index].at;
			p[index].wt=[index].tat-p[index].bt;
			t=p[index].ct;
			ct=t;
			k=k+1;
		}
		else
		{
			t=t+1;
			ct=ct+1;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		printf(" %2d  %2d  %2d  %2d  %2d\n ",p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	}
}
	
	
	
	
