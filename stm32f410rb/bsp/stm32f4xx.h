#ifndef STM32F4_H
#define STM32F4_H

#include <stdint.h>

/*Memory bus base addresses*/
#define BUS_APB1_BASE_ADDR (uint32_t)(0x40000000)
#define BUS_APB2_BASE_ADDR (uint32_t)(0x41000000)
#define BUS_AHB1_BASE_ADDR (uint32_t)(0x42000000)

#define USART2_BASE_ADDR   (uint32_t)(BUS_APB1_BASE_ADDR + 0x4400U)
#define RCC_BASE_ADDR      (uint32_t)(BUS_AHB1_BASE_ADDR + 0x3800U)




/*Bit manipulation*/
#define BIT(n)                  ((uint32_t)(1 << n))
#define SET_BIT(REG, BIT)       ((REG) |=  (BIT))
#define CLEAR_BIT(REG, BIT)     ((REG) &= ~(BIT))
#define TOGGLE_BIT(REG, BIT)    ((REG) ^=  (BIT))
#define REG_BIT(REG, BIT)       ((REG) &   (BIT))



#endif