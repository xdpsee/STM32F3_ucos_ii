//@filename: BaseLib_TimerInterrupt
//@author: kgolym
//@date: 2012-12-08


#ifndef _TIMER_INTERRUPT_H_
#define _TIMER_INTERRUPT_H_

#include "bsp.h"
#include "BaseLib_Types.h"


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
void InitTimerInt(TIM_TypeDef * _TIM, uint32_t _TIM_period, uint32_t  _div,
					FNCT_VOID _TIM_ISR,uint8_t _priority);


//@brief: 停止时钟中断
//@param:TIM_TypeDef * _TIM 定时器号
void StopTimer(TIM_TypeDef * _TIM );
#endif //_TIMER_INTERRUPT_H_