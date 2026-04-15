#ifndef __PWM_H_
#define __PWM_H_

#include <stdint.h>

void pwm_init(void);
void duty_set(uint16_t duty);

#endif
