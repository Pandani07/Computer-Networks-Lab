#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int checksum(int f){
      char data[100];
      int i,n,sum=0,temp;
      printf("Enter a string \n");
      fflush(stdin);
      gets(data);
      if(strlen(data)%2!=0)
            n=(strlen(data)+1)/2;
      else
            n=(strlen(data)/2);
      for(i=0;i<n;i++)
            sum+=(data[i*2]*256)+data[(i*2)+1];
      if(f==1){
            printf("Enter the checksum value \n");
            scanf("%x",&temp);
            sum+=temp;
      }
      if(sum%65535!=0)
            sum=sum%65535+sum/65535;
      sum=65535-sum;
      return sum;
}
void main(){
      int ch,sum,flag;
      while(1){
            printf("Enter choice:\n1.Encode\n2.Decode\n3.Exit\n");
            scanf("%d",&ch);
            switch (ch)
            {
            case 1:sum=checksum(0);
                        printf("Checksum to be appended is %x \n",sum);
                  break;
            case 2:sum=checksum(1);
                  if(sum!=0)
                        printf("Checksum is invalid or data has been tampered with \n");
                  else
                  {
                        printf("Valid checksum\n");
                  }
                  break;
            case 3:exit(0);
            }
      }
}
