#include<stdio.h>
struct process
{
	int at,bt,r_bt;
};
int swap(struct process p[],int i,int j)
{
	struct process temp=p[i];
	p[i]=p[j];
	p[j]=temp;
}
int sort(struct process p[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(p[i].at>p[j].at)
			{
				swap(p,i,j);
			}
		}
	}
}
int print(struct process p[],int ct[],int tat[],int wt[],int n)
{
	int sum1=0,sum2=0;
	float r1,r2;
	printf("AT\tBT\tCT\tTAT\tWT\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\n",p[i].at,p[i].bt,ct[i],tat[i],wt[i]);
		sum1+=tat[i];
		sum2+=wt[i];	
	}
	r1=sum1/n;
	r2=sum2/n;
	printf("The Average TAT : %.2f\n",r1);
	printf("The Average WT : %.2f\n",r2);
}
int main()
{
	int n,tq,k,sum=0;
	printf("Enter the Number of Processers :");
	scanf("%d",&n);
	k=n;
	int ct[n],tat[n],wt[n],come[n];
	struct process p[n];
	printf("Enter the Arrival Times :");
	for(int i=0;i<n;i++)
		scanf("%d",&p[i].at);
	printf("Enter the Burst Times :");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&p[i].bt);
		p[i].r_bt=p[i].bt;
		come[i]=-1;
	}
	printf("Enter the Time Quantum :");
	scanf("%d",&tq);
	sort(p,n);
	int i=0;
	while(n>0)
	{
		if(p[i].r_bt<=tq && p[i].r_bt>0)
		{
			sum+=p[i].r_bt;
			p[i].r_bt=0;
			
		}	
		else if(p[i].r_bt>tq)
		{
			p[i].r_bt=p[i].r_bt-tq;
			sum+=tq;	
		}
		if(p[i].r_bt==0 && come[i]==-1)
		{
			n-=1;
			come[i]=0;
			ct[i]=sum;
			tat[i]=ct[i]-p[i].at;
			wt[i]=tat[i]-p[i].bt;
		}
		if(i==k-1)
			i=0;
		else if(p[i+1].at<=sum)
			i+=1;
		else
			i=0;
		
	}
	print(p,ct,tat,wt,k);
}
