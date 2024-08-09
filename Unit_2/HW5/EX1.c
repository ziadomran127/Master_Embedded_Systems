#include<stdio.h>
#include<stdlib.h>

struct S_student {
    char name[50] ;
    int roll_Num ;
    float marks ;

};

int main()
{
    struct S_student data ;
    printf("Enter information of Students : \n") ;
    printf("Enter Name : ") ;
    scanf("%s" , data.name ) ;
    printf("\n") ;


    printf("Enter roll Number : ") ;
    scanf("%d" , &data.roll_Num ) ;
    printf("\n") ;

     
    printf("Enter marks : ") ;
    scanf("%f" , &data.marks ) ;
    printf("\n") ;


    printf("Displaying informaation : \n") ;
    printf("Name : %s \n" , data.name) ;
    printf("Roll : %d \n" ,data.roll_Num ) ;
    printf("Marks : %0.2f \n" , data.marks) ;
}