#ifndef CONFIG_H
#define CONFIG_H

#define TemperatureSensorPin      2
#define ButtonPlusPin             5
#define ButtonMinusPin            6
#define ButtonOkPin               7
#define ButtonCancelPin           8

#define ThermostatMainPageID 0
#define ThermostatSettingsPageID 1
#define ThermostatDebugPageID 2

#define FirstRow 0
#define SecondRow 1
#define CursorStart0 0

#define ButtonLongPressTime_ms 3000

#define configBlockResTickPeriod 6
#define Task10msPeriod 10
#define Task100msPeriod 100
#define Task1000msPeriod 1000


extern int initApp;

#endif