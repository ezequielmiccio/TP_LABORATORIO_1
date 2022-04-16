#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

// menu principal
int menu(int km, float aerolineas, float latam)
{
    int opcion;
    char cant;

    system("cls");
    printf("Ezequiel Miccio - DIV G\n\n\n");
    printf("                    ******************************************\n                    ******************************************\n                    ********* BIENVENIDOS A DESPEGAR *********\n                    ******************************************\n                    ******************************************\n\n");

    printf("1) Ingresar Kilometros: km = %d\n", km);
    printf("2) Ingresar Precio de Vuelos: Aerolineas = %.2f, Latam %.2f\n", aerolineas, latam);
    printf("3) Calcular todos los costos\n");
    printf("4) Informar resultados\n");
    printf("5) Carga forzada de datos\n");
    printf("6) Salir\n\n");

    printf("Ingrese una opcion: \n");
    fflush(stdin);
    cant = scanf("%d", &opcion);

    if(cant != NULL)
    {
        if(cant == 0)
        {
            printf("ERROR: La opcion elegida no existe\n");

        }
    }
    else
    {
        printf("ERROR: Ingrese una opcion valida\n");
    }

    return opcion;
}

// menu vuelos

int menuVuelos()
{
    int opcion;

    printf("OPCION 2) Ingrese el precio de las siguientes aerolineas:\n");
    printf("1) Precio Aerolineas Argentinas\n");
    printf("2) Precio Latam\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

// menu pagos: case 4
void menuPagos(float aereoTd, float aereoTc, float aereoBit, float aereoU, float latamTd, float latamTc, float latamBit, float latamU, float dif)
{

    printf("AEROLINEAS ARGENTINAS\n");
    printf("A) Tarjeta de Debito (10 descuento): $%.2f\n", aereoTd);
    printf("B) Tarjeta de Credito (25 interes): $%.2f\n", aereoTc);
    printf("C) Bitcoin (1BTC = 4606954.55 PESOS ARG): $%.2f\n", aereoBit);
    printf("D) Mostrar precio por KM (precio unitario): $%.2f\n\n", aereoU);

    printf("LATAM\n");
    printf("A) Tarjeta de Debito (10 descuento): %.2f: $\n", latamTd);
    printf("B) Tarjeta de Credito (25 interes): $%.2f\n", latamTc);
    printf("C) Bitcoin (1BTC = 4606954.55 PESOS ARG): $%f\n", latamBit);
    printf("D) Mostrar precio por KM (precio unitario): $%.2f\n", latamU);

    printf("Diferencia de precio ingresada (Latam - Aerolineas): $%.2f\n", dif);

}


