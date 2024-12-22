/*
 * Berechnen des Dezimalwerts einer hexadezimalen Zahl
 * 
 * Sebastian Girke, PIA24
 * 2024-12-12
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv) {
	
	// Überprüfe, ob hexadezimale Zahl eingegeben wurde
	if (argc == 1) {
		fprintf(stderr,
			"%s: Bitte mind. eine hexadezimale Zahl eingeben!\n",
			argv[0]);
		return EXIT_FAILURE;
	}
	
	// Iteriere über alle Eingaben
	// (d.h. einzelne Eingaben sowie jedes Zeichen)
	for (int i = 1; i < argc; i++) {
		// Hinweis
		printf("Berechne Eingabe '%s'\n", argv[i]);
		
		int dezimal = 0; // Dezimalzahl einer hexadezimalen Zahl
		int length = (int)strlen(argv[i]); // Länge des Strings
		
		bool valid = true; // Variable, ob hexadezimale Zahl valide ist
		
		for (int j = 0; j < length; j++) {
			// Lies aktuelles Zeichen aus
			char c = argv[i][j];
			
			/* 
			 * Exponent (16 hoch n) entspricht Länge des Strings
			 * minus des aktuellen Index (Bsp.: äußerst linke Stelle
			 * der Zahl hat den höchsten Exponent, äußerst rechte Stelle
			 * der Zahl hat den Exponent 0)
			 */
			int exponent = length - j - 1;
			
			// Überprüfe aktuelles Zeichen
			if (c >= '0' && c <= '9') {
				// Erklärung: '0' = 48 in ASCII, also ziehe 48 ab,
				// um auf den entsprechenden Zahlenwert zu kommen
				dezimal += (c - 48) * pow(16, exponent);
			} else if (c >= 'A' && c <= 'F') {
				// Erklärung: 'A' = 65 in ASCII, also ziehe 55 ab,
				// um auf den entsprechenden Zahlenwert zu kommen
				dezimal += (c - 55) * pow(16, exponent);
			} else if (c >= 'a' && c <= 'f') {
				// Erklärung: 'a' = 97 in ASCII, also ziehe 87 ab,
				// um auf den entsprechenden Zahlenwert zu kommen
				dezimal += (c - 87) * pow(16, exponent);
			} else {
				fprintf(stderr, "%s: Die Zahl %s enthält ein "
					"nicht-hexadezimales Zeichen '%c'\n", argv[0],
					argv[i], c);
				valid = false;
				break; // Brich aktuelle Zahl ab
			}
		}
		
		// Ausgabe
		if (valid) printf("0x%s = %d\n", argv[i], dezimal);
	}
	
	return EXIT_SUCCESS;
}
