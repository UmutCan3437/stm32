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

StatusTypeDef_t gpioInitIRQ(GpioHandleTypeDef_t* Handle, uint8_t extiLineNumber, uint8_t irqNumber)
{
    if(Handle->gpioBaseAddr != NULL){
        
        SYSCFG_CLK_ENABLE();
        EXTI_CLK_ENABLE();
        
        uint8_t sysCfgPortVal = GPIO_PORT_SELECTION(Handle->gpioBaseAddr);
        uint8_t sysCfgRegOffset = extiLineNumber / 4;
        uint8_t sysCfgShiftOffset = extiLineNumber % 4;

        /* Configure the port as a EXTI line */
        SYSCFG->EXTICR[sysCfgRegOffset] |= (sysCfgPortVal << sysCfgShiftOffset * 4U);

        /* Unmask EXTI line interrupt */
        EXTI->IMR |= (1U << extiLineNumber);

        if(Handle->gpioConfig.gpioInterruptDetectType != EXTI_TRIGGER_SELECTION_BOTHEDGE)
        {
            if(Handle->gpioConfig.gpioInterruptDetectType != EXTI_TRIGGER_SELECTION_FT){
                EXTI->RTSR |= (1U << extiLineNumber);
            }
            else{
                EXTI->FTSR |= (1U << extiLineNumber);
            }
        }
        else{
            EXTI->RTSR |= (1U << extiLineNumber);
            EXTI->FTSR |= (1U << extiLineNumber);
        }

        /* Set NVIC_SETENA register for a particular irq number*/
        uint8_t nvicOffset = irqNumber / 32;
        uint8_t nvicShiftOffset = irqNumber % 32;
        *(NVIC_ISER_BASE_ADDR + nvicOffset) |= (1U << nvicShiftOffset);

        return NO_ERROR;
    }
    else{
        return INVALID_PARAM;
    }
}
