#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char str[50] ;
    char *ptr ;


    scanf("%s" , str) ;

    ptr = str + strlen(str)-1;

    for(int i =0 ; i<strlen(str) ; i++)
    {
        printf("%c" , *ptr) ;
        ptr--;
    }

    
}