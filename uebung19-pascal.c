/*
 * Pascalsches Dreieck
 * 
 * Sebastian Girke, PIA24
 * 2024-12-17
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	
	// Überprüfe, ob eine Zahl eingegeben wurde
	if (argc == 1) {
		fprintf(stderr, "%s: Bitte Anzahl von Zeilen eingeben!\n",
			argv[0]);
		exit(EXIT_FAILURE); // Programmende
	}
	
	// Einlesen und Validieren der Benutzereingabe
	int z = atoi(argv[1]);
	
	// Anzahl der Zeilen müssen größer als 0 sein
	if (z < 1) {
		fprintf(stderr, "%s: Bitte nur Zahlen größer als 0 eingeben!\n",
			argv[0]);
		exit(EXIT_FAILURE);
	}
	
	int pascal[z][z]; // Zweidimensionales Array (Pascalsches Dreieck)
	
	// Iteration über alle Zeilen
	for (int i = 0; i < z; i++) {
		
		// Iteration über alle Spalten
		for (int j = 0; j < z; j++) {
			
			pascal[i][j] = 0;
			
			if (j == 0) {
				// Werte in erster Spalte haben den Wert "1"
				pascal[i][j] = 1;
			} else if (i >= 1 && i >= j) {
				// Alle Werte ab Zeile 2 werden aus der Summe der
				// beiden darüberliegenden Werte gebildet
				pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
			}
			
			printf("%4d ", pascal[i][j]); // Formatierte Ausgabe
		}
		
		printf("\n"); // Zeilenumbruch
	}
	
	return EXIT_SUCCESS;
}
