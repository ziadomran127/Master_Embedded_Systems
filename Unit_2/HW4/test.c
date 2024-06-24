#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define Size 5 

int queue[Size] ;
int rear = -1     ;
int front = -1    ;

bool IsEmpty()          ;
bool IsFull()           ;
void Enqueue(int value) ;
void Dequeue(void)      ;
void display(void)      ;

int main()
{
Enqueue(1);
Enqueue(2);
Enqueue(3);
Enqueue(4);
display() ;
}

bool IsEmpty()
{
    if(rear==-1 && front ==-1)
    return true ;
    else
    return false ;
}

bool IsFull()
{
    if(rear == Size-1  && front==0)
    return true ;
    else if (front == rear+1)
    return true ;
    else
    return false ;
}


void Enqueue(int value)
{
    if (IsFull())
    {
        printf("The Queue is full") ;
        printf("\n");
    }
    else
    {
    if(IsEmpty())
    {
        rear = 0 ; front = 0 ;
        queue[rear] = value ; 
    }
    else if(rear == Size-1)
    {
        rear = 0 ;
        queue[rear] = value ;   
    }
    else
    queue[++rear] = value ;
    
    }
}


void dequeue(void)
{
    if(IsEmpty())
    {
        printf("The queue is empty " ) ;
        printf("\n");
    }
    
    else
    {
     if (front == rear)
     {
        rear = -1 ; front = -1 ;
     }
    else if(front == Size-1)
    front = 0 ;
    else
    front++; 
    }
}

void display()
{
    if(IsEmpty)
    {
        printf("The queue is Empty") ;
        printf("\n");   
    }
    else
    {
        if(front<=rear)
        {
            for(int i= front ; i<=rear ; i++)
            {
                printf("%d " , queue[i] );
            
            }
            printf("\n");
        }
        else
        {
             for (int i = front; i < Size ; i++)
        {
            printf("%d " , queue[i]) ;
        }
            for(int i=0 ; i <= rear ; i++ )
            {
                printf("%d ", queue[i] );
            } 
            printf("\n");
        }
       
        
    }
}