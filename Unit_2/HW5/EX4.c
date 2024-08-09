#include<stdio.h>
#include<stdlib.h>

struct S_Student 
{
    char name[50] ;
    int roll ; 
    float mark ;
}  ;

int main()
{
    
    struct S_Student s[10] ;
    int i ; 
    printf("Enter information of Students : ") ;
    for( i =0 ; i<3 ; i++)
    {
        s[i].roll = i+1 ;
        printf("For roll number %d \n" , s[i].roll) ;
        printf("Enter Name : ") ;
        scanf("%s" , &s[i].name) ;
        printf("Enter marks : ");
        scanf("%f" , &s[i].mark );
        printf("\n") ;

    }

    printf("Displaying information for student : \n ") ;

    for (int i = 0; i < 3; i++)
    {
        printf("Information for roll number %d : \n " , i+1) ;
        printf("Name : %s \n" , s[i].name) ;
        printf("Marks : ") ;
        printf("%0.2f \n" , s[i].mark ) ;

    }
    


}
