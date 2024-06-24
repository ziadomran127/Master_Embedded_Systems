#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char user1[100] ;
    char user2[100] ; 
    fgets(user1 , sizeof(user1) , stdin) ;
    fgets(user2 , sizeof(user2) , stdin) ;

    if(strcmpi(user1 , user2)==0)
    printf("Identical") ;
    else
    printf("Different") ;

}