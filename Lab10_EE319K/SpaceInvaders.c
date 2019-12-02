// SpaceInvaders.c
// Runs on LM4F120/TM4C123
// Jonathan Valvano and Daniel Valvano
// This is a starter project for the EE319K Lab 10

// Last Modified: 9/2/2019 
// http://www.spaceinvaders.de/
// sounds at http://www.classicgaming.cc/classics/spaceinvaders/sounds.php
// http://www.classicgaming.cc/classics/spaceinvaders/playguide.php
/* This example accompanies the books
   "Embedded Systems: Real Time Interfacing to Arm Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2019

   "Embedded Systems: Introduction to Arm Cortex M Microcontrollers",
   ISBN: 978-1469998749, Jonathan Valvano, copyright (c) 2019

 Copyright 2019 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */
// ******* Possible Hardware I/O connections*******************
// Slide pot pin 1 connected to ground
// Slide pot pin 2 connected to PD2/AIN5
// Slide pot pin 3 connected to +3.3V 
// fire button connected to PE0
// special weapon fire button connected to PE1
// 8*R resistor DAC bit 0 on PB0 (least significant bit)
// 4*R resistor DAC bit 1 on PB1
// 2*R resistor DAC bit 2 on PB2
// 1*R resistor DAC bit 3 on PB3 (most significant bit)
// LED on PB4
// LED on PB5

// Backlight (pin 10) connected to +3.3 V
// MISO (pin 9) unconnected
// SCK (pin 8) connected to PA2 (SSI0Clk)
// MOSI (pin 7) connected to PA5 (SSI0Tx)
// TFT_CS (pin 6) connected to PA3 (SSI0Fss)
// CARD_CS (pin 5) unconnected
// Data/Command (pin 4) connected to PA6 (GPIO), high for data, low for command
// RESET (pin 3) connected to PA7 (GPIO)
// VCC (pin 2) connected to +3.3 V
// Gnd (pin 1) connected to ground

#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "ST7735.h"
#include "Random.h"
#include "PLL.h"
#include "ADC.h"
#include "Images.h"
#include "Sound.h"
#include "Timer0.h"
#include "Timer1.h"

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
void Delay100ms(uint32_t count); // time delay in 0.1 seconds


//-----List of Variables--------
uint32_t drawSemaphore = 0;  // Flag if sprites need to be drawn again (0 means screen does not need to be printed, 1 means it does)  
uint32_t gameStatus = 0; 		 // Flag to continue the game (0 means game is over, 1 means game is still running) 

uint32_t score=0; 					 // score of the player
uint32_t numlives=3;

uint32_t enemiesLeft = 18; 	 // how many enemies are left on the screen 

uint32_t playerLaserCnt = 0; // can only shoot one laser at a time
uint32_t enemyLaserCnt = 0;  // can only have five enemy lasers live at any time
uint32_t enemyFireRate = 0;  // rate at which enemies fire lasers should be randomized 

uint32_t xaxisCounter = 0;	 // tracks how pixels left/right enemies have moved
uint32_t downFlag = 0; 	 		 // flag for when enemies should move down 
uint32_t MoveFlag = 0; 			 // because the enemy ships would otherwise move so quickly, they will move every othertime the interrupt gets called by toggling this flag, allowing the enemy sprites to move
uint32_t speed=0;						 // used to determine the speed at which the enemies should move	

uint8_t i = 0;							 // for indexing
uint8_t k = 0;							 // for indexing

uint32_t gameOver=0; 				 //	flag to determine if game is over and game over screen should be printed
uint32_t English;						 // used to determine what language should be outputed
uint32_t state;							 // flag to determine to move on from menu screeen


