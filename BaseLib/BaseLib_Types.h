//@filename:  BaseLib_types.c
//@date: 2012-12-08
//@author: kgolym

#ifndef _BaseLib_TYPES_H_
#define _BaseLib_TYPES_H_

#include "bsp.h"

typedef void (*FNCT_VOID)(void);        //无返回值空参数的函数指针类型

typedef void (*BaseLib_COMMAND_FUNT)(uint8_t *, uint8_t);        //无返回值空参数的函数指针类型

#define Boolean uint8_t
#define TRUE (1==1)
#define FALSE (1==0)



uint32_t GetBaseLib_RCC_AHBPeriph_GPIO(GPIO_TypeDef *_g);
uint16_t  GetBaseLib_GPIO_PinSource(uint32_t _p);
uint8_t GetBaseLib_EXTI_PortSourceGPIO(GPIO_TypeDef *_g);
uint8_t GetBaseLib_EXTI_PinSource(uint32_t _p);
uint32_t GetBaseLib_EXTI_Line(uint32_t _p);
uint16_t GetBaseLib_EXTI_IRQn(uint32_t _p);
CPU_DATA GetBaseLib_BSP_INT_ID_EXTI(uint32_t _p);


uint32_t  GetBaseLib_RCC_APB1Periph_USART(USART_TypeDef *_u);
uint32_t  GetBaseLib_RCC_APB2Periph_USART(USART_TypeDef *_u);
uint8_t  GetBaseLib_GPIO_AF(USART_TypeDef *_u);
CPU_DATA  GetBSP_INT_ID_USART(USART_TypeDef *_u);
uint8_t  GetBaseLib_USART_IRQn(USART_TypeDef *_u);


uint32_t GetBaseLib_RCC_APB1Periph_TIM(TIM_TypeDef * _t);
uint32_t GetBaseLib_RCC_APB2Periph_TIM(TIM_TypeDef * _t);
CPU_DATA GetBSP_INT_ID_TIM(TIM_TypeDef * _t);
uint8_t GetBaseLib_TIM_IRQn(TIM_TypeDef * _t);
uint8_t GetBaseLib_GPIO_AF_TIM(TIM_TypeDef * _t);



#endif  //  _BaseLib_TYPES_H_
