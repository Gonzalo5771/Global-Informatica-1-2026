#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

//Prototipos funcs.
void cargar_datos(char Codigos_kits[][8], char Nombres_kits[][30], int Unidades_kits[], int Prestados_kits[][5]);
void ver_prestamos_disponibilidad(char Codigos_kits[][8], char Nombres_kits[][30], int Unidades_kits[], int Prestados_kits[][5]);
bool es_numerico(char string[]);

	//Funcion para DEBUG. Creada por IA. https://share.gemini.google/GieD2gmICYnd
	void cargar_datos_debug(char Codigos_kits[][8], char Nombres_kits[][30], int Unidades_kits[], int Prestados_kits[][5]);

int main ()
{
	//Opción menú ppal.
	int op;
	
//	//Códigos kits
//	
//	int Cod_kit_1;
//	int Cod_kit_2;
//	int Cod_kit_3;	
//	int Cod_kit_4;
//	int Cod_kit_5;	
//	int Cod_kit_6;	
//	int Cod_kit_7;	
//	int Cod_kit_8;	
//	int Cod_kit_9;
//	int Cod_kit_10;
	
	
	
//	//Unidades kits
//	
//	int Unit_kit_1[];
//	int Unit_kit_2[20];
//	int Unit_kit_3[20];	
//	int Unit_kit_4[20];
//	int Unit_kit_5[20];	
//	int Unit_kit_6[20];	
//	int Unit_kit_7[20];	
//	int Unit_kit_8[20];	
//	int Unit_kit_9[20];
//	int Unit_kit_10[20];

	
	
//	//Unidades prestadas cada día de la semana.
//	
//	int Prest_kit_1[5];
//	int Prest_kit_2[5];
//	int Prest_kit_3[5];	
//	int Prest_kit_4[5];
//	int Prest_kit_5[5];	
//	int Prest_kit_6[5];	
//	int Prest_kit_7[5];	
//	int Prest_kit_8[5];	
//	int Prest_kit_9[5];
//	int Prest_kit_10[5];	
	
	
	// Datos Kits
	char Nombres_kits[10][30]= {NULL};
	char Codigos_kits[10][8]= {NULL};
	int Unidades_kits[10]= {NULL};
	int Prestados_kits[10][5]= {NULL};
	
	cargar_datos_debug(Codigos_kits, Nombres_kits, Unidades_kits, Prestados_kits);
	
	while (op != 5)
	{
		printf("\n----------------------------------------------\n");
		printf("Elija que desea hacer:\n1-Cargar datos\n2-Ver prestamos y disponibilidad\n3-Ver disponibilidad de un kit\n4-Ver estadisticas\n");

		scanf("%d", &op);
		
		printf("\n----------------------------------------------\n");

		switch(op)
		{
			case 1: //Carga de datos
				
				printf("\n-DEBUG: CASE 1\n");
			
				cargar_datos(Codigos_kits, Nombres_kits, Unidades_kits, Prestados_kits);
			
				break;
			
			case 2: //Ver prestamos y disponibilidad
			
				ver_prestamos_disponibilidad(Codigos_kits, Nombres_kits, Unidades_kits, Prestados_kits);
				
				break;
			
			case 3: //Ver disponibilidad de un kit
			
				break;
			
			case 4: //Ver estadísticas
			
				break;
				
			case 5: //Salir del programa
				
				break;
		
		}
	}	 
		
	return 0;
}

