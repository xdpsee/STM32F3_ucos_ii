#include "main.h"

#pragma data_alignment=8
static OS_STK startup_task_stk[STARTUP_TASK_STK_SIZE];
static void startup_task(void *p_arg);

int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    BSP_IntDisAll();                        //关闭所有中断

    OSInit();
    OSTaskCreate(startup_task,
                 (void *)0,
                 &startup_task_stk[STARTUP_TASK_STK_SIZE - 1],
                 STARTUP_TASK_PRIO);
    OSStart();

    return 0;

}
static void startup_task(void *p_arg)
{
	BSP_Init(); //包含了中断向量的初始化
	CPU_Init(); //

	//根据官方代码，时钟要在这里初始化
	RCC_ClocksTypeDef rcc_clocks;
	RCC_GetClocksFreq(&rcc_clocks);
	SysTick_Config(rcc_clocks.HCLK_Frequency / OS_TICKS_PER_SEC);
	Mem_Init();
#if(OS_TASK_STAT_EN > 0)
	OSStatInit(); // Determine CPU capacity.
#endif


	/*TODO:create application tasks here*/
	
	OSTaskDel(OS_PRIO_SELF);
}


#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
    /* User can add his own implementation to report the file name and line number,
       ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

    /* Infinite loop */
    while (1)
    {
    }
}


#endif

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
