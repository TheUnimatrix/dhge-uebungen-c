/*
 * Berechnung einer wiederholten Quersumme
 * 
 * Sebastian Girke, PIA24
 * 2024-12-12
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	
	// Überprüfe, ob Zahl eingegeben wurde
	if (argc == 1) {
		fprintf(stderr, "%s: Bitte Zahl eingeben!\n", argv[0]);
		return 1;
	}
	
	// Zahl einlesen und in absoluten Betrag umwandeln
	int zahl = atoi(argv[1]);
	zahl = (zahl < 0) ? abs(zahl) : zahl;
	
	int quer = 0;
	int temp = zahl;
	
	// Berechnen der wiederholten Quersumme
	while (temp > 9) {
		quer = 0;
		
		while (temp > 0) {
			quer += temp % 10;
			temp /= 10;
		}
		
		temp = quer;
	}
	
	// Ausgabe
	printf("Wiederholte Quersumme von %d = %d\n", zahl, quer);
	
	return 0;
}

