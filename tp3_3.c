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

    srand((int)time(NULL));
    rand();

    int n, nProd;
    char *buffNombre; 
    Producto unProducto, *vectorProductos;////////**?
    Cliente  unCliente , *vectorClientes;

    printf("\nIngrese la cantidad de clientes: ");
    scanf("%d", &n);
    buffNombre = (char *) malloc(30*sizeof(char));
    vectorClientes = (Cliente *) malloc(n*sizeof(Cliente));

    for (int i = 0; i < n; i++) {
        
        //id cliente:
        unCliente.ClienteID = i;
        //nombre cliente:
        printf("%d) Nombre del cliente: ", i+1);
        fflush(stdin);
        gets(buffNombre);
        unCliente.NombreCliente = (char *) malloc((strlen(buffNombre)+1)*sizeof(char));
        strcpy(unCliente.NombreCliente, buffNombre);
        //cantidad de productos:
        unCliente.CantidadProductosAPedir = rand()%5 + 1; 
        nProd = unCliente.CantidadProductosAPedir;

        /*** Producto *******/
        vectorProductos = (Producto *) malloc(nProd*sizeof(Producto));
        for (int j = 0; j < nProd; j++) {

            unProducto.ProductoID = j;//id
            unProducto.Cantidad = rand()%10 + 1;//cantidad
            unProducto.TipoProducto = TiposProductos[rand()%5];//tipo
            unProducto.PrecioUnitario = (rand()%9001+(float)1000)/100;//--->(de 0 a 9.000 + 1.000)/100
            *(vectorProductos+j) = unProducto;
        }
        unCliente.Productos = vectorProductos;
        /*** fin Producto ***/

        *(vectorClientes+i) = unCliente;
    }
    free(buffNombre);

    int idC, idP, cantidad, unidades;      
    char *nombre, *tipo;
    float precio;

    printf("\n");
    for (int i = 0; i < n; i++) {

        idC      = vectorClientes[i].ClienteID;
        nombre   = vectorClientes[i].NombreCliente; 
        cantidad = vectorClientes[i].CantidadProductosAPedir; 

        printf("--- Cliente %d - %s - %d productos ---\n", idC+1, nombre, cantidad);

        for (int j = 0; j < cantidad; j++) {
            
            idP      = vectorClientes[i].Productos[j].ProductoID;
            unidades = vectorClientes[i].Productos[j].Cantidad;
            tipo     = vectorClientes[i].Productos[j].TipoProducto;
            precio   = vectorClientes[i].Productos[j].PrecioUnitario;

            printf("\t%d) %s:\t%d x $%.2f\n", j+1, tipo, unidades, precio);
        }
        printf("\n");
    }

    free(vectorProductos);
    free(vectorClientes);

    // for (int i = 0; i < n; i++) {

    //     for (int j = 0; j < cantidad; j++) {
            
    //         free(vectorProductos+i);
    //     }
    // }

    
    
    
    
    return 0;
}