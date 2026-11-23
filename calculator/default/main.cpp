#include "CalculatorService.h"

#include <android/binder_manager.h>  //these provides AServiceManger_addService(), ABinderProcess_startThreadPool() ABinderProcess_joinThreadPool()
#include <android/binder_process.h>

using aidl::vendor::visteon::calculator::CalculatorService;

int main() {
   ABinderProcess_setThreadPoolMaxThreadCount(0);
   ABinderProcess_startThreadPool();
   
   //create service obj
   std::shared_ptr<CalculatorService> service = ndk::SharedRefBase::make<CalculatorService>(); 
   
   //Create instance name
   const std::string instance = std::string(CalculatorService::descriptor ) + "/default";
   
   //Register service
   binder_status_t status = AServiceManager_addService(
                            service->asBinder().get(),
                            instance.c_str());
                            
   if (status != STATUS_OK) {
        return EXIT_FAILURE;
   }
   
   ABinderProcess_joinThreadPool();
   
   return EXIT_FAILURE;
   
}