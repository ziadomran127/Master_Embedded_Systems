#include<stdio.h>
#include<stdlib.h>

int main()
{
  
   char alpha[27] ;
   char *ptr = alpha ;
   for (int i = 0; i < 27; i++)
   {
        *ptr = 'A'+i ;
        ptr++ ;
   }
ptr = alpha ;
   for(int i=0 ; i<26 ; i++)
   {
    printf("%c   " , *ptr);
    ptr++;
   }
   
        
    
}