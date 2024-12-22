/*
 * Auswerten von Minimum und Maximum inkl. Ausgabe der Position
 * 
 * Sebastian Girke, PIA24
 * 2024-12-12
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char **argv) {
	
	// Überprüfe, ob Eingabe erfolgte
	if (argc == 1) {
		fprintf(stderr, "%s: Bitte mind. eine Zahl eingeben!\n", argv[0]);
		return EXIT_FAILURE;
	}
	
	// Initialwerte für Minimum und Maximum
	int min = INT_MAX;
	int max = INT_MIN;
	
	// Initialwerte der jeweiligen Positionen
	int minPos = 0;
	int maxPos = 0;
	
	// Iteriere über alle Eingaben
	for (int i = 1; i < argc; i++) {
		
		int current = atoi(argv[i]); // Aktuelle Zahl
		
		// Überprüfe, ob neues Minimum
		if (min > current) {
			min = current;
			minPos = i;
		}
		
		// Überprüfe, ob neues Maximum
		if (max < current) {
			max = current;
			maxPos = i;
		}
	}	
	
	if (min == max) { // Ausgabe (falls alle Werte gleich)
		printf("Alle Werte sind gleich: %d\n", min);
	} else { // Ausgabe, wenn unterschiedliche Werte eingegeben wurden
		printf("Minimum: %d, Zahl Nummer %d\n", min, minPos);
		printf("Maximum: %d, Zahl Nummer %d\n", max, maxPos);
	}
	
	return EXIT_SUCCESS; // Programmende
}
