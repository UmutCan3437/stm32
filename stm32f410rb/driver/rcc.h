#include "bsp/stm32f4xx.h"


typedef struct 
{
    volatile uint32_t RCC_CR;
    volatile uint32_t RCC_PLLCFGR;
    volatile uint32_t RCC_CFGR;
    volatile uint32_t RCC_CIR;
    volatile uint32_t RCC_AHB1RSTR;
    volatile uint32_t RCC_RESERVED0[3];
    volatile uint32_t RCC_APB1RSTR;
    volatile uint32_t RCC_APB2RSTR;
    volatile uint32_t RCC_RESERVED1[2];
    volatile uint32_t RCC_AHB1ENR;
    volatile uint32_t RCC_RESERVED2[3];
    volatile uint32_t RCC_APB1ENR;
    volatile uint32_t RCC_APB2ENR;
    volatile uint32_t RESERVED3[2];
    volatile uint32_t RCC_AHB1LPENR;
    volatile uint32_t RCC_RESERVED4[3];
    volatile uint32_t RCC_APB1LPENR;
    volatile uint32_t RCC_APB2LPENR;
    volatile uint32_t RESERVED5[2];
    volatile uint32_t RCC_BDCR;
    volatile uint32_t RCC_CSR;
    volatile uint32_t RCC_RESERVED6[2];
    volatile uint32_t RCC_SSCGR;
    volatile uint32_t RESERVED7[2];
    volatile uint32_t RCC_DCKCFGR;
    volatile uint32_t RCC_RESERVED8;
    volatile uint32_t RCC_DCKCFGR2;
}RccRegisterDef_t;



