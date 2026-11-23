#include "CalculatorService.h"

namespace aidl::vendor::visteon::calculator {

ndk::ScopedAStatus CalculatorService::add(
  int32_t a,
  int32_t b,
  int32_t* _aidl_return) {
  
  *_aidl_return = a+b;
  
  return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus CalculatorService::addFloat(
  float a,
  float b,
  float* _aidl_return) {
  
  *_aidl_return = a+b;
  
  return ndk::ScopedAStatus::ok();
}

}//namespace aidl::vendor::visteon::calculator
