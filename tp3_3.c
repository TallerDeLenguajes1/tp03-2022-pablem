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

    int nClientes, nProductos;
    char *buffNombre; 
    Producto *vectorProductos;
    Cliente  *vectorClientes;

    buffNombre = (char *) malloc(32*sizeof(char));

    printf("\nIngrese la cantidad de clientes: ");
    scanf("%d", &nClientes);

    vectorClientes = (Cliente *) malloc(nClientes*sizeof(Cliente));

    for (int i = 0; i < nClientes; i++) {
        
        //id cliente:
        vectorClientes[i].ClienteID = i;

        //nombre cliente:
        printf("%d) Nombre del cliente: ", i+1);
        fflush(stdin);
        gets(buffNombre);
        vectorClientes[i].NombreCliente = (char *) malloc((strlen(buffNombre)+1)*sizeof(char));
        strcpy(vectorClientes[i].NombreCliente, buffNombre);

        //cantidad de productos:
        vectorClientes[i].CantidadProductosAPedir = rand()%5 + 1; 
        nProductos = vectorClientes[i].CantidadProductosAPedir;

        /*** Producto *******/
        vectorProductos = (Producto *) malloc(nProductos*sizeof(Producto));

        for (int j = 0; j < nProductos; j++) {

            vectorProductos[j].ProductoID = j;//id
            vectorProductos[j].Cantidad = rand()%10 + 1;//cantidad
            vectorProductos[j].TipoProducto = TiposProductos[rand()%5];//tipo
            vectorProductos[j].PrecioUnitario = (rand()%9001+(float)1000)/100;//--->(de 0 a 9.000 + 1.000)/100
        }
        vectorClientes[i].Productos = vectorProductos;
        /*** fin Producto ***/
    }

    ///FUNCION MOSTRAR TODOS LOS CLIENTES Y PRODUCTOS
    int idC, idP, cantidad, unidades;      
    char *nombre, *tipo;
    float precio;

    printf("\n");
    for (int i = 0; i < nClientes; i++) {

        idC      = vectorClientes[i].ClienteID;
        nombre   = vectorClientes[i].NombreCliente; 
        cantidad = vectorClientes[i].CantidadProductosAPedir; 

        printf("------ Cliente %d, %s, %d producto/s ------\n", idC+1, nombre, cantidad);

        for (int j = 0; j < cantidad; j++) {
            
            idP      = vectorClientes[i].Productos[j].ProductoID;
            unidades = vectorClientes[i].Productos[j].Cantidad;
            tipo     = vectorClientes[i].Productos[j].TipoProducto;
            precio   = vectorClientes[i].Productos[j].PrecioUnitario;

            printf("\t%d) %s:\t%d x $%.2f\n", j+1, tipo, unidades, precio);
        }
        printf("\n");
    }

    ////FUNCION LIBERAR MEMORIA DINAMICA

    for (int i = 0; i < nClientes; i++) {
        
        free(vectorClientes[i].Productos);
        free(vectorClientes[i].NombreCliente);
    }

    free(buffNombre);
    free(vectorProductos);
    free(vectorClientes);

    return 0;
}