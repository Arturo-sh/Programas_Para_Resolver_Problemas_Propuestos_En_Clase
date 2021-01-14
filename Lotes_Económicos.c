/*
Programa que resuelve los ejercicios propuestos en clase haciendo uso de funciones
Autor: Arturo Salas Hernández
*/
#include<stdio.h> // Libreia estandar para entrada y salida de datos
#include<math.h> //Libreria para poder sacar la raiz cuadrada de un numero
#include<stdlib.h>
#include<time.h>

//Prototipos de las funciones para cada ejercicio
void Ejercicio1();
void Ejercicio2();
void Ejercicio3();

int main(){
	
	int opcion = 0;
	char caracter;
	
	do{
	printf("\n\t   :: Menu ::\n");
	printf("\t1.- Ejercicio 1\n\t2.- Ejercicio 2\n\t3.- Ejercicio 3\n\t4.- Salir\n\n\tDigite una opcion del menu: ");
	scanf("%d",&opcion);
	system("cls"); // Limpiado de pantalla
		
	switch(opcion){
		case 1: Ejercicio1();
		break;
		
		case 2: Ejercicio2();
		break;
		
		case 3: Ejercicio3();
		break;
		
		case 4: printf("\n\tUsted eligio salir\n"); 
		sleep(2);
		break;
		
		default: printf("\n\tNumero fuera del menu!\n\tIntentelo de nuevo\n");
		break;
	}
	
	if(opcion != 4){
	printf("\n\tDesea ejecutar otro ejercicio?(s/n): ");
	scanf("%s",&caracter);
	system("cls");
	}
	else{
		caracter = 'n';
	}
	
	}while(caracter == 's' || caracter == 'S');
	
	system("cls");
	printf("\n\tGracias por usar nuestro software :)\n");
	
	return 0;
}
	// Implementacion de funciones para la resolucion de los ejercicios
	void Ejercicio1(){
		
	float D, C, S, i, H, Q, TC; // Declaracion de las variables
	
	printf("\t\tPrimer ejercicio\n\n");
	printf("Digite el valor de la demanda (D): ");
	scanf("%f",&D);
	
	printf("Digite el costo de la unidad (C): ");
	scanf("%f",&C);

	printf("Digite el costo por realizar el pedido (S): ");
	scanf("%f",&S);
	
	printf("Digite el costo por mantener el inventario (i): ");
	scanf("%f",&i);
	
	H = i * C; // Operacion para obtener el valor de H
	Q = sqrt((2*D*S)/H); // Operacion para obtener el valor de Q
	TC = (D * C) + ((D / Q) * S) + ((Q / 2) * H); // Operacion para obtener el tamaño de la orden (TC)
	
	printf("\n\tEl costo por mantener en nivel el inventario (H) es: %.2f\n",H);
	printf("\tLa cantidad economica (Q) es: %.2f\n",Q);
	printf("\tEl tama%co de la orden (TC) es: %.2f\n",-92,TC);
	}

	void Ejercicio2(){
		
		float D, S, H, Q,  CA, CM; // Declaracion de las variables
		
		printf("\tSegundo ejercicio\n\n");
		printf("Digite el valor de la demanda (D): ");
		scanf("%f",&D);
		
		printf("Digite el costo por colocar una orden (S): ");
		scanf("%f",&S);
		
		printf("Digite el costo por almacenar anual (H): ");
		scanf("%f",&H);
		
		Q = sqrt((2*D*S)/H); // Operacion para obtener el valor de Q
		CA = S * (D / Q);
		CM = H * (Q / 2);
		
		printf("\n\tEl tama%co de la orden (Q) es: %.2f\n",-92,Q);
		printf("\tEl costo anual por ordenar es: %.2f\n",CA);
		printf("\tEl costo por manejo es: %.2f\n",CM);
	}

	void Ejercicio3(){
		
		float D, S, H, C, U, Q, TC, Pa, t; // Declaracion de las variables
		
		printf("\tTercer ejercicio\n\n");
		printf("Digite el valor de la demanda (D): ");
		scanf("%f",&D);
		
		printf("Digite el costo por realizar el pedido (S): ");
		scanf("%f",&S);
		
		printf("Digite el costo por almacen anual (H): ");
		scanf("%f",&H);
		
		printf("Digite el costo unitario (C): ");
		scanf("%f",&C);
		
		printf("Digite el costo por unidad faltante (U): ");
		scanf("%f",&U);
		
		Q = sqrt((2 * D * S) / H) * sqrt((H * U) / U);
		TC = sqrt((2 * D * S) / U) * sqrt(H / (H + U));
			
		Pa = D / Q;
		t = Q / D;
		
		printf("\n\tla cantidad optima perdida es: %.2f\n",Q);
		printf("\tEl costo total por a%co es: %.2f\n",-92,TC);
		printf("\tEl numero de perdidas por a%co es: %.2f\n",-92,Pa);		
		printf("\tEl tiempo entre pedidos es: %.2f\n",t);		
	}
