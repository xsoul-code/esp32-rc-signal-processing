#pragma once
#include <numeric>
#include <vector>

class Filter
{
    public:
    Filter(int windowSize)
    {
        this -> windowSize = windowSize;
    }
    std::vector<float> process(std::vector<float> samples)
    {
        for(int i = windowSize; i < samples.size(); i++)
        {
            float sum = std::accumulate(samples.begin() + (i - windowSize), samples.begin() + i, 0.0f);
            float average = sum / windowSize;
            result.push_back(average);
        }
        return result;
    }
    private:
        std::vector<float> result;
        int windowSize = 5;
};