//--------Buttons Initialization----------
//used to select language
//PC1 and PC2 (red button and blue button respectively) 
void PortC_Init(void){
	SYSCTL_RCGCGPIO_R |=  0x04;		// enable port C clock
	int32_t delay=SYSCTL_RCGCGPIO_R; //delay
	delay=SYSCTL_RCGCGPIO_R; 			// delay											
	GPIO_PORTC_DIR_R &= ~0x06;		// set PC1 - PC2 as  input
	GPIO_PORTC_AFSEL_R &= ~0x06;	// disable alternate function for PC1-PC2
	GPIO_PORTC_DEN_R |= 0x06;		// enable GPIO for PC1-PC2
}



//--------Menu Screen Functions-----------
//to be called in the main program but written out here
//LCD Output of Menu screen and language selection
void DrawMenuScreen(void){
	ST7735_FillScreen(0x0000);            
  ST7735_SetCursor(1, 2);
  ST7735_OutString("Space Invaders");
  ST7735_SetCursor(1, 4);
  ST7735_OutString("Select Your Language to Start");
  ST7735_SetCursor(1, 6);
  ST7735_OutString("Red Button For English");
	ST7735_SetCursor(1, 8);
	ST7735_OutString("Blue Button For Spanish");
}

void Menu (void) {
	while ((GPIO_PORTC_DATA_R&0x00000001)==0x00000001){
		if ((GPIO_PORTC_DATA_R&0x00000000)==0x00000000) {
			English = 1; 
			state = 1; 
		}
	}
	while ((GPIO_PORTC_DATA_R&0x00000002)==0x00000002) {
		if ((GPIO_PORTC_DATA_R&0x00000000)==0x00000000) {
			English = 0; 
			state =1; 
		}
	}
}



//--------Current Score----------
void UpdateScoreLives(uint32_t score, uint32_t numlives){
	ST7735_SetCursor(5, 0);
	if (English==1) {
		ST7735_OutString("Score:");
		LCD_OutDec(score);
		ST7735_SetCursor(50, 0);
		ST7735_OutString("Lives:");
		LCD_OutDec(numlives);
	}
	else {
		ST7735_OutString("Puntos:");
		LCD_OutDec(score);
		ST7735_SetCursor(50, 0);
		ST7735_OutString("Vidas:");
		LCD_OutDec(numlives);
	}
}



//---------Game Over-----------
void GameOver (void) {
	ST7735_FillScreen(0x0000);            // set screen to black
  ST7735_SetCursor(5, 1);
	if (English==1) {
		ST7735_OutString("Score:");
		LCD_OutDec(score);
		ST7735_SetCursor(5, 5);
		ST7735_OutString("GAME OVER");
		ST7735_SetCursor(5, 7);
		ST7735_OutString("Press RESET");
	}
	else {
		ST7735_OutString("Vidas:");
		LCD_OutDec(score);
		ST7735_SetCursor(4, 5);
		ST7735_OutString("FIN DEL JUEGO");
		ST7735_SetCursor(4, 7);
		ST7735_OutString("Pulse RESET");
	}
	while(1){								// infinite loop
	}
}



//---------SysTick_Init---------
void SysTick_Init (void) {
	DisableInterrupts();
	NVIC_ST_CTRL_R = 0;					// disable SysTick for init
	NVIC_ST_RELOAD_R = 2666667;	// 30 Hz ISR on 80MHz clock
	NVIC_ST_CURRENT_R = 0;			// clear CURRENT
	NVIC_ST_CTRL_R = 0x07;
	EnableInterrupts();
}
//handler found later in this file 

//----------Sprites-------------
//structure for all the playerShip, enemyShip, playerLaser, and enemyLaser sprites
typedef enum {dead, alive} status_t; 

//player ship sprite
struct playerSprite {
	int32_t xCoor; 
	int32_t yCoor; 
	const unsigned short *image; 
	uint32_t width; 
	uint32_t height;  
	status_t life; 
};
typedef struct playerSprite PlayerShip_t; 

//enemy ship sprite
struct enemySprite {
	int32_t xCoor; 
	int32_t yCoor; 
	int32_t vx, vy; //speed of enemy sprite moving left/right and down
	const unsigned short *image; 
	const unsigned short *black; 
	uint32_t width; 
	uint32_t height; 
	status_t life; 
	uint32_t needDraw; 
};
typedef struct enemySprite EnemyShip_t;

