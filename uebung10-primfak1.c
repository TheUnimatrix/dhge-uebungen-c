/*
 * Primfaktorzerlegung einer Zahl (Variante 1)
 * 
 * Sebastian Girke, PIA24
 * 2024-12-12 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	
	// Überprüfe, ob eine Zahl eingegeben wurde
	if (argc == 1) {
		fprintf(stderr, "%s: Bitte geben Sie eine Zahl ein!\n", argv[0]);
		return EXIT_FAILURE;
	}
	
	// Einlesen der Zahl
	int zahl = abs(atoi(argv[1]));
	int n = zahl; // Initialwert für Schleife
	
	// Überprüfe, ob Zahl 0 oder 1 ist
	if (zahl == 0 || zahl == 1) {
		printf("Primfaktoren von %d = %d\n", zahl, zahl);
		return EXIT_SUCCESS; // Programmende
	}
		
	int divisor = 2; // Initalwert für Divisor
	
	// Anfangsausgabe
	printf("Primfaktoren von %d =", zahl);
	
	// Führe Primfaktorzerlegung durch
	while (n > 1) {
		
		// Solange n durch Divisor teilbar ist, ...
		while (n % divisor == 0) {
			// Restteilung ist möglich ==> gib aktuellen Primfaktor
			// aus und behalte den Divisor
			n /= divisor;
			printf(" %d", divisor);
		}
		
		// keine Restteilung mit aktuellem Divisor möglich
		// ==> Divisor erhöhen
		divisor++;
	}
	
	printf("\n"); // Zeilenumbruch am Ende, damit Ausgabe hübsch ist
	
	return EXIT_SUCCESS; // Programmende
}
