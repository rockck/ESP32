#ifndef __MYADC_H_
#define __MYADC_H

#include "esp_adc/adc_oneshot.h"

extern adc_oneshot_unit_handle_t adc_unit_handle ;

void adc_init(void);

#endif
