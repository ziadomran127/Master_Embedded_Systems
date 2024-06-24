#include<stdio.h>
#include<stdlib.h>
int main()
{
    float a[2][2] ;
    float b[2][2] ;
    float c[2][2] ;
    printf("enter the elements of first matrix :\n\r ") ;
    for(int i=0 ; i<2 ; i++)
    {
         for(int j=0 ; j<2 ; j++)
            {
              printf("enter a%d%d : " , i+1 , j+1 );
              scanf("%f" , &a[i][j]);   
            }
    }
   
printf("enter the elements of second matrix :\n\r ") ;
    for(int i=0 ; i<2 ; i++)
    {
         for(int j=0 ; j<2 ; j++)
            {
              printf("enter b%d%d : " , i , j );
              scanf("%f" , &b[i][j]);   
            }
    }
   
for(int i=0 ; i<2 ; i++)
{
    for(int j=0 ; j<2 ; j++)
    {
        c[i][j] = a[i][j] + b[i][j] ;
    }
}


for(int i=0 ; i<2 ; i++)
{
    for(int j=0 ; j<2 ; j++)
    {
        printf("%f " , c[i][j]) ;
        if(j==1)
        printf("\n\r") ;        
        
    }
}

}