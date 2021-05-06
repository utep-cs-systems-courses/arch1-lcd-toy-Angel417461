/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

short redrawScreen = 1;
u_int fontFgColor = COLOR_YELLOW;

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
  fillRectangle(0, 135, 128, 40, COLOR_WHITE);
  
}

void wdt_c_handler(){
  
  static int secCount = 0;

  secCount++;
  
  if (secCount == 25) {		/* once/sec */
    secCount = 0;
    
    if (fontFgColor == COLOR_YELLOW){
      fontFgColor = COLOR_RED;
    }else{
      fontFgColor = COLOR_YELLOW;
    } 
    redrawScreen = 1;
  }

}

void animation(){
  
  if (redrawScreen) {
    redrawScreen = 0;
    static char state = 0;
    switch(state){
    case 0:
      drawString11x16(60,7, "~", COLOR_YELLOW, COLOR_BLUE);
      state++;
      break;
    case 1:
      drawString11x16(60,7, "~", COLOR_BLUE, COLOR_BLUE);
      drawString11x16(60,5, "~", COLOR_RED, COLOR_BLUE);
      state++;
      break;
    case 2:
      drawString11x16(60,5, "~", COLOR_BLUE, COLOR_BLUE);
      drawString11x16(60,3, "~", COLOR_YELLOW, COLOR_BLUE);
      state++;
      break;
    case 3:
      drawString11x16(60,3, "~", COLOR_BLUE, COLOR_BLUE);
      drawString11x16(60,5, "~", COLOR_RED, COLOR_BLUE);
      state++;
      break;
    default: state = 0;
    }
  }
}
  

int main(){
 
  configureClocks();
  lcd_init();
  
  enableWDTInterrupts();      /**< enable periodic interrupt */
  or_sr(0x8);	              /**< GIE (enable interrupts) */

  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLUE);
  drawString11x16(1,10, "merry", COLOR_WHITE, COLOR_BLUE);
  drawString5x7(3,29, "christmas", COLOR_WHITE, COLOR_BLUE);
  draw_christmas_tree(20,65);

  
  while (1) {    /* forever */
    animation();
    or_sr(0x10);		/**< CPU OFF */
  }
}
