#pragma once
#include "esp_log.h"
#include <vector>

#define TAG "ESP32 Signal Procesor"

class Logger
{
    public:
    void log(std::vector<float> result, const char* label)
    {
        for(int i = 0; i < result.size(); i++)
        {
            ESP_LOGI(TAG, "[%s] Sample[%d]: %f ", label, i+1, result[i]);
        }
    }

};