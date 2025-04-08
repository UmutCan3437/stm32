#include "bsp/stm32f4xx.h"


typedef struct 
{
    volatile uint32_t RCC_PLLCFG;
    volatile uint32_t RCC_PLLCFG;
    volatile uint32_t RCC_CFGR;
    volatile uint32_t RCC_CIR;
    volatile uint32_t RCC_AHB1RSTR;
    volatile uint32_t RCC_RESERVED[2];
    volatile uint32_t RCC_APB1RSTR;
    volatile uint32_t RCC_APB2RSTR;
    volatile uint32_t RCC_RESERVED;
    volatile uint32_t RCC_AHB1ENR;
    volatile uint32_t RCC_RESERVED;
    volatile uint32_t RCC_APB1ENR;
    volatile uint32_t RCC_APB2ENR;
    volatile uint32_t RESERVED;

    /*TODO: definitions will be continiue*/
}RccRegisterMap_t;



