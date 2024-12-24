/*
 * Arrays (Sortieren, einfügen und löschen von Zahlen)
 * 
 * Sebastian Girke, PIA24
 * 2024-12-24
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

/** Methode zum Hinzufügen eines neuen Wertes in ein Array */
void addValueToArray(int *array, int value, int anz) {
	
	// Überprüfe aktuelle Anzahl des Arrays
	if (anz == 0) {
		array[0] = value;
	} else {
		// Suche nach der Stelle, wo das Element eingefügt werden kann
		for (int i = 0; i < anz; ++i) {
			if (array[i] > value || i == anz) array[i] = value;
		}
	}
}

int main() {
	
	int zahlen[MAX_SIZE]; // Array
	int anz = 0; // Anzahl gespeicherter Zahlen
	
	int input = 0;
	
	// Ausgabe einer Anleitung
	printf("Anleitung / Hinweise\n"
		" -> Eingabe einer positiven Zahl fügt diese dem Array hinzu\n"
		" -> Eingabe einer negativen Zahl löscht diese aus dem Array\n"
		" -> Wird die Zahl nicht gefunden, erscheint eine Fehlermeldung\n"
		" -> Eingabe der Zahl 0 beendet das Programm\n\n");
	
	// Schleife für Programmablauf
	while (1) {
		printf(">> ");
		scanf("%d", &input); // Einlesen einer Zahl
		
		fflush(stdin); // Löschen des Eingabepuffers
		
		// Verarbeiten der Eingabe
		if (input == 0) {
			break; // Schleifenabbruch, weil 0 eingegeben wurde
		}
		
		// Überprüfe, ob die maximale Größe des Arrays erreicht wurde
		if (anz == MAX_SIZE) {
			printf("Maximalgröße des Arrays (%d) erreicht! Es können "
				"keine weiteren Zahlen hinzugefügt werden. Bitte erst "
				"eine Zahl löschen!\n", MAX_SIZE);
			continue; // Fortfahren der Schleife
		}
		
		// Wenn eingegebene Zahl größer als 0 ist, dann füge diese hinzu
		if (input > 0) {
			addValueToArray(zahlen, input, anz++);
		}
		// Wenn eingegebene Zahl kleiner als 0 ist, dann lösche diese
		else if (input < 0) {
			int del = abs(input); // der zu löschende Wert
		}
		
		// Ausgabe des Arrays
		printf("Array: ");
		for (int i = 0; i < anz; ++i) {
			printf("%d ", zahlen[i]);
		}
		
		printf("\n\n"); // Leerzeile
	}
	
	return EXIT_SUCCESS; // Programmende
}



void delValueFromArray(int array[], int value) {
}
