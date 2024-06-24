#include<stdio.h>
#include<stdlib.h>

void reverse () ;

int main()
{
  printf("Enter a sentence: ");
    reverse();
}

void reverse()
{
  char c ;
  scanf("%c" , &c) ;
  if(c != '\n') 
  {
    reverse() ;
  printf("%c" , c) ;
  }
  
}