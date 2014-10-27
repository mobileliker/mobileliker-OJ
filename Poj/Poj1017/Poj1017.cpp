#include "stdio.h"
//#include "stdlib.h"
int main()
{
    int a[3],i;
    int b1,b2,b3,b4,b5,b6;
    int count;
    scanf("%d%d%d%d%d%d",&b1,&b2,&b3,&b4,&b5,&b6);
    while(!(b1==0 && b2==0 && b3==0 && b4==0 && b5==0 && b6==0))
    {
       count = b6+b5+b4;
       for(i=1;i<=2;i++) a[i]=0;
       a[1]=11*b5;
       a[2]=5*b4;
       //printf("count1=%d\n",count);
       if(b3%4==0) count+=b3/4;
       else count+=b3/4+1;
       if(b3%4==1) {a[2]+=5;a[1]+=7;}
       else if(b3%4==2){a[2]+=3;a[1]+=6;}
       else if(b3%4==3){a[2]++;a[1]+=5;}
       if(a[2]>=b2) {a[1]+=(a[2]-b2)*4;}
       else
       {
           b2-=a[2];
           if(b2%9==0) a[0]=b2/9;
           else a[0]=b2/9+1;
           count+=a[0];
           a[1]+=(a[0]*9-b2)*4;
       }
       if(a[1]<b1)
       {
          b1-=a[1];
          if(b1%36==0) count+=b1/36;
          else count+=b1/36+1;
       }
       printf("%d\n",count);
       scanf("%d%d%d%d%d%d",&b1,&b2,&b3,&b4,&b5,&b6);
    }
    //system("pause");
    return 0;
}