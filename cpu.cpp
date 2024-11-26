#include<stdio.h>
int main(){
	int n;
	float avg1=0,avg2=0;
	printf("enter number of processers:");
	scanf("%d",&n);
	int at[n],bt[n],wt[n];
	for(int i=0;i<n;i++){
		printf("enter arrival time %d:",i+1);
		scanf("%d",&at[i]);
	}
	for(int j=0;j<n;j++){
		printf("enter brust time %d:",j+1);
		scanf("%d",&bt[j]);
	}
	for(int i=0;i<n;i++){
		if(i==0){
			wt[i]=at[0];
		}
		else{
			wt[i]=wt[i-1]+bt[i-1];
		}
		avg1+=wt[i];
		avg2+=wt[i]+bt[i];
	}
	printf("\np\tat\tbt\twt\ttat");
	for(int i=0;i<n;i++){
		printf("\np%d\t%d\t%d\t%d\t%d",i+1,at[i],bt[i],wt[i],wt[i]+bt[i]);
	}
	printf("\n\naverage waiting time %f:",avg1/n);
	printf("\naverage turn around time %f:",avg2/n);
}
