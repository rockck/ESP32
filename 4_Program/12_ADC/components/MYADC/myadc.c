#include "myadc.h"
#include "driver/adc.h"
#include "esp_adc/adc_oneshot.h"

adc_oneshot_unit_handle_t adc_unit_handle ;

void adc_init(void)
{
    adc_oneshot_unit_init_cfg_t oneshot_structure = {
        .clk_src = ADC_RTC_CLK_SRC_DEFAULT,
        .ulp_mode = ADC_ULP_MODE_DISABLE,
        .unit_id = ADC_UNIT_1,
    };
    adc_oneshot_new_unit(&oneshot_structure, &adc_unit_handle);

    adc_oneshot_chan_cfg_t oneshot_chan_structure = {
        .atten = ADC_ATTEN_DB_11,
        .bitwidth = ADC_BITWIDTH_12,
    };
    adc_oneshot_config_channel(adc_unit_handle, ADC_CHANNEL_3, &oneshot_chan_structure);
    adc_oneshot_config_channel(adc_unit_handle, ADC_CHANNEL_4, &oneshot_chan_structure);
}