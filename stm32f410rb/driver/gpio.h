#include "bsp/stm32f4xx.h"
#include "driver/rcc.h"


typedef struct 
{
    volatile int32_t MODER;
    volatile int32_t OTYPER;
    volatile int32_t OSPEEDR;
    volatile int32_t PUPDR;
    volatile int32_t IDR;
    volatile int32_t ODR;
    volatile int32_t BSRR;
    volatile int32_t LCKR;
    volatile int32_t AFRL;
    volatile int32_t AFRH;
}GpioRegisterTypeDef_t;

#define GPIOA   ((GpioRegisterTypeDef_t*)(GPIOA_BASE_ADDR))
#define GPIOB   ((GpioRegisterTypeDef_t*)(GPIOB_BASE_ADDR))
#define GPIOC   ((GpioRegisterTypeDef_t*)(GPIOC_BASE_ADDR))
#define GPIOH   ((GpioRegisterTypeDef_t*)(GPIOH_BASE_ADDR))

typedef struct {
    uint8_t pinNumber;
    uint8_t gpioPinMode;
    uint8_t gpioOutputType;
    uint8_t gpioOutputSpeed;
    uint8_t gpioPuPdSelection;
}GpioConfig_t;

typedef struct{
    GpioRegisterTypeDef_t* gpioBaseAddr;
    GpioConfig_t gpioConfig;
}GpioHandleTypeDef_t;


