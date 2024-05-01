#include "gpio.h"

void INVALID()
{
  while(1){
  }
  
  
  
};
void VALID()
{ 
  __asm("NOP")
    ;}

void GPIO_ClockEnable(unsigned int* gpio_x) {
__assert(__IS_GPIO_ALL_INSTANCE(gpio_x));
             if (gpio_x==GPIO_A) 
         *RCC_AHB1ENR|=1;
        else  if (gpio_x==GPIO_B) 
       *RCC_AHB1ENR |=1<<1;
         else  if (gpio_x==GPIO_C) 
             *RCC_AHB1ENR |=1<<2;
         else  if (gpio_x==GPIO_D) 
            *RCC_AHB1ENR |=1<<3;
         else if (gpio_x==GPIO_E) 
           *RCC_AHB1ENR|=1<<4;      
         else  if (gpio_x==GPIO_F) 
       *RCC_AHB1ENR |=1<<5;
         else  if (gpio_x==GPIO_G) 
             *RCC_AHB1ENR |=1<<6;
         else  if (gpio_x==GPIO_H) 
            *RCC_AHB1ENR |=1<<7;
         else if (gpio_x==GPIO_I) 
           *RCC_AHB1ENR|=1<<8; 
}


void GPIO_DeInit(unsigned int * gpio_x)
{__assert(__IS_GPIO_ALL_INSTANCE(gpio_x));

             if (gpio_x==GPIO_A) 
             { *RCC_AHB1RSTR|=1;
             *RCC_AHB1RSTR&=~1;}
        else  if (gpio_x==GPIO_B) 
        {*RCC_AHB1RSTR|=(1<<1);
        *RCC_AHB1RSTR&=~(1<<1);}
        else  if (gpio_x==GPIO_C) 
        {*RCC_AHB1RSTR|=(1<<2);
        *RCC_AHB1RSTR&=~(1<<2);}
        else  if (gpio_x==GPIO_D) 
        { *RCC_AHB1RSTR|=(1<<3);
        *RCC_AHB1RSTR&=~(1<<3);}
         else if (gpio_x==GPIO_E) 
         {*RCC_AHB1RSTR|=(1<<4);
         *RCC_AHB1RSTR&=~(1<<4);}
         else  if (gpio_x==GPIO_F) 
         {*RCC_AHB1RSTR|=(1<<5);
         *RCC_AHB1RSTR&=~(1<<5);}
         else  if (gpio_x==GPIO_G) 
         {*RCC_AHB1RSTR|=(1<<6);
         *RCC_AHB1RSTR&=~(1<<6);}
         else  if (gpio_x==GPIO_H) 
         {*RCC_AHB1RSTR|=(1<<7);
         *RCC_AHB1RSTR&=~(1<<7);}
         else if (gpio_x==GPIO_I) 
         {*RCC_AHB1RSTR|=(1<<8);
         *RCC_AHB1RSTR&=~(1<<8);}

}



void GPIO_Init(unsigned int * gpio_x, char Mode, char typeOutput, short int pin)
{__assert(__IS_GPIO_ALL_INSTANCE(gpio_x));
 __assert(__VALID_MODE(Mode));
 __assert(__VALID_TYPE_OUTPUT(typeOutput));
 __assert(__VALID_PIN(pin));
 
 if (Mode == MODE_INPUT)
 {*(gpio_x + OFFSET_MODER) &=~ (1<<(2*pin));
 *(gpio_x + OFFSET_MODER) &=~ (1<<(2*pin+1));}
 else if (Mode == MODE_OUTPUT)
 { *(gpio_x + OFFSET_MODER) |= (1<<(2*pin));
 *(gpio_x + OFFSET_MODER) &=~ (1<<(2*pin+1));}
 else if (Mode == MODE_ALTERNATE )
  { *(gpio_x + OFFSET_MODER) &=~ (1<<(2*pin));
 *(gpio_x + OFFSET_MODER) |= (1<<(2*pin+1));}  
  else if (Mode == MODE_ANALOG )
  { *(gpio_x + OFFSET_MODER) |= (1<<(2*pin));
 *(gpio_x + OFFSET_MODER) |= (1<<(2*pin+1));} 
  unsigned int* GPIO_OTYPER = (unsigned int*)((int) gpio_x + OFFSET_OTYPER);
 if (typeOutput == PUSH_PULL)
    *(GPIO_OTYPER) &=~ (1<<pin); 
     
 else if (typeOutput == OPEN_DRAIN) 
   *(GPIO_OTYPER) |= (1<<pin); 

 
 }
 

unsigned  char GPIO_ReadInputDataBit(unsigned int *  gpio_x, unsigned  short int GPIO_Pin)
{
__assert(__IS_GPIO_ALL_INSTANCE(gpio_x));
__assert(__VALID_PIN(GPIO_Pin));
 unsigned int* GPIO_IDR = (unsigned int*)((int) gpio_x + OFFSET_IDR);
 if ((* GPIO_IDR &= (1<<GPIO_Pin)) == 0x00)
return 0;
else return 1;
}

unsigned  short int GPIO_ReadInputData(unsigned int *  gpio_x)
{
__assert(__IS_GPIO_ALL_INSTANCE(gpio_x));
unsigned int* GPIO_IDR = (unsigned int*)((int) gpio_x + OFFSET_IDR);
return * GPIO_IDR;
}

void GPIO_WriteBit(unsigned int * gpio_x, unsigned  short int GPIO_Pin, char BitVal)
{
__assert(__IS_GPIO_ALL_INSTANCE(gpio_x));
__assert(__VALID_PIN(GPIO_Pin));
__assert(__VALID_VALUE(BitVal));
unsigned int* GPIO_BSRR = (unsigned int*)((int) gpio_x + OFFSET_BSRR);
if (BitVal == 0x00)
{* GPIO_BSRR |= (1<<(GPIO_Pin+16)) ;
* GPIO_BSRR &=~ (1<<GPIO_Pin) ;}
//* GPIO_BSRR &=~ (1<<(GPIO_Pin+16)) ;}
else {* GPIO_BSRR |= (1<<GPIO_Pin) ;
* GPIO_BSRR &=~ (1<<(GPIO_Pin+16)) ;}
//* GPIO_BSRR &=~ (1<<GPIO_Pin) ;}
}

void GPIO_Write(unsigned int * gpio_x, unsigned  short int PortVal)
{
__assert(__IS_GPIO_ALL_INSTANCE(gpio_x));
unsigned int* GPIO_ODR = (unsigned int*)((int) gpio_x + OFFSET_ODR);
* GPIO_ODR = PortVal;
}
