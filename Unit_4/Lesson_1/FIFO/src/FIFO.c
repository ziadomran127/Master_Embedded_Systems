/*
 * FIFO.c
 *
 *  Created on: Oct 17, 2024
 *      Author: LEGION
 */

#include "stdio.h"
#include "FIFO.h"


Fifo_Status Fifo_Init( Fifo_Buf_t* Fifo , Element_Type* Buf , uint32_t length ) 
{
    if(Buf==NULL)
    return Fifo_Null      ;

    Fifo->Base = Buf      ;
    Fifo->Header = Buf    ;
    Fifo->Tail = Buf      ;
    Fifo->Length = length ;
    Fifo->Count = 0       ;
    
    return Fifo_No_Error  ;
}

Fifo_Status Fifo_Enqueue( Fifo_Buf_t* Fifo , Element_Type Item ) 
{
    if (!Fifo->Base || !Fifo->Header || !Fifo->Tail )
    return Fifo_Null ;

    if(Fifo_Is_Full(Fifo) == Fifo_Full )
    return Fifo_Full ;

    *(Fifo->Header) = Item ;
    Fifo->Count++ ;

    //circular fifo
    if(Fifo->Header == (Fifo->Base + (Fifo->Length*sizeof(Element_Type))))
    Fifo->Header = Fifo->Base ;
    else
    Fifo->Header++ ;
    return Fifo_No_Error ;
}

Fifo_Status Fifo_dequeue( Fifo_Buf_t* Fifo , Element_Type* Item ) 
{
    if (!Fifo->Base || !Fifo->Header || !Fifo->Tail )
    return Fifo_Null ;

    if(Fifo->Count == 0 )
    return Fifo_Empty ;

    *Item = *(Fifo->Tail) ;
    Fifo->Count-- ;

    //circulaar fifo
    if(Fifo->Tail == (Fifo->Tail + (Fifo->Length*sizeof(Element_Type))))
    Fifo->Tail == Fifo->Base ;
    else
    Fifo->Tail++ ;
    return Fifo_No_Error ;

}

Fifo_Status Fifo_Is_Full(Fifo_Buf_t* Fifo)
{
    if (!Fifo->Base || !Fifo->Header || !Fifo->Tail )
    return Fifo_Null ;

    if(Fifo->Count == Fifo->Length)
    return Fifo_Full ;
}

void Fifo_Print(Fifo_Buf_t* Fifo ) 
{
    Element_Type* temp ;
    int i ; 
    if(Fifo->Count == 0)
    {
        printf("------<<Fifo Is Empty>>-------");
    }else{
        temp =Fifo->Tail ;
        printf("\n========fifo_Print==========\n") ;
        for ( i = 0; i < Fifo->Count; i++)
        {
            printf("\t %X \n" , *temp) ;
            temp++ ;
        }

        printf("===============\n") ;

    }
}

