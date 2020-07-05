/**
 * Used for sending signals to plugs. Included in telegram.h and main.cpp
 */
#include "transmitter.h"


RCSwitch mySwitch = RCSwitch();
extern std::map<String, std::map<String, int>> codes = {};

/**
 * initial transmitter setup. Called in main::setup() once.
 * */
void setupSwitch()
{
    mySwitch.enableTransmit(12);    // Transmitter is connected to esp32 Pin #12
    mySwitch.setPulseLength(175);   // We need to set pulse length as it's different from default
    
    codes["1401"]["1ON"] = 1398067;
    codes["1401"]["1OFF"] = 1398076;
    codes["1401"]["2ON"] = 1398211;
    codes["1401"]["2OFF"] = 1398220;
    codes["1401"]["3ON"] = 1398531;
    codes["1401"]["3OFF"] = 1398540;

    codes["1402"]["1ON"] = 4543795;
    codes["1402"]["1OFF"] = 4543804;
    codes["1402"]["2ON"] = 4543939;
    codes["1402"]["2OFF"] = 4543948;
    codes["1402"]["3ON"] = 4544259;
    codes["1402"]["3OFF"] = 4544268;

    codes["1403"]["1ON"] = 349491;
    codes["1403"]["1OFF"] = 349500;
    codes["1403"]["2ON"] = 349635;
    codes["1403"]["2OFF"] = 349644;
    codes["1403"]["3ON"] = 349955;
    codes["1403"]["3OFF"] = 349964;

    codes["1404"]["1ON"] = 5330227;
    codes["1404"]["1OFF"] = 5330236;
    codes["1404"]["2ON"] = 5330371;
    codes["1404"]["2OFF"] = 5330380;
    codes["1404"]["3ON"] = 5330691;
    codes["1404"]["3OFF"] = 5330700;

    codes["1405"]["1ON"] = 1135923;
    codes["1405"]["1OFF"] = 1135932;
    codes["1405"]["2ON"] = 1136067;
    codes["1405"]["2OFF"] = 1136076;
    codes["1405"]["3ON"] = 1136387;
    codes["1405"]["3OFF"] = 1136396;

    codes["1406"]["1ON"] = 4281651;
    codes["1406"]["1OFF"] = 4281660;
    codes["1406"]["2ON"] = 4281795;
    codes["1406"]["2OFF"] = 4281804;
    codes["1406"]["3ON"] = 4282115;
    codes["1406"]["3OFF"] = 4282124;

    codes["1407"]["1ON"] = 87347;
    codes["1407"]["1OFF"] = 87356;
    codes["1407"]["2ON"] = 87491;
    codes["1407"]["2OFF"] = 87500;
    codes["1407"]["3ON"] = 87811;
    codes["1407"]["3OFF"] = 87820;

    codes["1408"]["1ON"] = 5526835;
    codes["1408"]["1OFF"] = 5526844;
    codes["1408"]["2ON"] = 5526979;
    codes["1408"]["2OFF"] = 5526988;
    codes["1408"]["3ON"] = 5527299;
    codes["1408"]["3OFF"] = 5527308;
}


/**
 * methods for toggling plugs using mySwitch. Will not function properly if setupSwitch() is 
 * not called beforehand.
 * */
bool toggleSwitch(String socketName, String socketStatus){
  int code = codes[socketName][socketStatus];
  if (code == 0)
    return false;
  else{
    mySwitch.send(code, 24);
    return true;
  }
}

//1401 2 and 1408 3 switches
void toggleOurs(bool turnOn){
  String toggle = "OFF";
  if(turnOn) toggle = "ON";
  
  int code = codes["1401"]["2" + toggle];
  mySwitch.send(code, 24);
  
  code = codes["1408"]["3" + toggle];
  mySwitch.send(code, 24);

}

void plug2On()
{
  mySwitch.send(1398211, 24);
}

void plug2Off()
{
  mySwitch.send(1398220, 24);      
}

void plug3On()
{
  mySwitch.send(5527299, 24);
}

void plug3Off()
{
  mySwitch.send(5527308, 24);
}
//end of toggling plug methods
