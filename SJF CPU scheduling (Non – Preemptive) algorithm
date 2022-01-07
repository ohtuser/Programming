#include<stdio.h>
int main(){
  int n,i,j,p[20], pro[20],temp=0,bt[20],st[20],ct[20],tt[20],wt[20]; 
  float awt=0,awtsjf=0;
  printf("Enter Number Of Process: ");
  scanf("%d",&n);
  printf("\n");
  for(i=0;i<n;i++){
    p[i]=i+1;
    printf("Enter Burst Time Of P%d: ",i+1);
    scanf("%d",&bt[i]);
  }
  st[0]=0;
  printf("\nProcess BurstTime StartingTime CompletionTime TurnAroundTime WaitingTime");
  for(i=0;i<n;i++){
    printf("\nP%d",p[i]);
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
}
