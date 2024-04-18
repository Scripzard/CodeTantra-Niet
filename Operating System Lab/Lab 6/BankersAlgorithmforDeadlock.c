#include<stdio.h>
#include<conio.h>
int main(){
    int n,r,i,j,k,p,u=0,s=0,m;
    int block[10],run[10],active[10],newreq[10];
    int max[10][10],resalloc[10][10],resreq[10][10];
    int totalloc[10],totext[10],simalloc[10];
    printf("ENTER THE NO. OF PROCESSES:");
    scanf("%d",&n);
    printf("ENTER THE NO. OF RESOURCES:");
    scanf("%d",&n);
    printf("PROCESS 1 \nMAXIMUM VALUE FOR RESOURCE 1:\nMAXIMUM VALUE FOR RESOURCE2:\nMAXIMUM VALUE FOR RESOURCE 3:\nALLOCATED FROM RESOURCE 1:\nALLOCATED FROM RESOURCE2:\nALLOCATED FROM RESOURCE 3:\nPROCESS 2 \nMAXIMUM VALUE FOR RESOURCE 1:\nMAXIMUM VALUE FORRESOURCE 2:\nMAXIMUM VALUE FOR RESOURCE 3:\nALLOCATED FROM RESOURCE 1:\nALLOCATED FROMRESOURCE 2:\nALLOCATED FROM RESOURCE 3:\nPROCESS 3 \nMAXIMUM VALUE FOR RESOURCE 1:\nMAXIMUMVALUE FOR RESOURCE 2:\nMAXIMUM VALUE FOR RESOURCE 3:\nALLOCATED FROM RESOURCE 1:\nALLOCATEDFROM RESOURCE 2:\nALLOCATED FROM RESOURCE 3:\nPROCESS 4 \nMAXIMUM VALUE FOR RESOURCE1:\nMAXIMUM VALUE FOR RESOURCE 2:\nMAXIMUM VALUE FOR RESOURCE 3:\nALLOCATED FROM RESOURCE1:\nALLOCATED FROM RESOURCE 2:\nALLOCATED FROM RESOURCE 3:\n");
    for(k=1;k<=r;k++)
    scanf("%d",&totext[k]);
    for(i=1;i<=n;i++)
    for(k=1;k<=r;k++)
    scanf("%d",&totext[k]);
    printf("ENTER TOTAL VALUE OF RESOURCE 1:\nENTER TOTAL VALUE OF RESOURCE 2:\nENTERTOTAL VALUE OF RESOURCE 3:\nRESOURCES ALLOCATED NEEDED TOTAL AVAIL\nP1\t322\t100\t222\t936 112\nP2 \t613\t511\t102\t \nP3 \t314\t211\t103\t \nP4\t422\t002\t420\t \n\tAVAIL BEFORE\t AVAIL AFTER \nP2 \t010\t623\nP1 \t401\t723\nP3\t620\t934\nP4 \t514\t936\nTHE ABOVE SEQUENCE IS A SAFE SEQUENCE\n");
    scanf("%d",&p);
    for(k=1;k<=r;k++)
    scanf("%d",&newreq[k]);
    for(i=1;i<=n;i++){
        if(i!=p){
            scanf("%d%d",&block[i],&run[i]);
        }
    }
    block[p]=0;
    run[p]=0;
    for(k=1;k<=r;i++){
        j=0;
        for(i=1;i<=n;k++){
            totalloc[k]=j+resalloc[i][k];
            j=totalloc[k];
        }
    }
    for(i=1;i<=n;i++){
        if(block[i]==1 || run[i]==1)
        active[i]=1;
        else{
            active[i]=0;
        }
    for(k=1;k<=r;k++){
        resalloc[p][k]+=newreq[k];
        totalloc[k]+=newreq[k];
    }
    for(k=1;k<=r;k++){
        if(totext[k]-totalloc[k]<0){
            u=1;
            break;
        }
    }
    if(u==0){
        for(k=1;k<=r;k++)
        simalloc[k]=totalloc[k];
        for(s=1;s<=n;s++)
        for(i=1;i<=n;i++)
        {
            if(active[i]==1){
                j=0;
                for(k=1;k<=r;k++){
                    if((totext[k]-simalloc[k])<(max[i][k]-resalloc[i][k])){
                        j=1;
                        break;
                    }
                }
            }
            if(j==0){
                active[i];
                for(k=1;k<=r;k++)
                simalloc[k]=resalloc[i][k];
            }
        }
        m=0;
        for(k=1;k<=r;k++)
        resalloc[p][k]=newreq[k];
        resreq[p][k]=newreq[k];
    }
    else{
        for(k=1;k<=r;k++){
            resalloc[p][k]=newreq[k];
            totalloc[k]=newreq[k];
        }
    }
    return 0;
    }
}
