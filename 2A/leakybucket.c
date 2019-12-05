#include<stdio.h>
#define max 10
void insert(int rate,int bucket){
      int currpack,pmax=1.3*bucket,buffersize=0,i;
      for(i=0;i<max;i++){
            printf("\nIncoming packet of size : ");
            currpack=rand()%pmax+10;
            printf("%d \n",currpack);
            if(buffersize+currpack>bucket)
                  printf("\nPacket dropped:Innsufficient Space\n");
            else{
                  printf("\nAdded packet of size: %d\n",currpack);
                  buffersize+=currpack;
            }
            printf("\nBuffer size is: %d \n",buffersize);
            if(!buffersize)
                  printf("\nEmpty\n");
            if(buffersize>=rate){
                  buffersize-=rate;
                  printf("\nBytes sent: %d\n",rate);
                  printf("\nNew buffer size: %d\n",buffersize);
            }
            else{
                  printf("\nBytes sent: %d\n",buffersize);
                  buffersize=0;
                  printf("\nNew buffer size: %d\n",buffersize);
            }
      }
      while(buffersize){
            if(buffersize>=rate){
                  buffersize-=rate;
                  printf("\nBytes sent: %d\n",rate);
                  printf("\nNew buffer size: %d\n",buffersize);
            }
            else{
                  printf("\nBytes sent: %d\n",buffersize);
                  buffersize=0;
                  printf("\nNew buffer size: %d\n",buffersize);
            }
      }
      printf("Max number of incoming packets reached:\n");
}
void main(){
      int rate,buck;
      printf("Enter the rate and bucketsize\n");
      scanf("%d %d",&rate,&buck);
      insert(rate,buck);
}
