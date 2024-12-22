/*
 * Noten zählen (als Punkte)
 * 
 * Sebastian Girke, PIA24
 * 2024-12-16
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
	
	// Überprüfe, ob Punkte eingegeben wurden
	if (argc == 1) {
		fprintf(stderr, "%s: Bitte verschiedene Punkte eingeben!\n",
			argv[0]);
		exit(EXIT_FAILURE); // Programmende
	}
	
	int noten[5] = { 0 }; // Array für Noten; Initialwert = 0
	double gesamtPkt = 0; // Summe aller Punkte
	
	// Lies alle Punkte von der Befehlszeile ein
	for (int i = 1; i < argc; i++) {
		
		int punkte = atoi(argv[i]);
		int note = 0;
		
		// Überprüfe, ob aktuelle Punkte zwischen 0 und 100 liegen
		if (punkte < 0 || punkte > 100) {
			fprintf(stderr, "%s: Aktuelle Punkte '%d' liegen nicht im "
				"erlaubten Bereich von 0 bis 100!\n", argv[0], punkte);
			exit(EXIT_FAILURE); // Programmende
		}
		
		// Berechne Note aus den aktuellen Punkten
		if (punkte < 50) {
			noten[4]++; // Weniger als 50% = Note 5
		} else {
			note = lround(40 - 3 * ((punkte - 50) / 5.0));
			note = lround(note / 10.0 - 0.1);
			
			noten[note - 1]++; // Erhöhe Zähler für aktuelle Note
		}
		
		gesamtPkt += punkte; // Zähle Gesamtpunkte zusammen
	}
	
	int max = -1;
	
	// Bestimme Höchstanzahl einer bestimmten Note
	for (int i = 0; i < 5; i++)
		max = (max < noten[i]) ? noten[i] : max;
		
	/* Balkendiagramm (waagerecht) */
	/*
	 * Berechnung des Faktors:
	 *  - 184 = max. Zeichen meines Linux-Terminals
	 *  -  23 = Ausgabe für "Note X: 1234 => 100.00%"
	 *  -   3 = Ausgabe für Trennstrich inkl. Leerzeichen
	 *  - max = Höchstanzahl einer bestimmten Note
	 */
	double faktor = (184.0 - 23.0 - 3.0) / max;
	
	// Ausgabe
	for (int i = 0; i < 5; i++) {
		printf("Note %d: %4d => %6.2f%% | ", i + 1, noten[i],
			noten[i] * 100.0 / (argc - 1));
		
		// Ausgabe des Balkens mit '#'
		for (int j = 0; j < (faktor * noten[i]); j++) {
			printf("#");
		}
		
		// Zeilenumbruch für nächste Ausgabe
		printf("\n");
	}
	
	printf("\n"); // Leerzeile als Abstandshalter
	
	/* Balkendiagramm (senkrecht) */
	/*
	 * Neuberechnung des Faktors:
	 *  -  45 = max. Zeilen des Terminals
	 *  -   2 = Ausgabe der Note und einer Trennzeile
	 *  - max = Höchstanzahl einer bestimmten Note (s. oben)
	 */
	faktor = (45.0 - 2.0) / max;
	
	// Ausgabe (Iteriere über alle Zeilen des Terminals)
	for (int i = (faktor * max); i > 0; i--) {
		
		// Iteriere über alle Noten
		for (int j = 0; j < 5; j++) {
			
			// Gib '#' aus, wenn das Balkendiagramm geschrieben wird
			if (i <= noten[j] * faktor) {
				printf("         #      ");
			} else {
				printf("                ");
			}
		}
		
		printf("\n"); // Zeilenumbruch für Ausgabe in nächster Zeile
	}
	
	// Ausgabe der Achsenbeschriftung
	for (int i = 0; i < 16 * 5 + 1; i++) printf("-");
	printf("\n| ");
	
	for (int i = 0; i < 5; i++) {
		printf("Note %d = %4d | ", i + 1, noten[i]);
	}
	
	printf("\n\n"); // Leerzeilen als Abstandshalter
	
	// Ausgabe Mittelwert
	printf("Mittelwert: %g\n", gesamtPkt / (argc - 1));
	
	return EXIT_SUCCESS; // Programmende
}
