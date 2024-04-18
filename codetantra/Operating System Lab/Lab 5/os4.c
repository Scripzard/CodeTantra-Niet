#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max 50
void main(){
    int i,n,s,c,y,quant,wt,tat,at[max],bt[max],temp[max],wT[max],rem_bt[max],taT[max];
    float avg_wt,avg_tat;
    printf("Enter Total Number of Processes: ");
    scanf("%d",&n);
    y=n;
    for(i=0;i<n;i++){
        printf("Enter Details of Process[%d]: Arrival Time:\t",i+1);
        scanf("%d",&at[i]);
        printf("Burst Time:\t");
        scanf("%d",&bt[i]);
        temp[i]=bt[i];
    }
    printf("Enter Time Quantum:\t");
    scanf("%d",&quant);
    printf("Process ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
    for(s=0,i=0;y!=0;){
        if (temp[i]<=quant && temp[i]>0){
            s+=temp[i];
            temp[i]=0;
            c=1;
        }
        else if(temp[i]>0){
            temp[i]-=quant;
        }
        if (temp[i]==0 && c==1){
            y--;
            printf("Process[%d]\t\t%d\t\t %d\t\t\t %d\n",i+1,bt[i],s-at[i],sat[i]-bt[i]);
            wt=wt+s-at[i]-bt[i];
            tat=tat+s-at[i];
            c=0;
        }
        if(i==n-1){
            i=0;
        }
        else if(at[i+1]<=s){
            i++;
        }
        else {
            i=0;
        }
    }
    avg_wt=(float)wt/n;
    avg_tat=(float)tat/n;
    printf("Average Waiting Time:\t%f\n",avg_wt);
    printf("Avg Turnaround Time:\t%f\n",avg_tat);
}
