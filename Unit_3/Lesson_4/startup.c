/* Ziad abdlhakeem */

#include<stdint.h>
//#define STACK_Start_SP 0x20001000
extern int main(void) ;

void Reset_Handler(void);

void Default_Handler() 
{
    Reset_Handler() ;
}




void NMI_Handler(void)__attribute__((weak, alias("Default_Handler")));


void H_Fault_Handler(void)__attribute__((weak, alias("Default_Handler")));

/* reserve stack size */
static unsigned long Stack_top[256];

void (*const g_p_fn_Vectors[])() __attribute__((section(".vectors"))) = {
(void (*)())  ((unsigned long)Stack_top + sizeof(Stack_top)),
     &Reset_Handler,
     &NMI_Handler,
     &H_Fault_Handler,
};



extern unsigned int _E_TEXT ;
extern unsigned int _S_DATA ;
extern unsigned int _E_DATA ;
extern unsigned int _S_BSS  ;
extern unsigned int _E_BSS  ;

void Reset_Handler()
{
    unsigned int Data_Size =  (unsigned char *)&_E_DATA -(unsigned char *) &_S_DATA ;
    unsigned char* P_Src = (unsigned char * )&_E_TEXT;
    unsigned char* P_Dst = (unsigned char * )&_S_DATA;

    for(int i=0 ; i< Data_Size ; i++)
    {
        *((unsigned char*)(P_Dst)++) = *((unsigned char*)(P_Src)++) ;
    }
    

    unsigned int Bss_Size =  (unsigned char *)&_E_BSS -(unsigned char *) &_S_BSS ;
     P_Dst = (unsigned char * )&_S_BSS;

    for(int i=0 ; i< Data_Size ; i++)
    {
        *((unsigned char*)(P_Dst)++) = (unsigned char) 0 ;

    }

    main() ;
}