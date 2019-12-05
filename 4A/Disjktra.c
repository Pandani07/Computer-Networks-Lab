#include<stdio.h>
int distance[100],previous[100];
void printpath(int v){
      if(previous[v]==-1)
            printf(" %d ",v);
      else{
            printpath(previous[v]);
            printf("-->%d ",v);
      }
}
void main(){
      int n,j,i,source,min,k,u,weight[100][100],mark[100];
      printf("Enter the number of vertices \n");
      scanf("%d",&n);
      printf("Enter the weight matrix\n");
      for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                  scanf("%d",&weight[i][j]);
      for(i=1;i<=n;i++){
            distance[i]=999;
            previous[i]=-1;
            mark[i]=0;
      }
      printf("Enter the source node \n");
      scanf("%d",&source);
      mark[source]=1;
      distance[source]=0;
      u=source;
      k=1;
      while(k<n){
            for(i=1;i<=n;i++)
                  if(mark[i]==0  && distance[i]>distance[u]+weight[u][i]){
                        distance[i]=distance[u]+weight[u][i];
                        previous[i]=u;
                  }
            min=99;
            for(i=1;i<=n;i++)
                  if(mark[i]==0 && distance[i]<min){
                        min=distance[i];
                        u=i;
                  }
            mark[u]=1;
            k++;
      }
      printf("The shortest path tree from source node %d is:\n",source);
      for(i=1;i<=n;i++)
            if(i!=source){
                  printf("For vertex %d ",i);
                  if(distance[i]==999)
                        printf("No path\n");
                  else{
                        printpath(i);
                        printf("Distance: %d \n",distance[i]);
                  }
            }
}
