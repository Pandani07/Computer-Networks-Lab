#include<stdio.h>
#include<stdlib.h>
#define max 10
void leakybucket(int buck, int rate){
      int i,currpack,bucketsize=0,pmax=1.3*buck;
      srand(time(NULL));
      for(i=0;i<max;i++){
            printf("\nIncoming packet size is: ");
            currpack=rand()%pmax+10;
            printf("%d \n",currpack);
            if(currpack+bucketsize>buck)
                  printf("\n Packet dropped, Insufficient space\n");
            else{
                  printf("\n Added packet of size:  %d \n",currpack);
                  bucketsize+=currpack;
            }
            printf("\n Buffer Size: %d \n",bucketsize);
            if(!bucketsize)
                  printf("\n Empty\n");
            if(bucketsize>=rate){
                  bucketsize-=rate;
                  printf("\n Bytes sent: %d \n",rate);
                  printf("\n New bucketsize: %d \n",bucketsize);
            }
            else{
                  printf("\n Bytes sent: %d \n",bucketsize);
                  bucketsize=0;
                  printf("\n New bucketsize: %d \n",bucketsize);
            }
      }
      while(bucketsize){
            if(bucketsize>=rate){
                  bucketsize-=rate;
                  printf(" \nBytes sent: %d \n",rate);
                  printf("\n New bucketsize: %d \n",bucketsize);
            }
            else{
                  printf(" \nBytes sent: %d \n",bucketsize);
                  bucketsize=0;
                  printf("\n New bucketsize: %d \n",bucketsize);
            }
            printf("\n Size of the buffer: %d \n",bucketsize);
      }
      printf("\n No more data \n");
}
void main()
{
      int rate,buck;
      printf("Enter the rate in MBPS \n");
      scanf("%d",&rate);
      printf("Enter the bucket size \n");
      scanf("%d",&buck);
      leakybucket(buck,rate);
}
