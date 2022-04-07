/* Trabajo Práctio No3 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} Producto;

typedef struct {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos //El tamaño de este arreglo depende de la variable
} Cliente;

int main() {

    int nClientes, nProductos;
    char *buff; 
    char* nombres[20];

    Cliente unCliente;
    Producto unProducto;

    //vector de clientes / productos

    buff = (char *) malloc(30*sizeof(char));
    // buff2 = (char *) malloc(15*sizeof(char));

    srand((int)time(NULL));

    printf("\nIngrese la cantidad de clientes: ");
    scanf("%d", nClientes);

    for (int i = 0; i < nClientes; i++) {
        
        //id cliente:
        unCliente.ClienteID = i;

        //nombre cliente:
        printf("%d) Nombre del cliente: ", i+1);
        gets(buff);
        unCliente.NombreCliente = (char *) malloc((strlen(buff)+1)*sizeof(char));
        strcpy(unCliente.NombreCliente, buff);

        //cantidad de productos:
        unCliente.CantidadProductosAPedir = rand()%5 + 1; 

        /* Producto */
        for (int j = 0; j < unCliente.CantidadProductosAPedir; j++) {
            
            unProducto.ProductoID = j;
            unProducto.Cantidad = rand()%10 + 1;
            buff = TiposProductos[rand()%5+1];
            unProducto.TipoProducto = (char *) malloc((strlen(buff)+1)*sizeof(char));
            strcpy(unProducto.TipoProducto, buff);
            unProducto.PrecioUnitario = (rand()%9001+1000)/100;//---> probar
        }
        // unCliente.Productos = 
        

    }
    free(buff);
    
    
    
    return 0;
}