#include<stdio.h>
int scheduling(int p[],int at[],int bt[],int n)
{
 for(int i=0;i<n-1;i++)
    {
     for(int j=0;j<n-i-1;j++)
    {
      if(at[j]>at[j+1])
     {
        int temp=p[j+1];
        p[j+1]=p[j];
        p[j]=temp;
        temp=at[j+1];
        at[j+1]=at[j];
        at[j]=temp;
        temp=bt[j+1];
        bt[j+1]=bt[j];
        bt[j]=temp;
      }
     }
    }
}
int completetime(int at[],int bt[],int ct[],int n)
{
	int time=0;
	ct[0]=at[0]+bt[0];
	for(int i=1;i<n;i++)
	{
		if(ct[i-1]<at[i])
		{
			time=at[i-1]-ct[i-1];
		}
		ct[i]=ct[i-1]+bt[i]+time;
	}
}
int turnaroundtime(int tat[],int ct[],int at[],int n)
{
	for(int i=0;i<n;i++)
	{
		tat[i]=ct[i]-at[i];
	}
}
int waitingtime(int wt[],int tat[],int bt[],int n)
{
	for(int i=0;i<n;i++)
	{
		wt[i]=tat[i]-bt[i];
	}
}
int main()
{
	int n,wtt=0,tatt=0;
	float avgtat,avgwt;
	printf("enter the no of processes:");
	scanf("%d",&n);
	int at[n],bt[n],p[n],ct[n],wt[n],tat[n];;
	printf("enter processorid arrival time and burst time respectively:\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&p[i],&at[i],&bt[i]);
	}
	scheduling(p,at,bt,n);
	completetime(at,bt,ct,n);
	turnaroundtime(tat,ct,at,n);
	waitingtime(wt,tat,bt,n);
	printf("\nprocesses\t A.T\t B.T\t C.T\t TAT\t WT");
	for(int i=0;i<n;i++)
	printf("\nP%d\t %d\t %d\t %d \t %d \t %d",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
	printf("\n");
	for(int i=0;i<n;i++)
	{
		wtt+=wt[i];
		tatt+=tat[i];	
	}
	avgwt=(float)wtt/(float)n;
	avgtat=(float)tatt/(float)n;
	printf("AWT  = %f\n",avgwt);
	printf("ATAT = %f\n",avgtat);
    }
  	
	
