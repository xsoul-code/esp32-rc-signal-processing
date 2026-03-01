#include <iostream>
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "Signal.h"
#include "RCSignal.h"
#include "Filter.h"
#include "Logger.h"
#include "driver/gpio.h"

#define PWM GPIO_NUM_26

//Null pointers for reference in app_main
RCSignal* rc1 = nullptr;
Filter* f = nullptr;
Logger* logger = nullptr;

extern "C" void PWM_Handler(void *pvParameters)
{
    while(1) 
    {
        gpio_set_level(PWM, 1);
        vTaskDelay(pdMS_TO_TICKS(1000));
        gpio_set_level(PWM, 0);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

extern "C" void Data_Handler(void *pvParameters)
{
    while(1)
    {
        for(int i = 0; i < 20; i++) {
            rc1->acquire();
            vTaskDelay(pdMS_TO_TICKS(10));
        }
        
        auto filtered = f->process(rc1->getSamples());

        logger->log(filtered);
        rc1->clearSamples();
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}


extern "C" void app_main(void)
{
    gpio_config_t PWM_Config = {
    .pin_bit_mask = (1ULL << PWM),
    .mode = GPIO_MODE_OUTPUT,
    .pull_up_en = GPIO_PULLUP_DISABLE,
    .pull_down_en = GPIO_PULLDOWN_ENABLE,
    .intr_type = GPIO_INTR_DISABLE
    };
	gpio_config(&PWM_Config);

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
    //ADC_CHANNEL_4 coresponds to GPIO32 on ESP32-DevKitC
    adc_oneshot_config_channel(adc_handle, ADC_CHANNEL_4, &chan_config);

    rc1 = new RCSignal(adc_handle);
    f = new Filter(15);
    logger = new Logger();

    xTaskCreate(PWM_Handler, "PWM_Handler", 2048, NULL, 5, NULL);
    xTaskCreate(Data_Handler, "Data_Handler", 8192, NULL, 5, NULL);
    
}