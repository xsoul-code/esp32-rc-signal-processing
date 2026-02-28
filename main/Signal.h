#pragma once 
#include <vector>

class Signal{
    public:
    virtual void acquire() = 0;
    std::vector<float> getSamples()
    {
        return samples;
    }
    protected:
        std::vector<float> samples;
};