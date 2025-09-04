/**
 * @file     T1_Config.h
 * @author   Hesham Ahmed       (Hisham4Ahmed@gmail.com)
 * @author   Dev.Hozifa Ahmed   (hozifasedik@gmail.com)
 * @author   Rev.Naira Mohamed  (naira.mohammed.76@gmail.com)
 * @brief    Configuration file for TIMER1 driver
 * @version  0.3
 * @date     2025-09-04
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 * 
 */

#ifndef _T1_CONFIG_H_
#define _T1_CONFIG_H_


/* ------------------ Mode selection ------------------ */
#define TIMER1_MODE   14   /* Fast PWM, ICR1 as TOP */

/* ------------------ Prescaler selection ------------------ */
#define TIMER1_PRESCALER   T1_PSC_CLK_8

/* ------------------ OC modes ------------------ */
#define TIMER1_OC1A_MODE   2   /* Clear on compare match (non-inverting PWM) */
#define TIMER1_OC1B_MODE   2   /* Clear on compare match (non-inverting PWM) */

/* ------------------ TOP / initial duty ------------------ */
#define TIMER1_TOP_VALUE   0xFFFF  /* Max value for ICR1 */
#define TIMER1_INIT_DUTY_CYCLE   0 /* Initial duty 0..100 */



#endif /*_T1_CONFIG_H_*/
