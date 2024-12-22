// Potenz zweier ganzer Zahlen (a hoch n)
// Programm-Skelett zur Angabe
//
// Aufruf: power a n
//
// Klaus Kusche, 2010

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {
	
	// Überprüfe, ob zwei Zahlen eingegeben wurden
	if (argc != 3) {
		fprintf(stderr, "%s: Bitte genau zwei Zahlen eingeben!\n", argv[0]);
		return 1;
	}
  	
  	// Umwandeln der Eingaben in Zahlen
  	int basis = atoi(argv[1]);
  	int exponent = atoi(argv[2]);
  	
  	// Überprüfe, ob Exponent mind. 0 ist
  	if (exponent < 0) {
		fprintf(stderr, "%s: Nur positive Exponenten erlaubt "
			"(größer oder gleich 0)\n", argv[0]);
		return 1;
	}
	
	int potenz = 1; // neutrales Element einer Multiplikation
	
	// Berechne Potenz
	for (int i = 1; i <= exponent; i++) {
		potenz *= basis;
	}
	
	// Ausgabe der errechneten Potenz
	printf("%d hoch %d = %d\n", basis, exponent, potenz);
	
	return 0;
}