void cargar_datos(char Codigos_kits[][8], char Nombres_kits[][30],int Unidades_kits[], int Prestados_kits[][5])
{
	char dias_semana[5][10]={"LUNES","MARTES","MIERCOLES","JUEVES","VIERNES"};
	char nombre_auxiliar[30];
	
	//Variables intermediarias que permiten "arrepentirse" se hacer una carga de datos y conservar el vlaor anterior.
	char codigo_intermedio[8];
	char nombre_intermedio[30];
	int unidades_intermedio;
	int prestados_intermedio;
	
	char op;
	
	printf("\n-DEBUG: CARGAR_DATOS\n");
	
	printf("Ingrese los datos que se le soliciten. Presione enter si prefiere no modificar un dato");
	
	for(int i=0; i<10; i++)
	{
		if(Codigos_kits[i] == NULL);
		
		int num_kit = i+1;
		
		printf("\n--------------------KIT %d--------------------\n", num_kit);
		
		//Ingreso CÓDIGO
		printf("\nIngrese el codigo del kit %d (Max. 8 digitos numericos): ", num_kit);
		scanf("%s", codigo_intermedio);
		
		while (strlen(codigo_intermedio)>8 || es_numerico(codigo_intermedio)==false)
		{
			printf("ERROR: Ingrese un codigo valido de entre 1 y 8 digitos numéricos: ");
			scanf("%s", codigo_intermedio);
		}

		//Verificar si hay valores anteriores y guardar (o no)
		if(Codigos_kits[i][0] == '\0')
		{
			strcpy(Codigos_kits[i], codigo_intermedio);
		}
		else if(Codigos_kits[i][0] != '\0')
		{
			printf("El kit %d ya tiene un código asignado (%s), desea sobre escribirlo? s/n", num_kit, Codigos_kits[i]);
			
			do
			{
				scanf("%c", &op);
			}
			while(op != 's' && op != 'n');
			
			if(op=='s')
			{
				strcpy(Codigos_kits[i], codigo_intermedio);
			}
		}
		printf("-DEBUG: EL NÚMERO INGRESADO ES %s", Codigos_kits[i]);//DEBUG
		
		
		//Ingreso NOMBRE
		printf("\nIngrese el nombre del kit %d: ", num_kit);
		scanf("%c", &nombre_auxiliar);
		gets(nombre_intermedio);
		strncat(nombre_auxiliar, nombre_intermedio, 30);

		while (strlen(Nombres_kits[i])>30)
		{
			printf("ERROR: Ingrese un nombre valido de entre 1 y 30 caracteres alfanumericos: ");
			scanf("%c", &nombre_auxiliar);
			gets(nombre_intermedio);
			strncat(nombre_auxiliar, nombre_intermedio, 30);	
		}
		
		//Verificar si hay valores anteriores y guardar (o no)
		if(Nombres_kits[i][0] == '\0')
		{
			strcpy(Nombres_kits[i], nombre_intermedio);
		}
		else if(Nombres_kits[i][0] != '\0')
		{
			printf("El kit %d ya tiene un código asignado (%s), desea sobre escribirlo? s/n", num_kit, Nombres_kits[i]);
			
			do
			{
				scanf("%c", &op);
			}
			while(op != 's' && op != 'n');
			
			if(op=='s')
			{
				strcpy(Nombres_kits[i], nombre_intermedio);
			}
		}
		printf("\n-DEBUG: NOMBRE INGRESADO ES %s", Nombres_kits[i]);//DEBUG
		
		
//		//ingreso UNIDADES
//		printf("\nIngrese las unidades totales del kit %d: ", num_kit);
//		scanf("%d", &Unidades_kits[i]);
//		
//		while(Unidades_kits[i]<1||Unidades_kits[i]>20)
//		{
//			printf("ERROR: Ingrese una valor de unidades valida de entre 1 y 20: ");
//			scanf("%d", &Unidades_kits[i]);
//		}
//		printf("\n-DEBUG: UNIDADES INGRESADAS ES %d", Unidades_kits[i]);//DEBUG
//		
//		
//		//Ingreso PRESTAMOS
//		printf("\nA continuacion, ingresara las unidades prestadas del kit %d para cada dia de la semana", num_kit);
//		
//		for(int j=0; j<5; j++)
//		{
//			printf("\n%s: ", dias_semana[j]);
//			scanf("%d", &Prestados_kits[i][j]);
//			
//			while (Prestados_kits[i][j]>Unidades_kits[i])
//			{
//				printf("ERROR: Ingrese una valor de unidades prestadas valida de entre 1 y %d: ", Unidades_kits[i]);
//				scanf("%d", &Prestados_kits[i][j]);
//			}
//			printf("\n-DEBUG: UNIDADES PRESTADAS INGRESADAS %s ES %d", dias_semana[j], Prestados_kits[i][j]);//DEBUG
//		}
		
	}
	

}

void ver_prestamos_disponibilidad(char Codigos_kits[][8], char Nombres_kits[][30],int Unidades_kits[], int Prestados_kits[][5])
{
	char dias_semana[5][10]={"LUNES","MARTES","MIERCOLES","JUEVES","VIERNES"};
	
	for(int i=0; i<10; i++)
	{
		int num_kit = i+1;
		printf("\n--------------------KIT %d--------------------\n", num_kit);
		printf("Nombre: %s    Codigo: %s \n\n",Nombres_kits[i], Codigos_kits[i]);
		printf("Disponibilidad:\n\n");
		printf("Unidades totales: %d\n\n", Unidades_kits[i]);
		for(int j=0;j<5;j++)
		{
			printf("%s:  Prestamos: %d    Disponibilidad: %d\n", dias_semana[j], Prestados_kits[i][j], (Unidades_kits[i]-Prestados_kits[i][j]));
		}
	}
}

bool es_numerico(char string[8])
{
	int verificados = 0;
	bool veredicto;
	
	for (int i=0; i<strlen(string);i++)
	{
		if (isdigit(string[i]))
		{
			verificados++;
		}
	}
	if(verificados==strlen(string))
	{
		veredicto=true;
	}
	else
	{
		veredicto=false;
	}
	
	return veredicto;
}


//FUNCION PARA CARGAR DATOS DE PRUEBA A PARTIR DE UN .TX. CREADA POR IA SEGÚN SE INDICA EN EL INFORME.
// https://share.gemini.google/Cnf5ArymnMCT
void cargar_datos_debug(char Codigos_kits[][8], char Nombres_kits[][30], int Unidades_kits[], int Prestados_kits[][5])
{
	FILE *archivo = fopen("variables_debug.txt", "r");
	
	if (archivo == NULL)
	{
		printf("\n-ERROR DEBUG: No se pudo abrir 'variables_debug.txt'.\n");
		return;
	}
	
	int i = 0;
	while (i < 10 && fscanf(archivo, " %7[^;];%29[^;];%d;%d;%d;%d;%d;%d",
							Codigos_kits[i],
							Nombres_kits[i],
							&Unidades_kits[i],
							&Prestados_kits[i][0],
								&Prestados_kits[i][1],
									&Prestados_kits[i][2],
										&Prestados_kits[i][3],
											&Prestados_kits[i][4]) == 8)
	{
		i++;
	}
	
	fclose(archivo);
	printf("\n-DEBUG: Se cargaron %d kits desde 'variables_debug.txt'.\n", i);
}


