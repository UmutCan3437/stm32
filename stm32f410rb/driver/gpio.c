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

            /*Investigate whether it should be done for alternate func or not*/
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
