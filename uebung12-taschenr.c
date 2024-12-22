/*
 * Taschenrechner
 * 
 * Sebastian Girke, PIA24
 * 2024-12-13
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
	
	// Überprüfe, ob Eingabe erfolgt ist
	if (argc == 1) {
		fprintf(stderr, "%s: Bitte eine Rechnung eingeben!\n", argv[0]);
		return EXIT_FAILURE; // Programmende
	}
	
	// Überprüfe, ob eine gerade Anzahl von Parametern übergeben wurde
	if ((argc - 1) % 2 == 0) {
		fprintf(stderr, "%s: Keine gültige Anzahl an Parametern!\n",
			argv[0]);
		return EXIT_FAILURE; // Programmende
	}
	
	// Speichere erste Zahl als Zwischenwert
	double res = atof(argv[1]);
	
	// Überprüfe, ob nur eine Zahl ausgegeben wurde
	if (argc == 2) {
		// Ausgabe
		printf("Ergebnis: %g\n", res);
		return EXIT_SUCCESS; // Programmende
	}
	
	// Iteration über alle Zahlen in der Eingabe
	// Hinweis: Iteration beginnt erst ab der zweiten Zahl
	for (int i = 3; i < argc; i += 2) {
		
		double num = atof(argv[i]);
		char operand = argv[i - 1][0];
		
		// Überprüfe aktuellen Operanden
		switch (operand) {
			case '+':
				res += num;
				break;
			case '-':
				res -= num;
				break;
			case 'x':
				res *= num;
				break;
			case '/':
				// Bricht ab, wenn durch Null dividiert wird
				if (num == 0) {
					fprintf(stderr,
						"%s: Division durch Null nicht erlaubt!\n",
						argv[0]);
					return EXIT_FAILURE; // Programmende
				}
				res /= num;
				break;
			case 'p':
				res = pow(res, num);
				break;
			default:
				fprintf(stderr, "%s: Ungültiger Operand '%c'!\n",
					argv[0], operand);
				return EXIT_FAILURE; // Programmende
		}
	}
	
	// Ausgabe
	printf("Ergebnis: %g\n", res);
	
	return EXIT_SUCCESS; // Programmende
}
