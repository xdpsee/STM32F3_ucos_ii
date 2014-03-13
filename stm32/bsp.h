/*
*********************************************************************************************************
*                                     MICIRUM BOARD SUPPORT PACKAGE
*
*                             (c) Copyright 2007; Micrium, Inc.; Weston, FL
*
*               All rights reserved.  Protected by international copyright laws.
*               Knowledge of the source code may NOT be used to develop a similar product.
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                        BOARD SUPPORT PACKAGE
*
*                                     ST Microelectronics STM32
*                                              on the
*
*                                     Micrium uC-Eval-STM32F107
*                                        Evaluation Board
*
* Filename      : bsp.h
* Version       : V1.00
* Programmer(s) : EHS
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                                 MODULE
*
* Note(s) : (1) This header file is protected from multiple pre-processor inclusion through use of the
*               BSP present pre-processor macro definition.
*********************************************************************************************************
*/

#ifndef  BSP_PRESENT
#define  BSP_PRESENT


/*
*********************************************************************************************************
*                                                 EXTERNS
*********************************************************************************************************
*/

#ifdef   BSP_MODULE
#define  BSP_EXT
#else
#define  BSP_EXT  extern
#endif


/*
*********************************************************************************************************
*                                              INCLUDE FILES
*********************************************************************************************************
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <arm_math.h>
#include <cpu.h>
#include <cpu_core.h>

#include <lib_ascii.h>
#include <lib_def.h>
#include <lib_mem.h>
#include <lib_str.h>

#include "stm32f30x.h"
#include "stm32f3_discovery.h"
#include "stm32f30x_it.h"
#include "stm32f30x_conf.h"
#include <ucos_ii.h>
#include <app_cfg.h>

#define assert(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
/*
*********************************************************************************************************
*                                               INT DEFINES
*********************************************************************************************************
*/


