#include<stdio.h>
#include<stdlib.h>
int main()
{
    float a , b , c ;
    printf("enter 3 numbers : ");
    scanf("%f %f %f" , &a , &b , &c) ;
    if(a>b && a>c)
    printf("Largest number =  %f" , a);
    else if(b>a && b>c)
    printf("Largest number =  %f" , b);
    else
    printf("Largest number =  %f" , c);


}