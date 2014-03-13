//@filename:  BaseLib_types.c
//@date: 2012-12-08
//@author: kgolym


#include "BaseLib_Types.h"




uint32_t GetBaseLib_RCC_AHBPeriph_GPIO(GPIO_TypeDef *_g)
{

	if (_g == GPIOA)    return RCC_AHBPeriph_GPIOA;
	else if (_g == GPIOB)    return RCC_AHBPeriph_GPIOB;
	else if (_g == GPIOC)    return RCC_AHBPeriph_GPIOC;
	else if (_g == GPIOD)    return RCC_AHBPeriph_GPIOD;
	else if (_g == GPIOE)    return RCC_AHBPeriph_GPIOE;
	else if (_g == GPIOF)    return RCC_AHBPeriph_GPIOF;
	return -1;
}
uint8_t GetBaseLib_EXTI_PortSourceGPIO(GPIO_TypeDef *_g)
{

	if (_g == GPIOA)    return EXTI_PortSourceGPIOA;
	else if (_g == GPIOB)    return EXTI_PortSourceGPIOB;
	else if (_g == GPIOC)    return EXTI_PortSourceGPIOC;
	else if (_g == GPIOD)    return EXTI_PortSourceGPIOD;
	else if (_g == GPIOE)    return EXTI_PortSourceGPIOE;
	else if (_g == GPIOF)    return EXTI_PortSourceGPIOF;
	return -1;
}

uint16_t  GetBaseLib_GPIO_PinSource(uint32_t _p)
{
	switch (_p)
	{
	case GPIO_Pin_0: return GPIO_PinSource0;
	case GPIO_Pin_1: return GPIO_PinSource1;
	case GPIO_Pin_2: return GPIO_PinSource2;
	case GPIO_Pin_3: return GPIO_PinSource3;
	case GPIO_Pin_4: return GPIO_PinSource4;
	case GPIO_Pin_5: return GPIO_PinSource5;
	case GPIO_Pin_6: return GPIO_PinSource6;
	case GPIO_Pin_7: return GPIO_PinSource7;
	case GPIO_Pin_8: return GPIO_PinSource8;
	case GPIO_Pin_9: return GPIO_PinSource9;
	case GPIO_Pin_10: return GPIO_PinSource10;
	case GPIO_Pin_11: return GPIO_PinSource11;
	case GPIO_Pin_12: return GPIO_PinSource12;
	case GPIO_Pin_13: return GPIO_PinSource13;
	case GPIO_Pin_14: return GPIO_PinSource14;
	case GPIO_Pin_15: return GPIO_PinSource15;
	}
	return -1;
}

