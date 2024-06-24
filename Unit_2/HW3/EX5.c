#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n ; int a[100] ;
    printf("Enter num of elements : ") ;
    scanf("%d " , &n) ;
    for(int i =0 ; i <n ; i++)
    {
        scanf("%d" , &a[i]) ;
    }

int s ;
printf("Enter the element to be searched : ") ;
scanf("%d" , &s) ;
int c=0 ;
for(int j=0 ; j<n ; j++)
{
    c++ ;
    if (a[j] == s)
    break;
}
printf("Number found at location = ") ;
printf("%d" ,  c);
}