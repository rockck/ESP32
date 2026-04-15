#include "gptim.h"
#include "driver/gptimer.h"
#include "esp_attr.h"

gptimer_handle_t gptimer = NULL;
uint8_t flag_timer = 0 ;
bool IRAM_ATTR TimerCallback (gptimer_handle_t timer, const gptimer_alarm_event_data_t *edata, void *user_ctx);

void gptimer_init(void)
{
    gptimer_config_t    gptimer_structure = {
        .clk_src = GPTIMER_CLK_SRC_DEFAULT,
        .direction = GPTIMER_COUNT_UP,
        .flags.intr_shared = 0,
        .intr_priority = 0,
        .resolution_hz = 1000000,
    };
    gptimer_new_timer(&gptimer_structure, &gptimer);

    gptimer_alarm_config_t  alarm_structure = {
        .alarm_count = 500000,
        .flags.auto_reload_on_alarm = 1,
        .reload_count  = 0,
    };
    gptimer_set_alarm_action(gptimer, &alarm_structure);

    gptimer_event_callbacks_t   callbacks_structure = {
        .on_alarm = TimerCallback,
    };
    gptimer_register_event_callbacks(gptimer, &callbacks_structure, NULL);

    gptimer_enable(gptimer);
    gptimer_start(gptimer);
}

bool IRAM_ATTR TimerCallback (gptimer_handle_t timer, const gptimer_alarm_event_data_t *edata, void *user_ctx)
{
    flag_timer = 1 ;
    return 0 ;
}
