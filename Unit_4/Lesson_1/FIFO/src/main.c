/*
 ============================================================================
 Name        : FIFO.c
 Author      : Ziad abdelhakeem
 Version     :
 Copyright   : Your copyright notice
 Description : Fifo  C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "FIFO.h"

int main(void) {
	Fifo_Buf_t Fifo_Uart ;
	Element_Type i , temp ;
	if(Fifo_Init(&Fifo_Uart , Uart_Buf , 5)== Fifo_No_Error )
	printf("Fifo Init=======> Done\n") ;

	for(i=0 ; i<7 ; i++)
	{
		printf("FIFO Enqueue (%x) \n" , i) ;
		if(Fifo_Enqueue(&Fifo_Uart , i)==Fifo_No_Error)
		printf("Fifo Enqueu Doooooooonnnneee\n") ;
		else
		printf("fifo Enqueue Failed\n") ;
	}

	Fifo_Print(&Fifo_Uart) ;
	if(Fifo_dequeue(&Fifo_Uart , &temp)== Fifo_No_Error)
	printf("fifo dequeue %x =========Done\n" ,temp) ;
	
	if(Fifo_dequeue(&Fifo_Uart , &temp)== Fifo_No_Error)
	printf("fifo dequeue %x =========Done\n" ,temp) ;
	Fifo_Print(&Fifo_Uart) ;
	
	




	
	
}
