#include "gpio.h"

int main(void)
{
    GPIO_ClockEnable(GPIO_D);
    
    GPIO_DeInit(GPIO_D);
  
    GPIO_Init(GPIO_D,MODE_OUTPUT,OPEN_DRAIN,2);
    GPIO_WriteBit(GPIO_D,2,1);
   
    GPIO_Init(GPIO_D,MODE_INPUT,OPEN_DRAIN,2); 
    unsigned  char read_input_pin = GPIO_ReadInputDataBit(GPIO_D,2);
    
    unsigned  short int read_input = GPIO_ReadInputData(GPIO_D);
    
    
   
    GPIO_Write(GPIO_D,12);
    
    while (1){}
 }
