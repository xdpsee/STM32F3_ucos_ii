//@filename : BaseLib_Pwm.c
//@author : kgolym
//@date : 2012-12-08

#include "BaseLib_Pwm.h"

//@name: PWMInit
//@brief: 启动时钟中断
//@param:TIM_TypeDef * _TIM ： 定时器号
//@param:uint8_t _ch  ：定时器 pwm输出 通道号
//@param:GPIO_TypeDef* _port ：pwmm输出管脚
//@param:uint32_t _pin : pwm输出针脚
//@param:uint32_t _CLKHZ : 定时器计数器频率，必须为能被计时器时钟频率（84MHZ）整除
//@param:uint32_t _PWMHZ : pwm输出频率
//retval: 初始化成功与否
Boolean PWMInit(TIM_TypeDef *_TIM, uint8_t _ch,
				GPIO_TypeDef   *_port, uint32_t _pin,
				uint32_t _CLKHZ, uint32_t _PWMHZ)
{

	RCC_AHBPeriphClockCmd(GetBaseLib_RCC_AHBPeriph_GPIO(_port), ENABLE);

	if (_TIM == TIM1 ||  _TIM == TIM8  || _TIM == TIM15 || _TIM == TIM16 || _TIM == TIM17)
	{
		RCC_APB2PeriphClockCmd(GetBaseLib_RCC_APB2Periph_TIM(_TIM), ENABLE);
	}
	else
	{
		RCC_APB1PeriphClockCmd(GetBaseLib_RCC_APB1Periph_TIM(_TIM), ENABLE);
	}

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = _pin ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
	GPIO_Init(_port, &GPIO_InitStructure);

	GPIO_PinAFConfig(_port, GetBaseLib_GPIO_PinSource(_pin) , GetBaseLib_GPIO_AF_TIM(_TIM));

	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	RCC_ClocksTypeDef rcc_clocks;
	RCC_GetClocksFreq(&rcc_clocks);

	uint32_t TimClk = (uint32_t ) (rcc_clocks.SYSCLK_Frequency);

	uint32_t PrescalerValue = (uint16_t) (TimClk / _CLKHZ) - 1;
	uint32_t ARR = (uint32_t)(_CLKHZ / _PWMHZ);
	uint32_t CCRValue = (uint32_t)( 0.5 * ARR );

	TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
	TIM_TimeBaseStructure.TIM_Period = ARR - 1;
	TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(_TIM, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_Pulse = CCRValue;
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;
	
	if (_TIM == TIM1 ||  _TIM == TIM8  || _TIM == TIM15 || _TIM == TIM16 || _TIM == TIM17)
	{
		TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
		TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
		TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;
	}
	//选择输出通道，不同通道对应着不同的管脚
	if (_ch == 1)
	{
		TIM_OC1Init(_TIM, &TIM_OCInitStructure);
		TIM_OC1PreloadConfig(_TIM, TIM_OCPreload_Enable);
	}
	else if (_ch == 2)
	{
		TIM_OC2Init(_TIM, &TIM_OCInitStructure);
		TIM_OC2PreloadConfig(_TIM, TIM_OCPreload_Enable);
	}
	else if (_ch == 3)
	{
		TIM_OC3Init(_TIM, &TIM_OCInitStructure);
		TIM_OC3PreloadConfig(_TIM, TIM_OCPreload_Enable);
	}
	else if (_ch == 4)
	{
		TIM_OC4Init(_TIM, &TIM_OCInitStructure);
		TIM_OC4PreloadConfig(_TIM, TIM_OCPreload_Enable);
	}

	//预装载使能
	TIM_ARRPreloadConfig(_TIM, ENABLE);
	/* TIMx 计数器使能 */
	TIM_Cmd(_TIM, ENABLE);
	if (_TIM == TIM1 ||  _TIM == TIM8  || _TIM == TIM15 || _TIM == TIM16 || _TIM == TIM17)
	{
		TIM_CtrlPWMOutputs(_TIM,ENABLE);
	}

	return TRUE;
}