uint8_t GetBaseLib_EXTI_PinSource(uint32_t _p)
{
	switch (_p)
	{
	case GPIO_Pin_0: return EXTI_PinSource0;
	case GPIO_Pin_1: return EXTI_PinSource1;
	case GPIO_Pin_2: return EXTI_PinSource2;
	case GPIO_Pin_3: return EXTI_PinSource3;
	case GPIO_Pin_4: return EXTI_PinSource4;
	case GPIO_Pin_5: return EXTI_PinSource5;
	case GPIO_Pin_6: return EXTI_PinSource6;
	case GPIO_Pin_7: return EXTI_PinSource7;
	case GPIO_Pin_8: return EXTI_PinSource8;
	case GPIO_Pin_9: return EXTI_PinSource9;
	case GPIO_Pin_10: return EXTI_PinSource10;
	case GPIO_Pin_11: return EXTI_PinSource11;
	case GPIO_Pin_12: return EXTI_PinSource12;
	case GPIO_Pin_13: return EXTI_PinSource13;
	case GPIO_Pin_14: return EXTI_PinSource14;
	case GPIO_Pin_15: return EXTI_PinSource15;
	}
	return -1;
}
uint32_t GetBaseLib_EXTI_Line(uint32_t _p)
{
	switch (_p)
	{
	case GPIO_Pin_0: return EXTI_Line0;
	case GPIO_Pin_1: return EXTI_Line1;
	case GPIO_Pin_2: return EXTI_Line2;
	case GPIO_Pin_3: return EXTI_Line3;
	case GPIO_Pin_4: return EXTI_Line4;
	case GPIO_Pin_5: return EXTI_Line5;
	case GPIO_Pin_6: return EXTI_Line6;
	case GPIO_Pin_7: return EXTI_Line7;
	case GPIO_Pin_8: return EXTI_Line8;
	case GPIO_Pin_9: return EXTI_Line9;
	case GPIO_Pin_10: return EXTI_Line10;
	case GPIO_Pin_11: return EXTI_Line11;
	case GPIO_Pin_12: return EXTI_Line12;
	case GPIO_Pin_13: return EXTI_Line13;
	case GPIO_Pin_14: return EXTI_Line14;
	case GPIO_Pin_15: return EXTI_Line15;
	}
	return -1;
}
uint16_t GetBaseLib_EXTI_IRQn(uint32_t _p)
{
	switch (_p)
	{
	case GPIO_Pin_0: return EXTI0_IRQn;
	case GPIO_Pin_1: return EXTI1_IRQn;
	case GPIO_Pin_2: return EXTI2_TS_IRQn;
	case GPIO_Pin_3: return EXTI3_IRQn;
	case GPIO_Pin_4: return EXTI4_IRQn;
	case GPIO_Pin_5: return EXTI9_5_IRQn;
	case GPIO_Pin_6: return EXTI9_5_IRQn;
	case GPIO_Pin_7: return EXTI9_5_IRQn;
	case GPIO_Pin_8: return EXTI9_5_IRQn;
	case GPIO_Pin_9: return EXTI9_5_IRQn;
	case GPIO_Pin_10: return EXTI15_10_IRQn;
	case GPIO_Pin_11: return EXTI15_10_IRQn;
	case GPIO_Pin_12: return EXTI15_10_IRQn;
	case GPIO_Pin_13: return EXTI15_10_IRQn;
	case GPIO_Pin_14: return EXTI15_10_IRQn;
	case GPIO_Pin_15: return EXTI15_10_IRQn;
	}
	return -1;
}
CPU_DATA GetBaseLib_BSP_INT_ID_EXTI(uint32_t _p)
{
	switch (_p)
	{
	case GPIO_Pin_0: return BSP_INT_ID_EXTI0;
	case GPIO_Pin_1: return BSP_INT_ID_EXTI1;
	case GPIO_Pin_2: return BSP_INT_ID_EXTI2_TS;
	case GPIO_Pin_3: return BSP_INT_ID_EXTI3;
	case GPIO_Pin_4: return BSP_INT_ID_EXTI4;
	case GPIO_Pin_5: return BSP_INT_ID_EXTI9_5;
	case GPIO_Pin_6: return BSP_INT_ID_EXTI9_5;
	case GPIO_Pin_7: return BSP_INT_ID_EXTI9_5;
	case GPIO_Pin_8: return BSP_INT_ID_EXTI9_5;
	case GPIO_Pin_9: return BSP_INT_ID_EXTI9_5;
	case GPIO_Pin_10: return BSP_INT_ID_EXTI15_10;
	case GPIO_Pin_11: return BSP_INT_ID_EXTI15_10;
	case GPIO_Pin_12: return BSP_INT_ID_EXTI15_10;
	case GPIO_Pin_13: return BSP_INT_ID_EXTI15_10;
	case GPIO_Pin_14: return BSP_INT_ID_EXTI15_10;
	case GPIO_Pin_15: return BSP_INT_ID_EXTI15_10;
	}
	return -1;
}


uint32_t  GetBaseLib_RCC_APB1Periph_USART(USART_TypeDef *_u)
{
	if ( USART2 == _u) return  RCC_APB1Periph_USART2;
	else if ( USART3 == _u) return  RCC_APB1Periph_USART3;
	else if ( UART4  == _u) return  RCC_APB1Periph_UART4;
	else if ( UART5  == _u) return  RCC_APB1Periph_UART5;
	return -1;
}
uint32_t  GetBaseLib_RCC_APB2Periph_USART(USART_TypeDef *_u)
{
	if ( USART1 == _u) return  RCC_APB2Periph_USART1;
	return -1;
}
uint8_t  GetBaseLib_GPIO_AF(USART_TypeDef *_u)
{
	if ( USART1 == _u) return  GPIO_AF_7;
	else if ( USART2 == _u) return  GPIO_AF_7;
	else if ( USART3 == _u) return  GPIO_AF_7;
	else if ( UART4  == _u) return  GPIO_AF_5;
	else if ( UART5  == _u) return  GPIO_AF_5;
	return -1;
}
CPU_DATA  GetBSP_INT_ID_USART(USART_TypeDef *_u)
{

	if ( USART1 == _u) return  BSP_INT_ID_USART1;
	else if ( USART2 == _u) return  BSP_INT_ID_USART2;
	else if ( USART3 == _u) return  BSP_INT_ID_USART3;
	else if ( UART4  == _u) return  BSP_INT_ID_UART4;
	else if ( UART5  == _u) return  BSP_INT_ID_UART5;
	return -1;
}
uint8_t  GetBaseLib_USART_IRQn(USART_TypeDef *_u)
{
	if ( USART1 == _u) return  USART1_IRQn;
	else if ( USART2 == _u) return  USART2_IRQn;
	else if ( USART3 == _u) return  USART3_IRQn;
	else if ( UART4  == _u) return  UART4_IRQn;
	else if ( UART5  == _u) return  UART5_IRQn;
	return -1;
}

