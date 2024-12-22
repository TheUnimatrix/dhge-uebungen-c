/*
 * Berechnung des ggT nach Euklid
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
	int zahl1 = abs(atoi(argv[1]));
	int zahl2 = abs(atoi(argv[2]));
	
	int a = zahl1;
	int b = zahl2;
	
	// Berechnen des ggT
	while (b > 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	
	// Ausgabe
	printf("ggT von %d und %d = %d\n", zahl1, zahl2, a);
	
	return 0; // Programmende
}
