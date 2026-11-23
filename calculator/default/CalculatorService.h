#pragma once

#include <aidl/vendor/visteon/calculator/BnCalculatorService.h>

namespace aidl::vendor::visteon::calculator {

class CalculatorService : public BnCalculatorService {
public:
    ndk::ScopedAStatus add(
       int32_t a,
       int32_t b,
       int32_t* _aidl_return) override;
       
public:
    ndk::ScopedAStatus addFloat(
    float a,
    float b,
    float* _aidl_return) override;
};
} //namespace aidl::vendor::visteon::calculatorw
