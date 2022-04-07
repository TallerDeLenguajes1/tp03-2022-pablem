//Ejemplos resueltos
///Ejemplo 1 - Trabajando con cadena de caracteres
//cargar cadena con gets()
// imprimir frases por pantalla con printf() y puts()

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char frase [100];
    char texto[] = "Ud escribió:";

    printf ("Escriba una frase: ") ;
    gets (frase);
    printf ("%s\n", texto) ;
    printf ("%s\n", frase) ;//forma 1 de escribir
    puts (frase);//forma 2 de escribir

    print("strlen de frase --> %d\n", strlen(frase));
    print("sizeof de frase --> %d\n", sizeof(frase));

return 0;
}