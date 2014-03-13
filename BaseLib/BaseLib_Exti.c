//@filename: BaseLib_Exti.c
//@author : kgolym
//@date : 2012-12-08

#include "BaseLib_Exti.h"


//@name:    BaseLib_InitEXTI
//@brief:   初始化外部中断功能
//@param:GPIO_TypeDef *  _port: 端口
//@param:uint32_t _pin: 端口序号
//@param:FNCT_VOID _isr: 中断服务程序的函数指针
//@param:uint8_t _priority ：前4位为抢占优先级，后4位为响应优先级
//@retval: void
//@note： 清零中断函数  EXTI_ClearITPendingBit(BaseLib_EXTI_Lines[GPIONum]);
//          GPIONum为中断线号（端口序号）
void BaseLib_InitEXTI(GPIO_TypeDef *_port, uint32_t _pin, EXTITrigger_TypeDef _trigger, FNCT_VOID _isr, uint8_t _priority)
{
	GPIO_InitTypeDef   GPIO_InitStructure;
	NVIC_InitTypeDef   NVIC_InitStructure;
	EXTI_InitTypeDef   EXTI_InitStructure;
	/* Enable GPIO clock */
	RCC_AHBPeriphClockCmd(GetBaseLib_RCC_AHBPeriph_GPIO(_port), ENABLE);
	/* Enable SYSCFG clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

	/* Configure  pin as input floating */
	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	if (_trigger == EXTI_Trigger_Rising)
	{
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	}
	else
	{
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	}
	GPIO_InitStructure.GPIO_Pin = _pin;
	GPIO_Init(_port, &GPIO_InitStructure);

	/* Connect EXTI Line to pin */
	SYSCFG_EXTILineConfig(GetBaseLib_EXTI_PortSourceGPIO(_port), GetBaseLib_EXTI_PinSource(_pin));

	/* Configure EXTI Line */
	EXTI_StructInit(&EXTI_InitStructure);
	EXTI_InitStructure.EXTI_Line = GetBaseLib_EXTI_Line(_pin);
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = _trigger;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	BSP_IntVectSet(GetBaseLib_BSP_INT_ID_EXTI(_pin), _isr);

	NVIC_InitStructure.NVIC_IRQChannel = GetBaseLib_EXTI_IRQn(_pin);
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = (_priority >> 4) & 0x0f;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = _priority & 0x0f;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);


}

void SetGpioOutput(GPIO_TypeDef *_port, uint32_t _pin)
{
	GPIO_InitTypeDef   GPIO_InitStructure;
	/* Enable GPIO clock */
	RCC_AHBPeriphClockCmd(GetBaseLib_RCC_AHBPeriph_GPIO(_port), ENABLE);
	/* Enable SYSCFG clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = _pin ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(_port, &GPIO_InitStructure);
}

void SetGpioInput(GPIO_TypeDef *_port, uint32_t _pin)
{
	GPIO_InitTypeDef   GPIO_InitStructure;
	/* Enable GPIO clock */
	RCC_AHBPeriphClockCmd(GetBaseLib_RCC_AHBPeriph_GPIO(_port), ENABLE);
	/* Enable SYSCFG clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = _pin ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(_port, &GPIO_InitStructure);
}

