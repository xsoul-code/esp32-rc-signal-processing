#pragma once
#include "esp_adc/adc_oneshot.h"

class RCSignal : public Signal{
    public:
        RCSignal(adc_oneshot_unit_handle_t adc_handle) 
        {
            this->adc_handle = adc_handle;
        }
    void acquire()
    {
        int raw_value;
        adc_oneshot_read(adc_handle, ADC_CHANNEL_6, &raw_value);
        samples.push_back((float)raw_value);
    }
    private:
        adc_oneshot_unit_handle_t adc_handle;
   
};