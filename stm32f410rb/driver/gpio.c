#include "driver/gpio.h"


StatusTypeDef_t gpioInit(GpioHandleTypeDef_t* Handle)
{
    /*Enable Peripheral Clock*/
    if(Handle != NULL){
        if(Handle->gpioBaseAddr == GPIOA){
            GPIOA_CLK_EN();
        }
        else if(Handle->gpioBaseAddr == GPIOB){
            GPIOB_CLK_EN();
        }
        else if(Handle->gpioBaseAddr == GPIOC){
            GPIOC_CLK_EN();
        }
        else if(Handle->gpioBaseAddr == GPIOH){
            GPIOH_CLK_EN();
            uint32_t cnt = 0xFFFFFF;
            while(cnt--);
        }
        else{
            return INVALID_PARAM;
        }
        if(Handle->gpioConfig.gpioPinMode != GPIO_ALTERNATE){
            Handle->gpioBaseAddr->MODER |= (Handle->gpioConfig.gpioPinMode << Handle->gpioConfig.pinNumber * 2U);

            if(Handle->gpioConfig.gpioPinMode == GPIO_OUTPUT){
                Handle->gpioBaseAddr->OTYPER  |= (Handle->gpioConfig.gpioOutputType  << Handle->gpioConfig.pinNumber);
                Handle->gpioBaseAddr->OSPEEDR |= (Handle->gpioConfig.gpioOutputSpeed << Handle->gpioConfig.pinNumber * 2U);
            }

            Handle->gpioBaseAddr->PUPDR |= (Handle->gpioConfig.gpioPuPdSelection << Handle->gpioConfig.pinNumber * 2U);

            return NO_ERROR;
        }
        else{
            Handle->gpioBaseAddr->MODER |= (Handle->gpioConfig.gpioPinMode << Handle->gpioConfig.pinNumber * 2U);
            uint8_t regSelection    = Handle->gpioConfig.pinNumber / 8;
            uint8_t offsetSelection = Handle->gpioConfig.pinNumber % 8;
            Handle->gpioBaseAddr->AFRLH[regSelection] |= (Handle->gpioConfig.gpioAlternateFunc << offsetSelection * 4U);

            return NO_ERROR;
        }

    }
    else{
        return INVALID_PARAM;
    }
}

StatusTypeDef_t gpioTogglePin(GpioHandleTypeDef_t* Handle, uint8_t pinNumber)
{
    if(Handle->gpioBaseAddr != NULL){
        volatile uint16_t regVal = Handle->gpioBaseAddr->ODR;
        if(regVal & (1U << pinNumber)){
           Handle->gpioBaseAddr->BSRR |= ((1U << pinNumber) << 16U);
           return NO_ERROR;
        }
        else{
            Handle->gpioBaseAddr->BSRR |= (1U << pinNumber);
            return NO_ERROR;
        }
    }
    else{
        return INVALID_PARAM;
    }
}

StatusTypeDef_t gpioPinWrite(GpioHandleTypeDef_t* Handle, uint8_t pinNumber, uint8_t pinState)
{
    if(Handle->gpioBaseAddr != NULL){
        if(pinState == GPIO_PIN_RESET){
            Handle->gpioBaseAddr->ODR &= ~(1U << pinNumber);
            return NO_ERROR;
        }
        else if(pinState == GPIO_PIN_SET){
            Handle->gpioBaseAddr->ODR |= (1U << pinNumber);
            return NO_ERROR;
        }
        else{
            return INVALID_PARAM;
        }
    }
    else{
        return INVALID_PARAM;
    }
}

uint8_t gpioReadPin(GpioHandleTypeDef_t* Handle, uint8_t pinNumber)
{
    if(Handle->gpioBaseAddr != NULL){
        
        if(Handle->gpioBaseAddr->IDR & (1U << pinNumber)){
            return GPIO_PIN_SET;
        }
        else{
            return GPIO_PIN_RESET;
        }
    }
    else{
        return INVALID_PARAM;
    }
}