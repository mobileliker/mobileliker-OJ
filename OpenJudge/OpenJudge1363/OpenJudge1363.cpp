#include "stdio.h"
//#include "stdlib.h"
#include "stack"
using namespace std;
int main()
{
    stack<int> s;
    int n,i,j,tmp,top;
    bool flag;
    scanf("%d",&n);
    while(n!=0)
    {
       scanf("%d",&tmp);
       while(tmp != 0)
       {
            flag = true;
            //top = tmp-1;
            while(!s.empty()) s.pop();
            for(i = 1 ;i < tmp;i++) s.push(i);
            top = tmp;
            for(i = 1 ;i < n;i++)
            {
               scanf("%d",&tmp);
               if(flag)
               {
                   //if(top < tmp) top = tmp - 1;
                   if(top < tmp) {for(j = top+1;j<tmp;j++){s.push(j);}top=tmp;}
                   //else if(top == tmp) top--;
                   else if(s.top() == tmp) s.pop();
                   else flag = false;  
               }
            }
            if(!flag) printf("No\n");
            else printf("Yes\n");
            scanf("%d",&tmp);
       }
       scanf("%d",&n);
       while(!s.empty()) s.pop();
       if(n != 0) printf("\n");
    } 
    
    //system("pause");
    return 1;
}