//laser sprite
struct laserSprite {
	int32_t xCoor; 
	int32_t yCoor; 
	int32_t vy; //speed of laser moving down
	const unsigned short *image; 
	const unsigned short *black; 
	uint32_t width; 
	uint32_t height; 
	status_t life; 
	uint32_t needDraw; 
};

//enemy laser sprite
typedef struct laserSprite enemyLaser_t; 

//player laser sprite
typedef struct laserSprite playerLaser_t; 

//definition of all sprites 
PlayerShip_t Player; 
EnemyShip_t Enemies[18];			// maximum # of enemies is 18 in 3 rows of 6
playerLaser_t PlayerLaser;	
enemyLaser_t EnemyLasers[18];		// # of enemy lasers, but maximum is still only 5



//-------EdgeTriggered_Init-----
//Edge triggered interrupt that occurs when PF4 is pressed
//PF4 is the button that 'shoots' a player laser 
void EdgeTriggered_Init(void){       
  SYSCTL_RCGCGPIO_R |= 0x00000020; // activate clock for port F
	int32_t delay=SYSCTL_RCGCGPIO_R; //delay
	delay=SYSCTL_RCGCGPIO_R; 			// delay
  GPIO_PORTF_DIR_R &= ~0x10;    // make PF4 input (built-in button)
  GPIO_PORTF_AFSEL_R &= ~0x10;  // disable alt funct on PF4
  GPIO_PORTF_DEN_R |= 0x10;     // enable digital I/O on PF4
  GPIO_PORTF_PCTL_R &= ~0x000F0000; //  configure PF4 as GPIO
  GPIO_PORTF_AMSEL_R &= ~0x10;  // disable analog functionality on PF4
  GPIO_PORTF_PUR_R |= 0x10;     // enable pull-up resistor on PF4
  GPIO_PORTF_IS_R &= ~0x10;     // PF4 is edge-sensitive
  GPIO_PORTF_IBE_R &= ~0x10;    // PF4 is not both edges
  GPIO_PORTF_IEV_R &= ~0x10;    // PF4 falling edge event
  GPIO_PORTF_ICR_R = 0x10;      // clear flag4
  GPIO_PORTF_IM_R |= 0x10;      // arm interrupt on PF
  NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00A00000; // priority 5
  NVIC_EN0_R = 0x40000000;      // enable interrupt 30 in NVIC
  EnableInterrupts();           // Enable global Interrupt flag (I)
}

void PlayerLaserFire(void){
	if(playerLaserCnt < 1){																			// does not exceed max # of player lasers
		PlayerLaser.xCoor = (Player.xCoor + 4);										// laser is 4 x 10, places laser at center of player ship
		PlayerLaser.yCoor = (Player.yCoor - 8);										// places laser at front of player ship
		PlayerLaser.image = userlaser;														// shoots player laser
		PlayerLaser.black = Black; 
		PlayerLaser.vy = speed;																		// speed that player laser moves at
		PlayerLaser.life = alive;																	// player laser is live
		PlayerLaser.needDraw=1;
		playerLaserCnt++;																					// increment count of player lasers
		Sound_Shoot();
	}
}

void GPIOPortF_Handler(void){
  GPIO_PORTF_ICR_R = 0x10;      // acknowledge flag4
	PlayerLaserFire(); 						// run subroutine when PF4 is pressed and unpressed (laser sprite printed and sound made) 
}

//------Other Functions---------
//Random Number Generator 
uint32_t RandomNumber(uint32_t number){
	Random_Init(NVIC_ST_CURRENT_R);
  return ((Random32() >> 24) % number);
}



