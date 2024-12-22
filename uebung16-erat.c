/*
 * Sieb des Eratosthenes
 * 
 * Sebastian Girke, PIA24
 * 2024-12-17
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_GRENZE 100000

int main(int argc, char **argv) {
	
	// Überprüfe, ob Eingabe erfolgt ist
	if (argc == 1) {
		fprintf(stderr, "%s: Bitte eine Grenze eingeben!\n", argv[0]);
		exit(EXIT_FAILURE); // Programmende
	}
	
	int n = atoi(argv[1]); // Grenzwert
	
	// Überprüfe, dass Grenze größer oder gleich 2 ist
	if (n < 2) {
		fprintf(stderr, "%s: Grenze kleiner als 2 ist nicht erlaubt!\n",
			argv[0]);
		exit(EXIT_FAILURE); // Programmende
	}
	
	// Überprüfe, ob Grenze kleiner als der erlaubten Höchstgrenze ist
	if (n > MAX_GRENZE) {
		fprintf(stderr, "%s: Eingegebene Grenze '%d' ist größer als "
			"die erlaubte Grenze '%d'\n", argv[0], n, MAX_GRENZE);
		exit(EXIT_FAILURE); // Programmende
	}
	
	// Array für Primzahlen anlegen
	bool prim[n + 1];
	
	prim[0] = false;
	prim[1] = false;
	
	// Alle Elemente mit "true" belegen
	// (Annahme: alle Zahlen sind Primzahlen)
	for (int i = 2; i <= n; i++) {
		prim[i] = true;
	}
	
	// Algorithmus für Sieb des Eratosthenes
	for (int i = 2; i <= n; i++) {
		
		// Überprüfe, ob die aktuelle Zahl eine Primzahl ist
		// Wenn ja, dann streiche alle Vielfachen dieser Zahl
		if (prim[i]) {
			
			// Ausgabe, weil aktuelle Zahl eine Primzahl ist
			printf("%d ", i);
			
			// Startwert "i + i" schneller berechnet als "2 * i"
			for (int j = i + i; j <= n; j += i) {
				prim[j] = false;
			}
		}
	}
	
	printf("\n"); // Leerzeile für bessere Übersicht
	
	return EXIT_SUCCESS; // Programmende
}
