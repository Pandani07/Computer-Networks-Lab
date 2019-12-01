#include<stdio.h>
#include<stdlib.h>
int hf=0,lf=0,lr=0,hr=0;
int high[25]={0},low[25]={0};
void insert(int val,int priority){
      if(priority==1){
            if(hr<24){
                  printf("Packet inserted into the highest priority queue \n");
                  high[hr++]=val;
            }
            else
                  printf("Queue is full \n");
      }
      else if(priority==2){
            if(lr<24){
                  printf("Packet inserted into the lowest priority queue \n");
                  low[lr++]=val;
            }
            else
                  printf("Queue is full\n");
      }
      else
      {
            printf("Invalid\n");
      }
}
void process()
{
      if(hf!=hr){
            printf("Processing high priority queue \n");
            printf(" %d \t ",high[hf++]);
      }
      else{
            if(lf!=lr){
                  printf("Processing low priority queue \n");
                  printf(" %d \t",low[lf++]);
            }
      }
      printf("Process complete \n");
}
void main()
{
      int ch,val,priority;
      while(1){
            printf("Enter your choice: \n1.Insert\n2.Process\n3.Exit\n");
            scanf("%d",&ch);
            switch(ch){
                  case 1:printf("Enter value and priority\n");
                              scanf("%d",&val);
                              scanf("%d",&priority);
                              insert(val,priority);
                              break;
                  case 2:process();break;
                  case 3:exit(0);
            }
      }
}
