#ifndef STM32F4XX_H
#define STM32F4XX_H

#include <stdint.h>
#include <stdlib.h>

/*TODO: add comment */
#define APB1_BUS_BASE_ADDR  (0x40000000U)
#define APB2_BUS_BASE_ADDR  (0x40010000U)
#define AHB1_BUS_BASE_ADDR  (0x40020000U)

/*GPIO Peripherals Base Addresses*/
#define GPIOA_BASE_ADDR            (AHB1_BUS_BASE_ADDR)
#define GPIOB_BASE_ADDR            (AHB1_BUS_BASE_ADDR + 0x400U)
#define GPIOC_BASE_ADDR            (AHB1_BUS_BASE_ADDR + 0x800U)
#define GPIOH_BASE_ADDR            (AHB1_BUS_BASE_ADDR + 0x1C00U)

/*RCC Base Address*/
#define RCC_BASE_ADDR              (AHB1_BUS_BASE_ADDR + 0x3800U)

/*SYSCFG Base Address*/
#define SYSCFG_BASE_ADDR           (APB2_BUS_BASE_ADDR + 0x3800U)

/*EXTI Base Address*/
#define EXTI_BASE_ADDR             (APB2_BUS_BASE_ADDR + 0x3C00U)

/*Cortex-M Processor NVIC Base Address*/
#define NVIC_ISER_BASE_ADDR             ((volatile uint32_t*)(0xE000E100))  /* NVIC Set Enable Register      */
#define NVIC_ICER_BASE_ADDR             ((volatile uint32_t*)(0XE000E180))  /* NVIC Clear Enable Register    */
#define NVIC_ISPR_BASE_ADDR             ((volatile uint32_t*)(0XE000E200))  /* NVIC Set Pending Register     */
#define NVIC_ICPR_BASE_ADDR             ((volatile uint32_t*)(0XE000E280))  /* NVIC Clear Pending Register   */

/*Definition of SYSCFG registers*/
typedef struct{
    volatile uint32_t MEMRMP;
    volatile uint32_t PMC;
    volatile uint32_t EXTICR[4];
    volatile uint32_t CFGR2;
    volatile uint32_t RESERVED; /* ? */
    volatile uint32_t CMPCR;
    volatile uint32_t CFGR;
}SyscfgRegisterTypedef_t;



/*SYSCFG Registers*/
#define SYSCFG                  ((SyscfgRegisterTypedef_t*)SYSCFG_BASE_ADDR)

typedef enum{
    NO_ERROR,
    IO_ERROR,
    INVALID_PARAM
}StatusTypeDef_t;

#endif

