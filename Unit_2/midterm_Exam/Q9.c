#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char c[100]  ;
    char temp ;
    printf("Enter a string : ") ;
    fgets(c , sizeof(c) , stdin) ;
    int i= 0 ; int j = strlen(c)-1 ;
    while(i<j)
    {
      temp = c[i] ;
      c[i] = c[j] ;
      c[j] = temp ;
      i++ ;
      j--;
    }  
    printf("%s" , c);
}