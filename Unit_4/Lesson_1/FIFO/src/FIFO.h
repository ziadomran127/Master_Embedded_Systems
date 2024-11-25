/*
 * FIFO.h
 *
 *  Created on: Oct 17, 2024
 *      Author: LEGION
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdint.h"

#define Element_Type  uint8_t 
#define width1  5
Element_Type Uart_Buf[width1] ;

typedef struct 
{
    unsigned int Length   ;  
    unsigned int Count    ;
    Element_Type* Base    ;
    Element_Type* Header  ;
    Element_Type* Tail    ;
} Fifo_Buf_t ;

typedef enum 
{
    Fifo_No_Error,
    Fifo_Full,
    Fifo_Null,
    Fifo_Empty
} Fifo_Status ;


//APIS

Fifo_Status Fifo_Init( Fifo_Buf_t* Fifo , Element_Type* Buf , uint32_t length ) ;
Fifo_Status Fifo_Enqueue( Fifo_Buf_t* Fifo , Element_Type Item ) ;
Fifo_Status Fifo_dequeue( Fifo_Buf_t* Fifo , Element_Type* Item ) ;
Fifo_Status Fifo_Is_Full(Fifo_Buf_t* Fifo);
void Fifo_Print(Fifo_Buf_t* Fifo ) ; 







#endif /* FIFO_H_ */
