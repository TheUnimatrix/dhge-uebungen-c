/*
 * Geschachtelte Schleifen (rechtwinklige Dreiecke)
 * 
 * Sebastian Girke, PIA24
 * 2024-12-15
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
	
	// Überprüfe, ob Eingabe erfolgte
	if (argc == 1) {
		fprintf(stderr, "%s: Bitte Ganzzahl als Länge eingeben!\n",
			argv[0]);
		return EXIT_FAILURE; // Programmende
	}
	
	// Länge des Seils einlesen
	int laenge = atoi(argv[1]);
	
	// Überprüfe, ob Seil eine Länge größer als 0 hat
	if (laenge <= 0) {
		fprintf(stderr, "%s: Länge muss mindestens 1 betragen!\n",
			argv[0]);
		return EXIT_FAILURE; // Programmende
	}
	
	int anz = 0; // Anzahl der Kombinationen mit dem Seil
	
	// Iteriere bis zum max. Umfang des Dreiecks (d.h. Länge des Seils)
	for (int u = 1; u <= laenge; u++) {
		
		// Iteriere über alle möglichen Werte der ersten Seite
		for (int a = 1; a <= (u / 2); a++) {
			
			// Iteriere über alle möglichen Werte der zweiten Seite
			for (int b = a; b <= (u / 2); b++) {
				
				// Berechne dritte Seite
				int c = u - a - b;
				
				// Überprüfe, ob Dreieck rechtwinklig ist
				if (c == sqrt(pow(a, 2) + pow(b, 2))) {
					
					// Ausgabe der aktuellen Werte
					printf("a = %d, b = %d, c = %d, u = %d\n",
						a, b, c, u);
					anz++;
				}
			}
		} 
	}
	
	// Ausgabe der Anzahl gefundener Kombinationen
	printf("Anzahl d. Kombinationen: %d\n", anz);
	
	return EXIT_SUCCESS; // Programmende
}