//--------- Game_Init-----------
//initializes the positions of all the sprites
void Game_Init (void) {
	Player.xCoor = 57; 
	Player.yCoor = 159; 
	Player.image = usership;
	Player.width = 12;
	Player.height = 12; 
	Player.life =alive; 
	
	speed++; 
	
	i=0;
	for(i=0; i < 18; i++){														// initializes enemies
		Enemies[i].life = alive;										// enemy's status
		if(i < 6){																	// each row has 6 enemies, all of which are the same
			Enemies[i].xCoor = (16 * i) + 4;
			Enemies[i].yCoor = 20;			
			Enemies[i].vx=speed;
			Enemies[i].vy=speed; 
			Enemies[i].image = SmallEnemy30pointA;		
			Enemies[i].black = Black; 
			Enemies[i].width = 16;
			Enemies[i].height = 10; 
			Enemies[i].needDraw =1; 
		}
		else if(i < 12){														// second row of enemies 
			Enemies[i].xCoor = (16 * (i-6)) + 4;
			Enemies[i].yCoor = 30; 	
			Enemies[i].vx=speed+1;
			Enemies[i].vy=speed+1; 
			Enemies[i].image = SmallEnemy30pointB;		
			Enemies[i].black = Black; 
			Enemies[i].width = 16;
			Enemies[i].height = 10; 
			Enemies[i].needDraw =1; 
		}
		else{																				// third row of enemies
			Enemies[i].xCoor = (16 * (i - 12) + 4);
			Enemies[i].yCoor = 40; 								
			Enemies[i].vx=speed+1;
			Enemies[i].vy=speed+1; 
			Enemies[i].image = SmallEnemy30pointA;		
			Enemies[i].black = Black; 
			Enemies[i].width = 16;
			Enemies[i].height = 10; 
			Enemies[i].needDraw =1; 
		}
	}
								
		PlayerLaser.width = 4;									// initializes player laser
		PlayerLaser.height = 10; 
		PlayerLaser.life = dead; 								//no laser at the very beginning of the games
		PlayerLaser.needDraw = 0; 
		PlayerLaser.image= userlaser;
		PlayerLaser.black= Black;
		PlayerLaser.vy = speed; 

	
	i = 0;
	for(i=0; i < 18; i++){													// initializes enemy lasers
		EnemyLasers[i].width = 5;	
		EnemyLasers[i].height = 10; 
		EnemyLasers[i].life = dead; 								// no enemy lasers at the very beginning of the game
		EnemyLasers[i].needDraw = 0; 
		EnemyLasers[i].image= enemylaser;
		EnemyLasers[i].black= Black;										
	}

}



