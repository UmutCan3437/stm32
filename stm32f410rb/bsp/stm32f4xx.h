#include <stdint.h>

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


