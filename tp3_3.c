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
    Producto *Productos; //El tamaño de este arreglo depende de la variable
} Cliente;

int main() {

    int nClientes;
    char *buffNombre; 
    Producto unProducto, *vectorProductos;
    Cliente  unCliente , *vectorClientes;

    // int idC, idP, cantidad, unidades;      
    // char *nombre, *tipo;
    // float precio;

    buffNombre = (char *) malloc(30*sizeof(char));
    vectorProductos = (Producto *) malloc(5*sizeof(Producto));
    vectorClientes = (Cliente *) malloc(5*sizeof(Cliente));
    srand((int)time(NULL));

    printf("\nIngrese la cantidad de clientes: ");
    scanf("%d", nClientes);

    for (int i = 0; i < nClientes; i++) {
        
        //id cliente:
        unCliente.ClienteID = i;
        //nombre cliente:
        printf("%d) Nombre del cliente: ", i+1);
        gets(buffNombre);
        unCliente.NombreCliente = (char *) malloc((strlen(buffNombre)+1)*sizeof(char));
        strcpy(unCliente.NombreCliente, buffNombre);
        //cantidad de productos:
        unCliente.CantidadProductosAPedir = rand()%5 + 1; 

        /*** Producto *******/
        for (int j = 0; j < unCliente.CantidadProductosAPedir; j++) {
            
            unProducto.ProductoID = j;//id
            unProducto.Cantidad = rand()%10 + 1;//cantidad
            unProducto.TipoProducto = TiposProductos[rand()%5+1];//tipo
            unProducto.PrecioUnitario = (rand()%9001+1000)/100;//--->(de 0 a 9.000 + 1.000)/100
            vectorProductos[j] = unProducto;
        }
        unCliente.Productos = vectorProductos;
        /*** fin Producto ***/

        vectorClientes[i] = unCliente;
    }
    free(buffNombre);
    // free(vectorProductos);



    // printf("\n");
    // for (int i = 0; i < nClientes; i++) {

    //     idC      = vectorClientes[i].ClienteID;
    //     nombre   = vectorClientes[i].NombreCliente; 
    //     cantidad = vectorClientes[i].CantidadProductosAPedir; 

    //     printf("--- Cliente %d - %s - %d productos ---\n", idC, nombre, cantidad);

    //     for (int j = 0; j < cantidad; j++) {
            
    //         idP      = vectorClientes[i].Productos[j].ProductoID;
    //         unidades = vectorClientes[i].Productos[j].Cantidad;
    //         tipo     = vectorClientes[i].Productos[j].TipoProducto;
    //         precio   = vectorClientes[i].Productos[j].PrecioUnitario;

    //         printf("\t%d) %s: %d x $%.2f\n", i+1, tipo, unidades, precio);
    //     }
    //     printf("\n");
    // }


    
    
    
    
    return 0;
}