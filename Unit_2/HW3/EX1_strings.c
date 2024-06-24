#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int n=0 ;
    char s[100] ;
    printf("Enter a string : ");
    fgets(s , sizeof(s) , stdin) ;

    char c ;
    printf("Enter a character to find frequency : ");
    scanf("%c" , &c) ;

    for(int i=0 ; i<sizeof(s) ; i++)
    {
        if ( c == s[i] )
        n++ ;
    }
 printf("%d" , n) ;

}