#include "bsp/stm32f4xx.h"


typedef struct 
{
    volatile uint32_t RCC_CR;                 /*!< RCC clock control register,                                  Address offset: 0x00 */                                                      
    volatile uint32_t RCC_PLLCFGR;            /*!< RCC PLL configuration register,                              Address offset: 0x04 */                          
    volatile uint32_t RCC_CFGR;               /*!< RCC clock configuration register,                            Address offset: 0x08 */                      
    volatile uint32_t RCC_CIR;                /*!< RCC clock interrupt register,                                Address offset: 0x0C */                      
    volatile uint32_t RCC_AHB1RSTR;           /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */                          
    volatile uint32_t RCC_RESERVED0[3];       /*!< Reserved, 0x14-0x1C                                                               */                              
    volatile uint32_t RCC_APB1RSTR;           /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */                          
    volatile uint32_t RCC_APB2RSTR;           /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */                          
    volatile uint32_t RCC_RESERVED1[2];       /*!< Reserved, 0x28-0x2C                                                               */                              
    volatile uint32_t RCC_AHB1ENR;            /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */                          
    volatile uint32_t RCC_RESERVED2[3];       /*!< Reserved, 0x34-0x3C                                                               */                              
    volatile uint32_t RCC_APB1ENR;            /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */                          
    volatile uint32_t RCC_APB2ENR;            /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */                          
    volatile uint32_t RESERVED3[2];           /*!< Reserved, 0x48-0x4C                                                               */                          
    volatile uint32_t RCC_AHB1LPENR;          /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */                              
    volatile uint32_t RCC_RESERVED4[3];       /*!< Reserved, 0x54-0x5C                                                               */                              
    volatile uint32_t RCC_APB1LPENR;          /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */                              
    volatile uint32_t RCC_APB2LPENR;          /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */                              
    volatile uint32_t RESERVED5[2];           /*!< Reserved, 0x68-0x6C                                                               */                          
    volatile uint32_t RCC_BDCR;               /*!< RCC Backup domain control register,                          Address offset: 0x70 */                      
    volatile uint32_t RCC_CSR;                /*!< RCC clock control & status register,                         Address offset: 0x74 */                      
    volatile uint32_t RCC_RESERVED6[2];       /*!< Reserved, 0x78-0x7C                                                               */                              
    volatile uint32_t RCC_SSCGR;              /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */                          
    volatile uint32_t RESERVED7[2];           /*!< Reserved, 0x84-0x88                                                               */                          
    volatile uint32_t RCC_DCKCFGR;            /*!< RCC DCKCFGR configuration register,                          Address offset: 0x8C */                          
    volatile uint32_t RCC_RESERVED8;          /*!< RCC Clocks Gated Enable Register,                            Address offset: 0x90 */                              
    volatile uint32_t RCC_DCKCFGR2;           /*!< RCC Dedicated Clocks configuration register 2,               Address offset: 0x94 */                          
}RccRegisterDef_t;


#define RCC_REGS        ((RccRegisterDef_t *)(RCC_BASE_ADDR))

/* TODO: find a way to enable peripheral clocks in a generic way*/


