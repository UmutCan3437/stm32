#include "exti.h"


void ClearInterrupts(int8_t extiLineNumber, uint8_t irqNumber)
{
    if(-1 != extiLineNumber){
        EXTI->PR |= (1U << extiLineNumber);
    }

    uint8_t nvicRegOffset = irqNumber / 32;
    uint8_t nvicShiftOffset = irqNumber % 32;

    *(NVIC_ICPR_BASE_ADDR + nvicRegOffset) |= (1U << nvicShiftOffset);

    return;
}