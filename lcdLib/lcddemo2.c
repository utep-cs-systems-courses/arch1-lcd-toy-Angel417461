/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

void draw_christmas_tree(char offset_r, char offset_c){
  for(int r = 0; r< 40; r++){
    for (int c = 0; c <= r/2; c++){
      drawPixel(offset_c + c, offset_r + r, COLOR_GREEN);
      drawPixel(offset_c - c, offset_r + r, COLOR_GREEN);
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
  fillRectangle(0, 135, 400, 40, COLOR_WHITE);
  
}
      
/** Initializes everything, clears the screen, draws "hello" and a square */
int main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLUE);

  drawString5x7(15,20, "merry", COLOR_GREEN, COLOR_RED);
  drawString5x7(3,29, "christmas", COLOR_GREEN, COLOR_RED);

  //fillRectangle(30,30, 60, 60, COLOR_ORANGE);
  draw_christmas_tree(20,65);
  
  u_char offset_r = 50, offset_c = 50;
  for (int r = 0; r<=30; r++){
    for(int c = 0; c<=(15-r); c++){
      // drawPixel(offset_c + c, offset_r - r, COLOR_ORANGE);
      //drawPixel(offset_c - c, offset_r - r, COLOR_ORANGE);
      //drawPixel(c + offset_c, offset_r + r, COLOR_ORANGE);
      //drawPixel(offset_c - c, offset_r + r, COLOR_ORANGE);
      
    }
  }



  
}
