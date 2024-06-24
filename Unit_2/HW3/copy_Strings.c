#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char c[100] = "Ziad";
    char b[100] ;
 
    
    for(int i=0 ; c[i]!='\0' ; i++)
    {
        b[i] = c[i] ;
      
    }

printf("%s" , b) ;
}