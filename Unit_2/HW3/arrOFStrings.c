#include<stdio.h>
#include<stdlib.h>
int main()
{
    char names [4][20] = {"ziad omran" , "youssef mohammed" , "Ahmed osama" , "ali marwan"};
    
    for(int i=0 ; i<4 ; i++)
    {
        printf("%s \n\r" , names[i]) ;
    }
}