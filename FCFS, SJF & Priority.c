#include<stdio.h>
int main()
{
	int n,i,j,p[20],
	pro[20],temp=0,bt[20],st[20],ct[20],tt[20],wt[20],priority[20];
	float awt=0,awtsjf=0;
	printf("Number Of Process:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		p[i]=i+1;
		printf("\nEnter BT For P%d: ",i+1);
		scanf("%d",&bt[i]);
		printf("Enter Priority For P%d: ",i+1); scanf("%d",&priority[i]);
	}
	st[0]=0;
	printf("\nFOR FCFS: ");
	printf("\nProcess BurstTime StartingTime CompletionTime TurnAroundTime WaitingTime");
	for(i=0;i<n;i++){
		printf("\n	P%d",i+1);
		printf("\t %d",bt[i]);
		st[i+1]=st[i]+bt[i];
		printf("\t\t %d",st[i]);
		ct[i]=st[i]+bt[i];
		printf("\t\t %d",ct[i]);
		tt[i]=st[i]+bt[i];
		printf("\t\t %d",tt[i]);
		wt[i]=tt[i]-bt[i];
		awt=awt+wt[i];
		printf("\t %d",wt[i]);
	}
	awt=awt/n;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(bt[i]<bt[j]){
				temp=p[j];
				p[j]=p[i];
				p[i]=temp;
				temp=bt[j];
				bt[j]=bt[i];
				bt[i]=temp;
			}
			else if (bt[i] == bt[j]){
				temp=p[j]; p[j]=p[i]; p[i]=temp;
				temp=bt[j];
				bt[j]=bt[i];
				bt[i]=temp;
			}
		}
	}
	st[0]=0;
	printf("\nFOR SJF: ");
	printf("\nProcess BurstTime StartingTime CompletionTime TurnAroundTime WaitingTime");
	for(i=0;i<n;i++){
		printf("\n	P%d",p[i]);
		printf("\t %d",bt[i]);
		st[i+1]=st[i]+bt[i];
		printf("\t\t %d",st[i]);
		ct[i]=st[i]+bt[i];
		printf("\t\t %d",ct[i]);
		tt[i]=st[i]+bt[i];
		printf("\t\t %d",tt[i]);
		wt[i]=tt[i]-bt[i];
		awtsjf=awtsjf+wt[i];
		printf("\t %d",wt[i]);
	}
	awtsjf=awtsjf/n;
	printf("\nFCFS Average Waiting Time: %.2f",awt);
	printf("\nSJF Average Waiting Time: %.2f",awtsjf);
	if(awtsjf<awt){
		printf("\n\nMinimum Average Waiting Time SJF\n");
	}
	else{
		printf("\n\nMinimum Average Waiting Time FCFS\n");
	}
	st[0]=0;
	printf("\nFOR Prority: ");
	temp = 0;
	for(i=0;i<n+1;i++){
		for(j=0;j<n;j++){
			if(priority[i]<priority[j]){
				temp=p[j];
				p[j]=p[i];
				p[i]=temp;
				temp=priority[j];
				priority[j]=priority[i];
				priority[i]=temp;
			}
		}
	}
	printf("\nProcess BurstTime Priority StartingTime CompletionTime TurnAroundTime WaitingTime");
	for(i=0;i<n;i++){
		printf("\n	P%d",p[i]);
		printf("\t %d",bt[i]);
		printf("\t\t %d",priority[i]);
		st[i+1]=st[i]+bt[i];
		printf("\t\t %d",st[i]);
		ct[i]=st[i]+bt[i];
		printf("\t\t %d",ct[i]);
		tt[i]=st[i]+bt[i];
		printf("\t\t %d",tt[i]);
		wt[i]=tt[i]-bt[i];
		awtsjf=awtsjf+wt[i];
		printf("\t %d",wt[i]);
	}
}
