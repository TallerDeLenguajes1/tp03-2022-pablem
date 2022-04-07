//Ejemplo 2 - Trabajando con cadena de caracteres con reserva de memoria

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *Buff;

    Buff = (char *)malloc(100*sizeof(char));
    printf ("Ingrese una frase\n");
    gets(Buff);


    printf("strlen de buff --> %d\n", strlen(Buff));
    printf("sizeof de buff --> %d\n", sizeof(Buff));

    free(Buff);
    
    return 0;
}
