/* Trabajo Práctio No3 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

int main() {

    char *Buff; //variable auxiliar
    char* vector[N];

    Buff = (char *) malloc(30*sizeof(char));

    for (int i = 0; i < N; i++) {

        printf("%d) Ingrese un nombre: ", i+1);
        gets(Buff);
        vector[i] = (char *) malloc((strlen(Buff))*sizeof(char));
        strcpy(vector[i], Buff);
    }
    free(Buff);
    
    printf("\n El vector de nombres es:\n");
    printf("[ ");
    for (int i = 0; i < N; i++) {
        printf("%s ", vector[i]);
    }
    printf("]");

    for (int i = 0; i < N; i++) {
        free(vector[i]);
    }
    
    return 0;
}