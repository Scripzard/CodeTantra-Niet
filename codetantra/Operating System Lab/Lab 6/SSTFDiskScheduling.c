#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int abs_diff(int a ,int b){
    return abs(a-b);
}
int main(){
    int n, head, total_mov=0;
    printf("Enter the number of Requests: ");
    scanf("%d",&n);
    int requests[n];
    printf("Enter the Requests sequence: ");
    for(int i=0;i<n;i++)
    scanf("%d",&requests[i]);
    printf("Enter initial head position: ");
    scanf("%d",&head);
    for(int i=0;i<n;i++){
        int min_diff= INT_MAX, min_index =-1;
        for(int j=0;j<n;j++){
            if(requests[j]!=-1 && abs_diff(head,requests[j])<min_diff){
                min_diff=abs_diff(head,requests[j]);
                min_index=j;
            }
        }
        total_mov+=min_diff;
        head=requests[min_index];
        requests[min_index]=-1;
    }
    printf("Total head movement is %d\n",total_mov);
    return 0;
}
