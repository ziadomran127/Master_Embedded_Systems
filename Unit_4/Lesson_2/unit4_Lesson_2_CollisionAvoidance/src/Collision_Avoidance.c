/*
 * CA.c
 *
 *  Created on: Oct 27, 2024
 *      Author: Ziad Abdelhakeem
 */

#include "Collision_Avoidance.h"
#include "State.h"

int CA_Speed = 0 ;
int CA_Distance = 0 ;
int CA_Threshold = 50 ;


void (*CA_State)();


  void US_Distance_Set(int d)
  {
	  CA_Distance = d ;
	  (CA_Distance<=CA_Threshold) ? (CA_State = STATE(CA_Waiting)) : (CA_State = STATE(CA_Driving));
	  DPRINTF("US--------- distance=%d -------> CA " , CA_Distance);
  }

  STATE_define (CA_Waiting)
  {
	 CA_State_Id = CA_Waiting ;
	 DPRINTF(" CA Waiting state :distance=%d  Speed=%d\n " , CA_Distance , CA_Speed);

    CA_Speed = 0 ;

    DC_Motor(CA_Speed) ;



  }

STATE_define (CA_Driving)
  {
	  CA_State_Id = CA_Driving ;
  printf("CA_DRiving State : distance = %d Speed = %d \n  " , CA_Distance , CA_Speed);
    CA_Speed = 30 ;
    DC_Motor(CA_Speed) ;

  }

  int US_Get_Distance_Random (int l , int r , int count)
  {

    for(int i=0 ; i<count ; i++){
      int rand_num = (rand()% (r-l+1))+1 ;
      return rand_num ;
    }


  }