#define  BSP_INT_ID_WWDG                    0      /*!< Window WatchDog Interrupt                                         */
#define  BSP_INT_ID_PVD                     1      /*!< PVD through EXTI Line detection Interrupt                         */
#define  BSP_INT_ID_TAMPER_STAMP            2      /*!< Tamper and TimeStamp interrupts                                   */
#define  BSP_INT_ID_RTC_WKUP                3      /*!< RTC Wakeup interrupt through the EXTI lines 17, 19 & 20           */
#define  BSP_INT_ID_FLASH                   4      /*!< FLASH global Interrupt                                            */
#define  BSP_INT_ID_RCC                     5      /*!< RCC global Interrupt                                              */
#define  BSP_INT_ID_EXTI0                   6      /*!< EXTI Line0 Interrupt                                              */
#define  BSP_INT_ID_EXTI1                   7      /*!< EXTI Line1 Interrupt                                              */
#define  BSP_INT_ID_EXTI2_TS                8      /*!< EXTI Line2 Interrupt and Touch Sense Interrupt                    */
#define  BSP_INT_ID_EXTI3                   9      /*!< EXTI Line3 Interrupt                                              */
#define  BSP_INT_ID_EXTI4                   10     /*!< EXTI Line4 Interrupt                                              */
#define  BSP_INT_ID_DMA1_Channel1           11     /*!< DMA1 Channel 1 Interrupt                                          */
#define  BSP_INT_ID_DMA1_Channel2           12     /*!< DMA1 Channel 2 Interrupt                                          */
#define  BSP_INT_ID_DMA1_Channel3           13     /*!< DMA1 Channel 3 Interrupt                                          */
#define  BSP_INT_ID_DMA1_Channel4           14     /*!< DMA1 Channel 4 Interrupt                                          */
#define  BSP_INT_ID_DMA1_Channel5           15     /*!< DMA1 Channel 5 Interrupt                                          */
#define  BSP_INT_ID_DMA1_Channel6           16     /*!< DMA1 Channel 6 Interrupt                                          */
#define  BSP_INT_ID_DMA1_Channel7           17     /*!< DMA1 Channel 7 Interrupt                                          */
#define  BSP_INT_ID_ADC1_2                  18     /*!< ADC1 & ADC2 Interrupts                                            */
#define  BSP_INT_ID_USB_HP_CAN1_TX          19     /*!< USB Device High Priority or CAN1 TX Interrupts                    */
#define  BSP_INT_ID_USB_LP_CAN1_RX0         20     /*!< USB Device Low Priority or CAN1 RX0 Interrupts                    */
#define  BSP_INT_ID_CAN1_RX1                21     /*!< CAN1 RX1 Interrupt                                                */
#define  BSP_INT_ID_CAN1_SCE                22     /*!< CAN1 SCE Interrupt                                                */
#define  BSP_INT_ID_EXTI9_5                 23     /*!< External Line[9:5] Interrupts                                     */
#define  BSP_INT_ID_TIM1_BRK_TIM15          24     /*!< TIM1 Break and TIM15 Interrupts                                   */
#define  BSP_INT_ID_TIM1_UP_TIM16           25     /*!< TIM1 Update and TIM16 Interrupts                                  */
#define  BSP_INT_ID_TIM1_TRG_COM_TIM17      26     /*!< TIM1 Trigger and Commutation and TIM17 Interrupt                  */
#define  BSP_INT_ID_TIM1_CC                 27     /*!< TIM1 Capture Compare Interrupt                                    */
#define  BSP_INT_ID_TIM2                    28     /*!< TIM2 global Interrupt                                             */
#define  BSP_INT_ID_TIM3                    29     /*!< TIM3 global Interrupt                                             */
#define  BSP_INT_ID_TIM4                    30     /*!< TIM4 global Interrupt                                             */
#define  BSP_INT_ID_I2C1_EV                 31     /*!< I2C1 Event Interrupt                                              */
#define  BSP_INT_ID_I2C1_ER                 32     /*!< I2C1 Error Interrupt                                              */
#define  BSP_INT_ID_I2C2_EV                 33     /*!< I2C2 Event Interrupt                                              */
#define  BSP_INT_ID_I2C2_ER                 34     /*!< I2C2 Error Interrupt                                              */
#define  BSP_INT_ID_SPI1                    35     /*!< SPI1 global Interrupt                                             */
#define  BSP_INT_ID_SPI2                    36     /*!< SPI2 global Interrupt                                             */
#define  BSP_INT_ID_USART1                  37     /*!< USART1 global Interrupt                                           */
#define  BSP_INT_ID_USART2                  38     /*!< USART2 global Interrupt                                           */
#define  BSP_INT_ID_USART3                  39     /*!< USART3 global Interrupt                                           */
#define  BSP_INT_ID_EXTI15_10               40     /*!< External Line[15:10] Interrupts                                   */
#define  BSP_INT_ID_RTC_Alarm               41     /*!< RTC Alarm (A and B) through EXTI Line Interrupt                   */
#define  BSP_INT_ID_USBWakeUp               42     /*!< USB Wakeup Interrupt                                              */
#define  BSP_INT_ID_TIM8_BRK                43     /*!< TIM8 Break Interrupt                                              */
#define  BSP_INT_ID_TIM8_UP                 44     /*!< TIM8 Update Interrupt                                             */
#define  BSP_INT_ID_TIM8_TRG_COM            45     /*!< TIM8 Trigger and Commutation Interrupt                            */
#define  BSP_INT_ID_TIM8_CC                 46     /*!< TIM8 Capture Compare Interrupt                                    */
#define  BSP_INT_ID_ADC3                    47     /*!< ADC3 global Interrupt                                             */
#define  BSP_INT_ID_SPI3                    51     /*!< SPI3 global Interrupt                                             */
#define  BSP_INT_ID_UART4                   52     /*!< UART4 global Interrupt                                            */
#define  BSP_INT_ID_UART5                   53     /*!< UART5 global Interrupt                                            */
#define  BSP_INT_ID_TIM6_DAC                54     /*!< TIM6 global and DAC1&2 underrun error  interrupts                 */
#define  BSP_INT_ID_TIM7                    55     /*!< TIM7 global Interrupt                                             */
#define  BSP_INT_ID_DMA2_Channel1           56     /*!< DMA2 Channel 1 global Interrupt                                   */
#define  BSP_INT_ID_DMA2_Channel2           57     /*!< DMA2 Channel 2 global Interrupt                                   */
#define  BSP_INT_ID_DMA2_Channel3           58     /*!< DMA2 Channel 3 global Interrupt                                   */
#define  BSP_INT_ID_DMA2_Channel4           59     /*!< DMA2 Channel 4 global Interrupt                                   */
#define  BSP_INT_ID_DMA2_Channel5           60     /*!< DMA2 Channel 5 global Interrupt                                   */
#define  BSP_INT_ID_ADC4                    61     /*!< ADC4  global Interrupt                                            */
#define  BSP_INT_ID_COMP1_2_3               64     /*!< COMP1, COMP2 and COMP3 global Interrupt                           */
#define  BSP_INT_ID_COMP4_5_6               65     /*!< COMP5, COMP6 and COMP4 global Interrupt                           */
#define  BSP_INT_ID_COMP7                   66     /*!< COMP7 global Interrupt                                            */
#define  BSP_INT_ID_USB_HP                  74     /*!< USB High Priority global Interrupt remap                          */
#define  BSP_INT_ID_USB_LP                  75     /*!< USB Low Priority global Interrupt  remap                          */
#define  BSP_INT_ID_USBWakeUp_RMP           76     /*!< USB Wakeup Interrupt remap                                        */
#define  BSP_INT_ID_FPU                     81     /*!< Floating point Interrupt                                          */
 
