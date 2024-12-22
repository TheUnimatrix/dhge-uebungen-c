/*
 * Nagelbrett simulieren, Balkendiagramm anzeigen
 *
 * Sebastian Girke, PIA24
 * 2024-12-17
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {

    // Überprüfe auf korrekte Anzahl an Parametern
    if (argc != 3) {
        fprintf(stderr, "%s: Unkorrekte Anzahl an Parametern!\n",
                argv[0]);
        exit(EXIT_FAILURE); // Programmende
    }

    int r = atoi(argv[1]); // Reihen
    int k = atoi(argv[2]); // Kugeln

    // Überprüfe, ob r und k größer als 0 sind
    if (r <= 0 || k <= 0) {
        fprintf(stderr,
			"%s: Nur positive Zahlen größer als 0 erlaubt!\n", argv[0]);
        exit(EXIT_FAILURE); // Programmende
    }
    
    srand(time(NULL)); // Initialisiere Zufallszahlen
    int faecher[r + 1]; // Array für Fächer
    
    // Initialisiere alle Elemente im Array mit 0
    for (int i = 0; i < (r + 1); i++) {
		faecher[i] = 0;
	}
    
    // Wirf einzelne Kugeln
    for (int i = 0; i < k; i++) {
		
		int fach = 0; // Indexvariable für einzelnes Fach
		
		// Kugel fällt auf jede einzelne Reihe im Nagelbrett
		for (int j = 0; j < r; j++) {
			// Bestimme zufällig, ob Kugel nach links (0) oder
			// rechts (1) fällt
			fach += rand() % 2; // Generiere Zufallszahl (0 oder 1)
		}
		
		// Lasse Kugel in entsprechendes Fach fallen
		faecher[fach]++;
	}
	
	int max = -1; // maximale Anzahl an Kugeln
	
	// Bestimme das Fach mit den meisten Kugeln bzw. deren Anzahl
	for (int i = 0; i < (r + 1); i++) {
		if (max < faecher[i]) max = faecher[i];
	}
	
	// Berechne Faktor für Multiplikation (Ausgabe von '#')
	/* Erklärung:
	 *   --> 183 = max. Zeichenlänge meines Linux-Terminals
	 *   -->   8 = Ausgabe der Anzahl inkl. Trennstrich
	 *   --> max = max. Anzahl der Kugeln in einem Fach
	 */ 
	double faktor = (double)(183 - 8) / max;
	
	// Ausgabe als Balkendiagramm
	for (int i = 0; i < (r + 1); i++) {
		
		// Anzahl der Kugeln im Fach als Zahl
		printf("%5d | ", faecher[i]);
		
		// Bestimme Anzahl von '#' anhand des Faktors
		for (int j = 0; j < (faecher[i] * faktor); j++) {
			printf("#"); // Anzahl der Kugeln im Fach als Balken
		}
		
		printf("\n"); // Zeilenumbruch für nächsten Eintrag
	}

    return EXIT_SUCCESS; // Programmende
}
