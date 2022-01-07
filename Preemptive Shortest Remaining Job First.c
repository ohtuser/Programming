#include <stdio.h>
	#include <stdlib.h>
	#define MAX 50
	int main(){
		int a[MAX][10], i, count = 0, totalt, small, n, temp[MAX]; 
		printf("Enter Number Of Process: "); 
		scanf("%d", &n);
		printf("\nProcess ArrivalTime BurstTime\n");
		for (i = 0; i < n; i++){
			scanf("%d", &a[i][0]);
			scanf("%d", &a[i][1]);
			scanf("%d", &a[i][2]);
			count += a[i][2];
			a[i][6] = -1;
		}
		small = a[0][1];
		for (i = 0; i < n; i++){
			if (small > a[i][1])
			small = a[i][1];
			temp[i] = a[i][2];
		}
		totalt = small;
		count = count + small;
		while (totalt < count){
		for (i = 0; i < n; i++){
			if (a[i][6] == -1 && a[i][1] <= totalt){
				small = i;
				break;
			}
		}
		for (i = 0; i < n; i++){
			if (a[i][6] == -1 && a[i][1] <= totalt)
			{
				if (a[small][2] > a[i][2])
				small = i;
			}
		}
		totalt++;
		a[small][2]--;
		if (a[small][2] == 0){
			a[small][6] = 0;
			a[small][3] = totalt;
		}
		}
		
		printf("\nProcess\t ArrivalTime\t BurstTime\tCompletionTime\tTurnAroundTime\t WaitingTime\t"); 
		for(i=0;i<n;i++){
		printf("\n %d", a[i][0]);
		printf("\t\t %d", a[i][1]);
		printf("\t\t %d", temp[i]);
		printf("\t\t %d", a[i][3]);
		a[i][4] = a[i][3] - a[i][1];
		printf("\t\t %d", a[i][4]);
		a[i][5] = a[i][4] - temp[i];
		printf("\t\t %d", a[i][5]);
	}
	return 0;
	}
