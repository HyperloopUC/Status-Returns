
#include "Arduino.h"
#include "Status/DeviceStatus.h"
#include "Comms/SerialConsole.h"

SuIdManager suIdManager;
SerialConsole serialConsole;
DeviceStatus overallStatus;

void setup(){
    overallStatus.Initialize(SuId_SuIdCount);
    suIdManager = SuIdManager();
    serialConsole.Initialize(&suIdManager);
}

void loop(){
    overallStatus = serialConsole.Print("Hello world");
    if(overallStatus.IsError()){
        serialConsole.Print("Error");
        //NOTE: This wouldn't print because the serial port would fail 
    }
}