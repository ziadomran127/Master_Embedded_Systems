/*
 * Lifo.c
 *
 *  Created on: Oct 15, 2024
 *      Author: Ziad Abdelhakeem
 */

#include "Lifo.h" 



Lifo_Statues Lifo_Add_Item(Lifo_Buf_t* Lifo_Buf , unsigned int item  ) 
{
    if(!Lifo_Buf->base || !Lifo_Buf->head)
    return Lifo_Null;

    if(Lifo_Buf->count == Lifo_Buf->length)
    return Lifo_Full;

    *(Lifo_Buf->head) = item ;
    Lifo_Buf->head ++ ;
    Lifo_Buf->count++ ;
    return Lifo_No_Error ;

}


Lifo_Statues Lifo_Get_Item(Lifo_Buf_t* Lifo_Buf , unsigned int *item  ) 
{
    if(!Lifo_Buf->base || !Lifo_Buf->head)
    return Lifo_Null;

    if(Lifo_Buf->count == 0)
    return Lifo_Empty ;

    Lifo_Buf->head-- ;
    *item = *(Lifo_Buf->head) ;
    Lifo_Buf->count-- ;
    return Lifo_No_Error ;


}


Lifo_Statues Lifo_Init(Lifo_Buf_t* Lifo_Buf , unsigned int* Buf , unsigned int Length  ) 
{
    //check if its not valid
    if(Buf == '/0') 
    return Lifo_Null ;

    Lifo_Buf->base = Buf ;
    Lifo_Buf->head = Buf ;
    Lifo_Buf->length = Length ;
    Lifo_Buf->count = 0 ;
    return Lifo_No_Error ;


}


