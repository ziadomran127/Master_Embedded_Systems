#include<stdio.h>
#include<stdlib.h>

int Sum_All_Digits(int n)
{
    int sum =0 ;
    int rem ;
    while(n!=0)
    {
        rem = n%10 ;
        sum = sum + rem ;
        n=n/10 ;
    }
    return sum ;
}



int main()
{
    int n ; 
    scanf("%d" , &n) ;
     int result = Sum_All_Digits(n) ;
     printf("%d" , result) ;
    
}