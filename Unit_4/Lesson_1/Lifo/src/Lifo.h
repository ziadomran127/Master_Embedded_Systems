/*
 * Lifo.h
 *
 *  Created on: Oct 15, 2024
 *      Author: LEGION
 */

#ifndef LIFO_H_
#define LIFO_H_


typedef struct {
	unsigned int length;
	unsigned int count ;
	unsigned int *base ;
	unsigned int *head ;


} Lifo_Buf_t ;

typedef enum {
	Lifo_No_Error,
	Lifo_Full,
	Lifo_Empty,
	Lifo_Null

}Lifo_Statues ;

//APIs
Lifo_Statues Lifo_Add_Item(Lifo_Buf_t* Lifo_Buf , unsigned int item  ) ;
Lifo_Statues Lifo_Get_Item(Lifo_Buf_t* Lifo_Buf , unsigned int *item  ) ;
Lifo_Statues Lifo_Init(Lifo_Buf_t* Lifo_Buf , unsigned int* Buf , unsigned int Length  ) ;


#endif
