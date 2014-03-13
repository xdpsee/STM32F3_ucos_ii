//@filename: BaseLib_Exti.h
//@author : kgolym
//@date : 2012-12-08

#ifndef _BaseLib_EXTI_H_
#define _BaseLib_EXTI_H_

#include "bsp.h"
#include "BaseLib_Types.h"


//@name:    BaseLib_InitEXTI
//@brief:   初始化外部中断功能
//@param:GPIO_TypeDef *  _port: 端口
//@param:uint32_t _pin: 端口序号
//@param:FNCT_VOID _isr: 中断服务程序的函数指针
//@param:uint8_t _priority ：前4位为抢占优先级，后4位为响应优先级
//@retval: void
//@note： 清零中断函数  EXTI_ClearITPendingBit(BaseLib_EXTI_Lines[GPIONum]);
//          GPIONum为中断线号（端口序号）
void BaseLib_InitEXTI(GPIO_TypeDef *_port, uint32_t _pin, EXTITrigger_TypeDef _trigger, FNCT_VOID _isr, uint8_t _priority);

void SetGpioOutput(GPIO_TypeDef *_port, uint32_t _pin);
void SetGpioInput(GPIO_TypeDef *_port, uint32_t _pin);

inline void SetGpioLow(GPIO_TypeDef *_port, uint32_t _pin)
{
	/* Check the parameters */
	assert_param(IS_GPIO_ALL_PERIPH(_port));
	assert_param(IS_GPIO_PIN(_pin));
	_port->BRR = _pin;
}
inline void SetGpioHigh(GPIO_TypeDef *_port, uint32_t _pin)
{
	/* Check the parameters */
	assert_param(IS_GPIO_ALL_PERIPH(_port));
	assert_param(IS_GPIO_PIN(_pin));
	_port->BSRR = _pin;
}
inline void ToggleGpio(GPIO_TypeDef *_port, uint32_t _pin)
{
	assert_param(IS_GPIO_ALL_PERIPH(_port));
	_port->ODR ^= _pin;
}

inline uint8_t ReadGpio(GPIO_TypeDef *_port, uint32_t _pin)
{
	return GPIO_ReadInputDataBit(_port, _pin);
}
#endif  //  _BaseLib_EXTI_H_