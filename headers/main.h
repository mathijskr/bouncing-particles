#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "termbox.h"

#include "constants.h"

/* Draw a rectangle of size widht, heigth with that has color color and fill it with symbol symbol. */
void drawRectangle(int width, int maxWidth, int height, int maxHeight, int backColor, char symbol, int symbolColor);

/* Draw characters from a char array of length length at position x, y on the screen.
 * Color specifies the text color, backColor specifies the color of the background behind the characters*/
void drawString(char *string, int color, int length, int x, int y, int backColor);

#endif