uint32_t GetBaseLib_RCC_APB1Periph_TIM(TIM_TypeDef *_t)
{
	if ( TIM2  == _t) return RCC_APB1Periph_TIM2;
	else if ( TIM3  == _t) return RCC_APB1Periph_TIM3;
	else if ( TIM4  == _t) return RCC_APB1Periph_TIM4;
	else if ( TIM6  == _t) return RCC_APB1Periph_TIM6;
	else if ( TIM7  == _t) return RCC_APB1Periph_TIM7;
	return -1;
}
uint32_t GetBaseLib_RCC_APB2Periph_TIM(TIM_TypeDef *_t)
{
	if ( TIM1  == _t) return RCC_APB2Periph_TIM1;
	else if ( TIM8  == _t) return RCC_APB2Periph_TIM8;
	else if ( TIM15  == _t) return RCC_APB2Periph_TIM15;
	else if ( TIM16  == _t) return RCC_APB2Periph_TIM16;
	else if ( TIM17  == _t) return RCC_APB2Periph_TIM17;
	return -1;
}
CPU_DATA GetBSP_INT_ID_TIM(TIM_TypeDef *_t)
{
	if ( TIM1  == _t) return BSP_INT_ID_TIM1_UP_TIM16;
	else if ( TIM2  == _t) return BSP_INT_ID_TIM2;
	else if ( TIM3  == _t) return BSP_INT_ID_TIM3;
	else if ( TIM4  == _t) return BSP_INT_ID_TIM4;
	else if ( TIM6  == _t) return BSP_INT_ID_TIM6_DAC;
	else if ( TIM7  == _t) return BSP_INT_ID_TIM7;
	else if ( TIM8  == _t) return BSP_INT_ID_TIM8_UP;
	else if ( TIM15  == _t) return BSP_INT_ID_TIM1_BRK_TIM15;
	else if ( TIM16  == _t) return BSP_INT_ID_TIM1_UP_TIM16;
	else if ( TIM17  == _t) return BSP_INT_ID_TIM1_TRG_COM_TIM17;
	return -1;
}
uint8_t GetBaseLib_TIM_IRQn(TIM_TypeDef *_t)
{
	if ( TIM1  == _t) return TIM1_UP_TIM16_IRQn;
	else if ( TIM2  == _t) return TIM2_IRQn;
	else if ( TIM3  == _t) return TIM3_IRQn;
	else if ( TIM4  == _t) return TIM4_IRQn;
	else if ( TIM6  == _t) return TIM6_DAC_IRQn;
	else if ( TIM7  == _t) return TIM7_IRQn;
	else if ( TIM8  == _t) return TIM8_UP_IRQn;
	else if ( TIM15  == _t) return TIM1_BRK_TIM15_IRQn;
	else if ( TIM16  == _t) return TIM1_UP_TIM16_IRQn;
	else if ( TIM17  == _t) return TIM1_TRG_COM_TIM17_IRQn;
	return -1;
}
uint8_t GetBaseLib_GPIO_AF_TIM(TIM_TypeDef *_t)
{
	if ( TIM1  == _t) return GPIO_AF_2;
	else if ( TIM2  == _t) return GPIO_AF_2;
	else if ( TIM3  == _t) return GPIO_AF_2;
	else if ( TIM4  == _t) return GPIO_AF_2;
	else if ( TIM8  == _t) return GPIO_AF_4;
	else if ( TIM15  == _t) return GPIO_AF_9;
	else if ( TIM16  == _t) return GPIO_AF_1;
	else if ( TIM17  == _t) return GPIO_AF_1;
	return -1;
}
