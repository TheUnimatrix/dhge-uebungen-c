/*
 * Berechnen der Summe sowie des Mittelwerts beliebiger Zahlen
 * 
 * Autor: Sebastian Girke, PIA24
 * Datum: 2024-12-11
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {
	
	// Überprüfe, ob mind. eine Zahl eingegeben wurde
	if (argc == 1) {
		printf("%s: Bitte geben Sie mind. eine Zahl ein!\n", argv[0]);
		return 1;
	}
	
	// Berechnen der Summe aus allen eingegebenen Zahlen
	double summe = 0;
	
	for (int i = 1; i < argc; i++) {
		summe += atof(argv[i]);
	}
	
	// Berechnen des Mittelwerts
	double mittelwert = summe / (argc - 1);
	
	// Ausgabe der Summe und des Mittelwerts
	printf("Die Summe lautet: %f\n", summe);
	printf("Der Mittelwert lautet: %f\n", mittelwert);
	
	return 0; // Programmende
}
