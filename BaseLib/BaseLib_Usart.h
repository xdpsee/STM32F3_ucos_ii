//@filename:BaseLib_usart.c
//@author: kgolym
//@date:18-August-2012
//@brief:USART串口通信  功能函数封装类库

#ifndef _BaseLib_USART_H_
#define _BaseLib_USART_H_

#include "bsp.h"
#include "BaseLib.h"


//@name: USART_Config
//@brief: 配置USART的串口通信功能
//@param:_USARTx          需要绑定的USART串口
//@param:_GPIOx           需要绑定的GPIO组
//@param:_GPIO_PinX_T     需要绑定的串口发送管脚
//@param:_GPIO_PinX_R        需要绑定的串口接收管脚
//@param:_intFuc          接收中断函数的指针
//@param:_baudRate       传送的波特率
//@param:_pri           优先级
void BaseLib_USART_Config(USART_TypeDef * _USARTx, GPIO_TypeDef * _GPIOx, uint32_t _GPIO_PinX_T,
					  uint32_t _GPIO_PinX_R, FNCT_VOID _intFuc, uint32_t _baudRate,uint8_t _pri);



//@name: BaseLib_USART_Send_Char
//@brief: 通过已定义的串口发送一个字符
//@param:_USARTx         已经绑定的USART串口
//@param:_character       要发送的字符
inline void BaseLib_USART_Send_Char(USART_TypeDef * _USARTx, uint8_t _character)
{
	while (USART_GetFlagStatus(_USARTx, USART_FLAG_TC) == RESET);
	USART_SendData(_USARTx, (uint16_t)_character & 0x00ff);
}

//@name: BaseLib_USART_Send_Str
//@brief: 通过已定义的串口发送一个字符串
//@param:_USARTx         已经绑定的USART串口
//@param:_TxBuffer        要发送的字符串数组
inline void BaseLib_USART_Send_Str( USART_TypeDef * _USARTx,uint8_t _TxBuffer[])
{
	uint8_t i = 0;
	while (USART_GetFlagStatus(_USARTx, USART_FLAG_TC) == RESET);
	for (; _TxBuffer[i] != '\0'; i++)
	{
		USART_SendData(_USARTx, (uint16_t)_TxBuffer[i]);
		while (USART_GetFlagStatus(_USARTx, USART_FLAG_TC) == RESET);
	}
}

//@name: BaseLib_USART_Send_Data
//@brief: 通过已定义的串口发送一串数据
//@param:_USARTx         已经绑定的USART串口
//@param:address         数据起始地址
//@param:length          数据长度
inline void BaseLib_USART_Send_Data(USART_TypeDef * _USARTx, uint8_t *address, uint8_t length)
{
	uint8_t i = 0;
	while (USART_GetFlagStatus(_USARTx, USART_FLAG_TC) == RESET);
	for (; i < length ; i++)
	{
		USART_SendData(_USARTx, (uint16_t) * (address + i));
		while (USART_GetFlagStatus(_USARTx, USART_FLAG_TC) == RESET);
	}
}
//@name: BaseLib_USART_Accept_Char
//@brief: 通过已定义的串口接收一个字符
//@param: _USARTx         已经绑定的USART串口
//@retval: uint16位 的字符
inline uint16_t BaseLib_USART_Accept_Char(USART_TypeDef * _USARTx)
{
	return USART_ReceiveData(_USARTx);
}

#endif //_BaseLib_USART_H_