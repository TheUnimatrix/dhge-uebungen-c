/*
 * Wurzelrechnung
 * 
 * Sebastian Girke, PIA24
 * 2024-12-12
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
	
	// Überprüfe, ob Benutzer eine Eingabe getätigt hat
	if (argc != 2)  {
		fprintf(stderr, "%s: Bitte eine Zahl eingeben!\n", argv[0]);
		return 1;
	}
	
	// Umwandeln der Zahl
	double zahl = atof(argv[1]);
	
	// Überprüfe, ob die Zahl negativ ist
	if (zahl < 0) {
		fprintf(stderr, "%s: Nur positive Zahlen oder 0 sind erlaubt!\n",
			argv[0]);
	}
	
	// Berechnen der Wurzel
	double wurzel = zahl;
	
	int steps = 0; // Schrittzähler
	
	while (fabs(wurzel * wurzel - zahl) >= zahl * pow(10, -11)) {
		double mittel = (wurzel + zahl / wurzel) / 2;
		wurzel = mittel;
		steps++;
		printf("Aktueller Näherungswert: %.15g\n", wurzel);
	}
	
	// Ausgabe
	printf("Wurzel von %g = %.15g\n", zahl, wurzel);
	printf("Zum Vergleich: sqrt(%g) = %.15g\n", zahl, sqrt(zahl));
	printf("Anzahl der Schritte: %d\n", steps);
	
	return 0;
}
