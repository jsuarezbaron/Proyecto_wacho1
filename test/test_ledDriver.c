#include "unity.h"
#include "ledDriver.h"

uint16_t address;

void setUp(){

}
void tearDown(){
	address=0;

}

void testDriverCreateDebeApagarTodosLosLeds(){

	//address=0xFFFF;//Para el Test 1 se deja
	LedDriver_Create(&address);//funcion que quiero testear
	LedDriver_TurnOn(1);//Segundo test
	TEST_ASSERT_EQUAL_HEX16(1,address);

}
