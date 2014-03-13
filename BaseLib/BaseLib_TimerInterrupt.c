//@filename: BaseLib_TimerInterrupt
//@author: kgolym
//@date : 2012-12-08


#include "BaseLib_TimerInterrupt.h"

//@name: InitTimerInt
//@brief: 启动时钟中断
//@param:TIM_TypeDef * _TIM 定时器号
//@param:int32_t _TIM_period 计数周期
//@param:int32_t  _div 将一秒分割为_div个单位,必须大于3000，否则分频溢出
//@param:NCT_VOID _TIM_ISR: ISR指针
//@param:int8_t _priority ：前4位为抢占优先级，后4位为响应优先级
//@retval: 无
//@notes：ISR函数最后需要 清中断
//TIM_ClearITPendingBit(TIMx,TIM_IT_Update);
//周期计算为 _TIM_period/_div 秒
void InitTimerInt(TIM_TypeDef *_TIM, uint32_t _TIM_period, uint32_t  _div,
				  FNCT_VOID _TIM_ISR, uint8_t _priority)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	RCC_ClocksTypeDef rcc_clocks;
	RCC_GetClocksFreq(&rcc_clocks);

	uint32_t SysClk;

	//TIM_X clock enable
	if (_TIM == TIM1 ||  _TIM == TIM8  || _TIM == TIM15 || _TIM == TIM16 || _TIM == TIM17)
	{
		RCC_APB2PeriphClockCmd(GetBaseLib_RCC_APB2Periph_TIM(_TIM), ENABLE);
		SysClk = (uint32_t ) (rcc_clocks.SYSCLK_Frequency );
	}
	else
	{
		RCC_APB1PeriphClockCmd(GetBaseLib_RCC_APB1Periph_TIM(_TIM), ENABLE);
		SysClk = (uint32_t ) (rcc_clocks.SYSCLK_Frequency / 2);
	}
	assert( (uint32_t)(SysClk / (float)_div) <= 65536 );
	//enable the TIM_X global interrupt
	NVIC_InitStructure.NVIC_IRQChannel = GetBaseLib_TIM_IRQn(_TIM);
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = (_priority >> 4) & 0x0f;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = _priority & 0x0f;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);




	//set interrupt time _TIM_period
	TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
	TIM_TimeBaseStructure.TIM_Period = _TIM_period - 1;
	TIM_TimeBaseStructure.TIM_Prescaler = (uint16_t)(SysClk / (float)_div) - 1;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

	TIM_TimeBaseInit(_TIM, &TIM_TimeBaseStructure);
	BSP_IntVectSet(GetBSP_INT_ID_TIM(_TIM), (_TIM_ISR));
	TIM_ITConfig(_TIM, TIM_IT_Update, ENABLE);

	//TIM enable counter
	TIM_Cmd(_TIM, ENABLE);
}

//@brief: 停止时钟中断
//@param:TIM_TypeDef * _TIM 定时器号
void StopTimer(TIM_TypeDef *_TIM )
{
	TIM_Cmd(_TIM, DISABLE);
}