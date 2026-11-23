#include <aidl/vendor/visteon/calculator/ICalculatorService.h>

#include <android/binder_manager.h>
#include <android/binder_process.h>

#include <iostream>

using aidl::vendor::visteon::calculator::ICalculatorService;

int main() {
    const std::string instance =
        std::string(ICalculatorService::descriptor) + "/default";

    auto binder = AServiceManager_waitForService(instance.c_str());

    if (binder == nullptr) {
        std::cout << "Failed to get Calculator Service" << std::endl;
        return -1;
    }

    auto service =
        ICalculatorService::fromBinder(
            ndk::SpAIBinder(binder));

    if (service == nullptr) {
        std::cout << "Failed to create service proxy" << std::endl;
        return -1;
    }

    int32_t result = 0;

    ndk::ScopedAStatus status =
        service->add(10, 20, &result);

    if (!status.isOk()) {
        std::cout << "AIDL call failed" << std::endl;
        return -1;
    }

    std::cout << "10 + 20 = " << result << std::endl;

    return 0;
}
