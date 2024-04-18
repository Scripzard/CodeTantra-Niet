#include<stdio.h>
#define max 50
void main(){
    int p[max],bt[max],su[max],wt[max],tat[max],i,k,n,temp;
    float avg_wt,avg_tat;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        p[i]=i;
        printf("Enter the Burst Time of Process %d:",i);
        scanf("%d",&bt[i]);
        printf("System/User Process (0/1) ?");
        scanf("%d",&su[i]);
    }
    for(i=0;i<n;i++){
        for(k=i+1;k<n;k++){
            if (su[i]>su[k]){
                temp=p[i];
                p[i]=p[k];
                p[k]=temp;
                temp=bt[i];
                bt[i]=bt[k];
                bt[k]=temp;
                temp=su[i];
                su[i]=su[k];
                su[k]=temp;
            }
        }
    }
    avg_wt=wt[0]=0;
    avg_tat=tat[0]=bt[0];
    for(i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
        tat[i]=tat[i-1]+bt[i];
        avg_wt=avg_wt+wt[i];
        avg_tat=avg_tat+tat[i];
    }
    printf("PROCESS\t\t SYSTEM/USER PROCESS \tBURST TIME\tWAITING TIME\tTURNAROUNDTIME");
    for(i=0;i<n;i++){
        printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d",p[i],su[i],bt[i],wt[i],tat[i]);
    }
    printf("\nAverage Waiting Time is --- %f",avg_wt/n);
    printf("\nAverage Turnaround Time is --- %f", avg_tat/n);
}
