// Unser drittes Programm: Hallo mit Ausgabe eines oder mehrerer Namen
//
// Aufruf: hello3 name1 name2 ...
//
// Klaus Kusche, 2010

#include <stdio.h>

int main(int argc, const char *argv[])
{
    if (argc == 1) {
        printf("Hallo, wer bist du?\n");
    } else if (argc == 2) {
        printf("Hallo %s\n", argv[1]);
    } else {
        printf("Hallo");
        for (int i = 1; i < argc; ++i) {
            if (i < argc -1 ) {
                printf(", %s", argv[i]);
            } else {
                printf(" und %s!\n", argv[i]);
            }
        }
    }

    return 0;
}
