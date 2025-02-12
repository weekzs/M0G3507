/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "ti/driverlib/dl_gpio.h"
#include "ti/driverlib/dl_timerg.h"
#include "ti/driverlib/m0p/dl_core.h"
#include "ti_msp_dl_config.h"
//#include <cstdint>
uint32_t gpioB;
uint32_t gpioA;
volatile  int32_t left = 0;
volatile  int32_t right = 0;
volatile int32_t speed =500;
void straight(void);
int main(void)
{
    SYSCFG_DL_init();
    DL_Timer_startCounter(PWM_INST);
    /* Enable Interrupt for both GPIOA and GPIOB ports */
    //开启的两个外部中断
    NVIC_EnableIRQ(GPIO_Encoder_GPIOA_INT_IRQN);
    NVIC_EnableIRQ(GPIO_Encoder_GPIOB_INT_IRQN);
    //开启定时器中断
    NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);
    //开启定时器
    DL_TimerG_startCounter(TIMER_0_INST);
    while (1) {
       straight();
     //  DL_Timer_setCaptureCompareValue(PWM_INST,speed,DL_TIMER_CC_0_INDEX);
       DL_Timer_setCaptureCompareValue(PWM_INST,speed,DL_TIMER_CC_1_INDEX);
       delay_cycles(32000000);
    }
}
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
void straight(void)
{
    //左轮
  DL_GPIO_clearPins(GPIO_PWM_L_PORT,GPIO_PWM_L_GPIO_pwmL0_PIN);
  DL_GPIO_setPins(GPIO_PWM_L_PORT,GPIO_PWM_L_GPIO_pwmL1_PIN);
  //右轮
//     DL_GPIO_setPins(GPIO_PWM_R_PORT,GPIO_PWM_R_GPIO_pwmR0_PIN);
//   DL_GPIO_clearPins(GPIO_PWM_R_PORT,GPIO_PWM_R_GPIO_pwmR1_PIN);
//DL_GPIO_setPins(GPIO_LEDS_PORT, GPIO_LEDS_USER_LED_1_PIN);//高电平
}
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