#ifndef STM32F4_H
#define STM32F4_H

#include <stdint.h>

/*Memory bus base addresses*/
#define BUS_APB1_BASE_ADDR (0x40000000U)
#define BUS_APB2_BASE_ADDR (0x41000000U)
#define BUS_AHB1_BASE_ADDR (0x42000000U)

#define USART2_BASE_ADDR   (BUS_APB1_BASE_ADDR + 0x4400U)
#define RCC_BASE_ADDR      (BUS_AHB1_BASE_ADDR + 0x3800U)


#define WRITE_REG(REG,VAL)      ((REG) = (uint32_t)(VAL))

#endif
