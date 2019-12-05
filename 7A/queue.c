#include<stdio.h>
#include<stdlib.h>
int high[25]={0},low[25]={0},hf=0,hr=0,lf=0,lr=0;
void insert(int val, int p){
      if(p==1){
            if(hr<24){
                  printf("Inserting into the higher queue\n");
                  high[hr++]=val;
            }
            else
            {
                  printf("Queue is full\n");
            }
      }
      else if(p==2){
            if(lr<24){
                  printf("Inserting into the lower queue\n");
                  low[lr++]=val;
            }
            else
            {
                  printf("Queue is full\n");
            }
      }
      else
      {
            printf("Invalid\n");
      }
}
void process(){
      if(hf!=hr){
            printf("Processing the high priority queue\n");
            printf(" %d \t",high[hf++]);
      }
      else{
            if(lf!=lr){
                  printf("Processing the low priority queue\n");
                  printf(" %d \t",low[lf++]);
            }
      }
      printf("\nProcess complete\n");
}
void main(){
      int ch,val,p;
      while(1){
            printf("Enter choice:\n1.Insert\n2.Process\n3.Exit\n");
            scanf("%d",&ch);
            switch(ch){
                  case 1:printf("Enter the data and priority\n");
                              scanf("%d %d",&val,&p);
                              insert(val,p);
                              break;
                  case 2:process();break;
                  case 3:exit(0);
            }
      }
}
