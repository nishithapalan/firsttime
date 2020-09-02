//
#include "keypad_4x4.h"

//create library variables
static keypad_wires_typedef keypadStruct;

static unint8_t outpos[4];

static char *keypad_keys[16]=
{
  "1",
  "2",
  "3",
  "ENT",
  "4",
  "5",
  "6",
  "BSpa",
  "7",
  "8",
  "9",
  "0",
  "master_code1",
  "master_code2",
  "close_door1",
  "close_door2"
};

//function defn
//f1 setting pins and ports
void Keypad_4x4_setting(keypad_wires_typedef, *keypadwiringStruct)
{
 keypadStruct = *keypadwiringStruct;
 
 Keypad_4x4_findposition();
 keypadstruct.out0_port->OTYPER |= (1UL << outpos[0]);//sets as pushpull low or high
 keypadstruct.out1_port->OTYPER |= (1UL << outpos[1]);
 keypadstruct.out2_port->OTYPER |= (1UL << outpos[2]);
 keypadstruct.out3_port->OTYPER |= (1UL << outpos[3]);
 
 HAL_GPIO_WritePin(keypadStruct.out0_port, keypadStruct.out0pin, GPIO_PIN_SET);
 HAL_GPIO_WritePin(keypadStruct.out1_port, keypadStruct.out1pin, GPIO_PIN_SET);
 HAL_GPIO_WritePin(keypadStruct.out2_port, keypadStruct.out2pin, GPIO_PIN_SET);
 HAL_GPIO_WritePin(keypadStruct.out3_port, keypadStruct.out3pin, GPIO_PIN_SET);
 
 }
 
//f1 finding pin position
static void Keypad_4x4_findposition(void)
{
     uint8_t i=0;
     for(i=0;i<4;i++)
 {
      if(((keypadStruct.out0_pin >> i) &0x0001) == 0x0001)
       {
          outpos[0] = i;
       }
      if(((keypadStruct.out1_pin >> i) &0x0001) == 0x0001)
        {
          outpos[1] = i;
        }
       if(((keypadStruct.out2_pin >> i) &0x0001) == 0x0001)
        {
          outpos[2] = i;
         }
       if(((keypadStruct.out3_pin >> i) &0x0001) == 0x0001)
         {
           outpos[3] = i;
          }
 }
}

//f3 changing coloumn
static void Keypad_4x4_changecol(uint8_t coloumn0_3)
{
if(coloum0_3 == 0)
{
   KeypadStruct.out0_port -> OTYPER |= ~(1UL << outpos[0]);//sets the selected coloumn
   KeypadStruct.out1_port -> OTYPER &= (1UL << outpos[1]);
   KeypadStruct.out2_port -> OTYPER &= (1UL << outpos[2]);
   KeypadStruct.out3_port -> OTYPER &= (1UL << outpos[3]);
}
if(coloum0_3 == 1)
{
   KeypadStruct.out1_port -> OTYPER |= ~(1UL << outpos[1]);
   KeypadStruct.out0_port -> OTYPER &= (1UL << outpos[0]);
   KeypadStruct.out2_port -> OTYPER &= (1UL << outpos[2]);
   KeypadStruct.out3_port -> OTYPER &= (1UL << outpos[3]);
}
if(coloum0_3 == 2)
{
   KeypadStruct.out2_port -> OTYPER |= ~(1UL << outpos[2]);
   KeypadStruct.out0_port -> OTYPER &= (1UL << outpos[0]);
   KeypadStruct.out1_port -> OTYPER &= (1UL << outpos[1]);
   KeypadStruct.out3_port -> OTYPER &= (1UL << outpos[3]);
}
if(coloum0_3 == 3)
{
   KeypadStruct.out3_port -> OTYPER |= ~(1UL << outpos[3]);
   KeypadStruct.out0_port -> OTYPER &= (1UL << outpos[0]);
   KeypadStruct.out2_port -> OTYPER &= (1UL << outpos[1]);
   KeypadStruct.out2_port -> OTYPER &= (1UL << outpos[2]);
}
}

//f4 reading pin
void Keypad_4x4_readp(bool Keys[16])
{
//check rows by making each coloumn as high
Keypad_4x4_changecol(0);
keys[0] = HAL_GPIO_ReadPin(KeypadStruct.in0_port, KeypadStruct.in0pin);
keys[4] = HAL_GPIO_ReadPin(KeypadStruct.in1_port, KeypadStruck.in1pin);
keys[8] = HAL_GPIO_ReadPin(KeypadStruct.in2_port, KeypadStruck.in2pin);
keys[12] = HAL_GPIO_ReadPin(KeypadStruct.in3_port, KeypadStruck.in3pin);

Keypad_4x4_changecol(1);
keys[1] = HAL_GPIO_ReadPin(KeypadStruct.in0_port, KeypadStruct.in0pin);
keys[5] = HAL_GPIO_ReadPin(KeypadStruct.in1_port, KeypadStruct.in1pin);
keys[9] = HAL_GPIO_ReadPin(KeypadStruct.in2_port,KeypadStruct.in2pin);
keys[13] = HAL_GPIO_ReadPin(KeypadStruct.in3_port, KeypadStruct.in3pin);

Keypad_4x4_changecol(2);
keys[2] = HAL_GPIO_ReadPin(KeypadStructt.in0_port, KeypadStruct.in0pin);
keys[6] = HAL_GPIO_ReadPin(KeypadStructt.in1_port, KeypadStruct.in1pin);
keys[10] = HAL_GPIO_ReadPin(KeypadStruct.in2_port, KeypadStruct.in2pin);
keys[14] = HAL_GPIO_ReadPin(KeypadStruct.in3_port, KeypadStruct.in3pin);

Keypad_4x4_changecol(3);
keys[3] = HAL_GPIO_ReadPin(KeypadStruct.in0_port, KeypadStruct.in0pin);
keys[7] = HAL_GPIO_ReadPin(KeypadStruct.in1_port, KeypadStruct.in1pin);
keys[11] = HAL_GPIO_ReadPin(KeypadStructt.in2_port, KeypadStruct.in2pin);
keys[15] = HAL_GPIO_ReadPin(KeypadStruct.in3_port, KeypadStruct.in3pin);


}

//f5 getting char
char* Keypad_4x4_getcr(uint8_t keypadSw)
{
   return keypad_keys[keypadSw];
}








