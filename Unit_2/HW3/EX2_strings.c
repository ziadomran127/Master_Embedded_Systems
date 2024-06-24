#include<stdio.h>
#include<stdlib.h>
int main()
{
    int  i ;
   char c[100] ;
   printf("Enter a string : ");
   scanf("%s" , c) ;
   for( i=0 ; c[i]!='\0' ; i++);
  
   printf("%d" , i) ;
}