#include "uart.h"
#define UARTODR  *((volatile unsigned int *) ( (unsigned int*)0x101f1000))

void Uart_Send_String(unsigned char * P_tx_String)
{
    while (*P_tx_String != '\0')
    {
        UARTODR = (unsigned int)*P_tx_String ;
        P_tx_String++; 
    }

    
}