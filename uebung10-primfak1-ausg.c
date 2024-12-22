/*
 * Primfaktorzerlegung einer Zahl (Variante 1)
 * (hier: Ausgabe der Primfaktoren als Potenz)
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
		
	int divisor = 2;	// Initalwert für Divisor
	int loop;			// Exponent
	
	// Anfangsausgabe
	printf("Primfaktoren von %d =", zahl);
	
	// Führe Primfaktorzerlegung durch
	while (n > 1) {
		
		loop = 0; // Zurücksetzen des Exponenten
		
		// Solange n durch Divisor teilbar ist, ...
		while (n % divisor == 0) {
			// Restteilung ist möglich ==> erhöhe Exponent und behalte
			// den Divisor
			n /= divisor;
			loop++; // Exponent erhöhen
		}
		
		// Überprüfe, ob aktueller Exponent mindestens einmal
		// durchlaufen wurde
		if (loop == 1) {
			printf(" %d", divisor);
		} else if (loop > 1) {
			printf(" %d^%d", divisor, loop);
		}
		
		// keine Restteilung mit aktuellem Divisor möglich
		// ==> Divisor erhöhen
		divisor++;
	}
	
	printf("\n"); // Zeilenumbruch am Ende, damit Ausgabe hübsch ist
	
	return EXIT_SUCCESS; // Programmende
}
