#include "ledDriver.h"
#include "unity.h"


uint16_t address;



void setUp(){



}



void tearDown(){

 address=0;

}

void testDriver_LedsOffAfterCreate(){

 uint16_t virtualLeds2=0xFFFF;

 LedDriver_Create(&virtualLeds2);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((virtualLeds2)), (((void *)0)), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_HEX16);

}





void testDriver_TurnOnledUno(){

 uint16_t virtualLeds=0xFFFF;

 LedDriver_Create(&virtualLeds);

        LedDriver_TurnOn(1);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((virtualLeds)), (((void *)0)), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_HEX16);

}





void testDriver_TurnOffledUno(){



 uint16_t virtualLeds1=0x0001;

 LedDriver_Create(&virtualLeds1);

        LedDriver_TurnOff(1);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((virtualLeds1)), (((void *)0)), (UNITY_UINT)(49), UNITY_DISPLAY_STYLE_HEX16);

}







void testDriver_TurnOnMultipleLeds(){

 uint16_t virtualLedsX;

 LedDriver_TurnOn(9);

 LedDriver_TurnOn(8);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x180)), (UNITY_INT)(UNITY_INT16)((virtualLedsX)), (((void *)0)), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_HEX16);

}





void testDriver_TurnOffMultipleLeds(){

 uint16_t virtualLedsA;

 LedDriver_TurnAllOn();

 LedDriver_TurnOff(9);

 LedDriver_TurnOff(8);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(((~0x180)&0xffff)), (UNITY_INT)(UNITY_INT16)((virtualLedsA)), (((void *)0)), (UNITY_UINT)(67), UNITY_DISPLAY_STYLE_HEX16);

}



void TurnOffAnyLed(){

 uint16_t virtualLedsY;

 LedDriver_TurnOn(9);

 LedDriver_TurnOff(8);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xff7f)), (UNITY_INT)(UNITY_INT16)((virtualLedsY)), (((void *)0)), (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_HEX16);

}







void testDriver_AllLedsOn(){

    uint16_t LEDSXYZaddress = 0xffff;

    LedDriver_TurnAllOn();



    LedDriver_Create(&LEDSXYZaddress);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xffff)), (UNITY_INT)(UNITY_INT16)((LEDSXYZaddress)), (((void *)0)), (UNITY_UINT)(84), UNITY_DISPLAY_STYLE_HEX16);



}







void testDriver_AllLedsOff(){

    uint16_t LEDSXYZaddress2 = 0;

    LedDriver_TurnAllOn();



    LedDriver_Create(&LEDSXYZaddress2);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((LEDSXYZaddress2)), (((void *)0)), (UNITY_UINT)(95), UNITY_DISPLAY_STYLE_HEX16);

}













void testDriverValoresAltosyBajos(){

        uint16_t virtualLedsZ;

 LedDriver_TurnOn(1);

 LedDriver_TurnOn(16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x8001)), (UNITY_INT)(UNITY_INT16)((virtualLedsZ)), (((void *)0)), (UNITY_UINT)(107), UNITY_DISPLAY_STYLE_HEX16);

}







void testDriverValoresFueradeLimites(){

 uint16_t virtualLedsW;



 LedDriver_TurnOn(-1);



 LedDriver_TurnOn(0);



 LedDriver_TurnOn(17);



 LedDriver_TurnOn(3141);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((virtualLedsW)), (((void *)0)), (UNITY_UINT)(122), UNITY_DISPLAY_STYLE_HEX16);

}
