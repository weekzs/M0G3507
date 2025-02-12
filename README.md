# M0G3507——M03507基础
删除git仓库里面的文件
https://blog.csdn.net/weixin_45309916/article/details/108275311

1、GPIO_按键控制_led

2、TIMER_翻转_led

3、usart串口控制反转led

4、CMSIS-DSP引用

5、IQMath

6、Printf

7、Encoder

8、80MHZ_system_clock
~~~python
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
    // 延迟 ms 毫秒
    for (uint32_t i = 0; i < ms; i++)
    {
        delay_cycles(cycles_per_ms);
    }
}
//串口发送函数
DL_UART_Main_transmitData(UART_0_INST, gEchoData);
//串口中断判断
DL_UART_Main_getPendingInterrupt(UART_0_INST);
//串口接收函数
DL_UART_Main_receiveData(UART_0_INST);
//串口中断
void UART_0_INST_IRQHandler(void)
{
    switch (DL_UART_Main_getPendingInterrupt(UART_0_INST)) {
        case DL_UART_MAIN_IIDX_RX:
            DL_GPIO_togglePins(GPIO_LEDS_PORT,
                GPIO_LEDS_USER_LED_1_PIN | GPIO_LEDS_USER_TEST_PIN);
            gEchoData = DL_UART_Main_receiveData(UART_0_INST);
            DL_UART_Main_transmitData(UART_0_INST, gEchoData);
            break;
        default:
            break;
    }
}

#include "arm_math.h"
volatile float32_t ans;
ans=arm_sin_f32(PI/2);


${COM_TI_MSPM0_SDK_INSTALL_DIR}/source/third_party/CMSIS/DSP/Include
__BKPT();//这个是软件断点

//阻塞发送，发送完成才进行下一步发送
DL_UART_Main_transmitDataBlocking(UART_0_INST,c);
//延时函数
delay_cycles(32000000);
//三条重定向语句
int fputc(int c,FILE* stream)
{
    DL_UART_Main_transmitDataBlocking(UART_0_INST,c);
    return c;
}
//如果只定义上面一个函数的话，那么printf不能打印参数
//下面两个重定向就一起重定向
int fputs(const char* restrict s,FILE* restrict stream)
{
    uint16_t i,len;
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        DL_UART_Main_transmitDataBlocking(UART_0_INST,s[i]);
    }
    return len;
}
int puts(const char*_ptr)
{
    int count = fputs(_ptr,stdout);
    count+=fputs("\n",stdout);
    return count;
}
//定义自己的发送函数
void Sendtring(char *str)
{
    while(*str!='\0')
    {
        DL_UART_Main_transmitDataBlocking(UART_0_INST,*str++);
    }
}
//sprintf存储发送
char txBuff[100];
sprintf(txBuff,"msp0 %d",3507);
Sendtring(txBuff);


//PWM配置
//开启定时器
 DL_Timer_startCounter(PWM_INST);
//设置ccr占空比
DL_Timer_setCaptureCompareValue(PWM_INST,speed,DL_TIMER_CC_1_INDEX);
//外部中断编码器
//这里的中断合并了，在中断向量表中，Group0是GPIOA，Group1是GPIOB
void GROUP1_IRQHandler(void)
{
    /*
     * Get the pending interrupt for the GPIOA port and store for
     * comparisons later
     */
    gpioA = DL_GPIO_getEnabledInterruptStatus(GPIO_Encoder_Left_A_PORT,GPIO_Encoder_Left_A_PIN | GPIO_Encoder_Left_B_PIN);
if (gpioA & GPIO_Encoder_Left_A_PIN) {
    if (DL_GPIO_readPins(GPIOA, GPIO_Encoder_Left_B_PIN)) {
        left--; // A 上升沿时，B 为高电平，表示反向
    } else {
        left++; // A 上升沿时，B 为低电平，表示正向
    }
    //这里的清除标志位，不要忘记了
    DL_GPIO_clearInterruptStatus(GPIOA, GPIO_Encoder_Left_A_PIN);
}
if (gpioA & GPIO_Encoder_Left_B_PIN) {
    if (DL_GPIO_readPins(GPIOA, GPIO_Encoder_Left_A_PIN)) {
        left++; // B 上升沿时，A 为高电平，表示正向
    } else {
        left--; // B 上升沿时，A 为低电平，表示反向
    }
    DL_GPIO_clearInterruptStatus(GPIOA, GPIO_Encoder_Left_B_PIN);
}
}
//定时器中断编码器
void TIMER_0_INST_IRQHandler(void)
{
    switch (DL_TimerG_getPendingInterrupt(TIMER_0_INST)) {
        case DL_TIMER_IIDX_ZERO:
            left=0;
          //  DL_TimerG_clearInterruptStatus(TIMER_0_INST); // 清除中断标
            break;
        default:
            break;
    }
}
~~~