/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/
void         BSP_Init                    (void);

void         BSP_IntDisAll               (void);

CPU_INT32U   BSP_CPU_ClkFreq             (void);

/*
*********************************************************************************************************
*                                     PERIPHERAL POWER/CLOCK SERVICES
*********************************************************************************************************
*/

CPU_INT32U   BSP_PeriphClkFreqGet        (CPU_DATA       pwr_clk_id);

void         BSP_PeriphEn                (CPU_DATA       pwr_clk_id);

void         BSP_PeriphDis               (CPU_DATA       pwr_clk_id);
/*
*********************************************************************************************************
*                                           INTERRUPT SERVICES
*********************************************************************************************************
*/

void         BSP_IntInit                 (void);

void         BSP_IntEn                   (CPU_DATA       int_id);

void         BSP_IntDis                  (CPU_DATA       int_id);

void         BSP_IntClr                  (CPU_DATA       int_id);

void         BSP_IntVectSet              (CPU_DATA       int_id,
		CPU_FNCT_VOID  isr);

void         BSP_IntPrioSet              (CPU_DATA       int_id,
		CPU_INT08U     prio);

/*
*********************************************************************************************************
*                                              STATUS INPUTS
*********************************************************************************************************
*/

CPU_BOOLEAN  BSP_StatusRd                (CPU_INT08U  id);


void WWDG_IRQHandler(void) ;
void PVD_IRQHandler(void) ;
void TAMPER_STAMP_IRQHandler(void) ;
void RTC_WKUP_IRQHandler(void) ;
void FLASH_IRQHandler(void) ;
void RCC_IRQHandler(void) ;
void EXTI0_IRQHandler(void) ;
void EXTI1_IRQHandler(void) ;
void EXTI2_TS_IRQHandler(void) ;
void EXTI3_IRQHandler(void) ;
void EXTI4_IRQHandler(void) ;
void DMA1_Channel1_IRQHandler(void) ;
void DMA1_Channel2_IRQHandler(void) ;
void DMA1_Channel3_IRQHandler(void) ;
void DMA1_Channel4_IRQHandler(void) ;
void DMA1_Channel5_IRQHandler(void) ;
void DMA1_Channel6_IRQHandler(void) ;
void DMA1_Channel7_IRQHandler(void) ;
void ADC1_2_IRQHandler(void) ;
void USB_HP_CAN1_TX_IRQHandler(void) ;
void USB_LP_CAN1_RX0_IRQHandler(void) ;
void CAN1_RX1_IRQHandler(void) ;
void CAN1_SCE_IRQHandler(void) ;
void EXTI9_5_IRQHandler(void) ;
void TIM1_BRK_TIM15_IRQHandler(void) ;
void TIM1_UP_TIM16_IRQHandler(void) ;
void TIM1_TRG_COM_TIM17_IRQHandler(void) ;
void TIM1_CC_IRQHandler(void) ;
void TIM2_IRQHandler(void) ;
void TIM3_IRQHandler(void) ;
void TIM4_IRQHandler(void) ;
void I2C1_EV_IRQHandler(void) ;
void I2C1_ER_IRQHandler(void) ;
void I2C2_EV_IRQHandler(void) ;
void I2C2_ER_IRQHandler(void) ;
void SPI1_IRQHandler(void) ;
void SPI2_IRQHandler(void) ;
void USART1_IRQHandler(void) ;
void USART2_IRQHandler(void) ;
void USART3_IRQHandler(void) ;
void EXTI15_10_IRQHandler(void) ;
void RTC_Alarm_IRQHandler(void) ;
void USBWakeUp_IRQHandler(void) ;
void TIM8_BRK_IRQHandler(void) ;
void TIM8_UP_IRQHandler(void) ;
void TIM8_TRG_COM_IRQHandler(void) ;
void TIM8_CC_IRQHandler(void) ;
void ADC3_IRQHandler(void) ;
void SPI3_IRQHandler(void) ;
void UART4_IRQHandler(void) ;
void UART5_IRQHandler(void) ;
void TIM6_DAC_IRQHandler(void) ;
void TIM7_IRQHandler(void) ;
void DMA2_Channel1_IRQHandler(void) ;
void DMA2_Channel2_IRQHandler(void) ;
void DMA2_Channel3_IRQHandler(void) ;
void DMA2_Channel4_IRQHandler(void) ;
void DMA2_Channel5_IRQHandler(void) ;
void ADC4_IRQHandler(void) ;
void COMP1_2_3_IRQHandler(void) ;
void COMP4_5_6_IRQHandler(void) ;
void COMP7_IRQHandler(void) ;
void USB_HP_IRQHandler(void) ;
void USB_LP_IRQHandler(void) ;
void USBWakeUp_RMP_IRQHandler(void) ;
void FPU_IRQHandler(void) ;
#endif





