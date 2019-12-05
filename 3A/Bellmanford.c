#include<stdio.h>
struct node{
      unsigned from[20];
      unsigned distance[20];
}rt[10];
void main(){
      int n,i,j,k,count,cost[20][20];
      printf("Enter the number of nodes\n");
      scanf("%d",&n);
      printf("Enter the cost matrix\n");
      for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                  scanf("%d",&cost[i][j]);
                  cost[i][i]=0;
                  rt[i].distance[j]=cost[i][j];
                  rt[i].from[j]=j;
            }
      }
      do{
            count=0;
            for(i=0;i<n;i++)
                  for(j=0;j<n;j++)
                        for(k=0;k<n;k++)
                              if(rt[i].distance[j]>cost[i][k]+rt[k].distance[j]){
                                    rt[i].distance[j]=rt[i].distance[k]+rt[k].distance[j];
                                    rt[i].from[j]=k;
                                    count++;
                              }
      }while(count!=0);
      for(i=1;i<=n;i++)
      {
            printf("For router %d: \n",i);
            for(j=1;j<=n;j++){
                  printf(" \n node %d via %d,   distance=%d \n",j,rt[i].from[j],rt[i].distance[j]);
            }
      }
}
