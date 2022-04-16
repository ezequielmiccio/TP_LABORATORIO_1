#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

// ingreso de kilometros: case 1
int case1()
{
        int km;
        int cant;

            printf("OPCION 1) Ingrese kilometros: \n");
            cant = scanf("%d", &km);

            while(km <= 0 || cant == 0)
            {
                fflush(stdin);
                printf("Ingrese kilometros validos: ");
                cant = scanf("%d", &km);
            }

        return km;

}

// fin funcion case 1


// precio vuelos case 2
float precioVuelos(int x)
{
    float precio;

    if(x == 1)
    {
        printf("Ingrese el precio de vuelo de Aerolineas Argentinas:\n");
        scanf("%f", &precio);
    }
    else
    {
        printf("Ingrese el precio de vuelo de Latam:\n");
        scanf("%f", &precio);
    }

    return precio;
}

// fin precio vuelos case 2


// funciones case 3
float tarjetaCredito(float precio)
{
    precio = precio + precio * 1.25;

    return precio;
}

float tarjetaDebito(float precio)
{
    precio = precio - precio * 0.10;

    return precio;
}

float bitcoin(float precio)
{
    precio = precio / 4606954.55;

    return precio;
}

float valorUnitario(int km, float precio)
{
    precio = precio / km;

    return precio;
}

float diferenciaVuelos(float aero, float latam)
{
    float precio;


    if(aero > latam)
    {
        precio = aero - latam;
    }
    else
    {
        precio = latam - aero;
    }

    return precio;
}

// fin funciones case 3
