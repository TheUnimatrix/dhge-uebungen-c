/*
 * Arrays (Sortieren, einfügen und löschen von Zahlen)
 * 
 * Sebastian Girke, PIA24
 * 2024-12-24
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

/** Methode zum Hinzufügen eines neuen Wertes in ein Array */
void addValueToArray(int *array, int value, int *anz) {
	
	// Überprüfe aktuelle Anzahl des Arrays
	if (*anz == 0) {
		array[0] = value;
	} else {
		
		int pos = -1; // Position, an der Element eingefügt werden kann
		
		// Suche nach der Position, wo das Element eingefügt werden kann
		for (int i = 0; i <= *anz; ++i) {
			if (array[i] > value || i == *anz) {
				pos = i;
				break;
			}
		}
		
		// Überprüfe, ob das neue Element an die letzte Position soll
		if (pos == *anz) {
			array[pos] = value;
		} else {
		
			// Verschiebe alle Elemente nach rechts,
			// um Wert hinzuzufügen
			for (int i = *anz; i > pos; --i) {
				array[i] = array[i - 1];
			}
			
			array[pos] = value;
		}
	}
	
	++(*anz);
}

/** Methode zum Löschen eines Wertes aus einem Array */
bool delValueFromArray(int *array, int value, int *anz) {
	
	int pos = -1;
	
	// Suche das zu löschende Element
	for (int i = 0; i <= *anz; ++i) {
		
		if (array[i] > value) {
			// Abbruch der Schleife; Element wurde nicht gefunden
			return false;
		}
		
		if (array[i] == value) {
			pos = i; // Abbruch der Schleife; Element wurde gefunden
			break;
		}
	}
	
	// Verschiebe alle Elemente nach vorne,
	// um das zu löschende Element zu überschreiben
	for (int i = pos; i < *anz; ++i) {
		array[i] = array[i + 1];
	}
	
	--(*anz);
	
	return true;
}

int main(int argc, char **argv) {
	
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
		if (input > 0 && anz == MAX_SIZE) {
			fprintf(stderr, "%s: Maximalgröße des Arrays (%d) "
				"erreicht! Es können keine weiteren Zahlen hinzugefügt "
				"werden. Bitte erst eine Zahl löschen!\n\n", argv[0],
				MAX_SIZE);
			continue; // Fortfahren der Schleife
		}
		// Überprüfe, ob direkt eine Zahl gelöscht werden soll,
		// obwohl das Array noch keine Elemente enthält
		else if (input < 0 && anz == 0) {
			fprintf(stderr, "%s: Das Array besitzt noch keinerlei "
				"Elemente! Bitte erst Zahlen hinzufügen!\n\n", argv[0]);
			continue; // Fortfahren der Schleife
		}
		
		// Wenn eingegebene Zahl größer als 0 ist, dann füge diese hinzu
		if (input > 0) {
			addValueToArray(zahlen, input, &anz);
		}
		// Wenn eingegebene Zahl kleiner als 0 ist, dann lösche diese
		else if (input < 0) {
			int del = abs(input); // der zu löschende Wert
			bool result = delValueFromArray(zahlen, del, &anz);
			
			// Überprüfe, ob Wert gelöscht werden konnte
			// (d.h. Wert wurde im Array gefunden)
			if (!result) {
				printf("FEHLER: Der angegebene Wert '%d' konnte nicht "
					"gefunden werden!\n", del);
			}
		}
		
		// Ausgabe des Arrays
		printf("Array: ");
		
		if (anz == 0) { // passiert, wenn alle Elemente gelöscht wurden
			printf("(leer)");
		} else {
			// Ausgabe vorhandener Elemente
			for (int i = 0; i < anz; ++i) {
				printf("%d ", zahlen[i]);
			}
		}
		
		printf("\n\n"); // Leerzeile
	}
	
	return EXIT_SUCCESS; // Programmende
}
