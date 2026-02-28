#include <iostream>
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "Signal.h"
#include "RCSignal.h"

extern "C" void app_main(void)
{
    adc_oneshot_unit_handle_t adc_handle;
    adc_oneshot_unit_init_cfg_t init_config = {
        .unit_id = ADC_UNIT_1,
        .clk_src = ADC_RTC_CLK_SRC_DEFAULT,
        .ulp_mode = ADC_ULP_MODE_DISABLE,
    };
    adc_oneshot_new_unit(&init_config, &adc_handle);

    adc_oneshot_chan_cfg_t chan_config = {
        .atten = ADC_ATTEN_DB_12,
        .bitwidth = ADC_BITWIDTH_12,
    };
    //ADC_CHANNEL_6 coresponds to GPIO34 on ESP32-DevKitC
    adc_oneshot_config_channel(adc_handle, ADC_CHANNEL_6, &chan_config);

    RCSignal rc1;
    rc1.acquire();
    std::cout << rc1.getSamples()[0] << std::endl;
    
}