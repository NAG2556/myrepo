#include<stdio.h>
int main(){
	int n;
	printf("Enter the no of processes:");
	scanf("%d",&n);
	int bt[n],wt[n],tat[n];
	char p[n];
	printf("Enter the burst times");
	for(int i=0;i<n;i++){
		scanf("%d",&bt[i]);
	}
	printf("Enter the process ID");
	for(int i=0;i<n;i++){
		scanf("%c",&p[i]);
	}
	
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(bt[i]>bt[i+1]){
				int temp=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;
				int temp2=p[i];
				p[i]=p[i+1];
				p[i+1]=temp2;
			}
		}
	}
	wt[0] = 0;
	for(int i=1;i<n;i++){
		wt[i]=wt[i-1]+bt[i-1];
	}
	for(int i=0;i<n;i++){
		wt[i]=wt[i]+bt[i];
	}
	for(int i=0;i<n;i++){
		printf("results are: %d %d %d\n",bt[i],wt[i],tat[i]);
	}
	int sum_waiting =0;
	for(int i=0;i<n;i++){  
		sum_waiting += wt[i];
	}
	float avg =sum_waiting/n;
	int sum_tat=0;
	for(int i=0;i<n;i++){
		sum_tat += tat[i];
	}
	float avg_tat =sum_tat/n;
	printf("avg of waiting time %f\n",avg);
	printf("avg of tat %f\n",avg_tat);
	return 0;
}
	
		
