/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

short redrawScreen = 1;
u_int fontFgColor = COLOR_GREEN;

void draw_christmas_tree(char offset_r, char offset_c){
  for(int r = 0; r< 40; r++){
    for (int c = 0; c <= r/2; c++){
      drawPixel(offset_c + c, offset_r + r, COLOR_GREEN); //makes right half of the triangle
      drawPixel(offset_c - c, offset_r + r, COLOR_GREEN); //makes left half side of the triangle
    }
  }
  for(int r = 0; r< 50; r++){
    for (int c = 0; c <= r/2; c++){
      drawPixel(offset_c + c, offset_r + r+20, COLOR_GREEN);
      drawPixel(offset_c - c, offset_r + r+20, COLOR_GREEN);
    }
  }
  for(int r = 0; r< 60; r++){
    for (int c = 0; c <= r/2; c++){
      drawPixel(offset_c + c, offset_r + r+40, COLOR_GREEN);
      drawPixel(offset_c - c, offset_r + r+40, COLOR_GREEN);
    }
  }
  fillRectangle((offset_c-10), 120, 20, 15, COLOR_BROWN);
  fillRectangle(0, 135, 30, 40, COLOR_WHITE);
  
}

void wdt_c_handler()
{
  static int secCount = 0;

  secCount ++;
  if (secCount == 250) {		/* once/sec */
    secCount = 0;
    fontFgColor = (fontFgColor == COLOR_GREEN) ? COLOR_BLACK : COLOR_GREEN;
    redrawScreen = 1;
  }
}


      
/** Initializes everything, clears the screen, draws "hello" and a square */
int main()
{
 
  
  //P1DIR |= LED_GREEN;		/**< Green led on when CPU on */		
  //P1OUT |= LED_GREEN;
  configureClocks();
  lcd_init();
  
  enableWDTInterrupts();      /**< enable periodic interrupt */
  or_sr(0x8);	              /**< GIE (enable interrupts) */
  
  clearScreen(COLOR_BLUE);
  while (1) {			/* forever */
  if (redrawScreen) {
    redrawScreen = 0;
    drawString5x7(20,20, "hello", fontFgColor, COLOR_BLUE);
      drawString5x7(15,20, "merry", COLOR_GREEN, COLOR_RED);
    }
    //P1OUT &= ~LED_GREEN;	/* green off */
    or_sr(0x10);		/**< CPU OFF */
    //P1OUT |= LED_GREEN;		/* green on */
    }

  


  
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLUE);
  drawString11x16(1,10, "merry", COLOR_RED, COLOR_BLUE);
  drawString5x7(3,29, "christmas", COLOR_RED, COLOR_BLUE);
  drawString11x16(60,7, "~", COLOR_YELLOW, COLOR_BLUE);
  draw_christmas_tree(20,65);
  
  
}
