#ifndef GPIO_H
#define GPIO_H

#include "bsp/stm32f4xx.h"
#include "driver/rcc.h"

typedef struct 
{
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFRLH[2];
}GpioRegisterTypeDef_t;

#define GPIOA   ((volatile GpioRegisterTypeDef_t*)(GPIOA_BASE_ADDR))
#define GPIOB   ((volatile GpioRegisterTypeDef_t*)(GPIOB_BASE_ADDR))
#define GPIOC   ((volatile GpioRegisterTypeDef_t*)(GPIOC_BASE_ADDR))
#define GPIOH   ((volatile GpioRegisterTypeDef_t*)(GPIOH_BASE_ADDR))

/*GPIO Pin Definitions*/
#define GPIO_PIN_0       (0U)
#define GPIO_PIN_1       (1U)
#define GPIO_PIN_2       (2U)
#define GPIO_PIN_3       (3U)
#define GPIO_PIN_4       (4U)
#define GPIO_PIN_5       (5U)
#define GPIO_PIN_6       (6U)
#define GPIO_PIN_7       (7U)
#define GPIO_PIN_8       (8U)
#define GPIO_PIN_9       (9U)
#define GPIO_PIN_10      (10U)
#define GPIO_PIN_11      (11U)
#define GPIO_PIN_12      (12U)
#define GPIO_PIN_13      (13U)
#define GPIO_PIN_14      (14U)
#define GPIO_PIN_15      (15U)

/*Gpio Pin Mode Definitions*/
#define GPIO_INPUT      (0U)
#define GPIO_OUTPUT     (1U)
#define GPIO_ALTERNATE  (2U)
#define GPIO_ANALOG     (3U)

/*Gpio Output Type Definitions*/
#define PUSH_PULL       (0U)
#define OPEN_DRAIN      (1U)

/*Gpio Output Speed Definitions*/
#define LOW_SPEED       (0U)
#define MEDIUM_SPEED    (1U)
#define HIGH_SPEED      (2U)
#define VHIGH_SPEED     (3U)

/*Gpio port pull up pull down definitions*/
#define NO_PUP_PDOWN    (0U)
#define PULL_UP         (1U)
#define PULL_DOWN       (2U)

/*Gpio Alternate Function Definitions
    @warning: If you don't select alternate function mode*/
#define GPIO_AF0         (0U)
#define GPIO_AF1         (1U)
#define GPIO_AF2         (2U)
#define GPIO_AF3         (3U)
#define GPIO_AF4         (4U)
#define GPIO_AF5         (5U)
#define GPIO_AF6         (6U)
#define GPIO_AF7         (7U)
#define GPIO_AF8         (8U)
#define GPIO_AF9         (9U)
#define GPIO_AF10        (10U)
#define GPIO_AF11        (11U)
#define GPIO_AF12        (12U)
#define GPIO_AF13        (13U)
#define GPIO_AF14        (14U)
#define GPIO_AF15        (15U)

typedef struct {
    uint8_t pinNumber;
    uint8_t gpioPinMode;
    uint8_t gpioOutputType;
    uint8_t gpioOutputSpeed;
    uint8_t gpioPuPdSelection;
    uint8_t gpioAlternateFunc;
}GpioConfig_t;

typedef struct{
    volatile GpioRegisterTypeDef_t* gpioBaseAddr;
    GpioConfig_t gpioConfig;
}GpioHandleTypeDef_t;

/*There is an error for GPIOH ? */
StatusTypeDef_t gpioInit(GpioHandleTypeDef_t* Handle);

#endif
