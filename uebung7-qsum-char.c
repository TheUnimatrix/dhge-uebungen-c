/*
 * Berechnen der Quersumme aus einem String
 * (ohne Umwandlung in eine Zahl)
 * 
 * Sebastian Girke, PIA24
 * 2024-12-12
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	
	// Obligatorische Eingabe, ob eine Eingabe erfolgte
	if (argc == 1) {
		fprintf(stderr, "%s: Bitte eine Zahl eingeben!\n", argv[0]);
		return EXIT_FAILURE;
	}
	
	int i = 0; // Indexvariable
	int quer = 0;
	
	char c; // Zeichen zum Auslesen udn Auswerten
	
	// Lies übergebene Zahl aus und iteriere bis zum Ende
	while ((c = argv[1][i]) != '\0') {
		if (c >= '0' && c <= '9') {
			// Erklärung: '0' = 48 in ASCII, also ziehe 48 ab,
			// um auf den entsprechenden Zahlenwert zu kommen
			quer += c - 48;
		} else {
			fprintf(stderr, "%s: Die Zahl %s enthält ein ungültiges "
				"Zeichen '%c'\n", argv[0], argv[1], c);
			return EXIT_FAILURE; // Brich Programm und aktuelle Zahl ab
		}
		
		i++; // Erhöhe Zähler, um zum nächsten Zeichen zu springen
	}
	
	// Ausgabe
	printf("Die Quersumme von %s ist %d\n", argv[1], quer);
	
	return EXIT_SUCCESS; // Programmende
}

