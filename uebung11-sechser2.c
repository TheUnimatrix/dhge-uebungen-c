/*
 * Würfeln
 * 
 * Sebastian Girke, PIA24
 * 2024-12-13
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define DURCHLAEUFE 100000

int main(int argc, char **argv) {
	
	int wuerfe[DURCHLAEUFE];
	
	int anzahlSechser = 0;
	int anzahl = 0;
	
	int min = INT_MAX;
	int max = INT_MIN;
	
	// notwendig, damit jedes mal neue Zufallszahlen generiert werden
	srand(time(NULL));
	
	// Zusatzaufgabe: Führe 100.000 Durchgänge durch
	for (int i = 0; i < DURCHLAEUFE; i++) {
		
		// Zurücksetzen wesentlicher Variablen
		anzahl = 0;
		anzahlSechser = 0;
		
		// Solange noch keine zwei Sechser in Folge gewürfelt wurden...
		while (anzahlSechser < 2) {
		
			// Würfel eine Zahl von 1 bis 6
			int wurf = rand() % 6 + 1;
			
			anzahl++; // Zähle die Anzahl des aktuellen Durchlaufs
			
			// Überprüfe, ob 6 gewürfelt wurde
			if (wurf == 6) {
				anzahlSechser++;
			} else { // Setze Variable zurück
				anzahlSechser = 0;
			}
		}
		
		// Vergleiche aktuelle Werte für Minimum und Maximum
		if (min > anzahl) min = anzahl;
		if (max < anzahl) max = anzahl;
		
		// Speichere die aktuelle Anzahl an Würfen
		wuerfe[i] = anzahl;
	}
	
	// Berechne durchschnittliche Anzahl an Würfen
	double gesamt = 0;
	
	for (int i = 0; i < DURCHLAEUFE; i++) {
		gesamt += wuerfe[i];
	}
	
	// Ausgabe
	printf("Minimum Würfe: %d\n", min);
	printf("Maximum Würfe: %d\n", max);
	printf("Durchschnitt Würfe: %g\n", (gesamt / DURCHLAEUFE));
	
	return EXIT_SUCCESS; // Programmende
}
