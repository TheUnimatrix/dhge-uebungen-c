/*
 * Lotto-Ziehung (Arrays, Zufallszahlen)
 * 
 * Sebastian Girke, PIA24
 * 2024-12-17
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ZAHLEN 49
#define KUGELN 6

int main(int argc, char **argv) {
	
	// Array für Lottoziehung
	bool lotto[ZAHLEN] = { false };
	
	srand(time(NULL)); // Initialisiere Zufallszahlen
	
	// Ziehe Zufallszahlen
	for (int i = 0; i < KUGELN;) {
		
		int zahl = rand() % ZAHLEN; // Zahl zw. 0 und 48
		
		// Überprüfe, ob Zahl bereits gezogen wurde
		if (!lotto[zahl]) {
			lotto[zahl] = true; // Zahl wurde gezogen
			i++;
		}
	}
	
	// Gib gezogene Zahlen aus
	for (int i = 0; i < ZAHLEN; i++) {
		
		// Überprüfe, ob aktuelle Zahl gezogen wurde
		if (lotto[i]) {
			printf("%d ", i + 1);
		}
	}
	
	printf("\n");
	
	return EXIT_SUCCESS; // Programmende
}
