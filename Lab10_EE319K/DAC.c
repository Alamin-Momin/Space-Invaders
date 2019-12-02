// put implementations for functions, explain how it works
// Alamin Momin and Zakky Momin, 11/28/2019

#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"

// Code files contain the actual implemenation for public functions
// this file also contains an private functions and private data

// **************DAC_Init*********************
// Initialize 6-bit DAC, called once 
// Input: none
// Output: none
void DAC_Init(void){ 
	unsigned long volatile delay;
  SYSCTL_RCGCGPIO_R |= 0x02;     // activate port B
  delay = SYSCTL_RCGCGPIO_R;    // allow time to finish activating
  GPIO_PORTB_AMSEL_R &= ~0x03F;      // no analog 
  GPIO_PORTB_PCTL_R &= ~0x0000FFFF; // regular GPIO function
  GPIO_PORTB_DIR_R |= 0x03F;      // make PB5-0 out
  GPIO_PORTB_AFSEL_R &= ~0x003F;   // disable alt funct on PB5-0
  GPIO_PORTB_DEN_R |= 0x003F;      // enable digital I/O on PB5-0
}

// **************DAC_Out*********************
// output to DAC
// Input: 6-bit data, 0 to 63
// Input=n is converted to n*3.3V/63
// Output: none
void DAC_Out(uint32_t data){
  GPIO_PORTB_DATA_R = data;
}
