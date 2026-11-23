aidl

structure 

vendor/visteon/system/
└── calculator/
    │
    ├── aidl/
    │   │
    │   ├── Android.bp
    │   │
    │   └── vendor/
    │       └── visteon/
    │           └── calculator/
    │               └── ICalculatorService.aidl
    │
    ├── default/
    │   │
    │   ├── Android.bp
    │   ├── main.cpp                  //we need to register the service here by adding service
    │   ├── CalculatorService.h
    │   └── CalculatorService.cpp
    │
    └── testapp/
        │
        ├── Android.bp
        └── calculator_test_app_main.cpp                  //get service here 
		


Note : here while writing the aidl file in vendor/visteon/calculator/ICalculatorService.aidl
package name should be same as folder name 
and interface name should be same as file name 


stability: "vintf"
    = "Track and protect my API"

update-api
    = "Notice my changes"

freeze-api
    = "Create a new official version"
	
flow 
1. Create .aidl
2. Create aidl/Android.bp
3. after this do update 
4. m vendor.visteon.calculator-update-api -j1
5. once update done it will create the aidl_api with current folder inside the aidl folder 
6. then do freeze
7. m vendor.visteon.calculator-freeze-api -j1
8. after freeze it will cretae the version folder inside 
7. Implement service (default/)
8. Build service
9. Test client


when u add new api in source aidl file 
1. Modify AIDL
2. update-api
3. Implement generated method in .h/.cpp
4. freeze-api
5. update the lib with current version v1 v2 
6. Build
