#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arr1[10] ;
    int arr2[10] ;
    int arr3[10] ;
    printf("Enter first array : ") ;
    for(int i=0 ; i<10 ; i++)      //get first array
    {
        scanf("%d" , &arr1[i]) ;
    }

    printf("Enter second array : ") ;     
    for(int i=0 ; i<5 ; i++)      // get second array 
    {
        scanf("%d" , &arr2[i]) ;
    }

    printf("Arrays before swapping:  \n" ) ;
    for(int i=0 ; i<10 ; i++)       //print first array before swapping
    printf("%d " , arr1[i]) ;
    printf("\n") ;
 for(int i=0 ; i<5 ; i++)       //print Second array before swapping
    printf("%d" , arr2[i]) ;
printf("\n") ;

     for(int i=0 ; i<5 ; i++)
     {
        arr3[i]=arr1[i] ;
       arr1[i] = arr2[i];
       arr2[i] = arr3[i] ;
     }

 for(int i=0 ; i<5 ; i++)       //print first array after swapping
    printf("%d " , arr1[i]) ;
    printf("\n") ;
 for(int i=0 ; i<10 ; i++)       //print Second array after swapping
    printf("%d" , arr2[i]) ;

}