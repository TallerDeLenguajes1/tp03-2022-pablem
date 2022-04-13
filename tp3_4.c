/* Trabajo Práctio No3 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char *buff, **matrix;
    int filas;

    printf("Ingrese la cantidad de nombres: ");
    scanf("%d", &filas);

    buff = (char *) malloc(32*sizeof(char));
    matrix = (char **) malloc(filas*sizeof(char *));

    for (int i = 0; i < filas; i++) {

        printf("%d) Ingrese un nombre: ", i+1);
        fflush(stdin);
        gets(buff);

        matrix[i] = (char *) malloc((strlen(buff)+1)*sizeof(char));

        strcpy(matrix[i], buff);
    }
    free(buff);
    
    printf("\nNombres: [ ");
    for (int i = 0; i < filas; i++) {
        printf("%s ", matrix[i]);
    }
    printf("]");

    for (int i = 0; i < filas; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return 0;
}