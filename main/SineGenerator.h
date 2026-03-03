#pragma once
#include "Signal.h"
#include <cmath>

class SineGenerator : public Signal
{
    public:
        SineGenerator(double amp,double freq,float Ts)
        {
            this -> amp = amp;
            this -> freq = freq;
            this -> Ts = Ts;
        }
        void acquire()
        {
            float raw_value = amp*sin(2*M_PI*freq*n*Ts);
            samples.push_back((float)raw_value);
            n++;
        }
    private:
        double amp = 230*sqrt(2); // Amplitude of sine wave
        double freq = 50;         // Frequency [Hz]
        int n = 0;                    // Number of sample
        float Ts = 0.01;          // The period of sample
};
