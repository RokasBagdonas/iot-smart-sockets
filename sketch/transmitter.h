#ifndef TRANSMITOR
#define TRANSMITOR

#include <RCSwitch.h>             // 433 MHz remote switching
#include <map>

void setupSwitch();
void plug2On();
void plug2Off();
void plug3On();
void plug3Off();
bool toggleSwitch(String, String);
void toggleOurs(bool);

#endif
