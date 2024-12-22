/*
 * Auswerten von Minimum und Maximum
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
	
	// Iteriere über alle Eingaben
	for (int i = 1; i < argc; i++) {
		
		int current = atoi(argv[i]); // Aktuelle Zahl
		
		// Überprüfe, ob neues Minimum oder Maximum
		if (min > current) min = current;
		if (max < current) max = current;
	}
	
	// Ausgabe
	printf("Minimum: %d\n", min);
	printf("Maximum: %d\n", max);
	
	return EXIT_SUCCESS; // Programmende
}

