/*
 * Noten zählen
 * 
 * Sebastian Girke, PIA24
 * 2024-12-16
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	
	// Überprüfe, ob Noten eingegeben wurden
	if (argc == 1) {
		fprintf(stderr, "%s: Bitte verschiedene Noten eingeben!\n",
			argv[0]);
		exit(EXIT_FAILURE); // Programmende
	}
	
	int noten[5] = { 0 }; // Array für Noten; Initialwert = 0
	
	// Lies alle Noten von der Befehlszeile ein
	for (int i = 1; i < argc; i++) {
		
		int note = atoi(argv[i]);
		
		// Überprüfe, ob Note zwischen 1 und 5 liegt
		if (note < 1 || note > 5) {
			fprintf(stderr, "%s: Aktuelle Note '%d' liegt nicht im "
				"erlaubten Bereich von 1 bis 5!\n", argv[0], note);
			exit(EXIT_FAILURE); // Programmende
		}
		
		noten[note - 1]++; // Erhöhe Zähler für aktuelle Note
	}
	
	// Ausgabe
	for (int i = 0; i < 5; i++) {
		printf("Note %d: %d\n", i + 1, noten[i]);
	}
	
	return EXIT_SUCCESS; // Programmende
}

