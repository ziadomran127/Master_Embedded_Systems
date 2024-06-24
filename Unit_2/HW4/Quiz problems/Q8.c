#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[10] ;
    int n ; 
    int res ;
    int flag = 0 ;
    for(int i=0 ; i<10 ; i++)
    {
        scanf("%d" , &a[i]) ;
    }
    scanf("%d" , &n) ;

    for(int i=0 ; i<10 ; i++)
    {
        if(a[i]==n)
        {
            res = i ;
            flag =1 ;
        }
        
    }
   if(flag == 1)
    printf("%d" ,res+1);
    else
    printf("%d" , -1) ;
    
}