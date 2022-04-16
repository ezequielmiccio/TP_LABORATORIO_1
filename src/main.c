/*
 ============================================================================
 Name        : main.c
 Author      : 
 Version     :
 Copyright   :
 Description : Ezequiel Miccio - 1G
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "menu.h"
#include "funciones.h"

int main(void) {
	setbuf(stdout, NULL);

	// menu principal
	char salir = 'n';

	// case 1
	int km = 0;
	// case 2
	int opcionVuelos;
	int flagCase1 = 0;
	int flagAerolineas = 0;
	int flagLatam = 0;
	float aerolineas;
	float latam;
	// case 3
	float aeroDebito;
	float aeroCredito;
	float aeroBitcoin;
	float aeroUnitario;
	float latamDebito;
	float latamCredito;
	float latamBitcoin;
	float latamUnitario;
	float difenciaAerea;
	int flagCase3 = 0;

	do {

		switch (menu(km, aerolineas, latam)) {
		case 1:
			system("cls");
			km = case1();
			printf("Kilometros ingresados: %d", km);

			if (km >= 0) {
				flagCase1 = 1;
			}

			getch();
			break;

		case 2:

			system("cls");

			if (flagCase1 == 1) {
				opcionVuelos = menuVuelos();

				switch (opcionVuelos) {

				case 1:
					aerolineas = precioVuelos(opcionVuelos);
					flagAerolineas = 1;
					break;

				case 2:
					latam = precioVuelos(opcionVuelos);
					flagLatam = 1;
					break;

				}

				if (flagLatam == 1) {
					printf("El precio de latam fue cargado correctamente.\n");
				}

				if (flagAerolineas == 1) {
					printf(
							"El precio de aerolineas fue cargado correctamente.\n");
				}

			} else {
				printf(
						"ERROR: Para ingresar los precios, primero se deben ingresar los km.");
			}

			getch();
			break;

		case 3:

			system("cls");

			if (flagAerolineas == 0 && flagLatam == 0 && flagCase1 == 0) {
				printf(
						"Se deben ingresar los kilometros y precios de aerolineas LATAM y AEROLINEAS ARGENTINAS.");
			} else if (flagCase1 == 1 && flagAerolineas == 0
					&& flagLatam == 0) {
				printf(
						"Se deben ingresar los precios de aerolineas LATAM y AEROLINEAS ARGENTINAS.");
			} else if (flagCase1 == 1 && flagAerolineas == 1
					&& flagLatam == 0) {
				printf("ERROR: Se debe ingresar el precio de LATAM.");
			} else if (flagCase1 == 1 && flagAerolineas == 0
					&& flagLatam == 1) {
				printf(
						"ERROR: Se debe ingresar el precio de AEROLINEAS ARGENTINAS.");
			} else {
				aeroDebito = tarjetaDebito(aerolineas);
				aeroCredito = tarjetaCredito(aerolineas);
				aeroBitcoin = bitcoin(aerolineas);
				aeroUnitario = valorUnitario(km, aerolineas);

				latamDebito = tarjetaDebito(latam);
				latamCredito = tarjetaCredito(latam);
				latamBitcoin = bitcoin(latam);
				latamUnitario = valorUnitario(km, latam);

				difenciaAerea = diferenciaVuelos(aerolineas, latam);

				printf("Aguarde... Realizando calculos...\nPresionar OPC 4.");

				flagCase3 = 1;
			}

			getch();
			break;

		case 4:
			system("cls");

			if (flagCase3 == 1) {
				menuPagos(aeroDebito, aeroCredito, aeroBitcoin, aeroUnitario,
						latamDebito, latamCredito, latamBitcoin, latamUnitario,
						difenciaAerea);
			} else {
				printf("ERROR: Primero se deben realizar los calculos.");
			}

			getch();
			break;

		case 5:
			system("cls");

			printf("AEROLINEAS ARGENTINAS\n");
			printf("A) Tarjeta de Debito (10 descuento): $%.2f\n",
					tarjetaDebito(162965));
			printf("B) Tarjeta de Credito (25 interes): $%.2f\n",
					tarjetaCredito(162965));
			printf("C) Bitcoin (1BTC = 4606954.55 PESOS ARG): $%.2f\n",
					bitcoin(162965));
			printf("D) Mostrar precio por KM (precio unitario): $%.2f\n",
					valorUnitario(7090, 162965));

			printf("LATAM\n");
			printf("A) Tarjeta de Debito (10 descuento): %.2f: $\n",
					tarjetaDebito(159339));
			printf("B) Tarjeta de Credito (25 interes): $%.2f\n",
					tarjetaCredito(159339));
			printf("C) Bitcoin (1BTC = 4606954.55 PESOS ARG): $%.2f\n",
					bitcoin(159339));
			printf("D) Mostrar precio por KM (precio unitario): $%.2f\n",
					valorUnitario(7090, 159339));

			printf(
					"Diferencia de precio ingresada (Latam - Aerolineas): $%.2f\n",
					diferenciaVuelos(162965, 159339));

			getch();
			break;
		case 6:

			printf("¿Confirma salida?");
			fflush(stdin);
			scanf("%c", &salir);
			break;

		default:
			printf("¡ERROR! OPCION INVALIDA");
		}

	} while (salir != 's');


	return EXIT_SUCCESS;
}
