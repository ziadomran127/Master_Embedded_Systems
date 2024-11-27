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


void MM_Fault_Handler(void)__attribute__((weak, alias("Default_Handler")));


void Bus_Fault(void)__attribute__((weak, alias("Default_Handler")));


void Usage_Fault_Handler(void)__attribute__((weak, alias("Default_Handler")));

extern unsigned int _stack_top ;

uint32_t vectors[] __attribute__((section(".vectors"))) = {
    (uint32_t) &_stack_top,
    (uint32_t) &Reset_Handler,
    (uint32_t) &NMI_Handler,
    (uint32_t) &H_Fault_Handler,
    (uint32_t) &MM_Fault_Handler,
    (uint32_t) &Bus_Fault, 
    (uint32_t) &Usage_Fault_Handler

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