//---------SysTick_Handler----------
//Runs the entire ISR
void SysTick_Handler (void) {
	//Movement of player ship
	Player.xCoor=zakkysADCfunction();	//updates xCoor of ship
	
	//Movement of enemy ships
	if (MoveFlag==1) {
		if(xaxisCounter < (30/speed)){
			k=0;
				for(k=0; k < 18; k++){
					if (Enemies[k].life==alive){
						Enemies[k].xCoor += Enemies[k].vx;							// move every enemy right 1 pixel
						Enemies[k].needDraw=1; 
					}	
				}	
			xaxisCounter++;																				// increment counter
		}
	
		else if(xaxisCounter < (60/speed)){
			k=0;
				for(k=0; k < 18; k++){
					if (Enemies[k].life==alive) {
					Enemies[k].xCoor -= Enemies[k].vx;	// move every enemy right 1 pixel
					Enemies[k].needDraw=1; 	
					}
				}	
			xaxisCounter++;													// increment counter
		}
	
		else if(xaxisCounter == (60/speed)){
			xaxisCounter = 0;													// reset horizontal movement counter
			downFlag++;																// set vertical movement flag
		}
	
		if(downFlag == 1){
			downFlag = 0;															// reset vertical movement flag
			k=0;
				for(k=0; k < 18; k++){
					if (Enemies[k].life==alive){
						Enemies[k].yCoor += Enemies[k].vy;				// move every enemy down 1 pixel
						if (Enemies[k].yCoor>149) {
							Enemies[k].life = dead;
							enemiesLeft--;
							if(numlives>0){				
								numlives--;														// if player is alive, decrement health
								Sound_Hit();
								if(numlives == 0){			
									gameOver = 1; 											// game over flag
									Sound_GameOver();										// play explosion sound
								}
							}
						}
					Enemies[k].needDraw=1; 
					}
				}
		}
		MoveFlag=0;
	}
	else {
		MoveFlag=1;
	}
	
	//Movement of player laser
	if(PlayerLaser.life == alive){													// checks if each player laser is alive
		if(PlayerLaser.yCoor > 19){														// if laser has not reached top of screen
				PlayerLaser.yCoor -= PlayerLaser.vy;							// move player laser up screen by its speed
				PlayerLaser.needDraw=1;
			}
			else{
				PlayerLaser.life = dead;													//remove if player laser is not within bounds mentioned above
				playerLaserCnt--;
				PlayerLaser.needDraw=1;
			}
		}
	
	//Movement of enemy laser
	for(k=0;k<18; k++){																			// checks state of every enemy laser
		if(EnemyLasers[k].life == alive){											// if enemy laser is alive
			if((EnemyLasers[k].yCoor < 159) && (EnemyLasers[k].yCoor > 19)){									// checks if enemy laser has reached bottom of screen
				EnemyLasers[k].yCoor += EnemyLasers[k].vy;				// moves enemy laser down screen
				EnemyLasers[k].needDraw=1;
			}
			else{
				EnemyLasers[k].life = dead;											// removes enemy laser if it is not within the bounds identified above
				enemyLaserCnt--;																// decrease enemy laser count
				EnemyLasers[k].needDraw=1;
			}
		}
	}
	
	//Firing of enemy laser
	if(enemyFireRate > 0){						// random delay randomizes enemy firing scheme
		enemyFireRate--;								// decrement delay and return
		return;
	}
	
	else{
		int check;										 // new randomized Fire rate
		check = RandomNumber(60);			 // create new delay using a random number to randomize firing
		enemyFireRate = check;					
	}
	
	k = 0;													// index for aliens
	for(k=0; k < 18; k++){
		uint8_t fire = 0;						   // allows enemy to fire
		fire = RandomNumber(2); 			// boolean result decides if enemy fires
		if((Enemies[k].life==alive) && (enemyLaserCnt < 5) && (fire == 1)&& (EnemyLasers[k].life==dead)){	// fire if enemy is alive, there are less than max # of enemy lasers on screen, boolean allows fire, and laser is not already fired 
			EnemyLasers[k].xCoor = (Enemies[k].xCoor + (16 / 2));							// places laser at center of width of alien
			EnemyLasers[k].yCoor = Enemies[k].yCoor + 10;											// places laser at bottom of alien
			EnemyLasers[k].image = enemylaser;															// assigns sprite of alien laser
			EnemyLasers[k].vy = speed;																				// sets speed of laser
			EnemyLasers[k].life = alive;																				// enemy laser is live
			EnemyLasers[k].needDraw = 1; 
			enemyLaserCnt++;																							// increment laser count
			Sound_Shoot();
			return;
		}
	}

	//Enemy Laser and Player Collsion
	int k = 0;										// index for enemy lasers
		for(k=0;k < 18; k++){
			if((EnemyLasers[k].life == alive) && ((EnemyLasers[k].xCoor >= Player.xCoor)&&(EnemyLasers[k].xCoor < (Player.xCoor + 12))) && ((EnemyLasers[k].yCoor >= (Player.yCoor + 12)))){ // check if enemy laser is live, if enemy laser touches player ship in both x and y directions
				if(numlives>0){				
					numlives--;						// if player is alive, decrement health
					Sound_Hit();
					if(numlives == 0){			
						gameOver = 1; // game over flag
						Sound_GameOver();		// play explosion sound
					}
				}
				enemyLaserCnt--;				// decrement enemy laser count
				EnemyLasers[k].life = dead;	// kill enemy laser
			}
		}

	//Player Laser and Enemy Collision
	k = 0;															// enemy array index
	for(k=0; k < 18; k++){
		if(Enemies[k].life==alive){						// checks if enemy is alive
				if((PlayerLaser.life == alive) && ((PlayerLaser.xCoor >= Enemies[k].xCoor) && (PlayerLaser.xCoor < (Enemies[k].xCoor + 16))) &&((PlayerLaser.yCoor <= (Enemies[k].yCoor + 10)))){ // if player laser is live and touching enemy
					Enemies[k].life = dead;			// if enemy has just died, set recent death flag
					score += 10; 								// add point value of enemy to score
					enemiesLeft--;							// decrease number of alive enemies
					Sound_Hit();								// play enemy hit sound
					playerLaserCnt--;							// decrement player laser counter
					PlayerLaser.life = dead;				// player laser is dead		
				}	
			}
		}
	
}


