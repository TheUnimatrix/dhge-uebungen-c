/*
 * Berechnung des ggT nach Euklid
 * (Erweiterung: Kürzen eines Bruchs)
 * 
 * Sebastian Girke, PIA24
 * 2024-12-12
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	
	// Überprüfe, dass zwei Zahlen eingegeben wurden
	if (argc != 3) {
		fprintf(stderr, "%s: Bitte zwei Zahlen eingeben!\n", argv[0]);
		return 1;
	}
	
	// Umwandeln der Zahlen, außerdem absoluten Betrag bilden
	int zaehler = atoi(argv[1]);
	int nenner = atoi(argv[2]);
	
	// Überprüfe auf Nenner = 0
	if (nenner == 0) {
		fprintf(stderr, "%s: Nenner darf nicht 0 sein!\n", argv[0]);
		return 1;
	}
	
	int a = abs(zaehler);
	int b = abs(nenner);
	
	// Berechnen des ggT
	while (b > 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	
	// Bedingung für Umwandeln der Ausgabe
	// Bedeutung: Minuszeichen soll in den Zähler
	if (nenner < 0) {
		zaehler = -zaehler;
		nenner = -nenner;
	}
	
	// Geschönte Ausgabe (Ganzzahlen immer ohne Nenner ausgeben)
	if (nenner / a == 1) {
		printf("Bruch %d/%d gekürzt = %d\n", zaehler, nenner,
			zaehler / a);
	} else {
		printf("Bruch %d/%d gekürzt = %d/%d\n", zaehler, nenner,
			zaehler / a, nenner / a);
	}
	
	return 0; // Programmende
}
