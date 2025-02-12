/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
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

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X
#define CONFIG_MSPM0G3507

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     32000000



/* Defines for PWM */
#define PWM_INST                                                           TIMG0
#define PWM_INST_IRQHandler                                     TIMG0_IRQHandler
#define PWM_INST_INT_IRQN                                       (TIMG0_INT_IRQn)
#define PWM_INST_CLK_FREQ                                                 125000
/* GPIO defines for channel 0 */
#define GPIO_PWM_C0_PORT                                                   GPIOA
#define GPIO_PWM_C0_PIN                                            DL_GPIO_PIN_5
#define GPIO_PWM_C0_IOMUX                                        (IOMUX_PINCM10)
#define GPIO_PWM_C0_IOMUX_FUNC                       IOMUX_PINCM10_PF_TIMG0_CCP0
#define GPIO_PWM_C0_IDX                                      DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_C1_PORT                                                   GPIOA
#define GPIO_PWM_C1_PIN                                           DL_GPIO_PIN_24
#define GPIO_PWM_C1_IOMUX                                        (IOMUX_PINCM54)
#define GPIO_PWM_C1_IOMUX_FUNC                       IOMUX_PINCM54_PF_TIMG0_CCP1
#define GPIO_PWM_C1_IDX                                      DL_TIMER_CC_1_INDEX



/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMA0)
#define TIMER_0_INST_IRQHandler                                 TIMA0_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMA0_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                          (1249U)




/* Defines for Left_A: GPIOA.13 with pinCMx 35 on package pin 6 */
#define GPIO_Encoder_Left_A_PORT                                         (GPIOA)
// pins affected by this interrupt request:["Left_A","Left_B"]
#define GPIO_Encoder_GPIOA_INT_IRQN                             (GPIOA_INT_IRQn)
#define GPIO_Encoder_GPIOA_INT_IIDX             (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define GPIO_Encoder_Left_A_IIDX                            (DL_GPIO_IIDX_DIO13)
#define GPIO_Encoder_Left_A_PIN                                 (DL_GPIO_PIN_13)
#define GPIO_Encoder_Left_A_IOMUX                                (IOMUX_PINCM35)
/* Defines for Left_B: GPIOA.12 with pinCMx 34 on package pin 5 */
#define GPIO_Encoder_Left_B_PORT                                         (GPIOA)
#define GPIO_Encoder_Left_B_IIDX                            (DL_GPIO_IIDX_DIO12)
#define GPIO_Encoder_Left_B_PIN                                 (DL_GPIO_PIN_12)
#define GPIO_Encoder_Left_B_IOMUX                                (IOMUX_PINCM34)
/* Defines for Right_A: GPIOB.13 with pinCMx 30 on package pin 1 */
#define GPIO_Encoder_Right_A_PORT                                        (GPIOB)
// pins affected by this interrupt request:["Right_A","Right_B"]
#define GPIO_Encoder_GPIOB_INT_IRQN                             (GPIOB_INT_IRQn)
#define GPIO_Encoder_GPIOB_INT_IIDX             (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define GPIO_Encoder_Right_A_IIDX                           (DL_GPIO_IIDX_DIO13)
#define GPIO_Encoder_Right_A_PIN                                (DL_GPIO_PIN_13)
#define GPIO_Encoder_Right_A_IOMUX                               (IOMUX_PINCM30)
/* Defines for Right_B: GPIOB.14 with pinCMx 31 on package pin 2 */
#define GPIO_Encoder_Right_B_PORT                                        (GPIOB)
#define GPIO_Encoder_Right_B_IIDX                           (DL_GPIO_IIDX_DIO14)
#define GPIO_Encoder_Right_B_PIN                                (DL_GPIO_PIN_14)
#define GPIO_Encoder_Right_B_IOMUX                               (IOMUX_PINCM31)
/* Port definition for Pin Group GPIO_PWM_L */
#define GPIO_PWM_L_PORT                                                  (GPIOB)

/* Defines for GPIO_pwmL0: GPIOB.7 with pinCMx 24 on package pin 59 */
#define GPIO_PWM_L_GPIO_pwmL0_PIN                                (DL_GPIO_PIN_7)
#define GPIO_PWM_L_GPIO_pwmL0_IOMUX                              (IOMUX_PINCM24)
/* Defines for GPIO_pwmL1: GPIOB.8 with pinCMx 25 on package pin 60 */
#define GPIO_PWM_L_GPIO_pwmL1_PIN                                (DL_GPIO_PIN_8)
#define GPIO_PWM_L_GPIO_pwmL1_IOMUX                              (IOMUX_PINCM25)
/* Port definition for Pin Group GPIO_PWM_R */
#define GPIO_PWM_R_PORT                                                  (GPIOB)

/* Defines for GPIO_pwmR0: GPIOB.15 with pinCMx 32 on package pin 3 */
#define GPIO_PWM_R_GPIO_pwmR0_PIN                               (DL_GPIO_PIN_15)
#define GPIO_PWM_R_GPIO_pwmR0_IOMUX                              (IOMUX_PINCM32)
/* Defines for GPIO_pwmR1: GPIOB.16 with pinCMx 33 on package pin 4 */
#define GPIO_PWM_R_GPIO_pwmR1_PIN                               (DL_GPIO_PIN_16)
#define GPIO_PWM_R_GPIO_pwmR1_IOMUX                              (IOMUX_PINCM33)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_init(void);
void SYSCFG_DL_TIMER_0_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
