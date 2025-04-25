#include "bsp/stm32f4xx.h"


/*RCC peripheral register definitions*/
typedef struct 
{
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t AHB1RSTR;
    volatile uint32_t RESERVED1[3];
    volatile uint32_t APB1RSTR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t RESERVED2[2];
    volatile uint32_t AHB1ENR;
    volatile uint32_t RESERVED3[3];
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;
    volatile uint32_t RESERVED4[2];
    volatile uint32_t AHB1LPENR;
    volatile uint32_t RESERVED5[3];
    volatile uint32_t APB1LPENR;
    volatile uint32_t APB2LPENR;
    volatile uint32_t RESERVED6[2];
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
    volatile uint32_t RESERVED7[2];
    volatile uint32_t SSCGR;
    volatile uint32_t RESERVED8[2];
    volatile uint32_t DCKCFGR;
    volatile uint32_t RESERVED9;
    volatile uint32_t DCKCFGR2;
}RccRegTypedef_t;

#define RCC_REGS        ((RccRegTypedef_t*)RCC_BASE_ADDR)

/*GPIO Peripheral Clock Enable Macros*/
#define GPIOA_CLK_EN()          (RCC_REGS->AHB1ENR |= (1 << 0U))
#define GPIOB_CLK_EN()          (RCC_REGS->AHB1ENR |= (1 << 1U))
#define GPIOC_CLK_EN()          (RCC_REGS->AHB1ENR |= (1 << 2U))
#define GPIOH_CLK_EN()          (RCC_REGS->AHB1ENR |= (1 << 7U))

/*GPIO Peripheral Clock Disable Macros*/
#define GPIOA_CLK_DISABLE()     (RCC_REGS->AHB1ENR &= ~(1 << 0U))
#define GPIOB_CLK_DISABLE()     (RCC_REGS->AHB1ENR &= ~(1 << 1U))
#define GPIOC_CLK_DISABLE()     (RCC_REGS->AHB1ENR &= ~(1 << 2U))
#define GPIOH_CLK_DISABLE()     (RCC_REGS->AHB1ENR &= ~(1 << 7U))
