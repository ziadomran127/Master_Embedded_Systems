#include<stdio.h>
#include<stdlib.h>

int power(int base , int exp) ;


 

int main()
{
    int base , exp  , f ;
    scanf("%d  %d" , &base , &exp ) ;
    f = power(base , exp) ;
    printf("%d" , f);
}

int power(int  base ,int exp)
{
if (exp==1)
return base ;
else
return base*power(base , exp-1) ;
}