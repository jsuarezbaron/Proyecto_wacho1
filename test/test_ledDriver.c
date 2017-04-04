#include "unity.h"
#include "ledDriver.h"

uint16_t address;

void setUp(){

}

void tearDown(){
	address=0;
}

/*void testDriverEncenderUnLed(*address)
{   
    //LedDriver_Create(&address);
    LedDriver_TurnOn(1);
    TEST_ASSERT_EQUAL_HEX16(1, address);
}*/

/*void testDriverApagarUnLed(uint16_t * address)
{
    LedDriver_TurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(0, address);
}*/

/* Test 5 Apagar todos los leds ??????*/
/* Test 1 Todos los leds deben estar apagados después de inicializar el driver */
void testDriver_LedsOffAfterCreate(){
	uint16_t virtualLeds2=0xFFFF;//Para el Test 1 se deja ya que pone los inicializa en 1
	LedDriver_Create(&virtualLeds2);//funcion que quiero testear
	TEST_ASSERT_EQUAL_HEX16(0,virtualLeds2);
}


void testDriver_TurnOnledUno(){
	uint16_t virtualLeds=0xFFFF;//Req 2,Req 5,Req 6 y Req 8.Para el Test 1 se deja ya que pone los inicializa en 1
	LedDriver_Create(&virtualLeds);//funcion que quiero testear
        LedDriver_TurnOn(1);//Req 7->"1" Encendido/ "0" Apagado
	TEST_ASSERT_EQUAL_HEX16(1,virtualLeds);
}

/*Test 2 Un led puede ser encendido individualmente*/
void testDriver_TurnOffledUno(){

	uint16_t virtualLeds1=0x0001;//Para el Test 1 se deja ya que pone los inicializa en 1
	LedDriver_Create(&virtualLeds1);//funcion que quiero testear
        LedDriver_TurnOff(1);//Req 7->"1" Encendido/ "0" Apagado
	TEST_ASSERT_EQUAL_HEX16(0,virtualLeds1);
}


/* Test 4 Múltiple leds pueden ser encendidos/apagados */
void testDriver_TurnOnMultipleLeds(){
	uint16_t virtualLedsX;
	LedDriver_TurnOn(9);
	LedDriver_TurnOn(8);
	TEST_ASSERT_EQUAL_HEX16(0x180, virtualLedsX);
}

/*********************************************************/
void testDriver_TurnOffMultipleLeds(){
	uint16_t virtualLedsA;
	LedDriver_TurnAllOn();
	LedDriver_TurnOff(9);
	LedDriver_TurnOff(8);
	TEST_ASSERT_EQUAL_HEX16((~0x180)&0xffff, virtualLedsA);
}
/************************************************************/
void TurnOffAnyLed(){
	uint16_t virtualLedsY;
	LedDriver_TurnOn(9);
	LedDriver_TurnOff(8);
	TEST_ASSERT_EQUAL_HEX16(0xff7f, virtualLedsY);
}

/* Encender todos los leds */

void testDriver_AllLedsOn(){
    uint16_t LEDSXYZaddress = 0xffff;
    LedDriver_TurnAllOn();
    //*address = 0xffff;
    LedDriver_Create(&LEDSXYZaddress);
    TEST_ASSERT_EQUAL_HEX16(0xffff, LEDSXYZaddress);
 
}

/* Apagar todos los leds */

void testDriver_AllLedsOff(){
    uint16_t LEDSXYZaddress2 = 0;
    LedDriver_TurnAllOn();
    //LedDriver_TurnAllOff();
    LedDriver_Create(&LEDSXYZaddress2);
    TEST_ASSERT_EQUAL_HEX16(0, LEDSXYZaddress2);
}

/* Test 7 Consulta del estado individual de un led* /


/* Test 8 Verificación de valores límites */

void testDriverValoresAltosyBajos(){
        uint16_t virtualLedsZ;
	LedDriver_TurnOn(1);
	LedDriver_TurnOn(16);
	TEST_ASSERT_EQUAL_HEX16(0x8001, virtualLedsZ);
}

/* Test 9 Verificación de valores fuera de límites */ 

void testDriverValoresFueradeLimites(){
	uint16_t virtualLedsW;
        //LedDriver_TurnAllOn();
	LedDriver_TurnOn(-1);
	//TEST_ASSERT_EQUAL_HEX16(0, virtualLedsW);
	LedDriver_TurnOn(0);
	//TEST_ASSERT_EQUAL_HEX16(0, virtualLedsW);
	LedDriver_TurnOn(17);
	//TEST_ASSERT_EQUAL_HEX16(0, virtualLedsW);
	LedDriver_TurnOn(3141);
	TEST_ASSERT_EQUAL_HEX16(0, virtualLedsW);
}


