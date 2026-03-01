#pragma once
#include "esp_log.h"
#include <vector>

#define TAG "ESP32 Signal Procesor"

class Logger
{
    public:
    void log(std::vector<float> result)
    {
        for(int i = 0; i < result.size(); i++)
        {
            ESP_LOGI(TAG, " Sample[%d]: %f ", i, result[i]);
        }
    }

};