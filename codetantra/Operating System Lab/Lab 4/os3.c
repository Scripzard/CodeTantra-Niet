#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max 50
void main(){
    int b[max],a[max],n,i,j,temp,s[max],f[max],w[max],ta[max],pr[max];
    int tow=0,tota=0;
    float aw,ata;
    char pName[max][max],t[max];
    printf("Enter the number of process:");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("Enter process name,arrivaltime,execution time & priority:");
        scanf("%s%d%d%d",pName[i],&a[i],&b[i],&pr[i]);
    }
    for(i=0;i<n;i++){
        if (i==0){
            s[i]=a[i];
            w[i]=s[i]-a[i];
            f[i]=s[i]+b[i];
            ta[i]=f[i]-a[i];
        }
        else{
            s[i]=f[i-1];
            w[i]=s[i]-a[i];
            f[i]=s[i]+b[i];
            ta[i]=f[i]-a[i];
        }
        tow+=w[i];
        tota+=ta[i];
    }
    aw=(float)tow/n;
    ata=(float)tota/n;
    printf("Pname\tarrivaltime\texecutiontime\tpriority\twaitingtime\ttatime\n");
    for (i=0;i<n;i++){
        printf("%s\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d\n",pName[i],a[i],b[i],pr[i],w[i],ta[i]);
    }
    printf("Average waiting time is:%f\n",aw);
    printf("Average turnaroundtime is:%f\n",ata);
}