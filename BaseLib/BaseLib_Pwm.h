//@filename : BaseLib_Pwm.c
//@author : kgolym
//@date : 2012-12-08


#ifndef __BaseLib_PWM__
#define __BaseLib_PWM__

#include "bsp.h"
#include "BaseLib_Types.h"

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
				uint32_t _CLKHZ, uint32_t _PWMHZ);


//@brief:获取定时器的周期
//@param:   TIM_TypeDef * _TIM 使用的定时器
//@retval : 定时器的周期
inline uint32_t PWMGetPeriod(TIM_TypeDef *_TIM)
{
	uint32_t ARR = _TIM->ARR + 1;
	return ARR;
}


//@brief: 在输出频率不变的情况下改变pwm占空比
//@param:TIM_TypeDef * _TIM 使用的定时器
//@palam:uint8_t _ch，输出的通道
//@palam:double _percent 输出占分比
inline void PWMOutput(TIM_TypeDef *_TIM, uint8_t _ch, double _percent)
{
	uint32_t ARR = PWMGetPeriod(_TIM);
	uint32_t CCRValue = (uint32_t)(_percent * ARR );
	if (_ch == 1)
	{
		_TIM -> CCR1 = CCRValue;
	}
	else if (_ch == 2)
	{
		_TIM -> CCR2 = CCRValue;
	}
	else if (_ch == 3)
	{
		_TIM -> CCR3 = CCRValue;
	}
	else if (_ch == 4)
	{
		_TIM -> CCR4 = CCRValue;
	}
}

//@brief:获取pwm的占空比
//@param:TIM_TypeDef * _TIM 使用的定时器
//@param:uint8_t _ch，输出的通道
//@retval:占空比
inline double PWMGetPercent(TIM_TypeDef *_TIM, uint8_t _ch)
{
	uint32_t ARR = PWMGetPeriod(_TIM);
	if (_ch == 1)
	{
		return (double)(_TIM -> CCR1) / (double)ARR;
	}
	else if (_ch == 2)
	{
		return (double)(_TIM -> CCR2) / (double)ARR;
	}
	else if (_ch == 3)
	{
		return (double)(_TIM -> CCR3) / (double)ARR;
	}
	else if (_ch == 4)
	{
		return (double)(_TIM -> CCR4) / (double)ARR;
	}
	return -1;
}

#endif