//-------Main Function---------
int main(void){
  DisableInterrupts();
  PLL_Init(Bus80MHz);       		// Bus clock is 80 MHz 
  Random_Init(1);
	Sound_Init();
	ADC_Init();
	EdgeTriggered_Init();	
  Output_Init();
	PortC_Init();
  ST7735_FillScreen(0x0000);   	// set screen to black
  
	state = 0; 					//be used as a flag to move on from menu screen and start the game 

	DrawMenuScreen(); 
	while (state==0) {
		Menu();
	}

	while (1) {
		ST7735_FillScreen(0x0000);
		UpdateScoreLives(score, numlives);
		Game_Init();
		SysTick_Init();
		while (state) {
			if (enemiesLeft==0) {				//if there are no enemies left on screen, the game will reinitliaze (keeping the number of lives and score from the previous round) except it will run faster since speed is increased by 1 every time the Game Initilization function is called
				Game_Init();
			}
			if (gameOver==1) {					//checks if game is over,
				GameOver();
			}
			
			//Draw Player Sprite
			ST7735_DrawBitmap(Player.xCoor, Player.yCoor, Player.image, Player.width, Player.height);
			
			//Draw Enemy Sprites
			uint32_t i=0;
			for (i=0; i<18; i++){
				if(Enemies[i].needDraw){
					if(Enemies[i].life==alive){
					ST7735_DrawBitmap(Enemies[i].xCoor, Enemies[i].yCoor, Enemies[i].image, Enemies[i].width, Enemies[i].height);
					} else {
					ST7735_DrawBitmap(Enemies[i].xCoor, Enemies[i].yCoor, Enemies[i].black, Enemies[i].width, Enemies[i].height);
				}
				Enemies[i].needDraw=0;
				}
			}
			
			
			//Draw Player Laser
			if(PlayerLaser.needDraw){
				if(PlayerLaser.life==alive){
					ST7735_DrawBitmap(PlayerLaser.xCoor, PlayerLaser.yCoor, PlayerLaser.image, PlayerLaser.width, PlayerLaser.height);
				}
				else {
					ST7735_DrawBitmap(PlayerLaser.xCoor, PlayerLaser.yCoor, PlayerLaser.black, PlayerLaser.width, PlayerLaser.height);
				}
				PlayerLaser.needDraw=0;
			}
			
	
			//Draw Enemy Laser
			i=0;
			for (i=0; i<18; i++){
				if(EnemyLasers[i].needDraw){
					if(EnemyLasers[i].life==alive){
					ST7735_DrawBitmap(EnemyLasers[i].xCoor, EnemyLasers[i].yCoor, EnemyLasers[i].image, EnemyLasers[i].width, EnemyLasers[i].height);
					} 
					else {
					ST7735_DrawBitmap(EnemyLasers[i].xCoor, EnemyLasers[i].yCoor, EnemyLasers[i].black, EnemyLasers[i].width, EnemyLasers[i].height);
					}	
				EnemyLasers[i].needDraw=0;
				}
			}
		}
	}
}

