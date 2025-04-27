#ifndef EXTI_H
#define EXTI_H

#include "bsp/stm32f4xx.h"

typedef struct {
    volatile uint32_t IMR;
    volatile uint32_t EMR;
    volatile uint32_t RTSR;
    volatile uint32_t FTSR;
    volatile uint32_t SWIER;
    volatile uint32_t PR;
}ExtiRegisterTypeDef_t;

/*EXTI Registers*/
#define EXTI        ((ExtiRegisterTypeDef_t*)(EXTI_BASE_ADDR))

/*EXTI Interrupt Triger Type Selection*/
#define EXTI_TRIGGER_SELECTION_FT           (0U)
#define EXTI_TRIGGER_SELECTION_RT           (1U)
#define EXTI_TRIGGER_SELECTION_BOTHEDGE     (2U)

/*NVIC SETENA positions of EXTI Lines*/
#define EXTI0_IRQ       (6U)
#define EXTI1_IRQ       (7U)
#define EXTI2_IRQ       (8U)
#define EXTI3_IRQ       (9U)
#define EXTI4_IRQ       (10U)
#define EXTI9_5_IRQ     (23U)
#define EXTI15_10_IRQ   (40U)
#define EXTI17_IRQ      (41U)
#define EXTI19_IRQ      (62U)
#define EXTI20_IRQ      (76U)
#define EXTI21_IRQ      (2U)
#define EXTI22_IRQ      (3U)

/*EXTI Lines*/
#define EXTI0       (0U)
#define EXTI1       (1U)
#define EXTI2       (2U)
#define EXTI3       (3U)
#define EXTI4       (4U)
#define EXTI5       (5U)
#define EXTI6       (6U)
#define EXTI7       (7U)
#define EXTI8       (8U)
#define EXTI9       (9U)
#define EXTI10      (10U)
#define EXTI11      (11U)
#define EXTI12      (12U)
#define EXTI13      (13U)
#define EXTI14      (14U)
#define EXTI15      (15U)

void ClearExtiInterrupts(int8_t extiLineNumber, uint8_t irqNumber);

#endif
