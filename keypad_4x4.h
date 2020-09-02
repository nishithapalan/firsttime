//Header files

#include "stm32g0xx_hal.h"
#include <stdbool.h>

typedef struct
{
  GPIO_TypeDef* in0_Port;
	GPIO_TypeDef* in1_port;
	GPIO_TypeDef* in2_port;
	GPIO_TypeDef* in3_port;	
	GPIO_TypeDef* out0_port;	
	GPIO_TypeDef* out1_port;
	GPIO_TypeDef* out2_port;
	GPIO_TypeDef* out3_port;
	
	uint16_t	in0pin;
	uint16_t	in1pin;
	uint16_t	in2pin;
	uint16_t	in3pin;
	uint16_t	out0pin;
	uint16_t	out1pin;
	uint16_t	out2pin;
	uint16_t	out3pin;
}keypadwires_typedef;

//FUNCTIONS
//f1 setting keypad pins and ports
void Keypad_4x4_setting(keypadwires_typedef, *keypadwire_struct);

//f2 find pin position of the coloumn
void Keypad_4x4_findposition(void);

//f3 changing coloumn oin
void Keypad_4x4_changecol(uint8_t coloumn0_3);

//f4 reading the pin
void Keypad_4x4_readp(bool Keys[16]);

//f5 getting the key character
*char Keypad_4x4_getcr(uint8_t keySw0);
