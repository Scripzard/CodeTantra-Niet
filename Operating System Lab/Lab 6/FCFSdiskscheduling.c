#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int main(){
    int n,head,total_mov=0;
    printf("Enter the number of Requests: ");
    scanf("%d",&n);
    int requests[n];
    printf("Enter the Requests sequence: ");
    for(int i=0; i<n;i++)
    scanf("%d",&requests[i]);
    printf("Enter initial head position: ");
    scanf("%d",&head);
    for(int i=0; i<n;i++){
        total_mov+=abs(head-requests[i]);
        head=requests[i];
    }
    printf("Total head moment is %d\n",total_mov);
    return 0;
}
