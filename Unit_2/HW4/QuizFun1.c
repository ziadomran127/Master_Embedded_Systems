#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int result ; 
char str1[100] ;
char str2[100] ;
printf("Enter a string : ") ;
fgets(str1 , sizeof(str1) , stdin ); 
printf("Enter Your name : ");
fgets(str2 , sizeof(str2) , stdin ); 
result = strcasecmp(str1 , str2) ;
if(result == 0 )
printf("Identical") ;
else
printf("Different") ;
}