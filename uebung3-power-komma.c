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
		printf("%s: Bitte genau zwei Zahlen eingeben!\n", argv[0]);
		return 1;
	}
  	
  	// Umwandeln der Eingaben in Zahlen
  	double basis = atof(argv[1]);
  	double exponent = atof(argv[2]);
  	
  	double potenz = 1; // neutrales Element einer Multiplikation
  	
  	// Berechne Potenz (Möglichkeit 1)
  	for (int i = 1; i <= abs(exponent); i++) {
		potenz *= basis;
	}
	
	// Ausgabe der errechneten Potenz (Möglichkeit 1)
	printf("%g hoch %g = %g\n", basis, exponent,
		(exponent < 0) ? (1 / potenz) : potenz);
	
	// Zurücksetzen der Variable
	potenz = 1; // neutrales Element einer Multiplikation
  	
  	// Berechne Potenz (Möglichkeit 2)
  	// hier: Potenz wird in Abhängigkeit berechnet, ob Exponent
  	// positiv oder negativ ist
  	for (int i = 1; i <= abs(exponent); i++) {
		potenz *= (exponent < 0) ? (1 / basis) : basis;
	}
	
	// Ausgabe der errechneten Potenz (Möglichkeit 2)
	printf("%g hoch %g = %g\n", basis, exponent, potenz);
		
	return 0;
}
