# M0G3507——M03507基础
1、GPIO_按键控制_led

2、TIMER_翻转_led

~~~ python
DL_GPIO_readPins（）//读电平
DL_GPIO_setPins(GPIO_LEDS_PORT, GPIO_LEDS_USER_LED_1_PIN);//高电平
DL_GPIO_clearPins(GPIO_LEDS_PORT, GPIO_LEDS_USER_LED_1_PIN);//低电平
delay_cycles(CPUCLK_FREQ/1000);
//电平翻转
DL_GPIO_togglePins(GPIO_LEDS_PORT, GPIO_LEDS_USER_TEST_PIN);
//开启NVIC中断
NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);
//开启定时器
DL_TimerG_startCounter(TIMER_0_INST);
//定时中断函数
DL_TimerG_getPendingInterrupt(TIMER_0_INST)
void TIMER_0_INST_IRQHandler(void)
{
    switch (DL_TimerG_getPendingInterrupt(TIMER_0_INST)) {
        case DL_TIMER_IIDX_ZERO:
            DL_GPIO_togglePins(LED0_PORT,
                LED0_LED_PIN_0_PIN);
            break;
        default:
            break;
    }
}
//这里的系统主频是32MHZ
void delay_ms(uint32_t ms)
{
    delay_cycles(CPUCLK_FREQ/1000);
}
~~~
