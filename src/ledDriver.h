/*

 * Se declara dos funciones
 */
#include <stdint.h>
#define TRUE 1
#define FALSE 0
//typedef int BOOL;

void LedDriver_Create(uint16_t *);
void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnOff(int ledNumber);
//void LedDriver_TurnAllOn(uint16_t *)
void LedDriver_TurnAllOn(void);
void LedDriver_Destroy(void);

