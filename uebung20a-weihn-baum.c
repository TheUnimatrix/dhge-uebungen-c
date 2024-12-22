/*
 * Zeichnen eines Weihnachtsbaums
 * 
 * Sebastian Girke, PIA24
 * 2024-12-17
 */

#include <stdio.h>
#include <stdlib.h>
#include "sdlinterf.h"

#define CENTER_X 400
#define RAD_Y 30

int main(int argc, char **argv) {
	
	// Zeichnen der Baum-Ellipsen
	sdlDrawCirc(CENTER_X, 40, CENTER_X / 2, RAD_Y, 0, 255, 0);
	sdlUpdate();
	
	
	return EXIT_SUCCESS;
}
