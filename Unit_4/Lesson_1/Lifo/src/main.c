#include "Lifo.h"
#include <stdio.h>
#include<stdlib.h>
unsigned int Buffer_1[5] ;


int main(void) {
int i , temp ; 

    Lifo_Buf_t Uart_Lifo , I2C_Lifo ;
    
    //Static allocation
    Lifo_Init(&Uart_Lifo , Buffer_1 , 5) ;

    //dynamic allocation
    unsigned int* Buffer_2 = (unsigned int *) malloc(5 * sizeof(unsigned int)) ;
    Lifo_Init(&I2C_Lifo , Buffer_2 , 5);

   for(i=0 ; i<5 ; i++)
   {
      if (Lifo_Add_Item(&Uart_Lifo , i) == Lifo_No_Error)
        printf(" Uart_Lifo added :  %d \n " , i) ;

   }

   for (int i = 0; i < 5 ; i++)
   {
        if( Lifo_Get_Item(&Uart_Lifo , &temp ) == Lifo_No_Error)
        printf("Uart_Lifo get : %d \n " , temp) ;
   }
   
}
