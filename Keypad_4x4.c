//
#include "keypad_4x4.h"

//create library variables
keypadwires_typedef keypadstruct;

unint8_t outpositions[4];

char keypad_keys[16]=
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
void Keypad_4x4_setting(keypadwires_typedef, *keypadwire_struct)
{
 keypadstruct = *keypad_struct;
 
 Keypad_4x4_findposition();
 keypadstruct.out0_port - > OTYPER |= (1UL << outpos[0]);//sets as pushpull low or high
 keypadstruct.out1_port - > OTYPER |= (1UL << outpos[1]);
 keypadstruct.out2_port - > OTYPER |= (1UL << outpos[2]);
 keypadstruct.out3_port - > OTYPER |= (1UL << outpos[3]);
 
 HAL_GPIO_WritePin(keypadstruct.out0_port, keypadstruct.out0_pin, GPIO_PIN_SET);
 HAL_GPIO_WritePin(keypadstruct.out1_port, keypadstruct.out1_pin, GPIO_PIN_SET);
 HAL_GPIO_WritePin(keypadstruct.out2_port, keypadstruct.out2_pin, GPIO_PIN_SET);
 HAL_GPIO_WritePin(keypadstruct.out3_port, keypadstruct.out3_pin, GPIO_PIN_SET);
 
 }
 
//f1 finding pin position
void Keypad_4x4_findposition(void)
{
uint8_t i=0;
for(i=0;i<4;i++)
 {
   if(((keypadstruct.out0_pin >> i) &0x0001) == 0x0001)
    {
     outpos[0] = i;
    }
   if(((keypadstruct.out1_pin >> i) &0x0001) == 0x0001)
    {
     outpos[1] = i;
    }
    if(((keypadstruct.out2_pin >> i) &0x0001) == 0x0001)
    {
     outpos[2] = i;
    }
    if(((keypadstruct.out3_pin >> i) &0x0001) == 0x0001)
    {
     outpos[3] = i;
     }
 }
}

//f3 changing coloumn
void Keypad_4x4_changecol(uint8_t coloumn0_3)
{
if(coloum0_3 == 0)
{
keypadstruct.out0_port - > OTYPER |= ~(1UL << outpos[0]);//sets the selected coloumn
keypadstruct.out1_port - > OTYPER &= (1UL << outpos[1]);
keypadstruct.out2_port - > OTYPER &= (1UL << outpos[2]);
keypadstruct.out3_port - > OTYPER &= (1UL << outpos[3]);
}
if(coloum0_3 == 1)
{
keypadstruct.out1_port - > OTYPER |= ~(1UL << outpos[1]);
keypadstruct.out0_port - > OTYPER &= (1UL << outpos[0]);
keypadstruct.out2_port - > OTYPER &= (1UL << outpos[2]);
keypadstruct.out3_port - > OTYPER &= (1UL << outpos[3]);
}
if(coloum0_3 == 2)
{
keypadstruct.out2_port - > OTYPER |= ~(1UL << outpos[2]);
keypadstruct.out0_port - > OTYPER &= (1UL << outpos[0]);
keypadstruct.out1_port - > OTYPER &= (1UL << outpos[1]);
keypadstruct.out3_port - > OTYPER &= (1UL << outpos[3]);
}
if(coloum0_3 == 3)
{
keypadstruct.out3_port - > OTYPER |= ~(1UL << outpos[3]);
keypadstruct.out0_port - > OTYPER &= (1UL << outpos[0]);
keypadstruct.out2_port - > OTYPER &= (1UL << outpos[1]);
keypadstruct.out2_port - > OTYPER &= (1UL << outpos[2]);
}
}

//f4 reading pin
void Keypad_4x4_readp(bool Keys[16])
{
//check rows by making each coloumn as high
Keypad_4x4_changecol(0);
keys[0]=HAL_GPIO_ReadPin(keypadstruct.in0_port, keypad.in0_pin);
keys[4]=HAL_GPIO_ReadPin(keypadstruct.in1_port, keypad.in1_pin);
keys[8]=HAL_GPIO_ReadPin(keypadstruct.in2_port, keypad.in2_pin);
keys[12]=HAL_GPIO_ReadPin(keypadstruct.in3_port, keypad.in3_pin);

Keypad_4x4_changecol(1);
keys[1]=HAL_GPIO_ReadPin(keypadstruct.in0_port, keypad.in0_pin);
keys[5]=HAL_GPIO_ReadPin(keypadstruct.in1_port, keypad.in1_pin);
keys[9]=HAL_GPIO_ReadPin(keypadstruct.in2_port, keypad.in2_pin);
keys[13]=HAL_GPIO_ReadPin(keypadstruct.in3_port, keypad.in3_pin);

Keypad_4x4_changecol(2);
keys[2]=HAL_GPIO_ReadPin(keypadstruct.in0_port, keypad.in0_pin);
keys[6]=HAL_GPIO_ReadPin(keypadstruct.in1_port, keypad.in1_pin);
keys[10]=HAL_GPIO_ReadPin(keypadstruct.in2_port, keypad.in2_pin);
keys[14]=HAL_GPIO_ReadPin(keypadstruct.in3_port, keypad.in3_pin);

Keypad_4x4_changecol(3);
keys[3]=HAL_GPIO_ReadPin(keypadstruct.in0_port, keypad.in0_pin);
keys[7]=HAL_GPIO_ReadPin(keypadstruct.in1_port, keypad.in1_pin);
keys[11]=HAL_GPIO_ReadPin(keypadstruct.in2_port, keypad.in2_pin);
keys[15]=HAL_GPIO_ReadPin(keypadstruct.in3_port, keypad.in3_pin);


}

//f5 getting char
*char Keypad_4x4_getcr(uint8_t keySw)
{
return keypad_keys[keySw];
}








